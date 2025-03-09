# 1 "data//maps/Route110/scripts.pory"

# 2 "data//maps/Route110/scripts.pory"
.set LOCALID_CHALLENGE_BIKER, 21
# 3 "data//maps/Route110/scripts.pory"
.set LOCALID_RIVAL, 28
# 4 "data//maps/Route110/scripts.pory"
.set LOCALID_RIVAL_ON_BIKE, 29
# 5 "data//maps/Route110/scripts.pory"
.set LOCALID_BIRCH, 36
# 6 "data//maps/Route110/scripts.pory"

# 7 "data//maps/Route110/scripts.pory"
Route110_MapScripts::
# 8 "data//maps/Route110/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Route110_OnResume
# 9 "data//maps/Route110/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_OnTransition
# 10 "data//maps/Route110/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_OnFrame
# 11 "data//maps/Route110/scripts.pory"
	.byte 0
# 12 "data//maps/Route110/scripts.pory"

# 13 "data//maps/Route110/scripts.pory"
Route110_OnResume:
# 14 "data//maps/Route110/scripts.pory"
	special UpdateCyclingRoadState
# 15 "data//maps/Route110/scripts.pory"
	end
# 16 "data//maps/Route110/scripts.pory"

# 17 "data//maps/Route110/scripts.pory"
Route110_OnTransition:
# 18 "data//maps/Route110/scripts.pory"
	clearflag FLAG_SYS_SAVE_GET
# 19 "data//maps/Route110/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 20 "data//maps/Route110/scripts.pory"
	call Common_EventScript_SetupRivalOnBikeGfxId
# 21 "data//maps/Route110/scripts.pory"
	call_if_eq VAR_CYCLING_CHALLENGE_STATE, 1, Route110_EventScript_SaveCyclingMusic
# 22 "data//maps/Route110/scripts.pory"
	end
# 23 "data//maps/Route110/scripts.pory"

# 24 "data//maps/Route110/scripts.pory"
Route110_EventScript_SaveCyclingMusic::
# 25 "data//maps/Route110/scripts.pory"
	savebgm MUS_CYCLING
# 26 "data//maps/Route110/scripts.pory"
	return
# 27 "data//maps/Route110/scripts.pory"

# 28 "data//maps/Route110/scripts.pory"
Route110_OnFrame:
# 29 "data//maps/Route110/scripts.pory"
	map_script_2 VAR_CYCLING_CHALLENGE_STATE, 1, Route110_EventScript_BeginCylcingRoadChallenge
# 30 "data//maps/Route110/scripts.pory"
	.2byte 0
# 31 "data//maps/Route110/scripts.pory"

# 32 "data//maps/Route110/scripts.pory"
Route110_EventScript_BeginCylcingRoadChallenge::
# 33 "data//maps/Route110/scripts.pory"
	special Special_BeginCyclingRoadChallenge
# 34 "data//maps/Route110/scripts.pory"
	setvar VAR_CYCLING_CHALLENGE_STATE, 2
# 35 "data//maps/Route110/scripts.pory"
	return
# 36 "data//maps/Route110/scripts.pory"

# 37 "data//maps/Route110/scripts.pory"
Route110_EventScript_AquaGrunt1::
# 38 "data//maps/Route110/scripts.pory"
	lock
# 39 "data//maps/Route110/scripts.pory"
	faceplayer
# 40 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_WeCantTalkAboutAquaActivities, MSGBOX_DEFAULT
# 41 "data//maps/Route110/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 42 "data//maps/Route110/scripts.pory"
	waitmovement 0
# 43 "data//maps/Route110/scripts.pory"
	release
# 44 "data//maps/Route110/scripts.pory"
	end
# 45 "data//maps/Route110/scripts.pory"

# 46 "data//maps/Route110/scripts.pory"
Route110_EventScript_AquaGrunt2::
# 47 "data//maps/Route110/scripts.pory"
	lock
# 48 "data//maps/Route110/scripts.pory"
	faceplayer
# 49 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_KickUpARuckus, MSGBOX_DEFAULT
# 50 "data//maps/Route110/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 51 "data//maps/Route110/scripts.pory"
	waitmovement 0
# 52 "data//maps/Route110/scripts.pory"
	release
# 53 "data//maps/Route110/scripts.pory"
	end
# 54 "data//maps/Route110/scripts.pory"

# 55 "data//maps/Route110/scripts.pory"
Route110_EventScript_AquaGrunt3::
# 56 "data//maps/Route110/scripts.pory"
	lock
# 57 "data//maps/Route110/scripts.pory"
	faceplayer
# 58 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_MyFirstJobInAqua, MSGBOX_DEFAULT
# 59 "data//maps/Route110/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 60 "data//maps/Route110/scripts.pory"
	waitmovement 0
# 61 "data//maps/Route110/scripts.pory"
	release
# 62 "data//maps/Route110/scripts.pory"
	end
# 63 "data//maps/Route110/scripts.pory"

# 64 "data//maps/Route110/scripts.pory"
Route110_EventScript_AquaGrunt4::
# 65 "data//maps/Route110/scripts.pory"
	lock
# 66 "data//maps/Route110/scripts.pory"
	faceplayer
# 67 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_AquaActionsBringSmiles, MSGBOX_DEFAULT
# 68 "data//maps/Route110/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 69 "data//maps/Route110/scripts.pory"
	waitmovement 0
# 70 "data//maps/Route110/scripts.pory"
	release
# 71 "data//maps/Route110/scripts.pory"
	end
# 72 "data//maps/Route110/scripts.pory"

# 73 "data//maps/Route110/scripts.pory"
Route110_EventScript_Boy1::
# 74 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_RideBikeAtFullSpeed, MSGBOX_NPC
# 75 "data//maps/Route110/scripts.pory"
	end
# 76 "data//maps/Route110/scripts.pory"

# 77 "data//maps/Route110/scripts.pory"
Route110_EventScript_CyclingGirl1::
# 78 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_HairStreamsBehindMe, MSGBOX_NPC
# 79 "data//maps/Route110/scripts.pory"
	end
# 80 "data//maps/Route110/scripts.pory"

# 81 "data//maps/Route110/scripts.pory"
Route110_EventScript_CyclingGuy1::
# 82 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_YouGotBikeFromRydel, MSGBOX_NPC
# 83 "data//maps/Route110/scripts.pory"
	end
# 84 "data//maps/Route110/scripts.pory"

# 85 "data//maps/Route110/scripts.pory"
Route110_EventScript_OldMan::
# 86 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_TwoRoads, MSGBOX_NPC
# 87 "data//maps/Route110/scripts.pory"
	end
# 88 "data//maps/Route110/scripts.pory"

# 89 "data//maps/Route110/scripts.pory"
Route110_EventScript_OldWoman::
# 90 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_WalkOnTheLowRoad, MSGBOX_NPC
# 91 "data//maps/Route110/scripts.pory"
	end
# 92 "data//maps/Route110/scripts.pory"

# 93 "data//maps/Route110/scripts.pory"
Route110_EventScript_CyclingGuy2::
# 94 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_BikeTechniques, MSGBOX_NPC
# 95 "data//maps/Route110/scripts.pory"
	end
# 96 "data//maps/Route110/scripts.pory"

# 97 "data//maps/Route110/scripts.pory"
Route110_EventScript_Boy2::
# 98 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_WhichShouldIChoose, MSGBOX_NPC
# 99 "data//maps/Route110/scripts.pory"
	end
# 100 "data//maps/Route110/scripts.pory"

# 101 "data//maps/Route110/scripts.pory"
Route110_EventScript_SlateportCitySign::
# 102 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_SlateportCitySign, MSGBOX_SIGN
# 103 "data//maps/Route110/scripts.pory"
	end
# 104 "data//maps/Route110/scripts.pory"

# 105 "data//maps/Route110/scripts.pory"
Route110_EventScript_CyclingRoadSign::
# 106 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_CyclingRoadSign, MSGBOX_SIGN
# 107 "data//maps/Route110/scripts.pory"
	end
# 108 "data//maps/Route110/scripts.pory"

# 109 "data//maps/Route110/scripts.pory"
Route110_EventScript_VandalizedSign::
# 110 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_AquaWasHere, MSGBOX_SIGN
# 111 "data//maps/Route110/scripts.pory"
	end
# 112 "data//maps/Route110/scripts.pory"

# 113 "data//maps/Route110/scripts.pory"
Route110_EventScript_Route103Sign::
# 114 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_Route103Sign, MSGBOX_SIGN
# 115 "data//maps/Route110/scripts.pory"
	end
# 116 "data//maps/Route110/scripts.pory"

# 117 "data//maps/Route110/scripts.pory"
Route110_EventScript_SeasideParkingSign::
# 118 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_SeasideParkingSign, MSGBOX_SIGN
# 119 "data//maps/Route110/scripts.pory"
	end
# 120 "data//maps/Route110/scripts.pory"

# 121 "data//maps/Route110/scripts.pory"
Route110_EventScript_MauvilleCitySign::
# 122 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_MauvilleCitySign, MSGBOX_SIGN
# 123 "data//maps/Route110/scripts.pory"
	end
# 124 "data//maps/Route110/scripts.pory"

# 125 "data//maps/Route110/scripts.pory"
Route110_EventScript_TrainerTipsPrlzSleep::
# 126 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_TrainerTipsPrlzSleep, MSGBOX_SIGN
# 127 "data//maps/Route110/scripts.pory"
	end
# 128 "data//maps/Route110/scripts.pory"

# 129 "data//maps/Route110/scripts.pory"
Route110_EventScript_TrainerTipsRegisterItems::
# 130 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_TrainerTipsRegisterItems, MSGBOX_SIGN
# 131 "data//maps/Route110/scripts.pory"
	end
# 132 "data//maps/Route110/scripts.pory"

