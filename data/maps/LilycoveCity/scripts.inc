# 1 "data//maps/LilycoveCity/scripts.pory"

# 2 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_MapScripts::
# 3 "data//maps/LilycoveCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
# 4 "data//maps/LilycoveCity/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
# 5 "data//maps/LilycoveCity/scripts.pory"
	.byte 0
# 6 "data//maps/LilycoveCity/scripts.pory"

# 7 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_OnTransition:
# 8 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_VISITED_LILYCOVE_CITY
# 9 "data//maps/LilycoveCity/scripts.pory"
	setvar VAR_CONTEST_HALL_STATE, 0
# 10 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
# 11 "data//maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
# 12 "data//maps/LilycoveCity/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 13 "data//maps/LilycoveCity/scripts.pory"
	end
# 14 "data//maps/LilycoveCity/scripts.pory"

# 15 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_OnLoad:
# 16 "data//maps/LilycoveCity/scripts.pory"
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
# 17 "data//maps/LilycoveCity/scripts.pory"
	end
# 18 "data//maps/LilycoveCity/scripts.pory"

# 19 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_SetWailmerMetatiles::
# 20 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, TRUE
# 21 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, TRUE
# 22 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, TRUE
# 23 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, TRUE
# 24 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, TRUE
# 25 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, TRUE
# 26 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, TRUE
# 27 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, TRUE
# 28 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, TRUE
# 29 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, TRUE
# 30 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, TRUE
# 31 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, TRUE
# 32 "data//maps/LilycoveCity/scripts.pory"
	return
# 33 "data//maps/LilycoveCity/scripts.pory"

# 34 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BerryGentleman::
# 35 "data//maps/LilycoveCity/scripts.pory"
	lock
# 36 "data//maps/LilycoveCity/scripts.pory"
	faceplayer
# 37 "data//maps/LilycoveCity/scripts.pory"
	dotimebasedevents
# 38 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
# 39 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
# 40 "data//maps/LilycoveCity/scripts.pory"
	giverandomberry BERRY_ID_CHERI, BERRY_ID_SITRUS
# 41 "data//maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 42 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
# 43 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
# 44 "data//maps/LilycoveCity/scripts.pory"
	release
# 45 "data//maps/LilycoveCity/scripts.pory"
	end
# 46 "data//maps/LilycoveCity/scripts.pory"

# 47 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ReceivedBerry::
# 48 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
# 49 "data//maps/LilycoveCity/scripts.pory"
	release
# 50 "data//maps/LilycoveCity/scripts.pory"
	end
# 51 "data//maps/LilycoveCity/scripts.pory"

# 52 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Man3::
# 53 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
# 54 "data//maps/LilycoveCity/scripts.pory"
	end
# 55 "data//maps/LilycoveCity/scripts.pory"

# 56 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Girl::
# 57 "data//maps/LilycoveCity/scripts.pory"
	lock
# 58 "data//maps/LilycoveCity/scripts.pory"
	faceplayer
# 59 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
# 60 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
# 61 "data//maps/LilycoveCity/scripts.pory"
	release
# 62 "data//maps/LilycoveCity/scripts.pory"
	end
# 63 "data//maps/LilycoveCity/scripts.pory"

# 64 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_GirlAquaGone::
# 65 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
# 66 "data//maps/LilycoveCity/scripts.pory"
	release
# 67 "data//maps/LilycoveCity/scripts.pory"
	end
# 68 "data//maps/LilycoveCity/scripts.pory"

# 69 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_RichBoy::
# 70 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
# 71 "data//maps/LilycoveCity/scripts.pory"
	end
# 72 "data//maps/LilycoveCity/scripts.pory"

# 73 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Sailor2::
# 74 "data//maps/LilycoveCity/scripts.pory"
	lock
# 75 "data//maps/LilycoveCity/scripts.pory"
	faceplayer
# 76 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
# 77 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
# 78 "data//maps/LilycoveCity/scripts.pory"
	release
# 79 "data//maps/LilycoveCity/scripts.pory"
	end
# 80 "data//maps/LilycoveCity/scripts.pory"

# 81 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Sailor2AquaGone::
# 82 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
# 83 "data//maps/LilycoveCity/scripts.pory"
	release
# 84 "data//maps/LilycoveCity/scripts.pory"
	end
# 85 "data//maps/LilycoveCity/scripts.pory"

# 86 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Woman2::
# 87 "data//maps/LilycoveCity/scripts.pory"
	lock
# 88 "data//maps/LilycoveCity/scripts.pory"
	faceplayer
# 89 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
# 90 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
# 91 "data//maps/LilycoveCity/scripts.pory"
	release
# 92 "data//maps/LilycoveCity/scripts.pory"
	end
# 93 "data//maps/LilycoveCity/scripts.pory"

# 94 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Woman2AquaGone::
# 95 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
# 96 "data//maps/LilycoveCity/scripts.pory"
	release
# 97 "data//maps/LilycoveCity/scripts.pory"
	end
# 98 "data//maps/LilycoveCity/scripts.pory"

# 99 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Man2::
# 100 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
# 101 "data//maps/LilycoveCity/scripts.pory"
	end
# 102 "data//maps/LilycoveCity/scripts.pory"

# 103 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertM1::
# 104 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
# 105 "data//maps/LilycoveCity/scripts.pory"
	end
# 106 "data//maps/LilycoveCity/scripts.pory"

# 107 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertF::
# 108 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
# 109 "data//maps/LilycoveCity/scripts.pory"
	end
# 110 "data//maps/LilycoveCity/scripts.pory"

# 111 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertM2::
# 112 "data//maps/LilycoveCity/scripts.pory"
	lock
# 113 "data//maps/LilycoveCity/scripts.pory"
	faceplayer
# 114 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
# 115 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
# 116 "data//maps/LilycoveCity/scripts.pory"
	release
# 117 "data//maps/LilycoveCity/scripts.pory"
	end
# 118 "data//maps/LilycoveCity/scripts.pory"

# 119 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertM2AquaGone::
# 120 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
# 121 "data//maps/LilycoveCity/scripts.pory"
	release
# 122 "data//maps/LilycoveCity/scripts.pory"
	end
# 123 "data//maps/LilycoveCity/scripts.pory"

# 124 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Sailor1::
# 125 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
# 126 "data//maps/LilycoveCity/scripts.pory"
	end
# 127 "data//maps/LilycoveCity/scripts.pory"

