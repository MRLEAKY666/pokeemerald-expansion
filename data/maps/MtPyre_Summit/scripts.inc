# 1 "data//maps/MtPyre_Summit/scripts.pory"

# 2 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_MapScripts::
# 3 "data//maps/MtPyre_Summit/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_OnTransition
# 4 "data//maps/MtPyre_Summit/scripts.pory"
	.byte 0
# 5 "data//maps/MtPyre_Summit/scripts.pory"

# 6 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_OnTransition:
# 7 "data//maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_MT_PYRE_STATE, 2, MtPyre_Summit_EventScript_SetArchieMaxiePositions
# 8 "data//maps/MtPyre_Summit/scripts.pory"
	end
# 9 "data//maps/MtPyre_Summit/scripts.pory"

# 10 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_SetArchieMaxiePositions::
# 11 "data//maps/MtPyre_Summit/scripts.pory"
	setobjectxyperm LOCALID_MT_PYRE_SUMMIT_MAXIE, 23, 6
# 12 "data//maps/MtPyre_Summit/scripts.pory"
	setobjectxyperm LOCALID_MT_PYRE_SUMMIT_ARCHIE, 22, 6
# 13 "data//maps/MtPyre_Summit/scripts.pory"
	end
# 14 "data//maps/MtPyre_Summit/scripts.pory"

# 15 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_TeamAquaTrigger0::
# 16 "data//maps/MtPyre_Summit/scripts.pory"
	lockall
# 17 "data//maps/MtPyre_Summit/scripts.pory"
	setvar VAR_0x8008, 0
# 18 "data//maps/MtPyre_Summit/scripts.pory"
	goto MtPyre_Summit_EventScript_TeamAquaExits
# 19 "data//maps/MtPyre_Summit/scripts.pory"
	end
# 20 "data//maps/MtPyre_Summit/scripts.pory"

# 21 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_TeamAquaTrigger1::
# 22 "data//maps/MtPyre_Summit/scripts.pory"
	lockall
# 23 "data//maps/MtPyre_Summit/scripts.pory"
	setvar VAR_0x8008, 1
# 24 "data//maps/MtPyre_Summit/scripts.pory"
	goto MtPyre_Summit_EventScript_TeamAquaExits
# 25 "data//maps/MtPyre_Summit/scripts.pory"
	end
# 26 "data//maps/MtPyre_Summit/scripts.pory"

# 27 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_TeamAquaTrigger2::
# 28 "data//maps/MtPyre_Summit/scripts.pory"
	lockall
# 29 "data//maps/MtPyre_Summit/scripts.pory"
	setvar VAR_0x8008, 2
# 30 "data//maps/MtPyre_Summit/scripts.pory"
	goto MtPyre_Summit_EventScript_TeamAquaExits
# 31 "data//maps/MtPyre_Summit/scripts.pory"
	end
# 32 "data//maps/MtPyre_Summit/scripts.pory"

# 33 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_TeamAquaExits::
# 34 "data//maps/MtPyre_Summit/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 35 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 36 "data//maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 37 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterDown
# 38 "data//maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 39 "data//maps/MtPyre_Summit/scripts.pory"
	delay 50
# 40 "data//maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieFacePlayer0
# 41 "data//maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieFacePlayer1
# 42 "data//maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieFacePlayer2
# 43 "data//maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_ArchieAttack, MSGBOX_DEFAULT
# 44 "data//maps/MtPyre_Summit/scripts.pory"
	trainerbattle_no_intro TRAINER_ARCHIE_MT_PYRE_SUMMIT, MtPyre_Summit_Text_ArchieDefeat
# 45 "data//maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo, MSGBOX_DEFAULT
# 46 "data//maps/MtPyre_Summit/scripts.pory"
	closemessage
# 47 "data//maps/MtPyre_Summit/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 48 "data//maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_MT_PYRE_SUMMIT_ARCHIE
# 49 "data//maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_1
# 50 "data//maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_2
# 51 "data//maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_3
# 52 "data//maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_4
# 53 "data//maps/MtPyre_Summit/scripts.pory"
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
# 54 "data//maps/MtPyre_Summit/scripts.pory"
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
# 55 "data//maps/MtPyre_Summit/scripts.pory"
	fadedefaultbgm
# 56 "data//maps/MtPyre_Summit/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 57 "data//maps/MtPyre_Summit/scripts.pory"
	delay 20
# 58 "data//maps/MtPyre_Summit/scripts.pory"
	setvar VAR_MT_PYRE_STATE, 1
# 59 "data//maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_OldLadyApproachPlayer0
# 60 "data//maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_OldLadyApproachPlayer1
# 61 "data//maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_OldLadyApproachPlayer2
# 62 "data//maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis, MSGBOX_DEFAULT
# 63 "data//maps/MtPyre_Summit/scripts.pory"
	giveitem ITEM_MAGMA_EMBLEM
# 64 "data//maps/MtPyre_Summit/scripts.pory"
	setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
# 65 "data//maps/MtPyre_Summit/scripts.pory"
	setflag FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
# 66 "data//maps/MtPyre_Summit/scripts.pory"
	releaseall
# 67 "data//maps/MtPyre_Summit/scripts.pory"
	end
# 68 "data//maps/MtPyre_Summit/scripts.pory"

# 69 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieFacePlayer0::
# 70 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer0
# 71 "data//maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 72 "data//maps/MtPyre_Summit/scripts.pory"
	return
# 73 "data//maps/MtPyre_Summit/scripts.pory"

# 74 "data//maps/MtPyre_Summit/scripts.pory"
@ Archie is already facing player
# 75 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieFacePlayer1::
# 76 "data//maps/MtPyre_Summit/scripts.pory"
	return
# 77 "data//maps/MtPyre_Summit/scripts.pory"

# 78 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieFacePlayer2::
# 79 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer2
# 80 "data//maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 81 "data//maps/MtPyre_Summit/scripts.pory"
	return
