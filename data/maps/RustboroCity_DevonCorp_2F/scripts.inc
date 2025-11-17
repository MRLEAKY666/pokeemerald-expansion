# 1 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 2 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_MapScripts::
# 3 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_2F_OnTransition
# 4 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.byte 0
# 5 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 6 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_OnTransition:
# 7 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 8 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 9 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 10 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_SetFossilReady::
# 11 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 2
# 12 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	return
# 13 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 14 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_TalkToPokemonScientist::
# 15 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 16 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 17 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 18 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DeviceForTalkingToPokemon, MSGBOX_DEFAULT
# 19 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 20 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end

RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist::
# 24 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 25 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 26 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 27 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_TechnologyForTMs, MSGBOX_DEFAULT
# 28 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_ACCEPTED_BLANK_DISC_QUEST, RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_11
RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_9:
# 42 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_BLANK_DISC_GIVEN, RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_8
RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_6:
# 76 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_BLANK_DISC_GIVEN, RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_5
RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_1:
# 79 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
	end

RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_2:
# 29 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	delay 30
# 30 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_Text_0, MSGBOX_DEFAULT
# 31 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	getobjectfacingdirection LOCALID_DISC_SCIENTIST, VAR_RESULT
# 32 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, DIR_EAST
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_15
# 36 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_DISC_SCIENTIST, Common_Movement_WalkInPlaceLeft
RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_14:
# 38 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	giveitem ITEM_BLANK_DISC
# 39 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_Text_1, MSGBOX_DEFAULT
# 40 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_BLANK_DISC_GIVEN
	goto RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_1

RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_3:
# 43 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	checkitem ITEM_BLANK_DISC
# 44 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_18
# 49 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	checkpcitem ITEM_BLANK_DISC
# 50 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_21
# 55 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	delay 30
# 56 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_Text_3, MSGBOX_DEFAULT
# 57 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 58 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	delay 60
# 59 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_DISC_SCIENTIST, Common_Movement_ExclamationMark
# 60 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	playse SE_PIN
# 61 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_Text_4
# 62 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitse
# 63 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_Text_5, MSGBOX_DEFAULT
# 64 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	getobjectfacingdirection LOCALID_DISC_SCIENTIST, VAR_RESULT
# 65 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, DIR_EAST
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_25
# 69 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_DISC_SCIENTIST, Common_Movement_WalkInPlaceLeft
RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_24:
# 71 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	giveitem ITEM_BLANK_DISC
# 72 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_Text_6, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_1

RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_4:
# 77 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_Text_7, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_1

RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_5:
# 76 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_BLANK_DISC_DELIVERED, RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_4
	goto RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_1

RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_8:
# 42 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_unset FLAG_BLANK_DISC_DELIVERED, RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_3
	goto RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_6

RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_11:
# 28 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_unset FLAG_BLANK_DISC_GIVEN, RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_2
	goto RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_9

RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_15:
# 33 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_DISC_SCIENTIST, Common_Movement_WalkInPlaceRight
	goto RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_14

RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_18:
# 45 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	delay 30
# 46 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_Text_2, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_1

RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_21:
# 51 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	delay 30
# 52 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_Text_2, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_1

RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_25:
# 66 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_DISC_SCIENTIST, Common_Movement_WalkInPlaceRight
	goto RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_24


