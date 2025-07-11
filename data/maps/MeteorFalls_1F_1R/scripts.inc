# 1 "data//maps/MeteorFalls_1F_1R/scripts.pory"

# 2 "data//maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_MapScripts::
# 3 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, MeteorFalls_1F_1R_OnLoad
# 4 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.byte 0
# 5 "data//maps/MeteorFalls_1F_1R/scripts.pory"

# 6 "data//maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_OnLoad:
# 7 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	call_if_set FLAG_SYS_GAME_CLEAR, MeteorFalls_1F_1R_EventScript_OpenStevensCave
# 8 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	end
# 9 "data//maps/MeteorFalls_1F_1R/scripts.pory"

# 10 "data//maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_EventScript_OpenStevensCave::
# 11 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	setmetatile 4, 1, METATILE_MeteorFalls_CaveEntrance_Top, TRUE
# 12 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	setmetatile 3, 2, METATILE_MeteorFalls_CaveEntrance_Left, TRUE
# 13 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	setmetatile 4, 2, METATILE_MeteorFalls_CaveEntrance_Bottom, FALSE
# 14 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	setmetatile 5, 2, METATILE_MeteorFalls_CaveEntrance_Right, TRUE
# 15 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	return
# 16 "data//maps/MeteorFalls_1F_1R/scripts.pory"

# 17 "data//maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_EventScript_MagmaStealsMeteoriteScene::
# 18 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	lockall
# 19 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	setflag FLAG_PLATEAU_LEADER_EVENT
# 20 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
# 21 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
# 22 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 23 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	delay 30
# 24 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceDown
# 25 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 26 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_WithThisMeteorite, MSGBOX_DEFAULT
# 27 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	closemessage
# 28 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterUp
# 29 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
# 30 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 31 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	playse SE_PIN
# 32 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_ExclamationMark
# 33 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 34 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_Delay48
# 35 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 36 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_DontExpectMercyFromMagma, MSGBOX_DEFAULT
# 37 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	closemessage
# 38 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, MeteorFalls_1F_1R_Movement_MagmaGruntApproachPlayer
# 39 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 40 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_HoldItRightThereMagma, MSGBOX_DEFAULT
# 41 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	closemessage
# 42 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 43 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterLeft
# 44 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
# 45 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 46 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	addobject LOCALID_METEOR_FALLS_ARCHIE
# 47 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	addobject LOCALID_METEOR_FALLS_AQUA_GRUNT_1
# 48 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	addobject LOCALID_METEOR_FALLS_AQUA_GRUNT_2
# 49 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 50 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieArrive
# 51 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive
# 52 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive
# 53 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 54 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterLeft
# 55 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
# 56 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 57 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua, MSGBOX_DEFAULT
# 58 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	closemessage
# 59 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_PLAYER, MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay
# 60 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit
# 61 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_2, MeteorFalls_1F_1R_Movement_MagmaGrunt2Exit
# 62 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 63 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	removeobject LOCALID_METEOR_FALLS_MAGMA_GRUNT_1
# 64 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	removeobject LOCALID_METEOR_FALLS_MAGMA_GRUNT_2
# 65 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieApproachPlayer
# 66 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 67 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_ArchieSeenYouBefore, MSGBOX_DEFAULT
# 68 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	closemessage
# 69 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie
# 70 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie
# 71 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 72 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma, MSGBOX_DEFAULT
# 73 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_ARCHIE, Common_Movement_WalkInPlaceFasterDown
# 74 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 75 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo, MSGBOX_DEFAULT
# 76 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_ARCHIE, Common_Movement_WalkInPlaceFasterLeft
# 77 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 78 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_ArchieFarewell, MSGBOX_DEFAULT
# 79 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	closemessage
# 80 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieExit
# 81 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1Exit
# 82 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2Exit
# 83 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 84 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	fadedefaultbgm
# 85 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	removeobject LOCALID_METEOR_FALLS_ARCHIE
# 86 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	removeobject LOCALID_METEOR_FALLS_AQUA_GRUNT_1
# 87 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	removeobject LOCALID_METEOR_FALLS_AQUA_GRUNT_2
# 88 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	setflag FLAG_HIDE_ROUTE_112_TEAM_MAGMA
# 89 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	setflag FLAG_MET_ARCHIE_METEOR_FALLS
# 90 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	setflag FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT
# 91 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	setvar VAR_METEOR_FALLS_STATE, 1
# 92 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	releaseall
# 93 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	end
# 94 "data//maps/MeteorFalls_1F_1R/scripts.pory"