# 128 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_FatMan::
# 129 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
# 130 "data//maps/LilycoveCity/scripts.pory"
	end
# 131 "data//maps/LilycoveCity/scripts.pory"

# 132 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Man1::
# 133 "data//maps/LilycoveCity/scripts.pory"
	lockall
# 134 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
# 135 "data//maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_LILYCOVE_MAN_1, Common_Movement_FaceOriginalDirection
# 136 "data//maps/LilycoveCity/scripts.pory"
	end
# 137 "data//maps/LilycoveCity/scripts.pory"

# 138 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Woman1::
# 139 "data//maps/LilycoveCity/scripts.pory"
	lockall
# 140 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
# 141 "data//maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_LILYCOVE_WOMAN_1, Common_Movement_FaceOriginalDirection
# 142 "data//maps/LilycoveCity/scripts.pory"
	end
# 143 "data//maps/LilycoveCity/scripts.pory"

# 144 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_CitySign::
# 145 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
# 146 "data//maps/LilycoveCity/scripts.pory"
	end
# 147 "data//maps/LilycoveCity/scripts.pory"

# 148 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ContestHallSign::
# 149 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
# 150 "data//maps/LilycoveCity/scripts.pory"
	end
# 151 "data//maps/LilycoveCity/scripts.pory"

# 152 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MotelSign::
# 153 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
# 154 "data//maps/LilycoveCity/scripts.pory"
	end
# 155 "data//maps/LilycoveCity/scripts.pory"

# 156 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MuseumSign::
# 157 "data//maps/LilycoveCity/scripts.pory"
	lockall
# 158 "data//maps/LilycoveCity/scripts.pory"
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
# 159 "data//maps/LilycoveCity/scripts.pory"
	switch VAR_0x8004
# 160 "data//maps/LilycoveCity/scripts.pory"
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
# 161 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
# 162 "data//maps/LilycoveCity/scripts.pory"
	releaseall
# 163 "data//maps/LilycoveCity/scripts.pory"
	end
# 164 "data//maps/LilycoveCity/scripts.pory"

# 165 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MuseumSignNoPaintings::
# 166 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
# 167 "data//maps/LilycoveCity/scripts.pory"
	releaseall
# 168 "data//maps/LilycoveCity/scripts.pory"
	end
# 169 "data//maps/LilycoveCity/scripts.pory"

# 170 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_HarborSign::
# 171 "data//maps/LilycoveCity/scripts.pory"
	lockall
# 172 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
# 173 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
# 174 "data//maps/LilycoveCity/scripts.pory"
	releaseall
# 175 "data//maps/LilycoveCity/scripts.pory"
	end
# 176 "data//maps/LilycoveCity/scripts.pory"

# 177 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_HarborSignFerryReady::
# 178 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
# 179 "data//maps/LilycoveCity/scripts.pory"
	releaseall
# 180 "data//maps/LilycoveCity/scripts.pory"
	end
# 181 "data//maps/LilycoveCity/scripts.pory"

# 182 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_TrainerFanClubSign::
# 183 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
# 184 "data//maps/LilycoveCity/scripts.pory"
	end
# 185 "data//maps/LilycoveCity/scripts.pory"

# 186 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DepartmentStoreSign::
# 187 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
# 188 "data//maps/LilycoveCity/scripts.pory"
	end
# 189 "data//maps/LilycoveCity/scripts.pory"

# 190 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MoveDeletersHouseSign::
# 191 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
# 192 "data//maps/LilycoveCity/scripts.pory"
	end
# 193 "data//maps/LilycoveCity/scripts.pory"

# 194 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_WailmerTrainerGrunt::
# 195 "data//maps/LilycoveCity/scripts.pory"
	lockall
# 196 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
# 197 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
# 198 "data//maps/LilycoveCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 199 "data//maps/LilycoveCity/scripts.pory"
	waitmovement 0
# 200 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
# 201 "data//maps/LilycoveCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 202 "data//maps/LilycoveCity/scripts.pory"
	waitmovement 0
# 203 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_MET_WAILMER_TRAINER
# 204 "data//maps/LilycoveCity/scripts.pory"
	releaseall
# 205 "data//maps/LilycoveCity/scripts.pory"
	end
# 206 "data//maps/LilycoveCity/scripts.pory"

# 207 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MetWailmerTrainer::
# 208 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
# 209 "data//maps/LilycoveCity/scripts.pory"
	releaseall
# 210 "data//maps/LilycoveCity/scripts.pory"
	end
# 211 "data//maps/LilycoveCity/scripts.pory"

# 212 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt1::
# 213 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
# 214 "data//maps/LilycoveCity/scripts.pory"
	end
# 215 "data//maps/LilycoveCity/scripts.pory"

# 216 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt2::
# 217 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
# 218 "data//maps/LilycoveCity/scripts.pory"
	end
# 219 "data//maps/LilycoveCity/scripts.pory"

# 220 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt3::
# 221 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
# 222 "data//maps/LilycoveCity/scripts.pory"
	end
# 223 "data//maps/LilycoveCity/scripts.pory"

# 224 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt4::
# 225 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
# 226 "data//maps/LilycoveCity/scripts.pory"
	end
# 227 "data//maps/LilycoveCity/scripts.pory"

# 228 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Rival::
# 229 "data//maps/LilycoveCity/scripts.pory"
	lock
# 230 "data//maps/LilycoveCity/scripts.pory"
	faceplayer
# 231 "data//maps/LilycoveCity/scripts.pory"
	checkplayergender
# 232 "data//maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LilycoveCity_EventScript_May
# 233 "data//maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LilycoveCity_EventScript_Brendan
# 234 "data//maps/LilycoveCity/scripts.pory"
	end
# 235 "data//maps/LilycoveCity/scripts.pory"

# 236 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_May::
# 237 "data//maps/LilycoveCity/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 238 "data//maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
# 239 "data//maps/LilycoveCity/scripts.pory"
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
# 240 "data//maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineMayBattle
# 241 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
# 242 "data//maps/LilycoveCity/scripts.pory"
	switch VAR_STARTER_MON
# 243 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_BattleMay
# 244 "data//maps/LilycoveCity/scripts.pory"
	end
# 245 "data//maps/LilycoveCity/scripts.pory"

# 246 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayAskToBattleAgain::
# 247 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
# 248 "data//maps/LilycoveCity/scripts.pory"
	return