# 83 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 84 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 85 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_BallScientist::
# 86 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 87 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 88 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 89 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, RustboroCity_DevonCorp_2F_EventScript_DevelopedBalls
# 90 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopingNewBalls, MSGBOX_DEFAULT
# 91 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 92 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 93 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 94 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_DevelopedBalls::
# 95 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WeFinallyMadeNewBalls, MSGBOX_DEFAULT
# 96 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 97 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 98 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 99 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_PokenavScientist::
# 100 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 101 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 102 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 103 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_DevonCorp_2F_EventScript_HasPokenav
# 104 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_IMadePokenav, MSGBOX_DEFAULT
# 105 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 106 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 107 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 108 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_HasPokenav::
# 109 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WowThatsAPokenav, MSGBOX_DEFAULT
# 110 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 111 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 112 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 113 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_PokemonDreamsScientist::
# 114 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 115 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 116 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 117 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DeviceToVisualizePokemonDreams, MSGBOX_DEFAULT
# 118 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 119 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 120 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 121 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_FossilScientist::
# 122 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 123 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 124 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 2, RustboroCity_DevonCorp_2F_EventScript_FossilMonReady
# 125 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_StillRegenerating
# 126 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopDeviceToResurrectFossils, MSGBOX_DEFAULT
# 127 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	checkitem ITEM_ROOT_FOSSIL
# 128 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeRootFossil
# 129 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	checkitem ITEM_CLAW_FOSSIL
# 130 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeClawFossil
# 131 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 132 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 133 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 134 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
@ This whole section has needless duplication and could be condensed considerably
# 135 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_NoticeRootFossil::
# 136 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 137 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	playse SE_PIN
# 138 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
# 139 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmovement 0
# 140 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
# 141 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmovement 0
# 142 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
# 143 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil
# 144 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	checkitem ITEM_CLAW_FOSSIL
# 145 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
# 146 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_GiveRootFossil
# 147 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 148 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 149 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_GiveRootFossil::
# 150 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_ROOT_FOSSIL
# 151 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
# 152 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	removeitem ITEM_ROOT_FOSSIL
# 153 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
# 154 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_WHICH_FOSSIL_REVIVED, 1
# 155 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 156 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 157 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 158 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_NoticeClawFossil::
# 159 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 160 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	playse SE_PIN
# 161 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
# 162 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmovement 0
# 163 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
# 164 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmovement 0
# 165 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
# 166 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil
# 167 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	checkitem ITEM_ROOT_FOSSIL
# 168 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
# 169 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_GiveClawFossil
# 170 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 171 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 172 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_GiveClawFossil::
# 173 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_CLAW_FOSSIL
# 174 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
# 175 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	removeitem ITEM_CLAW_FOSSIL
# 176 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
# 177 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_WHICH_FOSSIL_REVIVED, 2
# 178 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 179 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 180 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 181 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil::
# 182 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_OhIsThatSo, MSGBOX_DEFAULT
# 183 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 184 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 185 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 186 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_StillRegenerating::
# 187 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_FossilRegeneratorTakesTime, MSGBOX_DEFAULT
# 188 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 189 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 190 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 191 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_FossilMonReady::
# 192 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 1, RustboroCity_DevonCorp_2F_EventScript_LileepReady
# 193 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 2, RustboroCity_DevonCorp_2F_EventScript_AnorithReady
# 194 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 195 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 196 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_LileepReady::
# 197 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_LILEEP
# 198 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
# 199 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveLileep
# 200 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 201 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 202 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_AnorithReady::
# 203 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_ANORITH
# 204 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
# 205 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorith
# 206 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 207 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 208 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveLileep::
# 209 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LILEEP
# 210 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	randompercentage 25
# 211 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_LILEEP, 20, shinyMode=VAR_RESULT
# 212 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepParty
# 213 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepPC
# 214 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 215 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 216 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 217 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepParty::
# 218 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedLileepFanfare
# 219 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 220 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep
# 221 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 222 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 223 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep
# 224 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 225 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 226 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepPC::
# 227 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedLileepFanfare
# 228 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 229 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_TransferLileepToPC
# 230 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 231 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_TransferLileepToPC
# 232 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 233 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 234 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_TransferLileepToPC::
# 235 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_TransferredToPC
# 236 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep
# 237 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 238 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 239 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceivedLileepFanfare::
# 240 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_LILEEP
# 241 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 242 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	message RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher
# 243 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmessage
# 244 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitfanfare
# 245 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_LILEEP
# 246 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	return
# 247 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 248 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep::
# 249 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
# 250 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
# 251 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 252 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 253 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 254 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorith::
# 255 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ANORITH
# 256 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	randompercentage 25
# 257 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_ANORITH, 20, shinyMode=VAR_RESULT
# 258 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithParty
# 259 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithPC
# 260 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 261 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 262 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 263 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithParty::
# 264 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedAnorithFanfare
# 265 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 266 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith
# 267 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 268 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 269 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith
# 270 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 271 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 272 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithPC::
# 273 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedAnorithFanfare
# 274 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 275 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_TransferAnorithToPC
# 276 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 277 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_TransferAnorithToPC
# 278 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 279 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 280 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_TransferAnorithToPC::
# 281 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_TransferredToPC
# 282 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith
# 283 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 284 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 285 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceivedAnorithFanfare::
# 286 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_ANORITH
# 287 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 288 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	message RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher
# 289 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmessage
# 290 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitfanfare
# 291 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ANORITH
# 292 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	return
# 293 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 294 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith::
# 295 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
# 296 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
# 297 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 298 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 299 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 300 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ChooseFossil::
# 301 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	message RustboroCity_DevonCorp_2F_Text_TwoFossilsPickOne
# 302 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmessage
# 303 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	multichoice 17, 6, MULTI_FOSSIL, FALSE
# 304 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	switch VAR_RESULT
# 305 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 0, RustboroCity_DevonCorp_2F_EventScript_ChooseClawFossil
# 306 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 1, RustboroCity_DevonCorp_2F_EventScript_ChooseRootFossil
# 307 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 2, RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect
# 308 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case MULTI_B_PRESSED, RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect
# 309 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 310 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 311 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ChooseClawFossil::
# 312 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_GiveClawFossil
# 313 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 314 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 315 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ChooseRootFossil::
# 316 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_GiveRootFossil
# 317 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 318 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 319 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect::
# 320 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 321 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 322 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 323 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_MatchCallScientist::
# 324 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 325 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 326 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 327 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_ge VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_DevonCorp_2F_EventScript_WorkOnNext
# 328 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopNewPokenavFeature, MSGBOX_DEFAULT
# 329 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 330 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 331 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 332 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_WorkOnNext::
# 333 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WhatToWorkOnNext, MSGBOX_DEFAULT
# 334 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 335 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 336 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 337 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_TechnologyForTMs:
# 338 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I'm developing a way for TRAINERS to\n"
# 339 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "copy their own TMs.\p"
# 340 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But my research partner lives near\n"
# 341 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "MT. CHIMNEY with poor reception…$"
# 342 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 343 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DeviceForTalkingToPokemon:
# 344 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "We're developing a device for talking\n"
# 345 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "with POKéMON.\p"
# 346 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But we haven't had much success…$"
# 347 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 348 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DevelopingNewBalls:
# 349 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I'm developing new kinds of\n"
# 350 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "POKé BALLS…\p"
# 351 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But I haven't made much headway…$"
# 352 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 353 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_WeFinallyMadeNewBalls:
# 354 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "We finally made new kinds of\n"
# 355 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "POKé BALLS!\p"
# 356 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "The REPEAT BALL makes it easier to\n"
# 357 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "catch POKéMON you've caught before.\p"
# 358 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "The TIMER BALL gets better at catching\n"
# 359 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "POKéMON the longer a battle runs.\p"
# 360 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Both are proudly developed by\n"
# 361 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "the DEVON CORPORATION.\p"
# 362 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Please give them a try!$"
# 363 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 364 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_IMadePokenav:
# 365 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I made the POKéNAV!\p"
# 366 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "As an engineer, I feel blessed to have\n"
# 367 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "made something so great!$"
# 368 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 369 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_WowThatsAPokenav:
# 370 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Oh, wow!\n"
# 371 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "That's a POKéNAV!\p"
# 372 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "It came about as a result of our\n"
# 373 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "PRESIDENT's desire to learn about\l"
# 374 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "the feelings of POKéMON.\p"
# 375 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Would you like me to describe its\n"
# 376 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "features in detail?\p"
# 377 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "No, no. I think you'll find out just by\n"
# 378 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "trying the POKéNAV out.$"
# 379 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 380 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DeviceToVisualizePokemonDreams:
# 381 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I'm trying to develop a device that\n"
# 382 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "visually reproduces the dreams of\l"
# 383 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "POKéMON…\p"
# 384 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But it's not going well.$"
# 385 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 386 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DevelopDeviceToResurrectFossils:
# 387 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I've been trying to develop a device\n"
# 388 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "that resurrects POKéMON from fossils…\p"
# 389 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "And, it's working!$"
# 390 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 391 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife:
# 392 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Wait! That thing you have there…\n"
# 393 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Is that a POKéMON fossil?\p"
# 394 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Would you like to bring that POKéMON\n"
# 395 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "back to life?\p"
# 396 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I can with my newly developed\n"
# 397 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "FOSSIL REGENERATOR.$"
# 398 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 399 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_OhIsThatSo:
# 400 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Oh, is that so?\p"
# 401 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "DEVON's technological expertise\n"
# 402 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "is outstanding, I tell you.$"
# 403 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 404 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_TwoFossilsPickOne:
# 405 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Oh, now that's a surprise!\n"
# 406 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "You have not one, but two, fossils?\p"
# 407 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Unfortunately, my machine can only\n"
# 408 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "regenerate one POKéMON at a time.\p"
# 409 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Would you like to pick one of your\n"
# 410 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "fossils for regeneration?$"
# 411 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 412 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher:
# 413 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Excellent!\n"
# 414 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Let's do this right away.\p"
# 415 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "{PLAYER} handed the {STR_VAR_1} to\n"
# 416 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "the DEVON RESEARCHER.$"
# 417 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 418 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_FossilRegeneratorTakesTime:
# 419 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "The FOSSIL REGENERATOR, which I made,\n"
# 420 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "is incredible.\p"
# 421 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But it has one drawback--it takes\n"
# 422 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "a long time to work.\p"
# 423 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "So, uh… How about you go for a stroll\n"
# 424 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "and look around for a while?$"
# 425 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 426 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife:
# 427 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Thanks for waiting!\p"
# 428 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Your fossilized POKéMON has been\n"
# 429 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "brought back to life!\p"
# 430 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "The fossil was an ancient POKéMON.\n"
# 431 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "{STR_VAR_2}, it was!$"
# 432 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 433 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher:
# 434 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "{PLAYER} received {STR_VAR_2} from\n"
# 435 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "the DEVON RESEARCHER.$"
# 436 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 437 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
@ Unused
# 438 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_TooManyPokemon:
# 439 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Uh-oh, you've got too many POKéMON.\n"
# 440 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "You have no room for this one.$"
# 441 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 442 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DevelopNewPokenavFeature:
# 443 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I'm trying to develop a new feature\n"
# 444 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "for the POKéNAV…\p"
# 445 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But it's not going well.$"
# 446 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 447 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_WhatToWorkOnNext:
# 448 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Well, now what shall I work on\n"
# 449 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "developing next?\p"
# 450 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Our company allows us to make our\n"
# 451 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "inspirations into reality.\p"
# 452 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "One couldn't ask for a better\n"
# 453 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "environment as an engineer.$"

RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_Text_0:
# 30 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "What?\l"
	.string "LANETTE sent you here?\p"
	.string "She says the system is ready, and she\n"
	.string "just needs a BLANK DISC??\p"
	.string "Well say no more!$"

RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_Text_1:
# 39 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Sure, LANETTE is unusual,\l"
	.string "but her systems are revolutionary!\p"
	.string "I'm sure that her TM duplication system\n"
	.string "will work flawlessly!\p"
	.string "But don't lose that disc, because it's\n"
	.string "extremely valuable!$"

RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_Text_2:
# 46 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Wait…\l"
	.string "You were the one who I sent to deliver\n"
	.string "the BLANK DISC!\p"
	.string "I gave you the disc, but you haven't\n"
	.string "delivered it??\p"
	.string "Well I hope you haven't lost it…\p"
	.string "It's very valuable!$"

RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_Text_3:
# 56 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Wait…\l"
	.string "You were the one who I sent to deliver\n"
	.string "the BLANK DISC…\p"
	.string "I gave you the disc, but you don't have\n"
	.string "it anymore??$"

RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_Text_4:
# 61 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "WHAT?!$"

RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_Text_5:
# 63 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Lucky for you, I'm so confident in\n"
	.string "LANETTE'S design specifications that\l"
	.string "we already put these into limited\l"
	.string "production…$"

RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_Text_6:
# 72 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Now DON'T lose that one!\p"
	.string "It's essential for LANETTE to test her\n"
	.string "system!$"

RustboroCity_DevonCorp_2F_EventScript_TalkToDiscScientist_Text_7:
# 77 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "What?\l"
	.string "LANETTE received the BLANK DISC?\p"
	.string "The system works, and you saw it in\n"
	.string "action??\p"
	.string "That's fantastic!!$"