# 82 "data//maps/MtPyre_Summit/scripts.pory"

# 83 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLadyApproachPlayer0::
# 84 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer0
# 85 "data//maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 86 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 87 "data//maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 88 "data//maps/MtPyre_Summit/scripts.pory"
	return
# 89 "data//maps/MtPyre_Summit/scripts.pory"

# 90 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLadyApproachPlayer1::
# 91 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer1
# 92 "data//maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 93 "data//maps/MtPyre_Summit/scripts.pory"
	return
# 94 "data//maps/MtPyre_Summit/scripts.pory"

# 95 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLadyApproachPlayer2::
# 96 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer2
# 97 "data//maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 98 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 99 "data//maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 100 "data//maps/MtPyre_Summit/scripts.pory"
	return
# 101 "data//maps/MtPyre_Summit/scripts.pory"

# 102 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_OldLadyApproachPlayer0:
# 103 "data//maps/MtPyre_Summit/scripts.pory"
	walk_down
# 104 "data//maps/MtPyre_Summit/scripts.pory"
	walk_down
# 105 "data//maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_left
# 106 "data//maps/MtPyre_Summit/scripts.pory"
	step_end
# 107 "data//maps/MtPyre_Summit/scripts.pory"

# 108 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_OldLadyApproachPlayer1:
# 109 "data//maps/MtPyre_Summit/scripts.pory"
	walk_down
# 110 "data//maps/MtPyre_Summit/scripts.pory"
	step_end
# 111 "data//maps/MtPyre_Summit/scripts.pory"

# 112 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_OldLadyApproachPlayer2:
# 113 "data//maps/MtPyre_Summit/scripts.pory"
	walk_down
# 114 "data//maps/MtPyre_Summit/scripts.pory"
	walk_down
# 115 "data//maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_right
# 116 "data//maps/MtPyre_Summit/scripts.pory"
	step_end
# 117 "data//maps/MtPyre_Summit/scripts.pory"

# 118 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_ArchieFacePlayer0:
# 119 "data//maps/MtPyre_Summit/scripts.pory"
	walk_left
# 120 "data//maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_down
# 121 "data//maps/MtPyre_Summit/scripts.pory"
	step_end
# 122 "data//maps/MtPyre_Summit/scripts.pory"

# 123 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_ArchieFacePlayer2:
# 124 "data//maps/MtPyre_Summit/scripts.pory"
	walk_right
# 125 "data//maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_down
# 126 "data//maps/MtPyre_Summit/scripts.pory"
	step_end
# 127 "data//maps/MtPyre_Summit/scripts.pory"

# 128 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldMan::
# 129 "data//maps/MtPyre_Summit/scripts.pory"
	lock
# 130 "data//maps/MtPyre_Summit/scripts.pory"
	faceplayer
# 131 "data//maps/MtPyre_Summit/scripts.pory"
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, MtPyre_Summit_EventScript_OldManAfterRayquaza
# 132 "data//maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_WillYouHearOutMyTale, MSGBOX_YESNO
# 133 "data//maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManTale
# 134 "data//maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
# 135 "data//maps/MtPyre_Summit/scripts.pory"
	release
# 136 "data//maps/MtPyre_Summit/scripts.pory"
	end
# 137 "data//maps/MtPyre_Summit/scripts.pory"

# 138 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldManAfterRayquaza::
# 139 "data//maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_HearTheNewLegendOfHoenn, MSGBOX_YESNO
# 140 "data//maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManNewTale
# 141 "data//maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
# 142 "data//maps/MtPyre_Summit/scripts.pory"
	release
# 143 "data//maps/MtPyre_Summit/scripts.pory"
	end
# 144 "data//maps/MtPyre_Summit/scripts.pory"

# 145 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldManTale::
# 146 "data//maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_GroudonKyogreTale, MSGBOX_DEFAULT
# 147 "data//maps/MtPyre_Summit/scripts.pory"
	return
# 148 "data//maps/MtPyre_Summit/scripts.pory"

# 149 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_DeclineOldManTale::
# 150 "data//maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_WellThatTooIsFine, MSGBOX_DEFAULT
# 151 "data//maps/MtPyre_Summit/scripts.pory"
	return
# 152 "data//maps/MtPyre_Summit/scripts.pory"

# 153 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldManNewTale::
# 154 "data//maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_HoennTrioTale, MSGBOX_DEFAULT
# 155 "data//maps/MtPyre_Summit/scripts.pory"
	return
# 156 "data//maps/MtPyre_Summit/scripts.pory"

# 157 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLady::
# 158 "data//maps/MtPyre_Summit/scripts.pory"
	lock
# 159 "data//maps/MtPyre_Summit/scripts.pory"
	faceplayer
# 160 "data//maps/MtPyre_Summit/scripts.pory"
	goto_if_set FLAG_RETURNED_RED_OR_BLUE_ORB, MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned
# 161 "data//maps/MtPyre_Summit/scripts.pory"
	call_if_ge VAR_MT_PYRE_STATE, 3, MtPyre_Summit_EventScript_OldLadyOrbsReturned
# 162 "data//maps/MtPyre_Summit/scripts.pory"
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, MtPyre_Summit_EventScript_OldLadyLegendariesAwake
# 163 "data//maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_OrbsHaveBeenTaken, MSGBOX_DEFAULT
# 164 "data//maps/MtPyre_Summit/scripts.pory"
	release
# 165 "data//maps/MtPyre_Summit/scripts.pory"
	end
# 166 "data//maps/MtPyre_Summit/scripts.pory"

# 167 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLadyOrbsReturned::
# 168 "data//maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs, MSGBOX_DEFAULT
# 169 "data//maps/MtPyre_Summit/scripts.pory"
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
# 170 "data//maps/MtPyre_Summit/scripts.pory"
	release
# 171 "data//maps/MtPyre_Summit/scripts.pory"
	end