# 249 "data//maps/LilycoveCity/scripts.pory"

# 250 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayAskToBattle::
# 251 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
# 252 "data//maps/LilycoveCity/scripts.pory"
	return
# 253 "data//maps/LilycoveCity/scripts.pory"

# 254 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DeclineMayBattle::
# 255 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
# 256 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
# 257 "data//maps/LilycoveCity/scripts.pory"
	savebgm MUS_DUMMY
# 258 "data//maps/LilycoveCity/scripts.pory"
	fadedefaultbgm
# 259 "data//maps/LilycoveCity/scripts.pory"
	release
# 260 "data//maps/LilycoveCity/scripts.pory"
	end
# 261 "data//maps/LilycoveCity/scripts.pory"

# 262 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Brendan::
# 263 "data//maps/LilycoveCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 264 "data//maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
# 265 "data//maps/LilycoveCity/scripts.pory"
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
# 266 "data//maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineBrendanBattle
# 267 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
# 268 "data//maps/LilycoveCity/scripts.pory"
	switch VAR_STARTER_MON
# 269 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_BattleBrendan
# 270 "data//maps/LilycoveCity/scripts.pory"
	end
# 271 "data//maps/LilycoveCity/scripts.pory"

# 272 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanAskToBattleAgain::
# 273 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
# 274 "data//maps/LilycoveCity/scripts.pory"
	return
# 275 "data//maps/LilycoveCity/scripts.pory"

# 276 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanAskToBattle::
# 277 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
# 278 "data//maps/LilycoveCity/scripts.pory"
	return
# 279 "data//maps/LilycoveCity/scripts.pory"

# 280 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DeclineBrendanBattle::
# 281 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
# 282 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
# 283 "data//maps/LilycoveCity/scripts.pory"
	savebgm MUS_DUMMY
# 284 "data//maps/LilycoveCity/scripts.pory"
	fadedefaultbgm
# 285 "data//maps/LilycoveCity/scripts.pory"
	release
# 286 "data//maps/LilycoveCity/scripts.pory"
	end
# 287 "data//maps/LilycoveCity/scripts.pory"

# 288 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleMay::
# 289 "data//maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_A, LilycoveCity_Text_MayDefeat
# 290 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedMay
# 291 "data//maps/LilycoveCity/scripts.pory"
	end
# 292 "data//maps/LilycoveCity/scripts.pory"

# 293 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleBrendan::
# 294 "data//maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_A, LilycoveCity_Text_BrendanDefeat
# 295 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedBrendan
# 296 "data//maps/LilycoveCity/scripts.pory"
	end
# 297 "data//maps/LilycoveCity/scripts.pory"

# 298 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DefeatedMay::
# 299 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
# 300 "data//maps/LilycoveCity/scripts.pory"
	setvar VAR_RESULT, FALSE
# 301 "data//maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
# 302 "data//maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_MayCollectBadges
# 303 "data//maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_MayPokemonLeague
# 304 "data//maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
# 305 "data//maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
# 306 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_RivalFlyAway
# 307 "data//maps/LilycoveCity/scripts.pory"
	end
# 308 "data//maps/LilycoveCity/scripts.pory"

# 309 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_CheckFinalBadge::
# 310 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
# 311 "data//maps/LilycoveCity/scripts.pory"
	return
# 312 "data//maps/LilycoveCity/scripts.pory"

# 313 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_HasFinalBadge::
# 314 "data//maps/LilycoveCity/scripts.pory"
	setvar VAR_RESULT, TRUE
# 315 "data//maps/LilycoveCity/scripts.pory"
	return
# 316 "data//maps/LilycoveCity/scripts.pory"

# 317 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayCollectBadges::
# 318 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
# 319 "data//maps/LilycoveCity/scripts.pory"
	return
# 320 "data//maps/LilycoveCity/scripts.pory"

# 321 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayPokemonLeague::
# 322 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
# 323 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
# 324 "data//maps/LilycoveCity/scripts.pory"
	return
# 325 "data//maps/LilycoveCity/scripts.pory"

# 326 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayBattleFrontier::
# 327 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
# 328 "data//maps/LilycoveCity/scripts.pory"
	return
# 329 "data//maps/LilycoveCity/scripts.pory"

# 330 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DefeatedBrendan::
# 331 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
# 332 "data//maps/LilycoveCity/scripts.pory"
	setvar VAR_RESULT, FALSE
# 333 "data//maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
# 334 "data//maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BrendanCollectBadges
# 335 "data//maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_BrendanPokemonLeague
# 336 "data//maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
# 337 "data//maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
# 338 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_RivalFlyAway
# 339 "data//maps/LilycoveCity/scripts.pory"
	end
# 340 "data//maps/LilycoveCity/scripts.pory"

# 341 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanCollectBadges::
# 342 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
# 343 "data//maps/LilycoveCity/scripts.pory"
	return
# 344 "data//maps/LilycoveCity/scripts.pory"

# 345 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanPokemonLeague::
# 346 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
# 347 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
# 348 "data//maps/LilycoveCity/scripts.pory"
	return
# 349 "data//maps/LilycoveCity/scripts.pory"

# 350 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanBattleFrontier::
# 351 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
# 352 "data//maps/LilycoveCity/scripts.pory"
	return
# 353 "data//maps/LilycoveCity/scripts.pory"

# 354 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_RivalFlyAway::
# 355 "data//maps/LilycoveCity/scripts.pory"
	closemessage
# 356 "data//maps/LilycoveCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
# 357 "data//maps/LilycoveCity/scripts.pory"
	waitmovement 0
# 358 "data//maps/LilycoveCity/scripts.pory"
	delay 50
# 359 "data//maps/LilycoveCity/scripts.pory"
	setfieldeffectargument 0, 1
# 360 "data//maps/LilycoveCity/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 361 "data//maps/LilycoveCity/scripts.pory"
	delay 15
# 362 "data//maps/LilycoveCity/scripts.pory"
	removeobject VAR_LAST_TALKED
# 363 "data//maps/LilycoveCity/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 364 "data//maps/LilycoveCity/scripts.pory"
	savebgm MUS_DUMMY
# 365 "data//maps/LilycoveCity/scripts.pory"
	fadedefaultbgm
# 366 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_MET_RIVAL_LILYCOVE
# 367 "data//maps/LilycoveCity/scripts.pory"
	release