# 95 "data//maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_MagmaGruntApproachPlayer:
# 96 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 97 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 98 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_in_place_faster_up
# 99 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 100 "data//maps/MeteorFalls_1F_1R/scripts.pory"

# 101 "data//maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit:
# 102 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_up
# 103 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_up
# 104 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 105 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 106 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 107 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 108 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 109 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 110 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 111 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 112 "data//maps/MeteorFalls_1F_1R/scripts.pory"

# 113 "data//maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_MagmaGrunt2Exit:
# 114 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_up
# 115 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_up
# 116 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_up
# 117 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 118 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 119 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 120 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 121 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 122 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 123 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 124 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 125 "data//maps/MeteorFalls_1F_1R/scripts.pory"

# 126 "data//maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_ArchieArrive:
# 127 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 128 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 129 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 130 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 131 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 132 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 133 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 134 "data//maps/MeteorFalls_1F_1R/scripts.pory"

# 135 "data//maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive:
# 136 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	delay_16
# 137 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	delay_16
# 138 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 139 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 140 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 141 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 142 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 143 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 144 "data//maps/MeteorFalls_1F_1R/scripts.pory"

# 145 "data//maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive:
# 146 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	delay_16
# 147 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	delay_16
# 148 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 149 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 150 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 151 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 152 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 153 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 154 "data//maps/MeteorFalls_1F_1R/scripts.pory"

# 155 "data//maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_ArchieExit:
# 156 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 157 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 158 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 159 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 160 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 161 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 162 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 163 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 164 "data//maps/MeteorFalls_1F_1R/scripts.pory"

# 165 "data//maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_ArchieApproachPlayer:
# 166 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 167 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 168 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_up
# 169 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_up
# 170 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_in_place_faster_left
# 171 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 172 "data//maps/MeteorFalls_1F_1R/scripts.pory"

# 173 "data//maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_AquaGrunt1Exit:
# 174 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_up
# 175 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_up
# 176 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 177 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 178 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 179 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 180 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 181 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 182 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 183 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 184 "data//maps/MeteorFalls_1F_1R/scripts.pory"

# 185 "data//maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie:
# 186 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 187 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 188 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 189 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_in_place_faster_up
# 190 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 191 "data//maps/MeteorFalls_1F_1R/scripts.pory"

# 192 "data//maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_AquaGrunt2Exit:
# 193 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_up
# 194 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_up
# 195 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_up
# 196 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 197 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 198 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 199 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 200 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 201 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 202 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 203 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 204 "data//maps/MeteorFalls_1F_1R/scripts.pory"

# 205 "data//maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie:
# 206 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 207 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 208 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 209 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_in_place_faster_up
# 210 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 211 "data//maps/MeteorFalls_1F_1R/scripts.pory"

# 212 "data//maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay:
# 213 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_in_place_faster_down
# 214 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	delay_4
# 215 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_in_place_faster_right
# 216 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	lock_facing_direction
# 217 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	walk_left
# 218 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	unlock_facing_direction
# 219 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	face_right
# 220 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 221 "data//maps/MeteorFalls_1F_1R/scripts.pory"

# 222 "data//maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_EventScript_ProfCozmo::
# 223 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	lock
# 224 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	faceplayer
# 225 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	goto_if_set FLAG_MET_PROF_COZMO, MeteorFalls_1F_1R_EventScript_MetCozmo
# 226 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	setflag FLAG_MET_PROF_COZMO
# 227 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_MeetProfCozmo, MSGBOX_DEFAULT
# 228 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	release
# 229 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	end
# 230 "data//maps/MeteorFalls_1F_1R/scripts.pory"

# 231 "data//maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_EventScript_MetCozmo::
# 232 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney, MSGBOX_DEFAULT
# 233 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	release
# 234 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	end
# 235 "data//maps/MeteorFalls_1F_1R/scripts.pory"