# 172 "data//maps/MtPyre_Summit/scripts.pory"

# 173 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLadyLegendariesAwake::
# 174 "data//maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_GroudonKyogreAwakened, MSGBOX_DEFAULT
# 175 "data//maps/MtPyre_Summit/scripts.pory"
	release
# 176 "data//maps/MtPyre_Summit/scripts.pory"
	end
# 177 "data//maps/MtPyre_Summit/scripts.pory"

# 178 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned::
# 179 "data//maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_SuperAncientPokemonTaughtUs, MSGBOX_DEFAULT
# 180 "data//maps/MtPyre_Summit/scripts.pory"
	release
# 181 "data//maps/MtPyre_Summit/scripts.pory"
	end
# 182 "data//maps/MtPyre_Summit/scripts.pory"

# 183 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieTrigger0::
# 184 "data//maps/MtPyre_Summit/scripts.pory"
	lockall
# 185 "data//maps/MtPyre_Summit/scripts.pory"
	setvar VAR_0x8008, 0
# 186 "data//maps/MtPyre_Summit/scripts.pory"
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
# 187 "data//maps/MtPyre_Summit/scripts.pory"
	end
# 188 "data//maps/MtPyre_Summit/scripts.pory"

# 189 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieTrigger1::
# 190 "data//maps/MtPyre_Summit/scripts.pory"
	lockall
# 191 "data//maps/MtPyre_Summit/scripts.pory"
	setvar VAR_0x8008, 1
# 192 "data//maps/MtPyre_Summit/scripts.pory"
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
# 193 "data//maps/MtPyre_Summit/scripts.pory"
	end
# 194 "data//maps/MtPyre_Summit/scripts.pory"

# 195 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieTrigger2::
# 196 "data//maps/MtPyre_Summit/scripts.pory"
	lockall
# 197 "data//maps/MtPyre_Summit/scripts.pory"
	setvar VAR_0x8008, 2
# 198 "data//maps/MtPyre_Summit/scripts.pory"
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
# 199 "data//maps/MtPyre_Summit/scripts.pory"
	end
# 200 "data//maps/MtPyre_Summit/scripts.pory"

# 201 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs::
# 202 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 203 "data//maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 204 "data//maps/MtPyre_Summit/scripts.pory"
	delay 60
# 205 "data//maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieMaxieBeginExit0
# 206 "data//maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieMaxieBeginExit1
# 207 "data//maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieMaxieBeginExit2
# 208 "data//maps/MtPyre_Summit/scripts.pory"
	playse SE_PIN
# 209 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, Common_Movement_ExclamationMark
# 210 "data//maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 211 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, Common_Movement_Delay48
# 212 "data//maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 213 "data//maps/MtPyre_Summit/scripts.pory"
	delay 30
# 214 "data//maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachPlayer0
# 215 "data//maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachPlayer1
# 216 "data//maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachPlayer2
# 217 "data//maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_MaxieSilence, MSGBOX_DEFAULT
# 218 "data//maps/MtPyre_Summit/scripts.pory"
	closemessage
# 219 "data//maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachArchie0
# 220 "data//maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachArchie1
# 221 "data//maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachArchie2
# 222 "data//maps/MtPyre_Summit/scripts.pory"
	delay 30
# 223 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
# 224 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
# 225 "data//maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 226 "data//maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_MT_PYRE_SUMMIT_ARCHIE
# 227 "data//maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_MT_PYRE_SUMMIT_MAXIE
# 228 "data//maps/MtPyre_Summit/scripts.pory"
	setvar VAR_MT_PYRE_STATE, 3
# 229 "data//maps/MtPyre_Summit/scripts.pory"
	releaseall
# 230 "data//maps/MtPyre_Summit/scripts.pory"
	end
# 231 "data//maps/MtPyre_Summit/scripts.pory"

# 232 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieBeginExit0::
# 233 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0
# 234 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
# 235 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
# 236 "data//maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 237 "data//maps/MtPyre_Summit/scripts.pory"
	return
# 238 "data//maps/MtPyre_Summit/scripts.pory"

# 239 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieBeginExit1::
# 240 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1
# 241 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
# 242 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
# 243 "data//maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 244 "data//maps/MtPyre_Summit/scripts.pory"
	return
# 245 "data//maps/MtPyre_Summit/scripts.pory"

# 246 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieBeginExit2::
# 247 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2
# 248 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
# 249 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
# 250 "data//maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 251 "data//maps/MtPyre_Summit/scripts.pory"
	return
# 252 "data//maps/MtPyre_Summit/scripts.pory"

# 253 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_MaxieApproachPlayer0::
# 254 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie0
# 255 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
# 256 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer0
# 257 "data//maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 258 "data//maps/MtPyre_Summit/scripts.pory"
	return
# 259 "data//maps/MtPyre_Summit/scripts.pory"

# 260 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_MaxieApproachPlayer1::
# 261 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
# 262 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
# 263 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer1
# 264 "data//maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 265 "data//maps/MtPyre_Summit/scripts.pory"
	return
# 266 "data//maps/MtPyre_Summit/scripts.pory"

# 267 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_MaxieApproachPlayer2::
# 268 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
# 269 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
# 270 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer2
# 271 "data//maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 272 "data//maps/MtPyre_Summit/scripts.pory"
	return
# 273 "data//maps/MtPyre_Summit/scripts.pory"

# 274 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_MaxieApproachArchie0::
# 275 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
# 276 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie0
# 277 "data//maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 278 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
# 279 "data//maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 280 "data//maps/MtPyre_Summit/scripts.pory"
	return
# 281 "data//maps/MtPyre_Summit/scripts.pory"

# 282 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_MaxieApproachArchie1::
# 283 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
# 284 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie1
# 285 "data//maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 286 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
# 287 "data//maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 288 "data//maps/MtPyre_Summit/scripts.pory"
	return