# 133 "data//maps/Route110/scripts.pory"
Route110_EventScript_TrickHouseSign::
# 134 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_TrickHouseSign, MSGBOX_SIGN
# 135 "data//maps/Route110/scripts.pory"
	end
# 136 "data//maps/Route110/scripts.pory"

# 137 "data//maps/Route110/scripts.pory"
Route110_EventScript_CyclingRoadResultsSign::
# 138 "data//maps/Route110/scripts.pory"
	lockall
# 139 "data//maps/Route110/scripts.pory"
	specialvar VAR_RESULT, GetRecordedCyclingRoadResults
# 140 "data//maps/Route110/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route110_EventScript_NoRecordSet
# 141 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_BestRecord, MSGBOX_DEFAULT
# 142 "data//maps/Route110/scripts.pory"
	releaseall
# 143 "data//maps/Route110/scripts.pory"
	end
# 144 "data//maps/Route110/scripts.pory"

# 145 "data//maps/Route110/scripts.pory"
Route110_EventScript_NoRecordSet::
# 146 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_ThereIsNoRecord, MSGBOX_DEFAULT
# 147 "data//maps/Route110/scripts.pory"
	releaseall
# 148 "data//maps/Route110/scripts.pory"
	end
# 149 "data//maps/Route110/scripts.pory"

# 150 "data//maps/Route110/scripts.pory"
Route110_EventScript_ChallengeGuy::
# 151 "data//maps/Route110/scripts.pory"
	lock
# 152 "data//maps/Route110/scripts.pory"
	faceplayer
# 153 "data//maps/Route110/scripts.pory"
	specialvar VAR_RESULT, GetPlayerAvatarBike
# 154 "data//maps/Route110/scripts.pory"
	goto_if_eq VAR_RESULT, 1, Route110_EventScript_PlayerRidingAcroBike
# 155 "data//maps/Route110/scripts.pory"
	goto_if_eq VAR_CYCLING_CHALLENGE_STATE, 0, Route110_EventScript_PlayerNotRidingBike
# 156 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_AlwaysAimHigher, MSGBOX_DEFAULT
# 157 "data//maps/Route110/scripts.pory"
	release
# 158 "data//maps/Route110/scripts.pory"
	end
# 159 "data//maps/Route110/scripts.pory"

# 160 "data//maps/Route110/scripts.pory"
Route110_EventScript_PlayerNotRidingBike::
# 161 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_RatedForNumberOfCollisions, MSGBOX_DEFAULT
# 162 "data//maps/Route110/scripts.pory"
	release
# 163 "data//maps/Route110/scripts.pory"
	end
# 164 "data//maps/Route110/scripts.pory"

# 165 "data//maps/Route110/scripts.pory"
Route110_EventScript_PlayerRidingAcroBike::
# 166 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_AcroBikesDoNotQualify, MSGBOX_DEFAULT
# 167 "data//maps/Route110/scripts.pory"
	release
# 168 "data//maps/Route110/scripts.pory"
	end
# 169 "data//maps/Route110/scripts.pory"

# 170 "data//maps/Route110/scripts.pory"
Route110_EventScript_Edward::
# 171 "data//maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_EDWARD, Route110_Text_EdwardIntro, Route110_Text_EdwardDefeated
# 172 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_EdwardPostBattle, MSGBOX_AUTOCLOSE
# 173 "data//maps/Route110/scripts.pory"
	end
# 174 "data//maps/Route110/scripts.pory"

# 175 "data//maps/Route110/scripts.pory"
Route110_EventScript_Jaclyn::
# 176 "data//maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_JACLYN, Route110_Text_JaclynIntro, Route110_Text_JaclynDefeated
# 177 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_JaclynPostBattle, MSGBOX_AUTOCLOSE
# 178 "data//maps/Route110/scripts.pory"
	end
# 179 "data//maps/Route110/scripts.pory"

# 180 "data//maps/Route110/scripts.pory"
Route110_EventScript_Edwin::
# 181 "data//maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_EDWIN_1, Route110_Text_EdwinIntro, Route110_Text_EdwinDefeated, Route110_EventScript_EdwinRegisterMatchCallAfterBattle
# 182 "data//maps/Route110/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 183 "data//maps/Route110/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_EdwinRematch
# 184 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_EdwinPostBattle, MSGBOX_DEFAULT
# 185 "data//maps/Route110/scripts.pory"
	release
# 186 "data//maps/Route110/scripts.pory"
	end
# 187 "data//maps/Route110/scripts.pory"

# 188 "data//maps/Route110/scripts.pory"
Route110_EventScript_EdwinRegisterMatchCallAfterBattle::
# 189 "data//maps/Route110/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 190 "data//maps/Route110/scripts.pory"
	waitmovement 0
# 191 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_EdwinRegister, MSGBOX_DEFAULT
# 192 "data//maps/Route110/scripts.pory"
	register_matchcall TRAINER_EDWIN_1
# 193 "data//maps/Route110/scripts.pory"
	release
# 194 "data//maps/Route110/scripts.pory"
	end
# 195 "data//maps/Route110/scripts.pory"

# 196 "data//maps/Route110/scripts.pory"
Route110_EventScript_EdwinRematch::
# 197 "data//maps/Route110/scripts.pory"
	trainerbattle_rematch TRAINER_EDWIN_1, Route110_Text_EdwinRematchIntro, Route110_Text_EdwinRematchDefeated
# 198 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_EdwinRematchPostBattle, MSGBOX_AUTOCLOSE
# 199 "data//maps/Route110/scripts.pory"
	end
# 200 "data//maps/Route110/scripts.pory"

# 201 "data//maps/Route110/scripts.pory"
Route110_EventScript_Dale::
# 202 "data//maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_DALE, Route110_Text_DaleIntro, Route110_Text_DaleDefeated
# 203 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_DalePostBattle, MSGBOX_AUTOCLOSE
# 204 "data//maps/Route110/scripts.pory"
	end
# 205 "data//maps/Route110/scripts.pory"

# 206 "data//maps/Route110/scripts.pory"
Route110_EventScript_Jacob::
# 207 "data//maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_JACOB, Route110_Text_JacobIntro, Route110_Text_JacobDefeated
# 208 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_JacobPostBattle, MSGBOX_AUTOCLOSE
# 209 "data//maps/Route110/scripts.pory"
	end
# 210 "data//maps/Route110/scripts.pory"

# 211 "data//maps/Route110/scripts.pory"
Route110_EventScript_Anthony::
# 212 "data//maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_ANTHONY, Route110_Text_AnthonyIntro, Route110_Text_AnthonyDefeated
# 213 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
# 214 "data//maps/Route110/scripts.pory"
	end
# 215 "data//maps/Route110/scripts.pory"

# 216 "data//maps/Route110/scripts.pory"
Route110_EventScript_Benjamin::
# 217 "data//maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_BENJAMIN_1, Route110_Text_BenjaminIntro, Route110_Text_BenjaminDefeated, Route110_EventScript_BenjaminRegisterMatchCallAfterBattle
# 218 "data//maps/Route110/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 219 "data//maps/Route110/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_BenjaminRematch
# 220 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_BenjaminPostBattle, MSGBOX_DEFAULT
# 221 "data//maps/Route110/scripts.pory"
	release
# 222 "data//maps/Route110/scripts.pory"
	end
# 223 "data//maps/Route110/scripts.pory"

# 224 "data//maps/Route110/scripts.pory"
Route110_EventScript_BenjaminRegisterMatchCallAfterBattle::
# 225 "data//maps/Route110/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 226 "data//maps/Route110/scripts.pory"
	waitmovement 0
# 227 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_BenjaminRegister, MSGBOX_DEFAULT
# 228 "data//maps/Route110/scripts.pory"
	register_matchcall TRAINER_BENJAMIN_1
# 229 "data//maps/Route110/scripts.pory"
	release
# 230 "data//maps/Route110/scripts.pory"
	end
# 231 "data//maps/Route110/scripts.pory"

# 232 "data//maps/Route110/scripts.pory"
Route110_EventScript_BenjaminRematch::
# 233 "data//maps/Route110/scripts.pory"
	trainerbattle_rematch TRAINER_BENJAMIN_1, Route110_Text_BenjaminRematchIntro, Route110_Text_BenjaminRematchDefeated
# 234 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_BenjaminRematchPostBattle, MSGBOX_AUTOCLOSE
# 235 "data//maps/Route110/scripts.pory"
	end
# 236 "data//maps/Route110/scripts.pory"

# 237 "data//maps/Route110/scripts.pory"
Route110_EventScript_Jasmine::
# 238 "data//maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_JASMINE, Route110_Text_JasmineIntro, Route110_Text_JasmineDefeated
# 239 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_JasminePostBattle, MSGBOX_AUTOCLOSE
# 240 "data//maps/Route110/scripts.pory"
	end
# 241 "data//maps/Route110/scripts.pory"

# 242 "data//maps/Route110/scripts.pory"
Route110_EventScript_Abigail::
# 243 "data//maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_ABIGAIL_1, Route110_Text_AbigailIntro, Route110_Text_AbigailDefeated, Route110_EventScript_AbigailRegisterMatchCallAfterBattle
# 244 "data//maps/Route110/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 245 "data//maps/Route110/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_AbigailRematch
# 246 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_AbigailPostBattle, MSGBOX_DEFAULT
# 247 "data//maps/Route110/scripts.pory"
	release
# 248 "data//maps/Route110/scripts.pory"
	end
# 249 "data//maps/Route110/scripts.pory"

# 250 "data//maps/Route110/scripts.pory"
Route110_EventScript_AbigailRegisterMatchCallAfterBattle::
# 251 "data//maps/Route110/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 252 "data//maps/Route110/scripts.pory"
	waitmovement 0
# 253 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_AbigailRegister, MSGBOX_DEFAULT
# 254 "data//maps/Route110/scripts.pory"
	register_matchcall TRAINER_ABIGAIL_1