# 368 "data//maps/LilycoveCity/scripts.pory"
	end
# 369 "data//maps/LilycoveCity/scripts.pory"

# 370 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_SchoolKidM::
# 371 "data//maps/LilycoveCity/scripts.pory"
	lock
# 372 "data//maps/LilycoveCity/scripts.pory"
	faceplayer
# 373 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
# 374 "data//maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, YES, LilycoveCity_EventScript_KnowAboutBerryBlender
# 375 "data//maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DontKnowAboutBerryBlender
# 376 "data//maps/LilycoveCity/scripts.pory"
	release
# 377 "data//maps/LilycoveCity/scripts.pory"
	end
# 378 "data//maps/LilycoveCity/scripts.pory"

# 379 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_KnowAboutBerryBlender::
# 380 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
# 381 "data//maps/LilycoveCity/scripts.pory"
	return
# 382 "data//maps/LilycoveCity/scripts.pory"

# 383 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DontKnowAboutBerryBlender::
# 384 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
# 385 "data//maps/LilycoveCity/scripts.pory"
	return
# 386 "data//maps/LilycoveCity/scripts.pory"

# 387 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayShoppingLetsBattle:
# 388 "data//maps/LilycoveCity/scripts.pory"
	.string "MAY: Oh, hey?\n"
# 389 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, are you shopping, too?\p"
# 390 "data//maps/LilycoveCity/scripts.pory"
	.string "I bought a whole bunch of DOLLS and\n"
# 391 "data//maps/LilycoveCity/scripts.pory"
	.string "POSTERS.\p"
# 392 "data//maps/LilycoveCity/scripts.pory"
	.string "Of course, I've also caught a lot of\n"
# 393 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéMON, and I'm raising them\l"
# 394 "data//maps/LilycoveCity/scripts.pory"
	.string "properly, too.\p"
# 395 "data//maps/LilycoveCity/scripts.pory"
	.string "Actually, I'm more worried if you're\n"
# 396 "data//maps/LilycoveCity/scripts.pory"
	.string "raising POKéMON properly, {PLAYER}{KUN}.\p"
# 397 "data//maps/LilycoveCity/scripts.pory"
	.string "I'll battle with you, so you can show\n"
# 398 "data//maps/LilycoveCity/scripts.pory"
	.string "me your POKéMON, {PLAYER}{KUN}.$"
# 399 "data//maps/LilycoveCity/scripts.pory"

# 400 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayNotRaisingPokemon:
# 401 "data//maps/LilycoveCity/scripts.pory"
	.string "MAY: Oh, why? {PLAYER}{KUN}, haven't you\n"
# 402 "data//maps/LilycoveCity/scripts.pory"
	.string "been raising your POKéMON?\p"
# 403 "data//maps/LilycoveCity/scripts.pory"
	.string "That's not a very good showing as a\n"
# 404 "data//maps/LilycoveCity/scripts.pory"
	.string "TRAINER…$"
# 405 "data//maps/LilycoveCity/scripts.pory"

# 406 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayBattleMe:
# 407 "data//maps/LilycoveCity/scripts.pory"
	.string "MAY: Come on, battle with me, so I can\n"
# 408 "data//maps/LilycoveCity/scripts.pory"
	.string "check out your POKéMON!$"
# 409 "data//maps/LilycoveCity/scripts.pory"

# 410 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayWontBeBeaten:
# 411 "data//maps/LilycoveCity/scripts.pory"
	.string "MAY: The POKéMON I raised won't be\n"
# 412 "data//maps/LilycoveCity/scripts.pory"
	.string "beaten by your POKéMON, {PLAYER}{KUN}!$"
# 413 "data//maps/LilycoveCity/scripts.pory"

# 414 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayDefeat:
# 415 "data//maps/LilycoveCity/scripts.pory"
	.string "… … … … … … … …\p"
# 416 "data//maps/LilycoveCity/scripts.pory"
	.string "I remember the battle I had with you,\n"
# 417 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, on ROUTE 103.\p"
# 418 "data//maps/LilycoveCity/scripts.pory"
	.string "That battle helped you become this\n"
# 419 "data//maps/LilycoveCity/scripts.pory"
	.string "strong, {PLAYER}{KUN}, didn't it?$"
# 420 "data//maps/LilycoveCity/scripts.pory"

# 421 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayGoingBackToLittleroot:
# 422 "data//maps/LilycoveCity/scripts.pory"
	.string "MAY: I'm thinking of going back to\n"
# 423 "data//maps/LilycoveCity/scripts.pory"
	.string "LITTLEROOT soon.\p"
# 424 "data//maps/LilycoveCity/scripts.pory"
	.string "I've caught a decent group of POKéMON,\n"
# 425 "data//maps/LilycoveCity/scripts.pory"
	.string "and my POKéDEX is coming along, so\l"
# 426 "data//maps/LilycoveCity/scripts.pory"
	.string "I'm going home to show my dad.$"
# 427 "data//maps/LilycoveCity/scripts.pory"

# 428 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayYouGoingToCollectBadges:
# 429 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, what are you going to do?\p"
# 430 "data//maps/LilycoveCity/scripts.pory"
	.string "Collect all the GYM BADGES and take\n"
# 431 "data//maps/LilycoveCity/scripts.pory"
	.string "the POKéMON LEAGUE challenge?\p"
# 432 "data//maps/LilycoveCity/scripts.pory"
	.string "Well, while you're collecting BADGES,\n"
# 433 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, I'm going to work on my\l"
# 434 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéDEX. I'll complete it before you!\p"
# 435 "data//maps/LilycoveCity/scripts.pory"
	.string "See you!$"
# 436 "data//maps/LilycoveCity/scripts.pory"

# 437 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayYouGoingToPokemonLeague:
# 438 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, what are you going to do?\p"
# 439 "data//maps/LilycoveCity/scripts.pory"
	.string "Are you taking the POKéMON LEAGUE\n"
# 440 "data//maps/LilycoveCity/scripts.pory"
	.string "challenge?\p"
# 441 "data//maps/LilycoveCity/scripts.pory"
	.string "Or, are you going to complete your\n"
# 442 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéDEX?\p"
# 443 "data//maps/LilycoveCity/scripts.pory"
	.string "I might've lost to you in battling,\n"
# 444 "data//maps/LilycoveCity/scripts.pory"
	.string "but I'll finish my POKéDEX before you!\p"