# 289 "data//maps/MtPyre_Summit/scripts.pory"

# 290 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_MaxieApproachArchie2::
# 291 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
# 292 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie2
# 293 "data//maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 294 "data//maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
# 295 "data//maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 296 "data//maps/MtPyre_Summit/scripts.pory"
	return
# 297 "data//maps/MtPyre_Summit/scripts.pory"

# 298 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PlayerFaceMaxie0:
# 299 "data//maps/MtPyre_Summit/scripts.pory"
	delay_16
# 300 "data//maps/MtPyre_Summit/scripts.pory"
	delay_16
# 301 "data//maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_right
# 302 "data//maps/MtPyre_Summit/scripts.pory"
	step_end
# 303 "data//maps/MtPyre_Summit/scripts.pory"

# 304 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PlayerFaceMaxie:
# 305 "data//maps/MtPyre_Summit/scripts.pory"
	delay_16
# 306 "data//maps/MtPyre_Summit/scripts.pory"
	delay_16
# 307 "data//maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_left
# 308 "data//maps/MtPyre_Summit/scripts.pory"
	step_end
# 309 "data//maps/MtPyre_Summit/scripts.pory"

# 310 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_ArchieExit:
# 311 "data//maps/MtPyre_Summit/scripts.pory"
	walk_down
# 312 "data//maps/MtPyre_Summit/scripts.pory"
	walk_down
# 313 "data//maps/MtPyre_Summit/scripts.pory"
	walk_down
# 314 "data//maps/MtPyre_Summit/scripts.pory"
	walk_down
# 315 "data//maps/MtPyre_Summit/scripts.pory"
	walk_down
# 316 "data//maps/MtPyre_Summit/scripts.pory"
	walk_down
# 317 "data//maps/MtPyre_Summit/scripts.pory"
	step_end
# 318 "data//maps/MtPyre_Summit/scripts.pory"

# 319 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieExit:
# 320 "data//maps/MtPyre_Summit/scripts.pory"
	walk_down
# 321 "data//maps/MtPyre_Summit/scripts.pory"
	walk_down
# 322 "data//maps/MtPyre_Summit/scripts.pory"
	walk_down
# 323 "data//maps/MtPyre_Summit/scripts.pory"
	walk_down
# 324 "data//maps/MtPyre_Summit/scripts.pory"
	walk_down
# 325 "data//maps/MtPyre_Summit/scripts.pory"
	walk_down
# 326 "data//maps/MtPyre_Summit/scripts.pory"
	step_end
# 327 "data//maps/MtPyre_Summit/scripts.pory"

# 328 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0:
# 329 "data//maps/MtPyre_Summit/scripts.pory"
	delay_16
# 330 "data//maps/MtPyre_Summit/scripts.pory"
	delay_8
# 331 "data//maps/MtPyre_Summit/scripts.pory"
	walk_left
# 332 "data//maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_right
# 333 "data//maps/MtPyre_Summit/scripts.pory"
	delay_16
# 334 "data//maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_down
# 335 "data//maps/MtPyre_Summit/scripts.pory"
	step_end
# 336 "data//maps/MtPyre_Summit/scripts.pory"

# 337 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1:
# 338 "data//maps/MtPyre_Summit/scripts.pory"
	delay_16
# 339 "data//maps/MtPyre_Summit/scripts.pory"
	delay_8
# 340 "data//maps/MtPyre_Summit/scripts.pory"
	walk_right
# 341 "data//maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_left
# 342 "data//maps/MtPyre_Summit/scripts.pory"
	delay_16
# 343 "data//maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_down
# 344 "data//maps/MtPyre_Summit/scripts.pory"
	step_end
# 345 "data//maps/MtPyre_Summit/scripts.pory"

# 346 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2:
# 347 "data//maps/MtPyre_Summit/scripts.pory"
	delay_16
# 348 "data//maps/MtPyre_Summit/scripts.pory"
	delay_8
# 349 "data//maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_left
# 350 "data//maps/MtPyre_Summit/scripts.pory"
	delay_16
# 351 "data//maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_down
# 352 "data//maps/MtPyre_Summit/scripts.pory"
	step_end
# 353 "data//maps/MtPyre_Summit/scripts.pory"

# 354 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieApproachPlayer0:
# 355 "data//maps/MtPyre_Summit/scripts.pory"
	walk_up
# 356 "data//maps/MtPyre_Summit/scripts.pory"
	walk_up
# 357 "data//maps/MtPyre_Summit/scripts.pory"
	walk_up
# 358 "data//maps/MtPyre_Summit/scripts.pory"
	walk_left
# 359 "data//maps/MtPyre_Summit/scripts.pory"
	step_end
# 360 "data//maps/MtPyre_Summit/scripts.pory"

# 361 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieApproachPlayer1:
# 362 "data//maps/MtPyre_Summit/scripts.pory"
	walk_up
# 363 "data//maps/MtPyre_Summit/scripts.pory"
	walk_up
# 364 "data//maps/MtPyre_Summit/scripts.pory"
	walk_up
# 365 "data//maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_right
# 366 "data//maps/MtPyre_Summit/scripts.pory"
	step_end
# 367 "data//maps/MtPyre_Summit/scripts.pory"

# 368 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieApproachPlayer2:
# 369 "data//maps/MtPyre_Summit/scripts.pory"
	walk_up
# 370 "data//maps/MtPyre_Summit/scripts.pory"
	walk_up
# 371 "data//maps/MtPyre_Summit/scripts.pory"
	walk_up
# 372 "data//maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_right
# 373 "data//maps/MtPyre_Summit/scripts.pory"
	step_end
# 374 "data//maps/MtPyre_Summit/scripts.pory"

# 375 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_ArchieWatchMaxie:
# 376 "data//maps/MtPyre_Summit/scripts.pory"
	delay_16
# 377 "data//maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_up
# 378 "data//maps/MtPyre_Summit/scripts.pory"
	step_end