# 236 "data//maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_WithThisMeteorite:
# 237 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Hehehe!\p"
# 238 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "With this METEORITE, that thing in\n"
# 239 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "MT. CHIMNEY will…$"
# 240 "data//maps/MeteorFalls_1F_1R/scripts.pory"

# 241 "data//maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_DontExpectMercyFromMagma:
# 242 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Heh?\p"
# 243 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "I don't know who you are, but if you get\n"
# 244 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "in the way of TEAM MAGMA, don't\l"
# 245 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "expect any mercy!$"
# 246 "data//maps/MeteorFalls_1F_1R/scripts.pory"

# 247 "data//maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_HoldItRightThereMagma:
# 248 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Hold it right there, TEAM MAGMA!\p"
# 249 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "You're badly mistaken if you think you\n"
# 250 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "can have your way with the world!$"
# 251 "data//maps/MeteorFalls_1F_1R/scripts.pory"

# 252 "data//maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua:
# 253 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Hehehe!\n"
# 254 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Even TEAM AQUA joins us!\p"
# 255 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "But it's too much trouble to deal with\n"
# 256 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "you all…\p"
# 257 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Heh, it doesn't matter!\p"
# 258 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "We've got the METEORITE, so off to\n"
# 259 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "MT. CHIMNEY we go!\p"
# 260 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Hehehe! Be seeing you, you TEAM\n"
# 261 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "AQUA dingbats!$"
# 262 "data//maps/MeteorFalls_1F_1R/scripts.pory"

# 263 "data//maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_ArchieSeenYouBefore:
# 264 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "ARCHIE: Didn't I see you before?\n"
# 265 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "At SLATEPORT's MUSEUM?\p"
# 266 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Ah, so your name is {PLAYER}.\p"
# 267 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "At the time, I thought you were one\n"
# 268 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "of TEAM MAGMA's goons.\p"
# 269 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Humph…\n"
# 270 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "You're one odd kid.\p"
# 271 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "TEAM MAGMA is a dangerous group of\n"
# 272 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "total fanatics.\p"
# 273 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "They engage in destruction, claiming\n"
# 274 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "to expand the land mass.\p"
# 275 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "They are the rivals to us,\n"
# 276 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "the sea-loving TEAM AQUA!$"
# 277 "data//maps/MeteorFalls_1F_1R/scripts.pory"

# 278 "data//maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma:
# 279 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "BOSS, we should give chase to\n"
# 280 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "TEAM MAGMA…$"
# 281 "data//maps/MeteorFalls_1F_1R/scripts.pory"

# 282 "data//maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo:
# 283 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "ARCHIE: Yes, yes, we must!\n"
# 284 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "We've got to hurry.\p"
# 285 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "There's no telling what TEAM MAGMA\n"
# 286 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "will do at MT. CHIMNEY!$"
# 287 "data//maps/MeteorFalls_1F_1R/scripts.pory"

# 288 "data//maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_ArchieFarewell:
# 289 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "ARCHIE: {PLAYER}, you should keep\n"
# 290 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "an eye out for TEAM MAGMA, too.\p"
# 291 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Farewell!$"
# 292 "data//maps/MeteorFalls_1F_1R/scripts.pory"

# 293 "data//maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_MeetProfCozmo:
# 294 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "I… I'm COZMO…\n"
# 295 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "I'm a PROFESSOR…\p"
# 296 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "TEAM MAGMA asked me to guide them\n"
# 297 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "to METEOR FALLS…\p"
# 298 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "But they tricked me.\n"
# 299 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "They even took my METEORITE away…\p"
# 300 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "And then another similar bunch,\n"
# 301 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "TEAM AQUA showed up.\p"
# 302 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "After that…\n"
# 303 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "I don't understand any of it.\p"
# 304 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "But that TEAM MAGMA…\p"
# 305 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "What are they going to do with that\n"
# 306 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "METEORITE at MT. CHIMNEY?$"
# 307 "data//maps/MeteorFalls_1F_1R/scripts.pory"

# 308 "data//maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney:
# 309 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "PROF. COZMO: But that TEAM MAGMA…\p"
# 310 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "What are they going to do with that\n"
# 311 "data//maps/MeteorFalls_1F_1R/scripts.pory"
	.string "METEORITE at MT. CHIMNEY?$"