# 445 "data//maps/LilycoveCity/scripts.pory"
	.string "See you!$"
# 446 "data//maps/LilycoveCity/scripts.pory"

# 447 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayYouGoingToBattleFrontier:
# 448 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, what are you going to do?\p"
# 449 "data//maps/LilycoveCity/scripts.pory"
	.string "Are you taking the BATTLE FRONTIER\n"
# 450 "data//maps/LilycoveCity/scripts.pory"
	.string "challenge?\p"
# 451 "data//maps/LilycoveCity/scripts.pory"
	.string "Or, are you going to complete your\n"
# 452 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéDEX?\p"
# 453 "data//maps/LilycoveCity/scripts.pory"
	.string "I might've lost to you in battling,\n"
# 454 "data//maps/LilycoveCity/scripts.pory"
	.string "but I'll finish my POKéDEX before you!\p"
# 455 "data//maps/LilycoveCity/scripts.pory"
	.string "See you!$"
# 456 "data//maps/LilycoveCity/scripts.pory"

# 457 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanShoppingLetsBattle:
# 458 "data//maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Oh, hey, it's {PLAYER}.\p"
# 459 "data//maps/LilycoveCity/scripts.pory"
	.string "I'm running an errand for my dad.\n"
# 460 "data//maps/LilycoveCity/scripts.pory"
	.string "No, I'm not buying any DOLLS.\p"
# 461 "data//maps/LilycoveCity/scripts.pory"
	.string "Anyways, it's been a while.\p"
# 462 "data//maps/LilycoveCity/scripts.pory"
	.string "Want to have a battle to see who's been\n"
# 463 "data//maps/LilycoveCity/scripts.pory"
	.string "raising POKéMON better?$"
# 464 "data//maps/LilycoveCity/scripts.pory"

# 465 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanNoConfidence:
# 466 "data//maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Oh, what's the matter?\n"
# 467 "data//maps/LilycoveCity/scripts.pory"
	.string "Don't have the confidence?$"
# 468 "data//maps/LilycoveCity/scripts.pory"

# 469 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanBattleMe:
# 470 "data//maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Want to battle to see who's\n"
# 471 "data//maps/LilycoveCity/scripts.pory"
	.string "been raising POKéMON better?$"
# 472 "data//maps/LilycoveCity/scripts.pory"

# 473 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanWontBeBeaten:
# 474 "data//maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Aww, but you know I'm not\n"
# 475 "data//maps/LilycoveCity/scripts.pory"
	.string "going to lose to no {PLAYER}.$"
# 476 "data//maps/LilycoveCity/scripts.pory"

# 477 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanDefeat:
# 478 "data//maps/LilycoveCity/scripts.pory"
	.string "Humph…\n"
# 479 "data//maps/LilycoveCity/scripts.pory"
	.string "You've done a lot of raising.\p"
# 480 "data//maps/LilycoveCity/scripts.pory"
	.string "That stings a bit--I had a head start\n"
# 481 "data//maps/LilycoveCity/scripts.pory"
	.string "on you as a TRAINER…$"
# 482 "data//maps/LilycoveCity/scripts.pory"

# 483 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanGoingBackToLittleroot:
# 484 "data//maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: I…\n"
# 485 "data//maps/LilycoveCity/scripts.pory"
	.string "I plan on going home to LITTLEROOT.\p"
# 486 "data//maps/LilycoveCity/scripts.pory"
	.string "You know I'm helping out my dad on his\n"
# 487 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéDEX. It's coming together pretty\l"
# 488 "data//maps/LilycoveCity/scripts.pory"
	.string "decently, so I should go show him.$"
# 489 "data//maps/LilycoveCity/scripts.pory"

# 490 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanYouGoingToCollectBadges:
# 491 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}, what are you going to do?\p"
# 492 "data//maps/LilycoveCity/scripts.pory"
	.string "Collect all the GYM BADGES and take\n"
# 493 "data//maps/LilycoveCity/scripts.pory"
	.string "the POKéMON LEAGUE challenge?\p"
# 494 "data//maps/LilycoveCity/scripts.pory"
	.string "Maybe I'll do that, too…\p"
# 495 "data//maps/LilycoveCity/scripts.pory"
	.string "Well, anyway, hang in there!$"
# 496 "data//maps/LilycoveCity/scripts.pory"

# 497 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanYouGoingToPokemonLeague:
# 498 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}, what are you going to do?\p"
# 499 "data//maps/LilycoveCity/scripts.pory"
	.string "Since you're that strong, are you\n"
# 500 "data//maps/LilycoveCity/scripts.pory"
	.string "taking the POKéMON LEAGUE challenge?\p"
# 501 "data//maps/LilycoveCity/scripts.pory"
	.string "Heh, even me--if I trained my POKéMON\n"
# 502 "data//maps/LilycoveCity/scripts.pory"
	.string "a bit more, I should be stronger than\l"
# 503 "data//maps/LilycoveCity/scripts.pory"
	.string "you, {PLAYER}.\p"
# 504 "data//maps/LilycoveCity/scripts.pory"
	.string "Well, anyway, hang in there!$"
# 505 "data//maps/LilycoveCity/scripts.pory"

# 506 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanYouGoingToBattleFrontier:
# 507 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}, what are you going to do?\p"
# 508 "data//maps/LilycoveCity/scripts.pory"
	.string "Are you taking the BATTLE FRONTIER\n"
# 509 "data//maps/LilycoveCity/scripts.pory"
	.string "challenge?\p"
# 510 "data//maps/LilycoveCity/scripts.pory"
	.string "Or, are you going to complete your\n"
# 511 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéDEX?\p"
# 512 "data//maps/LilycoveCity/scripts.pory"
	.string "Since you're that strong, you should\n"
# 513 "data//maps/LilycoveCity/scripts.pory"
	.string "consider the BATTLE FRONTIER.\p"
# 514 "data//maps/LilycoveCity/scripts.pory"
	.string "Heh, if I train my POKéMON a bit more,\n"
# 515 "data//maps/LilycoveCity/scripts.pory"
	.string "I'll get stronger than you, {PLAYER}.\p"
# 516 "data//maps/LilycoveCity/scripts.pory"
	.string "Maybe I should go to the BATTLE\n"
# 517 "data//maps/LilycoveCity/scripts.pory"
	.string "FRONTIER.\p"
# 518 "data//maps/LilycoveCity/scripts.pory"
	.string "Well, anyway, hang in there!$"