# 379 "data//maps/MtPyre_Summit/scripts.pory"

# 380 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PlayerWatchMaxie:
# 381 "data//maps/MtPyre_Summit/scripts.pory"
	delay_16
# 382 "data//maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_down
# 383 "data//maps/MtPyre_Summit/scripts.pory"
	step_end
# 384 "data//maps/MtPyre_Summit/scripts.pory"

# 385 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieApproachArchie0:
# 386 "data//maps/MtPyre_Summit/scripts.pory"
	walk_down
# 387 "data//maps/MtPyre_Summit/scripts.pory"
	walk_right
# 388 "data//maps/MtPyre_Summit/scripts.pory"
	walk_down
# 389 "data//maps/MtPyre_Summit/scripts.pory"
	walk_down
# 390 "data//maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_left
# 391 "data//maps/MtPyre_Summit/scripts.pory"
	step_end
# 392 "data//maps/MtPyre_Summit/scripts.pory"

# 393 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieApproachArchie1:
# 394 "data//maps/MtPyre_Summit/scripts.pory"
	walk_down
# 395 "data//maps/MtPyre_Summit/scripts.pory"
	walk_down
# 396 "data//maps/MtPyre_Summit/scripts.pory"
	walk_down
# 397 "data//maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_left
# 398 "data//maps/MtPyre_Summit/scripts.pory"
	step_end
# 399 "data//maps/MtPyre_Summit/scripts.pory"

# 400 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieApproachArchie2:
# 401 "data//maps/MtPyre_Summit/scripts.pory"
	walk_down
# 402 "data//maps/MtPyre_Summit/scripts.pory"
	walk_down
# 403 "data//maps/MtPyre_Summit/scripts.pory"
	walk_down
# 404 "data//maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_left
# 405 "data//maps/MtPyre_Summit/scripts.pory"
	step_end
# 406 "data//maps/MtPyre_Summit/scripts.pory"

# 407 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_Grunt1::
# 408 "data//maps/MtPyre_Summit/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_1, MtPyre_Summit_Text_Grunt1Intro, MtPyre_Summit_Text_Grunt1Defeat
# 409 "data//maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
# 410 "data//maps/MtPyre_Summit/scripts.pory"
	end
# 411 "data//maps/MtPyre_Summit/scripts.pory"

# 412 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_Grunt2::
# 413 "data//maps/MtPyre_Summit/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_2, MtPyre_Summit_Text_Grunt2Intro, MtPyre_Summit_Text_Grunt2Defeat
# 414 "data//maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
# 415 "data//maps/MtPyre_Summit/scripts.pory"
	end
# 416 "data//maps/MtPyre_Summit/scripts.pory"

# 417 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_Grunt3::
# 418 "data//maps/MtPyre_Summit/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_3, MtPyre_Summit_Text_Grunt3Intro, MtPyre_Summit_Text_Grunt3Defeat
# 419 "data//maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
# 420 "data//maps/MtPyre_Summit/scripts.pory"
	end
# 421 "data//maps/MtPyre_Summit/scripts.pory"

# 422 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_Grunt4::
# 423 "data//maps/MtPyre_Summit/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_4, MtPyre_Summit_Text_Grunt4Intro, MtPyre_Summit_Text_Grunt4Defeat
# 424 "data//maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
# 425 "data//maps/MtPyre_Summit/scripts.pory"
	end
# 426 "data//maps/MtPyre_Summit/scripts.pory"

# 427 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt1Intro:
# 428 "data//maps/MtPyre_Summit/scripts.pory"
	.string "No! Those TEAM MAGMA goons got\n"
# 429 "data//maps/MtPyre_Summit/scripts.pory"
	.string "here ahead of us!\p"
# 430 "data//maps/MtPyre_Summit/scripts.pory"
	.string "We can't fall behind!$"
# 431 "data//maps/MtPyre_Summit/scripts.pory"

# 432 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt1Defeat:
# 433 "data//maps/MtPyre_Summit/scripts.pory"
	.string "I thought you were one of the MAGMAS\n"
# 434 "data//maps/MtPyre_Summit/scripts.pory"
	.string "who happened to come back…$"
# 435 "data//maps/MtPyre_Summit/scripts.pory"

# 436 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt1PostBattle:
# 437 "data//maps/MtPyre_Summit/scripts.pory"
	.string "Yeah, so you are strong…\n"
# 438 "data//maps/MtPyre_Summit/scripts.pory"
	.string "But there're a lot of us!$"
# 439 "data//maps/MtPyre_Summit/scripts.pory"

# 440 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt2Intro:
# 441 "data//maps/MtPyre_Summit/scripts.pory"
	.string "Hah!\n"
# 442 "data//maps/MtPyre_Summit/scripts.pory"
	.string "Too bad for you!\p"
# 443 "data//maps/MtPyre_Summit/scripts.pory"
	.string "If you came earlier, you only would've\n"
# 444 "data//maps/MtPyre_Summit/scripts.pory"
	.string "had to battle the wimpy TEAM MAGMA.\p"
# 445 "data//maps/MtPyre_Summit/scripts.pory"
	.string "But since you arrived now, you have\n"
# 446 "data//maps/MtPyre_Summit/scripts.pory"
	.string "to take on us toughies!$"
# 447 "data//maps/MtPyre_Summit/scripts.pory"

# 448 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt2Defeat:
# 449 "data//maps/MtPyre_Summit/scripts.pory"
	.string "Urgh… I should've let you take on\n"
# 450 "data//maps/MtPyre_Summit/scripts.pory"
	.string "TEAM MAGMA first…$"
# 451 "data//maps/MtPyre_Summit/scripts.pory"

# 452 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt2PostBattle:
# 453 "data//maps/MtPyre_Summit/scripts.pory"
	.string "You don't know anything!\n"
# 454 "data//maps/MtPyre_Summit/scripts.pory"
	.string "So why are you messing with us?$"