# 255 "data//maps/Route110/scripts.pory"
	release
# 256 "data//maps/Route110/scripts.pory"
	end
# 257 "data//maps/Route110/scripts.pory"

# 258 "data//maps/Route110/scripts.pory"
Route110_EventScript_AbigailRematch::
# 259 "data//maps/Route110/scripts.pory"
	trainerbattle_rematch TRAINER_ABIGAIL_1, Route110_Text_AbigailRematchIntro, Route110_Text_AbigailRematchDefeated
# 260 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_AbigailRematchPostBattle, MSGBOX_AUTOCLOSE
# 261 "data//maps/Route110/scripts.pory"
	end
# 262 "data//maps/Route110/scripts.pory"

# 263 "data//maps/Route110/scripts.pory"
Route110_EventScript_Isabel::
# 264 "data//maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_ISABEL_1, Route110_Text_IsabelIntro, Route110_Text_IsabelDefeated, Route110_EventScript_IsabelRegisterMatchCallAfterBattle
# 265 "data//maps/Route110/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 266 "data//maps/Route110/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_IsabelRematch
# 267 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_IsabelPostBattle, MSGBOX_DEFAULT
# 268 "data//maps/Route110/scripts.pory"
	release
# 269 "data//maps/Route110/scripts.pory"
	end
# 270 "data//maps/Route110/scripts.pory"

# 271 "data//maps/Route110/scripts.pory"
Route110_EventScript_IsabelRegisterMatchCallAfterBattle::
# 272 "data//maps/Route110/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 273 "data//maps/Route110/scripts.pory"
	waitmovement 0
# 274 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_IsabelRegister, MSGBOX_DEFAULT
# 275 "data//maps/Route110/scripts.pory"
	register_matchcall TRAINER_ISABEL_1
# 276 "data//maps/Route110/scripts.pory"
	release
# 277 "data//maps/Route110/scripts.pory"
	end
# 278 "data//maps/Route110/scripts.pory"

# 279 "data//maps/Route110/scripts.pory"
Route110_EventScript_IsabelRematch::
# 280 "data//maps/Route110/scripts.pory"
	trainerbattle_rematch TRAINER_ISABEL_1, Route110_Text_IsabelRematchIntro, Route110_Text_IsabelRematchDefeated
# 281 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_IsabelRematchPostBattle, MSGBOX_AUTOCLOSE
# 282 "data//maps/Route110/scripts.pory"
	end
# 283 "data//maps/Route110/scripts.pory"

# 284 "data//maps/Route110/scripts.pory"
Route110_EventScript_Timmy::
# 285 "data//maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_TIMMY, Route110_Text_TimmyIntro, Route110_Text_TimmyDefeated
# 286 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_TimmyPostBattle, MSGBOX_AUTOCLOSE
# 287 "data//maps/Route110/scripts.pory"
	end
# 288 "data//maps/Route110/scripts.pory"

# 289 "data//maps/Route110/scripts.pory"
Route110_EventScript_Unused::
# 290 "data//maps/Route110/scripts.pory"
	end
# 291 "data//maps/Route110/scripts.pory"

# 292 "data//maps/Route110/scripts.pory"
Route110_EventScript_Kaleb::
# 293 "data//maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_KALEB, Route110_Text_KalebIntro, Route110_Text_KalebDefeated
# 294 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_KalebPostBattle, MSGBOX_AUTOCLOSE
# 295 "data//maps/Route110/scripts.pory"
	end
# 296 "data//maps/Route110/scripts.pory"

# 297 "data//maps/Route110/scripts.pory"
Route110_EventScript_Joseph::
# 298 "data//maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_JOSEPH, Route110_Text_JosephIntro, Route110_Text_JosephDefeated
# 299 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_JosephPostBattle, MSGBOX_AUTOCLOSE
# 300 "data//maps/Route110/scripts.pory"
	end
# 301 "data//maps/Route110/scripts.pory"

# 302 "data//maps/Route110/scripts.pory"
Route110_EventScript_Alyssa::
# 303 "data//maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_ALYSSA, Route110_Text_AlyssaIntro, Route110_Text_AlyssaDefeated
# 304 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_AlyssaPostBattle, MSGBOX_AUTOCLOSE
# 305 "data//maps/Route110/scripts.pory"
	end
# 306 "data//maps/Route110/scripts.pory"

# 307 "data//maps/Route110/scripts.pory"
Route110_EventScript_CyclingChallengeEnd::
# 308 "data//maps/Route110/scripts.pory"
	lockall
# 309 "data//maps/Route110/scripts.pory"
	applymovement LOCALID_CHALLENGE_BIKER, Common_Movement_WalkInPlaceFasterRight
# 310 "data//maps/Route110/scripts.pory"
	waitmovement 0
# 311 "data//maps/Route110/scripts.pory"
	call Route110_EventScript_CyclingChallengeResults
# 312 "data//maps/Route110/scripts.pory"
	releaseall
# 313 "data//maps/Route110/scripts.pory"
	end
# 314 "data//maps/Route110/scripts.pory"

# 315 "data//maps/Route110/scripts.pory"
Route110_EventScript_CyclingChallengeResults::
# 316 "data//maps/Route110/scripts.pory"
	special FinishCyclingRoadChallenge
# 317 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_CyclingChallengeResultSummary, MSGBOX_DEFAULT
# 318 "data//maps/Route110/scripts.pory"
	switch VAR_RESULT
# 319 "data//maps/Route110/scripts.pory"
	case 10, Route110_EventScript_ChallengeReactionBest
# 320 "data//maps/Route110/scripts.pory"
	case 9, Route110_EventScript_ChallengeReactionGood
# 321 "data//maps/Route110/scripts.pory"
	case 8, Route110_EventScript_ChallengeReactionGood
# 322 "data//maps/Route110/scripts.pory"
	case 7, Route110_EventScript_ChallengeReactionGood
# 323 "data//maps/Route110/scripts.pory"
	case 6, Route110_EventScript_ChallengeReactionOk
# 324 "data//maps/Route110/scripts.pory"
	case 5, Route110_EventScript_ChallengeReactionOk
# 325 "data//maps/Route110/scripts.pory"
	case 4, Route110_EventScript_ChallengeReactionOk
# 326 "data//maps/Route110/scripts.pory"
	case 3, Route110_EventScript_ChallengeReactionBad
# 327 "data//maps/Route110/scripts.pory"
	case 2, Route110_EventScript_ChallengeReactionBad
# 328 "data//maps/Route110/scripts.pory"
	case 1, Route110_EventScript_ChallengeReactionBad
# 329 "data//maps/Route110/scripts.pory"
	case 0, Route110_EventScript_ChallengeReactionWorst
# 330 "data//maps/Route110/scripts.pory"
	end
# 331 "data//maps/Route110/scripts.pory"

# 332 "data//maps/Route110/scripts.pory"
Route110_EventScript_ChallengeReactionBest::
# 333 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_ChallengeReactionBest, MSGBOX_DEFAULT
# 334 "data//maps/Route110/scripts.pory"
	goto Route110_EventScript_EndChallenge
# 335 "data//maps/Route110/scripts.pory"
	end
# 336 "data//maps/Route110/scripts.pory"

# 337 "data//maps/Route110/scripts.pory"
Route110_EventScript_ChallengeReactionGood::
# 338 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_ChallengeReactionGood, MSGBOX_DEFAULT
# 339 "data//maps/Route110/scripts.pory"
	goto Route110_EventScript_EndChallenge
# 340 "data//maps/Route110/scripts.pory"
	end
# 341 "data//maps/Route110/scripts.pory"

# 342 "data//maps/Route110/scripts.pory"
Route110_EventScript_ChallengeReactionOk::
# 343 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_ChallengeReactionOk, MSGBOX_DEFAULT
# 344 "data//maps/Route110/scripts.pory"
	goto Route110_EventScript_EndChallenge
# 345 "data//maps/Route110/scripts.pory"
	end
# 346 "data//maps/Route110/scripts.pory"

# 347 "data//maps/Route110/scripts.pory"
Route110_EventScript_ChallengeReactionBad::
# 348 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_ChallengeReactionBad, MSGBOX_DEFAULT
# 349 "data//maps/Route110/scripts.pory"
	goto Route110_EventScript_EndChallenge
# 350 "data//maps/Route110/scripts.pory"
	end
# 351 "data//maps/Route110/scripts.pory"

# 352 "data//maps/Route110/scripts.pory"
Route110_EventScript_ChallengeReactionWorst::
# 353 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_ChallengeReactionWorst, MSGBOX_DEFAULT
# 354 "data//maps/Route110/scripts.pory"
	goto Route110_EventScript_EndChallenge
# 355 "data//maps/Route110/scripts.pory"
	end
# 356 "data//maps/Route110/scripts.pory"

# 357 "data//maps/Route110/scripts.pory"
Route110_EventScript_EndChallenge::
# 358 "data//maps/Route110/scripts.pory"
	setvar VAR_CYCLING_CHALLENGE_STATE, 3
# 359 "data//maps/Route110/scripts.pory"
	savebgm MUS_DUMMY
# 360 "data//maps/Route110/scripts.pory"
	fadedefaultbgm
# 361 "data//maps/Route110/scripts.pory"
	return
# 362 "data//maps/Route110/scripts.pory"

# 363 "data//maps/Route110/scripts.pory"
Route110_EventScript_RivalTrigger1::
# 364 "data//maps/Route110/scripts.pory"
	setvar VAR_0x8008, 1
# 365 "data//maps/Route110/scripts.pory"
	goto Route110_EventScript_RivalScene
# 366 "data//maps/Route110/scripts.pory"
	end
# 367 "data//maps/Route110/scripts.pory"