# 519 "data//maps/LilycoveCity/scripts.pory"

# 520 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MovedLootIntoHideoutToday:
# 521 "data//maps/LilycoveCity/scripts.pory"
	.string "Fufufu…\p"
# 522 "data//maps/LilycoveCity/scripts.pory"
	.string "We moved more loot into our secret\n"
# 523 "data//maps/LilycoveCity/scripts.pory"
	.string "HIDEOUT today…\p"
# 524 "data//maps/LilycoveCity/scripts.pory"
	.string "Wh-who are you?!\n"
# 525 "data//maps/LilycoveCity/scripts.pory"
	.string "I was just talking to myself!$"
# 526 "data//maps/LilycoveCity/scripts.pory"

# 527 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ChanceToDoBigThings:
# 528 "data//maps/LilycoveCity/scripts.pory"
	.string "I'm just a GRUNT, so I don't know what\n"
# 529 "data//maps/LilycoveCity/scripts.pory"
	.string "the BOSS is thinking…\p"
# 530 "data//maps/LilycoveCity/scripts.pory"
	.string "But being on TEAM AQUA, I know I'll get\n"
# 531 "data//maps/LilycoveCity/scripts.pory"
	.string "the chance to do big things!\p"
# 532 "data//maps/LilycoveCity/scripts.pory"
	.string "Wh-who are you?!\n"
# 533 "data//maps/LilycoveCity/scripts.pory"
	.string "I was just talking to myself!$"
# 534 "data//maps/LilycoveCity/scripts.pory"

# 535 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_DontGoNearCaveInCove:
# 536 "data//maps/LilycoveCity/scripts.pory"
	.string "Hey, you!\p"
# 537 "data//maps/LilycoveCity/scripts.pory"
	.string "Don't go near the cave in the cove!\p"
# 538 "data//maps/LilycoveCity/scripts.pory"
	.string "Why? You don't need a reason why!\n"
# 539 "data//maps/LilycoveCity/scripts.pory"
	.string "I'm an adult, so you just listen to me!$"
# 540 "data//maps/LilycoveCity/scripts.pory"

# 541 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_IfWorldBecomesOurs:
# 542 "data//maps/LilycoveCity/scripts.pory"
	.string "If this whole wide world becomes ours,\n"
# 543 "data//maps/LilycoveCity/scripts.pory"
	.string "TEAM AQUA's, it will be a happier\l"
# 544 "data//maps/LilycoveCity/scripts.pory"
	.string "place for POKéMON, too.$"
# 545 "data//maps/LilycoveCity/scripts.pory"

# 546 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_WailmerLeapOutOfWater:
# 547 "data//maps/LilycoveCity/scripts.pory"
	.string "There! WAILMER!\n"
# 548 "data//maps/LilycoveCity/scripts.pory"
	.string "Leap out of the water now!$"
# 549 "data//maps/LilycoveCity/scripts.pory"

# 550 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_GetLostMessingUpTraining:
# 551 "data//maps/LilycoveCity/scripts.pory"
	.string "Hunh? What do you want?\p"
# 552 "data//maps/LilycoveCity/scripts.pory"
	.string "You're messing up our training,\n"
# 553 "data//maps/LilycoveCity/scripts.pory"
	.string "so can you, like, get lost?$"
# 554 "data//maps/LilycoveCity/scripts.pory"

# 555 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ContestHallInTown:
# 556 "data//maps/LilycoveCity/scripts.pory"
	.string "There's a POKéMON CONTEST HALL\n"
# 557 "data//maps/LilycoveCity/scripts.pory"
	.string "right in this here town. \p"
# 558 "data//maps/LilycoveCity/scripts.pory"
	.string "That means well-raised POKéMON will\n"
# 559 "data//maps/LilycoveCity/scripts.pory"
	.string "come from all over the country.\p"
# 560 "data//maps/LilycoveCity/scripts.pory"
	.string "My heart swells with excitement!$"
# 561 "data//maps/LilycoveCity/scripts.pory"

# 562 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_StrangeCaveInCove:
# 563 "data//maps/LilycoveCity/scripts.pory"
	.string "Have you seen that strange cave in\n"
# 564 "data//maps/LilycoveCity/scripts.pory"
	.string "the cove at the edge of town?$"
# 565 "data//maps/LilycoveCity/scripts.pory"

# 566 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_GoingToMoveDeleterForHMs:
# 567 "data//maps/LilycoveCity/scripts.pory"
	.string "I'm going to teach my POKéMON some new\n"
# 568 "data//maps/LilycoveCity/scripts.pory"
	.string "moves for entering a CONTEST.\p"
# 569 "data//maps/LilycoveCity/scripts.pory"
	.string "So, I'm going to see the MOVE DELETER\n"
# 570 "data//maps/LilycoveCity/scripts.pory"
	.string "and make it forget HM moves.$"
# 571 "data//maps/LilycoveCity/scripts.pory"

# 572 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ImFromKanto:
# 573 "data//maps/LilycoveCity/scripts.pory"
	.string "I came from KANTO.\p"
# 574 "data//maps/LilycoveCity/scripts.pory"
	.string "The HOENN region is beautiful with\n"
# 575 "data//maps/LilycoveCity/scripts.pory"
	.string "all its water and verdant nature.\p"
# 576 "data//maps/LilycoveCity/scripts.pory"
	.string "Hunh? Wait a second…\p"
# 577 "data//maps/LilycoveCity/scripts.pory"
	.string "Could there be rare POKéMON that live\n"
# 578 "data//maps/LilycoveCity/scripts.pory"
	.string "only in this area?$"
# 579 "data//maps/LilycoveCity/scripts.pory"

# 580 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TeamAquaBeenTrainingWailmer:
# 581 "data//maps/LilycoveCity/scripts.pory"
	.string "TEAM AQUA's been training their\n"
# 582 "data//maps/LilycoveCity/scripts.pory"
	.string "WAILMER in the cove.\p"
# 583 "data//maps/LilycoveCity/scripts.pory"
	.string "We SAILORS can't get our boats out\n"
# 584 "data//maps/LilycoveCity/scripts.pory"
	.string "to sea with them in the way!$"
# 585 "data//maps/LilycoveCity/scripts.pory"

# 586 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SomeonePuntedTeamAquaOut:
# 587 "data//maps/LilycoveCity/scripts.pory"
	.string "Ahoy, did you know?\p"