# 455 "data//maps/MtPyre_Summit/scripts.pory"

# 456 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt3Intro:
# 457 "data//maps/MtPyre_Summit/scripts.pory"
	.string "You…\n"
# 458 "data//maps/MtPyre_Summit/scripts.pory"
	.string "We saw you at MT. CHIMNEY.\p"
# 459 "data//maps/MtPyre_Summit/scripts.pory"
	.string "You don't belong to either TEAM,\n"
# 460 "data//maps/MtPyre_Summit/scripts.pory"
	.string "so why would you be here?$"
# 461 "data//maps/MtPyre_Summit/scripts.pory"

# 462 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt3Defeat:
# 463 "data//maps/MtPyre_Summit/scripts.pory"
	.string "If you're going to mess with anyone,\n"
# 464 "data//maps/MtPyre_Summit/scripts.pory"
	.string "let it be TEAM MAGMA…$"
# 465 "data//maps/MtPyre_Summit/scripts.pory"

# 466 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt3PostBattle:
# 467 "data//maps/MtPyre_Summit/scripts.pory"
	.string "Heh, it doesn't matter!\n"
# 468 "data//maps/MtPyre_Summit/scripts.pory"
	.string "We bought ourselves some time!\p"
# 469 "data//maps/MtPyre_Summit/scripts.pory"
	.string "The BOSS should have snatched what\n"
# 470 "data//maps/MtPyre_Summit/scripts.pory"
	.string "he was after!$"
# 471 "data//maps/MtPyre_Summit/scripts.pory"

# 472 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt4Intro:
# 473 "data//maps/MtPyre_Summit/scripts.pory"
	.string "Oh, I know!\n"
# 474 "data//maps/MtPyre_Summit/scripts.pory"
	.string "You tried to join TEAM MAGMA,\l"
# 475 "data//maps/MtPyre_Summit/scripts.pory"
	.string "but they wouldn't have you!\p"
# 476 "data//maps/MtPyre_Summit/scripts.pory"
	.string "Well, don't think that we'll let you\n"
# 477 "data//maps/MtPyre_Summit/scripts.pory"
	.string "join our TEAM AQUA!$"
# 478 "data//maps/MtPyre_Summit/scripts.pory"

# 479 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt4Defeat:
# 480 "data//maps/MtPyre_Summit/scripts.pory"
	.string "If you want to join TEAM AQUA that\n"
# 481 "data//maps/MtPyre_Summit/scripts.pory"
	.string "badly, we can consider it…$"
# 482 "data//maps/MtPyre_Summit/scripts.pory"

# 483 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt4PostBattle:
# 484 "data//maps/MtPyre_Summit/scripts.pory"
	.string "We have a great combination going\n"
# 485 "data//maps/MtPyre_Summit/scripts.pory"
	.string "with us members and our leader.$"
# 486 "data//maps/MtPyre_Summit/scripts.pory"

# 487 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_ArchieAttack:
# 488 "data//maps/MtPyre_Summit/scripts.pory"
	.string "Huh . . . ?\p"
# 489 "data//maps/MtPyre_Summit/scripts.pory"
	.string "You're following me around?\p"
# 490 "data//maps/MtPyre_Summit/scripts.pory"
	.string "Who do you think you are?\n"
# 491 "data//maps/MtPyre_Summit/scripts.pory"
	.string "Some kind of baby genius cop?\p"
# 492 "data//maps/MtPyre_Summit/scripts.pory"
	.string "I'll squash you!$"
# 493 "data//maps/MtPyre_Summit/scripts.pory"

# 494 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_ArchieDefeat:
# 495 "data//maps/MtPyre_Summit/scripts.pory"
	.string "You rat!\n"
# 496 "data//maps/MtPyre_Summit/scripts.pory"
	.string "You are so annoying!$"
# 497 "data//maps/MtPyre_Summit/scripts.pory"

# 498 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo:
# 499 "data//maps/MtPyre_Summit/scripts.pory"
	.string "ARCHIE: You defeated me . . .\n"
# 500 "data//maps/MtPyre_Summit/scripts.pory"
	.string "but this battle was inconsequential!\p"
# 501 "data//maps/MtPyre_Summit/scripts.pory"
	.string "I already have the RED ORB\n"
# 502 "data//maps/MtPyre_Summit/scripts.pory"
	.string "in my possession!\p"
# 503 "data//maps/MtPyre_Summit/scripts.pory"
	.string "Fufufu… Now we can bring our ultimate\n"
# 504 "data//maps/MtPyre_Summit/scripts.pory"
	.string "objective to fruition!\p"
# 505 "data//maps/MtPyre_Summit/scripts.pory"
	.string "Okay, TEAM!\n"
# 506 "data//maps/MtPyre_Summit/scripts.pory"
	.string "We're pulling out!$"
# 507 "data//maps/MtPyre_Summit/scripts.pory"

# 508 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis:
# 509 "data//maps/MtPyre_Summit/scripts.pory"
	.string "Oh, no…\n"
# 510 "data//maps/MtPyre_Summit/scripts.pory"
	.string "This cannot happen…\p"
# 511 "data//maps/MtPyre_Summit/scripts.pory"
	.string "Not only the BLUE ORB, but even\n"
# 512 "data//maps/MtPyre_Summit/scripts.pory"
	.string "the RED ORB has been taken…\p"
# 513 "data//maps/MtPyre_Summit/scripts.pory"
	.string "The BLUE ORB and RED ORB must never\n"
# 514 "data//maps/MtPyre_Summit/scripts.pory"
	.string "be separated. They belong together.\p"
# 515 "data//maps/MtPyre_Summit/scripts.pory"
	.string "What are those men trying to do with\n"
# 516 "data//maps/MtPyre_Summit/scripts.pory"
	.string "the two ORBS?\p"
# 517 "data//maps/MtPyre_Summit/scripts.pory"
	.string "… … … … … …\n"
# 518 "data//maps/MtPyre_Summit/scripts.pory"
	.string "… … … … … …\p"