# 368 "data//maps/Route110/scripts.pory"
Route110_EventScript_RivalTrigger2::
# 369 "data//maps/Route110/scripts.pory"
	setvar VAR_0x8008, 2
# 370 "data//maps/Route110/scripts.pory"
	goto Route110_EventScript_RivalScene
# 371 "data//maps/Route110/scripts.pory"
	end
# 372 "data//maps/Route110/scripts.pory"

# 373 "data//maps/Route110/scripts.pory"
Route110_EventScript_RivalTrigger3::
# 374 "data//maps/Route110/scripts.pory"
	setvar VAR_0x8008, 3
# 375 "data//maps/Route110/scripts.pory"
	goto Route110_EventScript_RivalScene
# 376 "data//maps/Route110/scripts.pory"
	end
# 377 "data//maps/Route110/scripts.pory"

# 378 "data//maps/Route110/scripts.pory"
Route110_EventScript_RivalScene::
# 379 "data//maps/Route110/scripts.pory"
	lockall
# 380 "data//maps/Route110/scripts.pory"
	checkplayergender
# 381 "data//maps/Route110/scripts.pory"
	call_if_eq VAR_RESULT, MALE, Route110_EventScript_PlayMayMusic
# 382 "data//maps/Route110/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, Route110_EventScript_PlayBrendanMusic
# 383 "data//maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 384 "data//maps/Route110/scripts.pory"
	waitmovement 0
# 385 "data//maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 386 "data//maps/Route110/scripts.pory"
	waitmovement 0
# 387 "data//maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 388 "data//maps/Route110/scripts.pory"
	waitmovement 0
# 389 "data//maps/Route110/scripts.pory"
	delay 30
# 390 "data//maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 1, Route110_EventScript_RivalApproachPlayer1
# 391 "data//maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 2, Route110_EventScript_RivalApproachPlayer2
# 392 "data//maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 3, Route110_EventScript_RivalApproachPlayer3
# 393 "data//maps/Route110/scripts.pory"
	checkplayergender
# 394 "data//maps/Route110/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, Route110_EventScript_MayBattle
# 395 "data//maps/Route110/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, Route110_EventScript_BrendanBattle
# 396 "data//maps/Route110/scripts.pory"
	releaseall
# 397 "data//maps/Route110/scripts.pory"
	end
# 398 "data//maps/Route110/scripts.pory"

# 399 "data//maps/Route110/scripts.pory"
Route110_EventScript_PlayMayMusic::
# 400 "data//maps/Route110/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 401 "data//maps/Route110/scripts.pory"
	return
# 402 "data//maps/Route110/scripts.pory"

# 403 "data//maps/Route110/scripts.pory"
Route110_EventScript_PlayBrendanMusic::
# 404 "data//maps/Route110/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 405 "data//maps/Route110/scripts.pory"
	return
# 406 "data//maps/Route110/scripts.pory"

# 407 "data//maps/Route110/scripts.pory"
Route110_EventScript_MayBattle::
# 408 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_MayLetsBattle, MSGBOX_DEFAULT
# 409 "data//maps/Route110/scripts.pory"
	switch VAR_STARTER_MON
# 410 "data//maps/Route110/scripts.pory"
	goto Route110_EventScript_BattleMay
# 411 "data//maps/Route110/scripts.pory"
	end
# 412 "data//maps/Route110/scripts.pory"

# 413 "data//maps/Route110/scripts.pory"
Route110_EventScript_BattleMay::
# 414 "data//maps/Route110/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_A, Route110_Text_MayDefeated
# 415 "data//maps/Route110/scripts.pory"
	goto Route110_EventScript_MayDefeated
# 416 "data//maps/Route110/scripts.pory"
	end
# 417 "data//maps/Route110/scripts.pory"

# 418 "data//maps/Route110/scripts.pory"
Route110_EventScript_MayDefeated::
# 419 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_MayTakeThis, MSGBOX_DEFAULT
# 420 "data//maps/Route110/scripts.pory"
	call Route110_EventScript_GiveItemfinder
# 421 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_MayExplainItemfinder, MSGBOX_DEFAULT
# 422 "data//maps/Route110/scripts.pory"
	goto Route110_EventScript_RivalExit
# 423 "data//maps/Route110/scripts.pory"
	end
# 424 "data//maps/Route110/scripts.pory"

# 425 "data//maps/Route110/scripts.pory"
Route110_EventScript_BrendanBattle::
# 426 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_BrendanLetsBattle, MSGBOX_DEFAULT
# 427 "data//maps/Route110/scripts.pory"
	switch VAR_STARTER_MON
# 428 "data//maps/Route110/scripts.pory"
	goto Route110_EventScript_BattleBrendan
# 429 "data//maps/Route110/scripts.pory"
	end
# 430 "data//maps/Route110/scripts.pory"

# 431 "data//maps/Route110/scripts.pory"
Route110_EventScript_BattleBrendan::
# 432 "data//maps/Route110/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_A, Route110_Text_BrendanDefeated
# 433 "data//maps/Route110/scripts.pory"
	goto Route110_EventScript_BrendanDefeated
# 434 "data//maps/Route110/scripts.pory"
	end
# 435 "data//maps/Route110/scripts.pory"

# 436 "data//maps/Route110/scripts.pory"
Route110_EventScript_BrendanDefeated::
# 437 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_BrendanTakeThis, MSGBOX_DEFAULT
# 438 "data//maps/Route110/scripts.pory"
	call Route110_EventScript_GiveItemfinder
# 439 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_BrendanExplainItemfinder, MSGBOX_DEFAULT
# 440 "data//maps/Route110/scripts.pory"
	goto Route110_EventScript_RivalExit
# 441 "data//maps/Route110/scripts.pory"
	end
# 442 "data//maps/Route110/scripts.pory"

# 443 "data//maps/Route110/scripts.pory"
Route110_EventScript_GiveItemfinder::
# 444 "data//maps/Route110/scripts.pory"
	giveitem ITEM_DOWSING_MACHINE
# 445 "data//maps/Route110/scripts.pory"
	return
# 446 "data//maps/Route110/scripts.pory"

# 447 "data//maps/Route110/scripts.pory"
Route110_EventScript_RivalExit::
# 448 "data//maps/Route110/scripts.pory"
	closemessage
# 449 "data//maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 1, Route110_EventScript_MoveRival1
# 450 "data//maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 2, Route110_EventScript_MoveRival2
# 451 "data//maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 3, Route110_EventScript_MoveRival3
# 452 "data//maps/Route110/scripts.pory"
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_RIGHT
# 453 "data//maps/Route110/scripts.pory"
	setobjectmovementtype LOCALID_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_RIGHT
# 454 "data//maps/Route110/scripts.pory"
	removeobject LOCALID_RIVAL
# 455 "data//maps/Route110/scripts.pory"
	addobject LOCALID_RIVAL_ON_BIKE
# 456 "data//maps/Route110/scripts.pory"
	delay 45
# 457 "data//maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 1, Route110_EventScript_RivalExit1
# 458 "data//maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 2, Route110_EventScript_RivalExit2
# 459 "data//maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 3, Route110_EventScript_RivalExit3
# 460 "data//maps/Route110/scripts.pory"
	removeobject LOCALID_RIVAL_ON_BIKE
# 461 "data//maps/Route110/scripts.pory"
	setvar VAR_ROUTE110_STATE, 1
# 462 "data//maps/Route110/scripts.pory"
	savebgm MUS_DUMMY
# 463 "data//maps/Route110/scripts.pory"
	fadedefaultbgm
# 464 "data//maps/Route110/scripts.pory"
	releaseall
# 465 "data//maps/Route110/scripts.pory"
	end
# 466 "data//maps/Route110/scripts.pory"

# 467 "data//maps/Route110/scripts.pory"
Route110_EventScript_RivalApproachPlayer1::
# 468 "data//maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL, Route110_Movement_RivalApproachPlayer1
# 469 "data//maps/Route110/scripts.pory"
	waitmovement 0
# 470 "data//maps/Route110/scripts.pory"
	return
# 471 "data//maps/Route110/scripts.pory"

# 472 "data//maps/Route110/scripts.pory"
Route110_EventScript_RivalApproachPlayer2::
# 473 "data//maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL, Route110_Movement_RivalApproachPlayer2
# 474 "data//maps/Route110/scripts.pory"
	waitmovement 0
# 475 "data//maps/Route110/scripts.pory"
	return
# 476 "data//maps/Route110/scripts.pory"

# 477 "data//maps/Route110/scripts.pory"
Route110_EventScript_RivalApproachPlayer3::
# 478 "data//maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL, Route110_Movement_RivalApproachPlayer3
# 479 "data//maps/Route110/scripts.pory"
	waitmovement 0
# 480 "data//maps/Route110/scripts.pory"
	return
# 481 "data//maps/Route110/scripts.pory"

# 482 "data//maps/Route110/scripts.pory"
Route110_EventScript_RivalExit1::
# 483 "data//maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, Route110_Movement_RivalExit1
# 484 "data//maps/Route110/scripts.pory"
	waitmovement 0
# 485 "data//maps/Route110/scripts.pory"
	return
# 486 "data//maps/Route110/scripts.pory"

# 487 "data//maps/Route110/scripts.pory"
Route110_EventScript_RivalExit2::
# 488 "data//maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, Route110_Movement_RivalExit2
# 489 "data//maps/Route110/scripts.pory"
	waitmovement 0
# 490 "data//maps/Route110/scripts.pory"
	return
# 491 "data//maps/Route110/scripts.pory"

# 492 "data//maps/Route110/scripts.pory"
Route110_EventScript_RivalExit3::
# 493 "data//maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, Route110_Movement_RivalExit3
# 494 "data//maps/Route110/scripts.pory"
	waitmovement 0
# 495 "data//maps/Route110/scripts.pory"
	return
