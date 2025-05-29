# 1 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 2 "data//maps/LilycoveCity_ContestHall/scripts.pory"
@ All the LOCALID constants used in this file are essentially redundant.
# 3 "data//maps/LilycoveCity_ContestHall/scripts.pory"
@ They're all used to have the NPC the player talked to turn back so they're facing
# 4 "data//maps/LilycoveCity_ContestHall/scripts.pory"
@ their original direction (because they're watching/participating in the contests).
# 5 "data//maps/LilycoveCity_ContestHall/scripts.pory"
@ They could all be substituted for VAR_LAST_TALKED.
# 6 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 7 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_MapScripts::
# 8 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.byte 0
# 9 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 10 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_Boy1::
# 11 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_TodayWonSmartnessContest, MSGBOX_NPC
# 12 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 13 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 14 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_Boy2::
# 15 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_EnteredBunchOfContests, MSGBOX_NPC
# 16 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 17 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 18 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_Girl::
# 19 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks, MSGBOX_NPC
# 20 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 21 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 22 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_Sailor::
# 23 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous, MSGBOX_NPC
# 24 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 25 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 26 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_SmartContestMC::
# 27 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 28 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 29 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal, MSGBOX_DEFAULT
# 30 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 31 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_SMART_MC, Common_Movement_FaceOriginalDirection
# 32 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 33 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 34 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 35 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 36 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_SmartContestJudge::
# 37 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 38 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 39 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest, MSGBOX_DEFAULT
# 40 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 41 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_SMART_JUDGE, Common_Movement_FaceOriginalDirection
# 42 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 43 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 44 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 45 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 46 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_SmartContestant1::
# 47 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 48 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 49 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_EnteredWrongContest, MSGBOX_DEFAULT
# 50 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 51 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_SMART_CONTESTANT_1, Common_Movement_FaceOriginalDirection
# 52 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 53 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 54 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 55 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 56 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_SmartContestant2::
# 57 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 58 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 59 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_RaisedMonToBeSmart, MSGBOX_DEFAULT
# 60 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 61 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_SMART_CONTESTANT_2, Common_Movement_FaceOriginalDirection
# 62 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 63 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 64 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 65 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 66 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_SmartContestant3::
# 67 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 68 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 69 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext, MSGBOX_DEFAULT
# 70 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 71 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_SMART_CONTESTANT_3, Common_Movement_FaceOriginalDirection
# 72 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 73 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 74 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 75 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 76 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_SmartContestant4::
# 77 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 78 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 79 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife, MSGBOX_DEFAULT
# 80 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 81 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_SMART_CONTESTANT_4, Common_Movement_FaceOriginalDirection
# 82 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 83 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 84 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 85 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 86 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_SmartContestAudience1::
# 87 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa, MSGBOX_SIGN
# 88 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 89 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 90 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_SmartContestAudience2::
# 91 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 92 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 93 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves, MSGBOX_DEFAULT
# 94 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 95 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_SMART_AUDIENCE_2, Common_Movement_FaceOriginalDirection
# 96 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 97 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 98 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 99 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 100 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_SmartContestAudience3::
# 101 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 102 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 103 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers, MSGBOX_DEFAULT
# 104 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 105 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_SMART_AUDIENCE_3, Common_Movement_FaceOriginalDirection
# 106 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 107 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 108 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 109 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 110 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_SmartContestAudience4::
# 111 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 112 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 113 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_StillLoveSmartnessContests, MSGBOX_DEFAULT
# 114 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 115 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_SMART_AUDIENCE_4, Common_Movement_FaceOriginalDirection
# 116 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 117 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 118 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 119 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 120 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_BeautyContestMC::
# 121 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 122 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 123 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest, MSGBOX_DEFAULT
# 124 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 125 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_BEAUTY_MC, Common_Movement_FaceOriginalDirection
# 126 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 127 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 128 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 129 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 130 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_BeautyContestJudge::
# 131 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 132 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 133 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty, MSGBOX_DEFAULT
# 134 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 135 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_BEAUTY_JUDGE, Common_Movement_FaceOriginalDirection
# 136 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 137 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 138 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 139 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 140 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_BeautyContestant1::
# 141 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 142 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 143 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty, MSGBOX_DEFAULT
# 144 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 145 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_BEAUTY_CONTESTANT_1, Common_Movement_FaceOriginalDirection
# 146 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 147 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 148 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 149 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 150 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_BeautyContestant2::
# 151 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 152 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 153 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_OverdidGrooming, MSGBOX_DEFAULT
# 154 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 155 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_BEAUTY_CONTESTANT_2, Common_Movement_FaceOriginalDirection
# 156 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 157 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 158 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 159 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 160 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_BeautyContestant3::
# 161 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 162 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 163 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam, MSGBOX_DEFAULT
# 164 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 165 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_BEAUTY_CONTESTANT_3, Common_Movement_FaceOriginalDirection
# 166 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 167 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 168 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 169 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 170 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_BeautyContestant4::
# 171 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 172 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 173 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe, MSGBOX_DEFAULT
# 174 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 175 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_BEAUTY_CONTESTANT_4, Common_Movement_FaceOriginalDirection
# 176 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 177 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 178 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 179 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 180 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_BeautyContestAudience1::
# 181 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 182 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 183 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy, MSGBOX_DEFAULT
# 184 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 185 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_BEAUTY_AUDIENCE_1, Common_Movement_FaceOriginalDirection
# 186 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 187 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 188 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 189 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 190 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_BeautyContestAudience2::
# 191 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 192 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 193 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon, MSGBOX_DEFAULT
# 194 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 195 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_BEAUTY_AUDIENCE_2, Common_Movement_FaceOriginalDirection
# 196 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 197 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 198 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 199 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 200 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_BeautyContestAudience3::
# 201 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 202 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 203 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone, MSGBOX_DEFAULT
# 204 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 205 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_BEAUTY_AUDIENCE_3, Common_Movement_FaceOriginalDirection
# 206 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 207 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 208 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 209 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 210 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_CuteContestMC::
# 211 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 212 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 213 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_InTheMiddleOfContest, MSGBOX_DEFAULT
# 214 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 215 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_CUTE_MC, Common_Movement_FaceOriginalDirection
# 216 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 217 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 218 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 219 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 220 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_CuteContestJudge::
# 221 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 222 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 223 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals, MSGBOX_DEFAULT
# 224 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 225 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_CUTE_JUDGE, Common_Movement_FaceOriginalDirection
# 226 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 227 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 228 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 229 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 230 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_CuteContestant1::
# 231 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 232 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 233 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_MyAzurillWasDistracted, MSGBOX_DEFAULT
# 234 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 235 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_CUTE_CONTESTANT_1, Common_Movement_FaceOriginalDirection
# 236 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 237 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 238 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 239 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 240 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_CuteContestant2::
# 241 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 242 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 243 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_NeverWonBattleButContest, MSGBOX_DEFAULT
# 244 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 245 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_CUTE_CONTESTANT_2, Common_Movement_FaceOriginalDirection
# 246 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 247 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 248 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 249 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 250 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_CuteContestant3::
# 251 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 252 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 253 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_PetalDanceIsMarvel, MSGBOX_DEFAULT
# 254 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 255 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_CUTE_CONTESTANT_3, Common_Movement_FaceOriginalDirection
# 256 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 257 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 258 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 259 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 260 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_CuteContestant4::
# 261 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 262 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 263 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter, MSGBOX_DEFAULT
# 264 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 265 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_CUTE_CONTESTANT_4, Common_Movement_FaceOriginalDirection
# 266 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 267 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 268 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 269 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 270 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_CuteContestAudience1::
# 271 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	lockall
# 272 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FacePlayer
# 273 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 274 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_MyChildIsInContest, MSGBOX_DEFAULT
# 275 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 276 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FaceOriginalDirection
# 277 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 278 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	delay 25
# 279 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_ComeOnDear, MSGBOX_DEFAULT
# 280 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	releaseall
# 281 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 282 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 283 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_CuteContestAudience2::
# 284 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 285 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 286 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn, MSGBOX_DEFAULT
# 287 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 288 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_CUTE_AUDIENCE_2, Common_Movement_FaceOriginalDirection
# 289 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 290 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 291 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 292 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 293 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_CuteContestAudience3::
# 294 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 295 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 296 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest, MSGBOX_DEFAULT
# 297 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 298 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_CUTE_AUDIENCE_3, Common_Movement_FaceOriginalDirection
# 299 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 300 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 301 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 302 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 303 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_BeautyStageSign::
# 304 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_BeautyContestStage, MSGBOX_SIGN
# 305 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 306 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 307 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_CuteStageSign::
# 308 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_CuteContestStage, MSGBOX_SIGN
# 309 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 310 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 311 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_SmartStageSign::
# 312 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_SmartContestStage, MSGBOX_SIGN
# 313 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 314 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 315 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_TodayWonSmartnessContest:
# 316 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "This POKéMON won the BEAUTY CONTEST\n"
# 317 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "here before.\p"
# 318 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Well, guess what? Today, I made it\n"
# 319 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "win a SMARTNESS CONTEST!\p"
# 320 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "My abilities scare even me…$"
# 321 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 322 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_EnteredBunchOfContests:
# 323 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "I've entered a bunch of CONTESTS,\n"
# 324 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "so I'm seeing how things work.\p"
# 325 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "If you're in a COOLNESS CONTEST,\n"
# 326 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "cool moves go over as appeals.\p"
# 327 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "But smart moves and cute moves\n"
# 328 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "don't go over well, for instance.$"
# 329 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 330 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks:
# 331 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "That young man who won earlier had\n"
# 332 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "a whole bunch of different {POKEBLOCK}S.\p"
# 333 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Can you win if you had that many\n"
# 334 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "of those things?$"
# 335 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 336 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous:
# 337 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Whoa, isn't this place humongous!\p"
# 338 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "The tension in the air… It's not\n"
# 339 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "like a CONTEST hall in the sticks.$"
# 340 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 341 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal:
# 342 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "MC: Okay, SMART POKéMON and their\n"
# 343 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "TRAINERS, are you ready?!\p"
# 344 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Give it your best showing!\n"
# 345 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Let's appeal!$"
# 346 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 347 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest:
# 348 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "JUDGE: Are you enjoying this CONTEST?\p"
# 349 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Come back with three friends, and\n"
# 350 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "all of you may enter a CONTEST!$"
# 351 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 352 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_EnteredWrongContest:
# 353 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Ayayayay…\n"
# 354 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "I entered the wrong CONTEST.\p"
# 355 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "I entered this tough POKéMON in\n"
# 356 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "the SMARTNESS CONTEST…\p"
# 357 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Come on, wow them with a smart-looking\n"
# 358 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "ROCK SMASH.$"
# 359 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 360 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_RaisedMonToBeSmart:
# 361 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "I've spent many a year, and all my\n"
# 362 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "wisdom besides, raising this POKéMON\l"
# 363 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "to be smart.\p"
# 364 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "It won't be easily bested by some\n"
# 365 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "young pup's POKéMON.\p"
# 366 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "My dear wife, are you seeing this?$"
# 367 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 368 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext:
# 369 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "There it is!\p"
# 370 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "If my POKéMON pulls a smart move next,\n"
# 371 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "the audience's excitement will peak!$"
# 372 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 373 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife:
# 374 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Oh, dear, no!\p"
# 375 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "My darling ZUBAT's LEECH LIFE is so\n"
# 376 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "cute I kept using it over and over!\p"
# 377 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "But these mean people don't appreciate\n"
# 378 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "it at all!$"
# 379 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 380 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa:
# 381 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Kiyaaah! You're beautiful, Grandpa!$"
# 382 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 383 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves:
# 384 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Even when TRAINERS enter the same\n"
# 385 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "kind of POKéMON, they all seem to use\l"
# 386 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "different moves for appeals.\p"
# 387 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "It's just like the way people have\n"
# 388 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "different styles for battling.$"
# 389 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 390 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers:
# 391 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "I think the POKéMON look smarter\n"
# 392 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "than their TRAINERS. By a lot.$"
# 393 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 394 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_StillLoveSmartnessContests:
# 395 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "When all's said and done, I still love\n"
# 396 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "SMARTNESS CONTESTS.\p"
# 397 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "That intellectual green color…\n"
# 398 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "It's so… So… Cool.$"
# 399 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 400 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest:
# 401 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "MC: Are you entering the BEAUTY\n"
# 402 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "CONTEST, too? Good luck!$"
# 403 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 404 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty:
# 405 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "JUDGE: Ah, every POKéMON here is\n"
# 406 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "a model of pristine beauty!\p"
# 407 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Why, I almost forgot to score them!$"
# 408 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 409 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty:
# 410 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "A POKéMON this beautiful…\n"
# 411 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "There isn't another one like it.\p"
# 412 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Everyone's eyes will be glued to\n"
# 413 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "my beauty.$"
# 414 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 415 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_OverdidGrooming:
# 416 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Waaaah!\p"
# 417 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "I brushed and groomed my POKéMON\n"
# 418 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "carefully for this CONTEST…\p"
# 419 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "But I overdid it…\n"
# 420 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "My POKéMON's coat turned all scraggly…\p"
# 421 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "What should I do?$"
# 422 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 423 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam:
# 424 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "This AURORA BEAM is so dazzling,\n"
# 425 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "the JUDGE won't be able to see it.\p"
# 426 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Uh, wait a second…\n"
# 427 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "That'll be meaningless, then!$"
# 428 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 429 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe:
# 430 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "This pretty POKéMON looks just like\n"
# 431 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "me when I was younger.\p"
# 432 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Right when I said that, my husband\n"
# 433 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "spewed the coffee he was drinking.\p"
# 434 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Did I say something funny?$"
# 435 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 436 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy:
# 437 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "You know, if I win at a BEAUTY\n"
# 438 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "CONTEST, sure it makes me\l"
# 439 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "happy. More than usual, anyway.$"
# 440 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 441 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon:
# 442 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Wahahahah!\p"
# 443 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Will you take a gander at all those\n"
# 444 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "pretty POKéMON!\l"
# 445 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "I just love this sort of glitz!$"
# 446 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 447 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone:
# 448 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "You can't always win on just beauty\n"
# 449 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "alone.\p"
# 450 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "You have to groom your POKéMON so\n"
# 451 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "it's nice and glossy like mine.$"
# 452 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 453 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_InTheMiddleOfContest:
# 454 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "MC: Uh-oh! Hello!\n"
# 455 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "We're in the middle of a CONTEST!\p"
# 456 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Please enter at our registration\n"
# 457 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "counter and come out, okay?$"
# 458 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 459 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals:
# 460 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "JUDGE: Oh, such charming and cute\n"
# 461 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "appeals!\p"
# 462 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Oh, my goodness! What a perfectly\n"
# 463 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "adorable WATER SPORT appeal!$"
# 464 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 465 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_MyAzurillWasDistracted:
# 466 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Oh, no… My sweet AZURILL was\n"
# 467 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "distracted by another POKéMON.$"
# 468 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 469 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_NeverWonBattleButContest:
# 470 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "My POKéMON has never won in a battle,\n"
# 471 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "but put it in a CONTEST and look out!$"
# 472 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 473 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_PetalDanceIsMarvel:
# 474 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "My POKéMON's PETAL DANCE is a marvel\n"
# 475 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "of elegance.\p"
# 476 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "I won't let anyone disturb its\n"
# 477 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "performance.$"
# 478 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 479 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter:
# 480 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Everyone's POKéMON are very cute.\p"
# 481 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "However, if my POKéMON were to make\n"
# 482 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "a cute appeal…\p"
# 483 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "I'm sure that it would be so much \n"
# 484 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "cuter than the others.$"
# 485 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 486 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_MyChildIsInContest:
# 487 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "My child is in this CONTEST.$"
# 488 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 489 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_ComeOnDear:
# 490 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Come on, dear. Go for it!\n"
# 491 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Your POKéMON is the best!$"
# 492 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 493 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest:
# 494 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "I think that girl over there is\n"
# 495 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "the cutest of the lot.\p"
# 496 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "What's that? They're judging\n"
# 497 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "POKéMON by their looks?$"
# 498 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 499 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn:
# 500 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Ohh, seeing all these cute POKéMON,\n"
# 501 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "they make we want to get my own!\p"
# 502 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "I'm going to go catch some!$"
# 503 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 504 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_BeautyContestStage:
# 505 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "BEAUTY CONTEST STAGE\n"
# 506 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "BE ALLURED BY BEAUTIFUL POKéMON!$"
# 507 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 508 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_CuteContestStage:
# 509 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "CUTENESS CONTEST STAGE\n"
# 510 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "BE CHARMED BY CUTE POKéMON!$"
# 511 "data//maps/LilycoveCity_ContestHall/scripts.pory"

# 512 "data//maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_SmartContestStage:
# 513 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "SMARTNESS CONTEST STAGE\n"
# 514 "data//maps/LilycoveCity_ContestHall/scripts.pory"
	.string "BE IMPRESSED BY SMART POKéMON!$"