# 519 "data//maps/MtPyre_Summit/scripts.pory"
	.string "Oh, yes. Was it TEAM MAGMA who came\n"
# 520 "data//maps/MtPyre_Summit/scripts.pory"
	.string "and took the BLUE ORB first?\p"
# 521 "data//maps/MtPyre_Summit/scripts.pory"
	.string "Well, in their haste, they left this\n"
# 522 "data//maps/MtPyre_Summit/scripts.pory"
	.string "behind.\p"
# 523 "data//maps/MtPyre_Summit/scripts.pory"
	.string "I couldn't imagine what exactly it\n"
# 524 "data//maps/MtPyre_Summit/scripts.pory"
	.string "could be.\p"
# 525 "data//maps/MtPyre_Summit/scripts.pory"
	.string "I would like you to have it.\n"
# 526 "data//maps/MtPyre_Summit/scripts.pory"
	.string "Perhaps it will be useful in some way.$"
# 527 "data//maps/MtPyre_Summit/scripts.pory"

# 528 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_OrbsHaveBeenTaken:
# 529 "data//maps/MtPyre_Summit/scripts.pory"
	.string "The BLUE ORB and RED ORB taken by\n"
# 530 "data//maps/MtPyre_Summit/scripts.pory"
	.string "those sinister men…\p"
# 531 "data//maps/MtPyre_Summit/scripts.pory"
	.string "They must never be apart…\n"
# 532 "data//maps/MtPyre_Summit/scripts.pory"
	.string "I fear something terrible will happen…$"
# 533 "data//maps/MtPyre_Summit/scripts.pory"

# 534 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_GroudonKyogreAwakened:
# 535 "data//maps/MtPyre_Summit/scripts.pory"
	.string "Oh, my goodness…\p"
# 536 "data//maps/MtPyre_Summit/scripts.pory"
	.string "You say that both GROUDON and KYOGRE\n"
# 537 "data//maps/MtPyre_Summit/scripts.pory"
	.string "have been awakened?\p"
# 538 "data//maps/MtPyre_Summit/scripts.pory"
	.string "It is said that the BLUE ORB and\n"
# 539 "data//maps/MtPyre_Summit/scripts.pory"
	.string "the RED ORB quelled the rage of\l"
# 540 "data//maps/MtPyre_Summit/scripts.pory"
	.string "the two POKéMON…\p"
# 541 "data//maps/MtPyre_Summit/scripts.pory"
	.string "It is also said that the true owner\n"
# 542 "data//maps/MtPyre_Summit/scripts.pory"
	.string "of the ORBS still exists.\p"
# 543 "data//maps/MtPyre_Summit/scripts.pory"
	.string "However, no one knows who, or what\n"
# 544 "data//maps/MtPyre_Summit/scripts.pory"
	.string "exactly, the ORBS belong to.\p"
# 545 "data//maps/MtPyre_Summit/scripts.pory"
	.string "It could be a human, or perhaps\n"
# 546 "data//maps/MtPyre_Summit/scripts.pory"
	.string "a POKéMON, but no one knows.$"
# 547 "data//maps/MtPyre_Summit/scripts.pory"

# 548 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs:
# 549 "data//maps/MtPyre_Summit/scripts.pory"
	.string "The two men who took the ORBS came\n"
# 550 "data//maps/MtPyre_Summit/scripts.pory"
	.string "back to return them on their own.\p"
# 551 "data//maps/MtPyre_Summit/scripts.pory"
	.string "Those men…\n"
# 552 "data//maps/MtPyre_Summit/scripts.pory"
	.string "Perhaps they are not so evil after all…$"
# 553 "data//maps/MtPyre_Summit/scripts.pory"

# 554 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_SuperAncientPokemonTaughtUs:
# 555 "data//maps/MtPyre_Summit/scripts.pory"
	.string "The embodiments of the land, sea,\n"
# 556 "data//maps/MtPyre_Summit/scripts.pory"
	.string "and the sky…\p"
# 557 "data//maps/MtPyre_Summit/scripts.pory"
	.string "That is said to be the identities of\n"
# 558 "data//maps/MtPyre_Summit/scripts.pory"
	.string "the super-ancient POKéMON…\p"
# 559 "data//maps/MtPyre_Summit/scripts.pory"
	.string "In the same way that we humans and\n"
# 560 "data//maps/MtPyre_Summit/scripts.pory"
	.string "POKéMON have life, our world, too,\l"
# 561 "data//maps/MtPyre_Summit/scripts.pory"
	.string "is alive…\p"
# 562 "data//maps/MtPyre_Summit/scripts.pory"
	.string "The super-ancient POKéMON have\n"
# 563 "data//maps/MtPyre_Summit/scripts.pory"
	.string "taught us that…$"
# 564 "data//maps/MtPyre_Summit/scripts.pory"

# 565 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_WillYouHearOutMyTale:
# 566 "data//maps/MtPyre_Summit/scripts.pory"
	.string "MT. PYRE is where we calm the spirits\n"
# 567 "data//maps/MtPyre_Summit/scripts.pory"
	.string "of POKéMON that have passed on…\p"
# 568 "data//maps/MtPyre_Summit/scripts.pory"
	.string "This is a high place where one can\n"
# 569 "data//maps/MtPyre_Summit/scripts.pory"
	.string "see all of HOENN…\p"
# 570 "data//maps/MtPyre_Summit/scripts.pory"
	.string "The disembodied spirits of POKéMON\n"
# 571 "data//maps/MtPyre_Summit/scripts.pory"
	.string "must find solace here…\p"
# 572 "data//maps/MtPyre_Summit/scripts.pory"
	.string "Is it coincidence that you are here…\p"
# 573 "data//maps/MtPyre_Summit/scripts.pory"
	.string "Will you hear out my tale? A tale long\n"
# 574 "data//maps/MtPyre_Summit/scripts.pory"
	.string "told in the HOENN region?$"