# 496 "data//maps/Route110/scripts.pory"

# 497 "data//maps/Route110/scripts.pory"
Route110_EventScript_MoveRival1::
# 498 "data//maps/Route110/scripts.pory"
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 33, 55
# 499 "data//maps/Route110/scripts.pory"
	return
# 500 "data//maps/Route110/scripts.pory"

# 501 "data//maps/Route110/scripts.pory"
Route110_EventScript_MoveRival2::
# 502 "data//maps/Route110/scripts.pory"
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 34, 55
# 503 "data//maps/Route110/scripts.pory"
	return
# 504 "data//maps/Route110/scripts.pory"

# 505 "data//maps/Route110/scripts.pory"
Route110_EventScript_MoveRival3::
# 506 "data//maps/Route110/scripts.pory"
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 35, 55
# 507 "data//maps/Route110/scripts.pory"
	return
# 508 "data//maps/Route110/scripts.pory"

# 509 "data//maps/Route110/scripts.pory"
Route110_Movement_RivalApproachPlayer1:
# 510 "data//maps/Route110/scripts.pory"
	walk_down
# 511 "data//maps/Route110/scripts.pory"
	walk_left
# 512 "data//maps/Route110/scripts.pory"
	walk_in_place_faster_down
# 513 "data//maps/Route110/scripts.pory"
	step_end
# 514 "data//maps/Route110/scripts.pory"

# 515 "data//maps/Route110/scripts.pory"
Route110_Movement_RivalApproachPlayer2:
# 516 "data//maps/Route110/scripts.pory"
	walk_down
# 517 "data//maps/Route110/scripts.pory"
	step_end
# 518 "data//maps/Route110/scripts.pory"

# 519 "data//maps/Route110/scripts.pory"
Route110_Movement_RivalApproachPlayer3:
# 520 "data//maps/Route110/scripts.pory"
	walk_down
# 521 "data//maps/Route110/scripts.pory"
	walk_right
# 522 "data//maps/Route110/scripts.pory"
	walk_in_place_faster_down
# 523 "data//maps/Route110/scripts.pory"
	step_end
# 524 "data//maps/Route110/scripts.pory"

# 525 "data//maps/Route110/scripts.pory"
Route110_Movement_RivalExit1:
# 526 "data//maps/Route110/scripts.pory"
	walk_fast_up
# 527 "data//maps/Route110/scripts.pory"
	walk_fast_up
# 528 "data//maps/Route110/scripts.pory"
	walk_fast_up
# 529 "data//maps/Route110/scripts.pory"
	walk_fast_up
# 530 "data//maps/Route110/scripts.pory"
	walk_fast_up
# 531 "data//maps/Route110/scripts.pory"
	walk_fast_up
# 532 "data//maps/Route110/scripts.pory"
	walk_fast_up
# 533 "data//maps/Route110/scripts.pory"
	step_end
# 534 "data//maps/Route110/scripts.pory"

# 535 "data//maps/Route110/scripts.pory"
Route110_Movement_RivalExit2:
# 536 "data//maps/Route110/scripts.pory"
	walk_fast_up
# 537 "data//maps/Route110/scripts.pory"
	walk_fast_up
# 538 "data//maps/Route110/scripts.pory"
	walk_fast_up
# 539 "data//maps/Route110/scripts.pory"
	walk_fast_up
# 540 "data//maps/Route110/scripts.pory"
	walk_fast_up
# 541 "data//maps/Route110/scripts.pory"
	walk_fast_up
# 542 "data//maps/Route110/scripts.pory"
	walk_fast_up
# 543 "data//maps/Route110/scripts.pory"
	walk_fast_down
# 544 "data//maps/Route110/scripts.pory"
	step_end
# 545 "data//maps/Route110/scripts.pory"

# 546 "data//maps/Route110/scripts.pory"
Route110_Movement_RivalExit3:
# 547 "data//maps/Route110/scripts.pory"
	walk_fast_up
# 548 "data//maps/Route110/scripts.pory"
	walk_fast_up
# 549 "data//maps/Route110/scripts.pory"
	walk_fast_up
# 550 "data//maps/Route110/scripts.pory"
	walk_fast_up
# 551 "data//maps/Route110/scripts.pory"
	walk_fast_up
# 552 "data//maps/Route110/scripts.pory"
	walk_fast_up
# 553 "data//maps/Route110/scripts.pory"
	walk_fast_up
# 554 "data//maps/Route110/scripts.pory"
	step_end
# 555 "data//maps/Route110/scripts.pory"

# 556 "data//maps/Route110/scripts.pory"
Route110_EventScript_BirchScene1::
# 557 "data//maps/Route110/scripts.pory"
	lockall
# 558 "data//maps/Route110/scripts.pory"
	setvar VAR_0x8008, 1
# 559 "data//maps/Route110/scripts.pory"
	goto Route110_EventScript_BirchScene
# 560 "data//maps/Route110/scripts.pory"

# 561 "data//maps/Route110/scripts.pory"
Route110_EventScript_BirchScene2::
# 562 "data//maps/Route110/scripts.pory"
	lockall
# 563 "data//maps/Route110/scripts.pory"
	setvar VAR_0x8008, 2
# 564 "data//maps/Route110/scripts.pory"
	goto Route110_EventScript_BirchScene
# 565 "data//maps/Route110/scripts.pory"

# 566 "data//maps/Route110/scripts.pory"
Route110_EventScript_BirchScene3::
# 567 "data//maps/Route110/scripts.pory"
	lockall
# 568 "data//maps/Route110/scripts.pory"
	setvar VAR_0x8008, 3
# 569 "data//maps/Route110/scripts.pory"
	goto Route110_EventScript_BirchScene
# 570 "data//maps/Route110/scripts.pory"

# 571 "data//maps/Route110/scripts.pory"
Route110_EventScript_BirchScene4::
# 572 "data//maps/Route110/scripts.pory"
	lockall
# 573 "data//maps/Route110/scripts.pory"
	setvar VAR_0x8008, 4
# 574 "data//maps/Route110/scripts.pory"
	goto Route110_EventScript_BirchScene
# 575 "data//maps/Route110/scripts.pory"

# 576 "data//maps/Route110/scripts.pory"
Route110_EventScript_BirchScene::
# 577 "data//maps/Route110/scripts.pory"
	addobject LOCALID_BIRCH
# 578 "data//maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchEntrance
# 579 "data//maps/Route110/scripts.pory"
	waitmovement 0
# 580 "data//maps/Route110/scripts.pory"
	playse SE_PIN
# 581 "data//maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_ExclamationMark
# 582 "data//maps/Route110/scripts.pory"
	waitmovement 0
# 583 "data//maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_Delay48
# 584 "data//maps/Route110/scripts.pory"
	waitmovement 0
# 585 "data//maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 1, Route110_EventScript_BirchApproachPlayer1
# 586 "data//maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 2, Route110_EventScript_BirchApproachPlayer2
# 587 "data//maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 3, Route110_EventScript_BirchApproachPlayer3
# 588 "data//maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 4, Route110_EventScript_BirchApproachPlayer4
# 589 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_ImagineSeeingYouHere, MSGBOX_DEFAULT
# 590 "data//maps/Route110/scripts.pory"
	closemessage
# 591 "data//maps/Route110/scripts.pory"
	delay 20
# 592 "data//maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterLeft
# 593 "data//maps/Route110/scripts.pory"
	waitmovement 0
# 594 "data//maps/Route110/scripts.pory"
	delay 10
# 595 "data//maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
# 596 "data//maps/Route110/scripts.pory"
	waitmovement 0
# 597 "data//maps/Route110/scripts.pory"
	delay 20
# 598 "data//maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterDown
# 599 "data//maps/Route110/scripts.pory"
	waitmovement 0
# 600 "data//maps/Route110/scripts.pory"
	delay 30
# 601 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_HeardYouInstallMatchCall, MSGBOX_DEFAULT
# 602 "data//maps/Route110/scripts.pory"
	closemessage
# 603 "data//maps/Route110/scripts.pory"
	delay 30
# 604 "data//maps/Route110/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 605 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_RegisteredBirchInPokenav, MSGBOX_DEFAULT
# 606 "data//maps/Route110/scripts.pory"
	waitfanfare
# 607 "data//maps/Route110/scripts.pory"
	closemessage
# 608 "data//maps/Route110/scripts.pory"
	delay 30
# 609 "data//maps/Route110/scripts.pory"
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
# 610 "data//maps/Route110/scripts.pory"
	msgbox Route110_Text_KeepAnEyeOutForRival, MSGBOX_DEFAULT
# 611 "data//maps/Route110/scripts.pory"
	closemessage
# 612 "data//maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 1, Route110_EventScript_BirchExit1
# 613 "data//maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 2, Route110_EventScript_BirchExit2
# 614 "data//maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 3, Route110_EventScript_BirchExit3
# 615 "data//maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 4, Route110_EventScript_BirchExit4
# 616 "data//maps/Route110/scripts.pory"
	removeobject LOCALID_BIRCH
# 617 "data//maps/Route110/scripts.pory"
	setvar VAR_REGISTER_BIRCH_STATE, 2
# 618 "data//maps/Route110/scripts.pory"
	releaseall
# 619 "data//maps/Route110/scripts.pory"
	end
# 620 "data//maps/Route110/scripts.pory"

# 621 "data//maps/Route110/scripts.pory"
Route110_EventScript_BirchApproachPlayer1::
# 622 "data//maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer1
# 623 "data//maps/Route110/scripts.pory"
	waitmovement 0
# 624 "data//maps/Route110/scripts.pory"
	return
# 625 "data//maps/Route110/scripts.pory"

# 626 "data//maps/Route110/scripts.pory"
Route110_EventScript_BirchApproachPlayer2::
# 627 "data//maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer2
# 628 "data//maps/Route110/scripts.pory"
	waitmovement 0