# 588 "data//maps/LilycoveCity/scripts.pory"
	.string "Someone punted TEAM AQUA out of\n"
# 589 "data//maps/LilycoveCity/scripts.pory"
	.string "the way for us!\p"
# 590 "data//maps/LilycoveCity/scripts.pory"
	.string "That got the WAILMER out of the cove,\n"
# 591 "data//maps/LilycoveCity/scripts.pory"
	.string "so we can get our boats out again.$"
# 592 "data//maps/LilycoveCity/scripts.pory"

# 593 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SomeoneStoleMyPokemon:
# 594 "data//maps/LilycoveCity/scripts.pory"
	.string "I was taking a relaxing snooze at the\n"
# 595 "data//maps/LilycoveCity/scripts.pory"
	.string "seaside inn to the sound of waves…\p"
# 596 "data//maps/LilycoveCity/scripts.pory"
	.string "When someone stole my POKéMON!\p"
# 597 "data//maps/LilycoveCity/scripts.pory"
	.string "Who's the abductor?\n"
# 598 "data//maps/LilycoveCity/scripts.pory"
	.string "TEAM AQUA? Is it TEAM AQUA?$"
# 599 "data//maps/LilycoveCity/scripts.pory"

# 600 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MissingPokemonCameBack:
# 601 "data//maps/LilycoveCity/scripts.pory"
	.string "My missing POKéMON…\n"
# 602 "data//maps/LilycoveCity/scripts.pory"
	.string "It came back without me noticing!$"
# 603 "data//maps/LilycoveCity/scripts.pory"

# 604 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ImArtDealer:
# 605 "data//maps/LilycoveCity/scripts.pory"
	.string "I'm an ART DEALER.\p"
# 606 "data//maps/LilycoveCity/scripts.pory"
	.string "I am a buyer and seller of fine art,\n"
# 607 "data//maps/LilycoveCity/scripts.pory"
	.string "especially paintings.\p"
# 608 "data//maps/LilycoveCity/scripts.pory"
	.string "I've heard that the MUSEUM here has\n"
# 609 "data//maps/LilycoveCity/scripts.pory"
	.string "magnificent works on exhibit…$"
# 610 "data//maps/LilycoveCity/scripts.pory"

# 611 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SeaRemainsForeverYoung:
# 612 "data//maps/LilycoveCity/scripts.pory"
	.string "Even as we grow old and wrinkled,\n"
# 613 "data//maps/LilycoveCity/scripts.pory"
	.string "the sea remains forever young with\l"
# 614 "data//maps/LilycoveCity/scripts.pory"
	.string "the vivid brilliance of life…\p"
# 615 "data//maps/LilycoveCity/scripts.pory"
	.string "Fwohoho fwohohohoho…$"
# 616 "data//maps/LilycoveCity/scripts.pory"

# 617 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SixtyYearsAgoHusbandProposed:
# 618 "data//maps/LilycoveCity/scripts.pory"
	.string "It was sixty years ago that my husband\n"
# 619 "data//maps/LilycoveCity/scripts.pory"
	.string "proposed to me here.\l"
# 620 "data//maps/LilycoveCity/scripts.pory"
	.string "The sea remains as beautiful as ever.\p"
# 621 "data//maps/LilycoveCity/scripts.pory"
	.string "Mufufufu mufufufufufu…$"
# 622 "data//maps/LilycoveCity/scripts.pory"

# 623 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TeamAquaRenovatedCavern:
# 624 "data//maps/LilycoveCity/scripts.pory"
	.string "Hm, you know of the peculiar cavern\n"
# 625 "data//maps/LilycoveCity/scripts.pory"
	.string "in this cove?\p"
# 626 "data//maps/LilycoveCity/scripts.pory"
	.string "That had been a natural formation,\n"
# 627 "data//maps/LilycoveCity/scripts.pory"
	.string "but then that TEAM AQUA lot came\l"
# 628 "data//maps/LilycoveCity/scripts.pory"
	.string "along and made their renovations.\p"
# 629 "data//maps/LilycoveCity/scripts.pory"
	.string "They call themselves\n"
# 630 "data//maps/LilycoveCity/scripts.pory"
	.string "the “nature-loving TEAM AQUA”!\p"
# 631 "data//maps/LilycoveCity/scripts.pory"
	.string "But what they do and what they say\n"
# 632 "data//maps/LilycoveCity/scripts.pory"
	.string "don't match at all!$"
# 633 "data//maps/LilycoveCity/scripts.pory"

# 634 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TeamAquaLotGoneForGood:
# 635 "data//maps/LilycoveCity/scripts.pory"
	.string "That cave in the cove…\p"
# 636 "data//maps/LilycoveCity/scripts.pory"
	.string "I didn't notice it right away,\n"
# 637 "data//maps/LilycoveCity/scripts.pory"
	.string "but it's completely empty now.\p"
# 638 "data//maps/LilycoveCity/scripts.pory"
	.string "That TEAM AQUA lot, they must\n"
# 639 "data//maps/LilycoveCity/scripts.pory"
	.string "have gone away for good.$"
# 640 "data//maps/LilycoveCity/scripts.pory"

# 641 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_CitySign:
# 642 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE CITY\p"
# 643 "data//maps/LilycoveCity/scripts.pory"
	.string "“Where the land ends and the\n"
# 644 "data//maps/LilycoveCity/scripts.pory"
	.string "sea begins.”$"
# 645 "data//maps/LilycoveCity/scripts.pory"

# 646 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ContestHallSign:
# 647 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéMON CONTEST HALL\n"
# 648 "data//maps/LilycoveCity/scripts.pory"
	.string "“The gathering place for TRAINERS!”$"
# 649 "data//maps/LilycoveCity/scripts.pory"

# 650 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MotelSign:
# 651 "data//maps/LilycoveCity/scripts.pory"
	.string "COVE LILY MOTEL\p"
# 652 "data//maps/LilycoveCity/scripts.pory"
	.string "“Remember us as COVE LILY of\n"
# 653 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE.”$"
# 654 "data//maps/LilycoveCity/scripts.pory"

# 655 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MuseumSign:
# 656 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE MUSEUM\p"
# 657 "data//maps/LilycoveCity/scripts.pory"
	.string "“POKéMON Masterpiece Collection\n"
# 658 "data//maps/LilycoveCity/scripts.pory"
	.string "on exhibit!”$"
# 659 "data//maps/LilycoveCity/scripts.pory"