# 575 "data//maps/MtPyre_Summit/scripts.pory"

# 576 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_GroudonKyogreTale:
# 577 "data//maps/MtPyre_Summit/scripts.pory"
	.string "It happened long, long ago…\p"
# 578 "data//maps/MtPyre_Summit/scripts.pory"
	.string "The world was wracked by a ferocious\n"
# 579 "data//maps/MtPyre_Summit/scripts.pory"
	.string "clash between the POKéMON of the land\l"
# 580 "data//maps/MtPyre_Summit/scripts.pory"
	.string "and the POKéMON of the sea…\p"
# 581 "data//maps/MtPyre_Summit/scripts.pory"
	.string "The POKéMON of the land raised\n"
# 582 "data//maps/MtPyre_Summit/scripts.pory"
	.string "mountains and created continents…\p"
# 583 "data//maps/MtPyre_Summit/scripts.pory"
	.string "The POKéMON of the sea raised huge\n"
# 584 "data//maps/MtPyre_Summit/scripts.pory"
	.string "waves and carved out oceans…\p"
# 585 "data//maps/MtPyre_Summit/scripts.pory"
	.string "Their fierce duel raged without end.\p"
# 586 "data//maps/MtPyre_Summit/scripts.pory"
	.string "The world was engulfed in massive\n"
# 587 "data//maps/MtPyre_Summit/scripts.pory"
	.string "infernos and vicious storms.\p"
# 588 "data//maps/MtPyre_Summit/scripts.pory"
	.string "The BLUE ORB and the RED ORB brought\n"
# 589 "data//maps/MtPyre_Summit/scripts.pory"
	.string "an end to the calamity.\p"
# 590 "data//maps/MtPyre_Summit/scripts.pory"
	.string "Light poured from the two ORBS and\n"
# 591 "data//maps/MtPyre_Summit/scripts.pory"
	.string "becalmed the enraged adversaries.\p"
# 592 "data//maps/MtPyre_Summit/scripts.pory"
	.string "The pair, made docile, dove deep into\n"
# 593 "data//maps/MtPyre_Summit/scripts.pory"
	.string "the sea where eventually they\l"
# 594 "data//maps/MtPyre_Summit/scripts.pory"
	.string "disappeared…$"
# 595 "data//maps/MtPyre_Summit/scripts.pory"

# 596 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_WellThatTooIsFine:
# 597 "data//maps/MtPyre_Summit/scripts.pory"
	.string "I see…\n"
# 598 "data//maps/MtPyre_Summit/scripts.pory"
	.string "Well, that, too, is fine…$"
# 599 "data//maps/MtPyre_Summit/scripts.pory"

# 600 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_MaxieSilence:
# 601 "data//maps/MtPyre_Summit/scripts.pory"
	.string "MAXIE: {PLAYER}…\p"
# 602 "data//maps/MtPyre_Summit/scripts.pory"
	.string "… … … … … …\n"
# 603 "data//maps/MtPyre_Summit/scripts.pory"
	.string "… … … … … …$"
# 604 "data//maps/MtPyre_Summit/scripts.pory"

# 605 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_HearTheNewLegendOfHoenn:
# 606 "data//maps/MtPyre_Summit/scripts.pory"
	.string "It is my role to pass on the legends\n"
# 607 "data//maps/MtPyre_Summit/scripts.pory"
	.string "of HOENN to future generations.\p"
# 608 "data//maps/MtPyre_Summit/scripts.pory"
	.string "And the crisis that just ended in\n"
# 609 "data//maps/MtPyre_Summit/scripts.pory"
	.string "SOOTOPOLIS rewrote a legend…\p"
# 610 "data//maps/MtPyre_Summit/scripts.pory"
	.string "Have you the time to hear the new\n"
# 611 "data//maps/MtPyre_Summit/scripts.pory"
	.string "legend of HOENN?$"
# 612 "data//maps/MtPyre_Summit/scripts.pory"

# 613 "data//maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_HoennTrioTale:
# 614 "data//maps/MtPyre_Summit/scripts.pory"
	.string "It happened long, long ago…\p"
# 615 "data//maps/MtPyre_Summit/scripts.pory"
	.string "The world was wracked by a ferocious\n"
# 616 "data//maps/MtPyre_Summit/scripts.pory"
	.string "clash between the POKéMON of the land\l"
# 617 "data//maps/MtPyre_Summit/scripts.pory"
	.string "and the POKéMON of the sea…\p"
# 618 "data//maps/MtPyre_Summit/scripts.pory"
	.string "The POKéMON of the land raised\n"
# 619 "data//maps/MtPyre_Summit/scripts.pory"
	.string "mountains and created continents…\p"
# 620 "data//maps/MtPyre_Summit/scripts.pory"
	.string "The POKéMON of the sea raised huge\n"
# 621 "data//maps/MtPyre_Summit/scripts.pory"
	.string "waves and carved out oceans…\p"
# 622 "data//maps/MtPyre_Summit/scripts.pory"
	.string "Their fierce duel raged without end.\p"
# 623 "data//maps/MtPyre_Summit/scripts.pory"
	.string "The world was engulfed in massive\n"
# 624 "data//maps/MtPyre_Summit/scripts.pory"
	.string "fires and vicious storms.\p"
# 625 "data//maps/MtPyre_Summit/scripts.pory"
	.string "It was then that the POKéMON of\n"
# 626 "data//maps/MtPyre_Summit/scripts.pory"
	.string "the sky descended from a storm.\p"
# 627 "data//maps/MtPyre_Summit/scripts.pory"
	.string "The POKéMON, shining a vivid green,\n"
# 628 "data//maps/MtPyre_Summit/scripts.pory"
	.string "becalmed the two enraged POKéMON.\p"
# 629 "data//maps/MtPyre_Summit/scripts.pory"
	.string "Then, its duty done, the green POKéMON\n"
# 630 "data//maps/MtPyre_Summit/scripts.pory"
	.string "flew off into the wild blue yonder…$"