# 629 "data//maps/Route110/scripts.pory"
	return
# 630 "data//maps/Route110/scripts.pory"

# 631 "data//maps/Route110/scripts.pory"
Route110_EventScript_BirchApproachPlayer3::
# 632 "data//maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer3
# 633 "data//maps/Route110/scripts.pory"
	waitmovement 0
# 634 "data//maps/Route110/scripts.pory"
	return
# 635 "data//maps/Route110/scripts.pory"

# 636 "data//maps/Route110/scripts.pory"
Route110_EventScript_BirchApproachPlayer4::
# 637 "data//maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer4
# 638 "data//maps/Route110/scripts.pory"
	waitmovement 0
# 639 "data//maps/Route110/scripts.pory"
	return
# 640 "data//maps/Route110/scripts.pory"

# 641 "data//maps/Route110/scripts.pory"
Route110_EventScript_BirchExit1::
# 642 "data//maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit1
# 643 "data//maps/Route110/scripts.pory"
	waitmovement 0
# 644 "data//maps/Route110/scripts.pory"
	return
# 645 "data//maps/Route110/scripts.pory"

# 646 "data//maps/Route110/scripts.pory"
Route110_EventScript_BirchExit2::
# 647 "data//maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit2
# 648 "data//maps/Route110/scripts.pory"
	waitmovement 0
# 649 "data//maps/Route110/scripts.pory"
	return
# 650 "data//maps/Route110/scripts.pory"

# 651 "data//maps/Route110/scripts.pory"
Route110_EventScript_BirchExit3::
# 652 "data//maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit3
# 653 "data//maps/Route110/scripts.pory"
	waitmovement 0
# 654 "data//maps/Route110/scripts.pory"
	return
# 655 "data//maps/Route110/scripts.pory"

# 656 "data//maps/Route110/scripts.pory"
Route110_EventScript_BirchExit4::
# 657 "data//maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit4
# 658 "data//maps/Route110/scripts.pory"
	waitmovement 0
# 659 "data//maps/Route110/scripts.pory"
	return
# 660 "data//maps/Route110/scripts.pory"

# 661 "data//maps/Route110/scripts.pory"
Route110_Movement_BirchEntrance:
# 662 "data//maps/Route110/scripts.pory"
	walk_down
# 663 "data//maps/Route110/scripts.pory"
	walk_down
# 664 "data//maps/Route110/scripts.pory"
	walk_down
# 665 "data//maps/Route110/scripts.pory"
	step_end
# 666 "data//maps/Route110/scripts.pory"

# 667 "data//maps/Route110/scripts.pory"
Route110_Movement_BirchApproachPlayer1:
# 668 "data//maps/Route110/scripts.pory"
	walk_down
# 669 "data//maps/Route110/scripts.pory"
	walk_left
# 670 "data//maps/Route110/scripts.pory"
	walk_left
# 671 "data//maps/Route110/scripts.pory"
	walk_down
# 672 "data//maps/Route110/scripts.pory"
	step_end
# 673 "data//maps/Route110/scripts.pory"

# 674 "data//maps/Route110/scripts.pory"
Route110_Movement_BirchApproachPlayer2:
# 675 "data//maps/Route110/scripts.pory"
	walk_down
# 676 "data//maps/Route110/scripts.pory"
	walk_left
# 677 "data//maps/Route110/scripts.pory"
	walk_down
# 678 "data//maps/Route110/scripts.pory"
	step_end
# 679 "data//maps/Route110/scripts.pory"

# 680 "data//maps/Route110/scripts.pory"
Route110_Movement_BirchApproachPlayer3:
# 681 "data//maps/Route110/scripts.pory"
	walk_down
# 682 "data//maps/Route110/scripts.pory"
	walk_down
# 683 "data//maps/Route110/scripts.pory"
	step_end
# 684 "data//maps/Route110/scripts.pory"

# 685 "data//maps/Route110/scripts.pory"
Route110_Movement_BirchApproachPlayer4:
# 686 "data//maps/Route110/scripts.pory"
	walk_down
# 687 "data//maps/Route110/scripts.pory"
	walk_right
# 688 "data//maps/Route110/scripts.pory"
	walk_down
# 689 "data//maps/Route110/scripts.pory"
	step_end
# 690 "data//maps/Route110/scripts.pory"

# 691 "data//maps/Route110/scripts.pory"
Route110_Movement_BirchExit1:
# 692 "data//maps/Route110/scripts.pory"
	walk_up
# 693 "data//maps/Route110/scripts.pory"
	walk_up
# 694 "data//maps/Route110/scripts.pory"
	walk_right
# 695 "data//maps/Route110/scripts.pory"
	walk_up
# 696 "data//maps/Route110/scripts.pory"
	walk_up
# 697 "data//maps/Route110/scripts.pory"
	walk_up
# 698 "data//maps/Route110/scripts.pory"
	step_end
# 699 "data//maps/Route110/scripts.pory"

# 700 "data//maps/Route110/scripts.pory"
Route110_Movement_BirchExit2:
# 701 "data//maps/Route110/scripts.pory"
	walk_up
# 702 "data//maps/Route110/scripts.pory"
	walk_up
# 703 "data//maps/Route110/scripts.pory"
	walk_up
# 704 "data//maps/Route110/scripts.pory"
	walk_up
# 705 "data//maps/Route110/scripts.pory"
	walk_up
# 706 "data//maps/Route110/scripts.pory"
	step_end
# 707 "data//maps/Route110/scripts.pory"

# 708 "data//maps/Route110/scripts.pory"
Route110_Movement_BirchExit3:
# 709 "data//maps/Route110/scripts.pory"
	walk_up
# 710 "data//maps/Route110/scripts.pory"
	walk_up
# 711 "data//maps/Route110/scripts.pory"
	walk_up
# 712 "data//maps/Route110/scripts.pory"
	walk_up
# 713 "data//maps/Route110/scripts.pory"
	walk_up
# 714 "data//maps/Route110/scripts.pory"
	step_end
# 715 "data//maps/Route110/scripts.pory"

# 716 "data//maps/Route110/scripts.pory"
Route110_Movement_BirchExit4:
# 717 "data//maps/Route110/scripts.pory"
	walk_up
# 718 "data//maps/Route110/scripts.pory"
	walk_up
# 719 "data//maps/Route110/scripts.pory"
	walk_up
# 720 "data//maps/Route110/scripts.pory"
	walk_up
# 721 "data//maps/Route110/scripts.pory"
	walk_up
# 722 "data//maps/Route110/scripts.pory"
	step_end
# 723 "data//maps/Route110/scripts.pory"

# 724 "data//maps/Route110/scripts.pory"
Route110_Text_WeCantTalkAboutAquaActivities:
# 725 "data//maps/Route110/scripts.pory"
	.string "TEAM AQUA's activities…\n"
# 726 "data//maps/Route110/scripts.pory"
	.string "We can't talk about them yet.$"
# 727 "data//maps/Route110/scripts.pory"

# 728 "data//maps/Route110/scripts.pory"
Route110_Text_KickUpARuckus:
# 729 "data//maps/Route110/scripts.pory"
	.string "I want to get going to SLATEPORT and\n"
# 730 "data//maps/Route110/scripts.pory"
	.string "kick up a ruckus!$"
# 731 "data//maps/Route110/scripts.pory"

# 732 "data//maps/Route110/scripts.pory"
Route110_Text_MyFirstJobInAqua:
# 733 "data//maps/Route110/scripts.pory"
	.string "This is my first job after joining\n"
# 734 "data//maps/Route110/scripts.pory"
	.string "TEAM AQUA. It's a little scary.$"
# 735 "data//maps/Route110/scripts.pory"

# 736 "data//maps/Route110/scripts.pory"
Route110_Text_AquaActionsBringSmiles:
# 737 "data//maps/Route110/scripts.pory"
	.string "TEAM AQUA's actions should bring\n"
# 738 "data//maps/Route110/scripts.pory"
	.string "smiles to people's faces!$"
# 739 "data//maps/Route110/scripts.pory"

# 740 "data//maps/Route110/scripts.pory"
Route110_Text_MayLetsBattle:
# 741 "data//maps/Route110/scripts.pory"
	.string "MAY: Hi, {PLAYER}{KUN}, long time no see!\p"
# 742 "data//maps/Route110/scripts.pory"
	.string "While I was searching for other\n"
# 743 "data//maps/Route110/scripts.pory"
	.string "POKéMON, my POKéMON grew stronger.\p"
# 744 "data//maps/Route110/scripts.pory"
	.string "So…\n"
# 745 "data//maps/Route110/scripts.pory"
	.string "How about a little battle?$"
# 746 "data//maps/Route110/scripts.pory"

# 747 "data//maps/Route110/scripts.pory"
Route110_Text_MayDefeated:
# 748 "data//maps/Route110/scripts.pory"
	.string "Yikes!\n"
# 749 "data//maps/Route110/scripts.pory"
	.string "You're better than I expected!$"
# 750 "data//maps/Route110/scripts.pory"

# 751 "data//maps/Route110/scripts.pory"
Route110_Text_MayTakeThis:
# 752 "data//maps/Route110/scripts.pory"
	.string "MAY: {PLAYER}{KUN}, you've been busy\n"
# 753 "data//maps/Route110/scripts.pory"
	.string "training, too, haven't you?\p"
# 754 "data//maps/Route110/scripts.pory"
	.string "I think you deserve a reward!\n"
# 755 "data//maps/Route110/scripts.pory"
	.string "This is from me!$"
# 756 "data//maps/Route110/scripts.pory"

# 757 "data//maps/Route110/scripts.pory"
Route110_Text_MayExplainItemfinder:
# 758 "data//maps/Route110/scripts.pory"
	.string "MAY: That's an ITEMFINDER.\p"