# 660 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MuseumSignPlayersExhibit:
# 661 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE MUSEUM\p"
# 662 "data//maps/LilycoveCity/scripts.pory"
	.string "“{PLAYER}'s POKéMON Collection\n"
# 663 "data//maps/LilycoveCity/scripts.pory"
	.string "on exhibit!”$"
# 664 "data//maps/LilycoveCity/scripts.pory"

# 665 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HarborSignUnderConstruction:
# 666 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE CITY HARBOR\p"
# 667 "data//maps/LilycoveCity/scripts.pory"
	.string "“The ferry S.S. TIDAL is under\n"
# 668 "data//maps/LilycoveCity/scripts.pory"
	.string "construction in SLATEPORT CITY.\p"
# 669 "data//maps/LilycoveCity/scripts.pory"
	.string "“Service is scheduled to begin\n"
# 670 "data//maps/LilycoveCity/scripts.pory"
	.string "shortly.”$"
# 671 "data//maps/LilycoveCity/scripts.pory"

# 672 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HarborSign:
# 673 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE CITY HARBOR\p"
# 674 "data//maps/LilycoveCity/scripts.pory"
	.string "“Enjoy a delightful cruise on\n"
# 675 "data//maps/LilycoveCity/scripts.pory"
	.string "the ferry S.S. TIDAL.”$"
# 676 "data//maps/LilycoveCity/scripts.pory"

# 677 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TrainerFanClubSign:
# 678 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéMON TRAINER FAN CLUB\p"
# 679 "data//maps/LilycoveCity/scripts.pory"
	.string "The names of TRAINERS are scribbled\n"
# 680 "data//maps/LilycoveCity/scripts.pory"
	.string "all over the sign…$"
# 681 "data//maps/LilycoveCity/scripts.pory"

# 682 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_DepartmentStoreSign:
# 683 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE DEPARTMENT STORE\p"
# 684 "data//maps/LilycoveCity/scripts.pory"
	.string "“Overflowing with great merchandise\n"
# 685 "data//maps/LilycoveCity/scripts.pory"
	.string "and excitement!\p"
# 686 "data//maps/LilycoveCity/scripts.pory"
	.string "“A great place to find that something\n"
# 687 "data//maps/LilycoveCity/scripts.pory"
	.string "you need!”$"
# 688 "data//maps/LilycoveCity/scripts.pory"

# 689 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MoveDeletersHouseSign:
# 690 "data//maps/LilycoveCity/scripts.pory"
	.string "MOVE DELETER'S HOUSE\p"
# 691 "data//maps/LilycoveCity/scripts.pory"
	.string "“Unwanted POKéMON moves deleted.”$"
# 692 "data//maps/LilycoveCity/scripts.pory"

# 693 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_DoYouKnowAboutBerryBlender:
# 694 "data//maps/LilycoveCity/scripts.pory"
	.string "Do you know about the machine\n"
# 695 "data//maps/LilycoveCity/scripts.pory"
	.string "BERRY BLENDER?$"
# 696 "data//maps/LilycoveCity/scripts.pory"

# 697 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_FasterSpinBetterPokeblocks:
# 698 "data//maps/LilycoveCity/scripts.pory"
	.string "People have to work together to get it\n"
# 699 "data//maps/LilycoveCity/scripts.pory"
	.string "to spin faster.\p"
# 700 "data//maps/LilycoveCity/scripts.pory"
	.string "The faster you can make it spin, the\n"
# 701 "data//maps/LilycoveCity/scripts.pory"
	.string "better {POKEBLOCK}S you can get, I've heard.$"
# 702 "data//maps/LilycoveCity/scripts.pory"

# 703 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ExplainBerryBlender:
# 704 "data//maps/LilycoveCity/scripts.pory"
	.string "It's used for making a kind of candy\n"
# 705 "data//maps/LilycoveCity/scripts.pory"
	.string "called a {POKEBLOCK}.\p"
# 706 "data//maps/LilycoveCity/scripts.pory"
	.string "If you give a good {POKEBLOCK} to a POKéMON,\n"
# 707 "data//maps/LilycoveCity/scripts.pory"
	.string "its condition will improve by a lot.$"
# 708 "data//maps/LilycoveCity/scripts.pory"

# 709 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HeardTowerCalledSkyPillar:
# 710 "data//maps/LilycoveCity/scripts.pory"
	.string "I heard there's a tower somewhere out\n"
# 711 "data//maps/LilycoveCity/scripts.pory"
	.string "on the sea routes.\p"
# 712 "data//maps/LilycoveCity/scripts.pory"
	.string "It's called the SKY PILLAR, I hear.$"
# 713 "data//maps/LilycoveCity/scripts.pory"

# 714 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SawTallTowerOnRoute131:
# 715 "data//maps/LilycoveCity/scripts.pory"
	.string "I saw this tall tower somewhere\n"
# 716 "data//maps/LilycoveCity/scripts.pory"
	.string "around ROUTE 131.\p"
# 717 "data//maps/LilycoveCity/scripts.pory"
	.string "Could that possibly be…?$"
# 718 "data//maps/LilycoveCity/scripts.pory"

# 719 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_JustArrivedAndSawRarePokemon:
# 720 "data//maps/LilycoveCity/scripts.pory"
	.string "We just arrived here on our\n"
# 721 "data//maps/LilycoveCity/scripts.pory"
	.string "honeymoon vacation.\p"
# 722 "data//maps/LilycoveCity/scripts.pory"
	.string "We happened to see a DRAGON-type\n"
# 723 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéMON flying way up in the sky.\p"
# 724 "data//maps/LilycoveCity/scripts.pory"
	.string "Do cool POKéMON like that live in\n"
# 725 "data//maps/LilycoveCity/scripts.pory"
	.string "the HOENN region?$"
# 726 "data//maps/LilycoveCity/scripts.pory"

# 727 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HoneymoonVowToSeeRarePokemon:
# 728 "data//maps/LilycoveCity/scripts.pory"
	.string "On our honeymoon, we vowed to see as\n"
# 729 "data//maps/LilycoveCity/scripts.pory"
	.string "many rare POKéMON as we can.\p"
# 730 "data//maps/LilycoveCity/scripts.pory"
	.string "So we were delighted to see a rare\n"
# 731 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéMON as soon as we arrived.\p"
# 732 "data//maps/LilycoveCity/scripts.pory"
	.string "I mean, we are totally happy!$"