# 759 "data//maps/Route110/scripts.pory"
	.string "Try it out. If there is an item that's\n"
# 760 "data//maps/Route110/scripts.pory"
	.string "not visible, it emits a sound.\p"
# 761 "data//maps/Route110/scripts.pory"
	.string "Okay, {PLAYER}{KUN}, let's meet again!\p"
# 762 "data//maps/Route110/scripts.pory"
	.string "I know it's a little silly coming from\n"
# 763 "data//maps/Route110/scripts.pory"
	.string "me, but I think you should train a lot\l"
# 764 "data//maps/Route110/scripts.pory"
	.string "harder for the next time.$"
# 765 "data//maps/Route110/scripts.pory"

# 766 "data//maps/Route110/scripts.pory"
Route110_Text_BrendanLetsBattle:
# 767 "data//maps/Route110/scripts.pory"
	.string "BRENDAN: Hey, {PLAYER}.\n"
# 768 "data//maps/Route110/scripts.pory"
	.string "So this is where you were.\l"
# 769 "data//maps/Route110/scripts.pory"
	.string "How's it going?\p"
# 770 "data//maps/Route110/scripts.pory"
	.string "Have you been raising your POKéMON?\n"
# 771 "data//maps/Route110/scripts.pory"
	.string "I'll check for you.$"
# 772 "data//maps/Route110/scripts.pory"

# 773 "data//maps/Route110/scripts.pory"
Route110_Text_BrendanDefeated:
# 774 "data//maps/Route110/scripts.pory"
	.string "Hmm…\n"
# 775 "data//maps/Route110/scripts.pory"
	.string "You're pretty good.$"
# 776 "data//maps/Route110/scripts.pory"

# 777 "data//maps/Route110/scripts.pory"
Route110_Text_BrendanTakeThis:
# 778 "data//maps/Route110/scripts.pory"
	.string "BRENDAN: {PLAYER}, you've trained\n"
# 779 "data//maps/Route110/scripts.pory"
	.string "without me noticing…\p"
# 780 "data//maps/Route110/scripts.pory"
	.string "Good enough!\n"
# 781 "data//maps/Route110/scripts.pory"
	.string "Here, take this.$"
# 782 "data//maps/Route110/scripts.pory"

# 783 "data//maps/Route110/scripts.pory"
Route110_Text_BrendanExplainItemfinder:
# 784 "data//maps/Route110/scripts.pory"
	.string "BRENDAN: That's an ITEMFINDER.\p"
# 785 "data//maps/Route110/scripts.pory"
	.string "Use it to root around for items that\n"
# 786 "data//maps/Route110/scripts.pory"
	.string "aren't visible.\p"
# 787 "data//maps/Route110/scripts.pory"
	.string "If it senses something, it emits\n"
# 788 "data//maps/Route110/scripts.pory"
	.string "a sound.\p"
# 789 "data//maps/Route110/scripts.pory"
	.string "Anyway, I'm off to look for new\n"
# 790 "data//maps/Route110/scripts.pory"
	.string "POKéMON.$"
# 791 "data//maps/Route110/scripts.pory"

# 792 "data//maps/Route110/scripts.pory"
Route110_Text_RideBikeAtFullSpeed:
# 793 "data//maps/Route110/scripts.pory"
	.string "Wouldn't it be great to ride a BIKE\n"
# 794 "data//maps/Route110/scripts.pory"
	.string "at full speed on CYCLING ROAD?$"
# 795 "data//maps/Route110/scripts.pory"

# 796 "data//maps/Route110/scripts.pory"
Route110_Text_HairStreamsBehindMe:
# 797 "data//maps/Route110/scripts.pory"
	.string "How do you like the way my raven-\n"
# 798 "data//maps/Route110/scripts.pory"
	.string "colored hair streams behind me?\p"
# 799 "data//maps/Route110/scripts.pory"
	.string "I grew my hair out just for that.$"
# 800 "data//maps/Route110/scripts.pory"

# 801 "data//maps/Route110/scripts.pory"
Route110_Text_YouGotBikeFromRydel:
# 802 "data//maps/Route110/scripts.pory"
	.string "Oh, hey, you got that BIKE from RYDEL!\p"
# 803 "data//maps/Route110/scripts.pory"
	.string "Oh, it's glaringly obvious.\n"
# 804 "data//maps/Route110/scripts.pory"
	.string "It says right on your bike…\p"
# 805 "data//maps/Route110/scripts.pory"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
# 806 "data//maps/Route110/scripts.pory"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
# 807 "data//maps/Route110/scripts.pory"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
# 808 "data//maps/Route110/scripts.pory"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
# 809 "data//maps/Route110/scripts.pory"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
# 810 "data//maps/Route110/scripts.pory"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
# 811 "data//maps/Route110/scripts.pory"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
# 812 "data//maps/Route110/scripts.pory"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
# 813 "data//maps/Route110/scripts.pory"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL…\n"
# 814 "data//maps/Route110/scripts.pory"
	.string "That name's everywhere.\p"
# 815 "data//maps/Route110/scripts.pory"
	.string "You should ride it around all over\n"
# 816 "data//maps/Route110/scripts.pory"
	.string "the place--it's good advertising!$"
# 817 "data//maps/Route110/scripts.pory"

# 818 "data//maps/Route110/scripts.pory"
Route110_Text_TwoRoads:
# 819 "data//maps/Route110/scripts.pory"
	.string "The two roads, one above, one below…\p"
# 820 "data//maps/Route110/scripts.pory"
	.string "A road each for people and POKéMON.\n"
# 821 "data//maps/Route110/scripts.pory"
	.string "Perhaps that is right and fair.$"
# 822 "data//maps/Route110/scripts.pory"

# 823 "data//maps/Route110/scripts.pory"
Route110_Text_WalkOnTheLowRoad:
# 824 "data//maps/Route110/scripts.pory"
	.string "I don't have a BIKE, so I'll take\n"
# 825 "data//maps/Route110/scripts.pory"
	.string "a leisurely walk on the low road.$"
# 826 "data//maps/Route110/scripts.pory"

# 827 "data//maps/Route110/scripts.pory"
Route110_Text_BikeTechniques:
# 828 "data//maps/Route110/scripts.pory"
	.string "Learning techniques will make BIKE\n"
# 829 "data//maps/Route110/scripts.pory"
	.string "riding even more fun.\p"
# 830 "data//maps/Route110/scripts.pory"
	.string "There are some places that you can\n"
# 831 "data//maps/Route110/scripts.pory"
	.string "reach only by using a BIKE technique.$"
# 832 "data//maps/Route110/scripts.pory"

# 833 "data//maps/Route110/scripts.pory"
Route110_Text_WhichShouldIChoose:
# 834 "data//maps/Route110/scripts.pory"
	.string "Which should I choose?\p"
# 835 "data//maps/Route110/scripts.pory"
	.string "Make a beeline for MAUVILLE on\n"
# 836 "data//maps/Route110/scripts.pory"
	.string "CYCLING ROAD, or take the low road\l"
# 837 "data//maps/Route110/scripts.pory"
	.string "and look for POKéMON?$"
# 838 "data//maps/Route110/scripts.pory"

# 839 "data//maps/Route110/scripts.pory"
Route110_Text_CyclingChallengeResultSummary:
# 840 "data//maps/Route110/scripts.pory"
	.string "Number of collisions:\n"
# 841 "data//maps/Route110/scripts.pory"
	.string "… … {STR_VAR_1}!\p"
# 842 "data//maps/Route110/scripts.pory"
	.string "Total time:\n"
# 843 "data//maps/Route110/scripts.pory"
	.string "… … {STR_VAR_2}!$"
# 844 "data//maps/Route110/scripts.pory"

# 845 "data//maps/Route110/scripts.pory"
Route110_Text_ChallengeReactionBest:
# 846 "data//maps/Route110/scripts.pory"
	.string "Bravo! Splendid showing!\p"
# 847 "data//maps/Route110/scripts.pory"
	.string "Your love of cycling comes from deep\n"
# 848 "data//maps/Route110/scripts.pory"
	.string "within your heart.\l"
# 849 "data//maps/Route110/scripts.pory"
	.string "You've shaken me to my very soul!$"
# 850 "data//maps/Route110/scripts.pory"

# 851 "data//maps/Route110/scripts.pory"
Route110_Text_ChallengeReactionGood:
# 852 "data//maps/Route110/scripts.pory"
	.string "Your technique is remarkable.\p"
# 853 "data//maps/Route110/scripts.pory"
	.string "I suggest you speed up a bit while\n"
# 854 "data//maps/Route110/scripts.pory"
	.string "still avoiding collisions.$"
# 855 "data//maps/Route110/scripts.pory"

# 856 "data//maps/Route110/scripts.pory"
Route110_Text_ChallengeReactionOk:
# 857 "data//maps/Route110/scripts.pory"
	.string "I would consider you a work in\n"
# 858 "data//maps/Route110/scripts.pory"
	.string "progress.\p"
# 859 "data//maps/Route110/scripts.pory"
	.string "Still, I hope you don't forget the\n"
# 860 "data//maps/Route110/scripts.pory"
	.string "sheer pleasure of cycling.$"
# 861 "data//maps/Route110/scripts.pory"

# 862 "data//maps/Route110/scripts.pory"
Route110_Text_ChallengeReactionBad:
# 863 "data//maps/Route110/scripts.pory"
	.string "My word… Your cycling skills border\n"
# 864 "data//maps/Route110/scripts.pory"
	.string "on terrifying.\p"
# 865 "data//maps/Route110/scripts.pory"
	.string "Most certainly, you need much more\n"
# 866 "data//maps/Route110/scripts.pory"
	.string "practice riding.$"
# 867 "data//maps/Route110/scripts.pory"

# 868 "data//maps/Route110/scripts.pory"
Route110_Text_ChallengeReactionWorst:
# 869 "data//maps/Route110/scripts.pory"
	.string "…I am aghast…\p"
# 870 "data//maps/Route110/scripts.pory"
	.string "You're perhaps not cut out for this\n"
# 871 "data//maps/Route110/scripts.pory"
	.string "unfortunate cycling business.\p"
# 872 "data//maps/Route110/scripts.pory"
	.string "You ought to give serious thought to\n"
# 873 "data//maps/Route110/scripts.pory"
	.string "returning that BIKE to RYDEL.$"
# 874 "data//maps/Route110/scripts.pory"

# 875 "data//maps/Route110/scripts.pory"
Route110_Text_RatedForNumberOfCollisions:
# 876 "data//maps/Route110/scripts.pory"
	.string "This is CYCLING ROAD.\p"
# 877 "data//maps/Route110/scripts.pory"
	.string "If you were to ride from MAUVILLE to\n"
# 878 "data//maps/Route110/scripts.pory"
	.string "SLATEPORT on a MACH BIKE, you would\l"
# 879 "data//maps/Route110/scripts.pory"
	.string "be rated for the number of collisions\l"
# 880 "data//maps/Route110/scripts.pory"
	.string "and your total time.$"
# 881 "data//maps/Route110/scripts.pory"

# 882 "data//maps/Route110/scripts.pory"
Route110_Text_AlwaysAimHigher:
# 883 "data//maps/Route110/scripts.pory"
	.string "Regardless of the results, I count on\n"
# 884 "data//maps/Route110/scripts.pory"
	.string "seeing more challenges from you.\l"
# 885 "data//maps/Route110/scripts.pory"
	.string "Always aim higher!$"
# 886 "data//maps/Route110/scripts.pory"

# 887 "data//maps/Route110/scripts.pory"
Route110_Text_AcroBikesDoNotQualify:
# 888 "data//maps/Route110/scripts.pory"
	.string "On this CYCLING ROAD, those riding\n"
# 889 "data//maps/Route110/scripts.pory"
	.string "MACH BIKES are rated for their number\l"
# 890 "data//maps/Route110/scripts.pory"
	.string "of collisions and their total times.\p"
# 891 "data//maps/Route110/scripts.pory"
	.string "ACRO BIKES do not qualify for rating.\n"
# 892 "data//maps/Route110/scripts.pory"
	.string "They are easy to turn, so it's not fair.$"
# 893 "data//maps/Route110/scripts.pory"

# 894 "data//maps/Route110/scripts.pory"
Route110_Text_SlateportCitySign:
# 895 "data//maps/Route110/scripts.pory"
	.string "ROUTE 110\n"
# 896 "data//maps/Route110/scripts.pory"
	.string "{DOWN_ARROW} SLATEPORT CITY$"
# 897 "data//maps/Route110/scripts.pory"

# 898 "data//maps/Route110/scripts.pory"
Route110_Text_CyclingRoadSign:
# 899 "data//maps/Route110/scripts.pory"
	.string "SEASIDE CYCLING ROAD$"
# 900 "data//maps/Route110/scripts.pory"

# 901 "data//maps/Route110/scripts.pory"
Route110_Text_AquaWasHere:
# 902 "data//maps/Route110/scripts.pory"
	.string "“TEAM AQUA was here!”\p"
# 903 "data//maps/Route110/scripts.pory"
	.string "Someone painted that onto this sign,\n"
# 904 "data//maps/Route110/scripts.pory"
	.string "but then someone else painted over it.\p"
# 905 "data//maps/Route110/scripts.pory"
	.string "“TEAM MAGMA rules!” is what it\n"
# 906 "data//maps/Route110/scripts.pory"
	.string "says now.$"
# 907 "data//maps/Route110/scripts.pory"

# 908 "data//maps/Route110/scripts.pory"
Route110_Text_Route103Sign:
# 909 "data//maps/Route110/scripts.pory"
	.string "ROUTE 110\n"
# 910 "data//maps/Route110/scripts.pory"
	.string "{LEFT_ARROW} ROUTE 103$"
# 911 "data//maps/Route110/scripts.pory"

# 912 "data//maps/Route110/scripts.pory"
Route110_Text_SeasideParkingSign:
# 913 "data//maps/Route110/scripts.pory"
	.string "SEASIDE PARKING$"
# 914 "data//maps/Route110/scripts.pory"

# 915 "data//maps/Route110/scripts.pory"
Route110_Text_MauvilleCitySign:
# 916 "data//maps/Route110/scripts.pory"
	.string "ROUTE 110\n"
# 917 "data//maps/Route110/scripts.pory"
	.string "{UP_ARROW} MAUVILLE CITY$"
# 918 "data//maps/Route110/scripts.pory"

# 919 "data//maps/Route110/scripts.pory"
Route110_Text_TrainerTipsPrlzSleep:
# 920 "data//maps/Route110/scripts.pory"
	.string "TRAINER TIPS\p"
# 921 "data//maps/Route110/scripts.pory"
	.string "The foe can be made helpless by\n"
# 922 "data//maps/Route110/scripts.pory"
	.string "paralyzing it or causing it to sleep.\p"
# 923 "data//maps/Route110/scripts.pory"
	.string "It is an important technique for\n"
# 924 "data//maps/Route110/scripts.pory"
	.string "POKéMON battles.$"
# 925 "data//maps/Route110/scripts.pory"

# 926 "data//maps/Route110/scripts.pory"
Route110_Text_TrainerTipsRegisterItems:
# 927 "data//maps/Route110/scripts.pory"
	.string "TRAINER TIPS\p"
# 928 "data//maps/Route110/scripts.pory"
	.string "The items in the BAG can be reorganized\n"
# 929 "data//maps/Route110/scripts.pory"
	.string "by pressing SELECT.$"
# 930 "data//maps/Route110/scripts.pory"

# 931 "data//maps/Route110/scripts.pory"
Route110_Text_TrickHouseSign:
# 932 "data//maps/Route110/scripts.pory"
	.string "“Three steps {RIGHT_ARROW} and two steps {UP_ARROW}\n"
# 933 "data//maps/Route110/scripts.pory"
	.string "to reach the wondrous TRICK HOUSE.”$"
# 934 "data//maps/Route110/scripts.pory"

# 935 "data//maps/Route110/scripts.pory"
Route110_Text_BestRecord:
# 936 "data//maps/Route110/scripts.pory"
	.string "THE BEST RECORD TO DATE…\p"
# 937 "data//maps/Route110/scripts.pory"
	.string "No. of collisions: {STR_VAR_1}\p"
# 938 "data//maps/Route110/scripts.pory"
	.string "Elapsed time: {STR_VAR_2}$"
# 939 "data//maps/Route110/scripts.pory"

# 940 "data//maps/Route110/scripts.pory"
Route110_Text_ThereIsNoRecord:
# 941 "data//maps/Route110/scripts.pory"
	.string "THE BEST RECORD TO DATE…\p"
# 942 "data//maps/Route110/scripts.pory"
	.string "No one seems to have taken the\n"
# 943 "data//maps/Route110/scripts.pory"
	.string "challenge. There is no record…$"
# 944 "data//maps/Route110/scripts.pory"

# 945 "data//maps/Route110/scripts.pory"
Route110_Text_ImagineSeeingYouHere:
# 946 "data//maps/Route110/scripts.pory"
	.string "PROF. BIRCH: Oh, {PLAYER}{KUN}!\n"
# 947 "data//maps/Route110/scripts.pory"
	.string "Imagine seeing you here!\p"
# 948 "data//maps/Route110/scripts.pory"
	.string "And where might my {RIVAL} be?$"
# 949 "data//maps/Route110/scripts.pory"

# 950 "data//maps/Route110/scripts.pory"
Route110_Text_HeardYouInstallMatchCall:
# 951 "data//maps/Route110/scripts.pory"
	.string "Oh, I see!\n"
# 952 "data//maps/Route110/scripts.pory"
	.string "You two are running separately.\l"
# 953 "data//maps/Route110/scripts.pory"
	.string "Well, that's fine.\p"
# 954 "data//maps/Route110/scripts.pory"
	.string "Oh, yes, I heard that your POKéNAV\n"
# 955 "data//maps/Route110/scripts.pory"
	.string "had the MATCH CALL system installed.\p"
# 956 "data//maps/Route110/scripts.pory"
	.string "Well, then, I should register you in\n"
# 957 "data//maps/Route110/scripts.pory"
	.string "my POKéNAV as well.\p"
# 958 "data//maps/Route110/scripts.pory"
	.string "That way, even when we're apart,\n"
# 959 "data//maps/Route110/scripts.pory"
	.string "I can rate your POKéDEX anytime.\p"
# 960 "data//maps/Route110/scripts.pory"
	.string "… … … … … …$"
# 961 "data//maps/Route110/scripts.pory"

# 962 "data//maps/Route110/scripts.pory"
Route110_Text_RegisteredBirchInPokenav:
# 963 "data//maps/Route110/scripts.pory"
	.string "Registered PROF. BIRCH\n"
# 964 "data//maps/Route110/scripts.pory"
	.string "in the POKéNAV.$"
# 965 "data//maps/Route110/scripts.pory"

# 966 "data//maps/Route110/scripts.pory"
Route110_Text_KeepAnEyeOutForRival:
# 967 "data//maps/Route110/scripts.pory"
	.string "PROF. BIRCH: {PLAYER}{KUN}…\p"
# 968 "data//maps/Route110/scripts.pory"
	.string "Please keep an eye out for my {RIVAL}.\n"
# 969 "data//maps/Route110/scripts.pory"
	.string "… … … … … …\p"
# 970 "data//maps/Route110/scripts.pory"
	.string "Well, I had better get going.\n"
# 971 "data//maps/Route110/scripts.pory"
	.string "See you again, {PLAYER}{KUN}!$"
