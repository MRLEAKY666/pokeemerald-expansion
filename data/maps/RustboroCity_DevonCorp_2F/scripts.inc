# 1 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 2 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
.set LOCALID_FOSSIL_SCIENTIST, 5
# 3 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 4 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_MapScripts::
# 5 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_2F_OnTransition
# 6 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.byte 0
# 7 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 8 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_OnTransition:
# 9 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 10 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 11 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 12 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_SetFossilReady::
# 13 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 2
# 14 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	return
# 15 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 16 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_TalkToPokemonScientist::
# 17 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 18 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 19 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 20 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DeviceForTalkingToPokemon, MSGBOX_DEFAULT
# 21 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 22 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 23 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 24 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_BallScientist::
# 25 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 26 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 27 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 28 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, RustboroCity_DevonCorp_2F_EventScript_DevelopedBalls
# 29 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopingNewBalls, MSGBOX_DEFAULT
# 30 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 31 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 32 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 33 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_DevelopedBalls::
# 34 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WeFinallyMadeNewBalls, MSGBOX_DEFAULT
# 35 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 36 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 37 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 38 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_PokenavScientist::
# 39 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 40 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 41 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 42 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_DevonCorp_2F_EventScript_HasPokenav
# 43 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_IMadePokenav, MSGBOX_DEFAULT
# 44 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 45 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 46 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 47 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_HasPokenav::
# 48 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WowThatsAPokenav, MSGBOX_DEFAULT
# 49 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 50 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 51 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 52 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_PokemonDreamsScientist::
# 53 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 54 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 55 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 56 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DeviceToVisualizePokemonDreams, MSGBOX_DEFAULT
# 57 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 58 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 59 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 60 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_FossilScientist::
# 61 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 62 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 63 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 2, RustboroCity_DevonCorp_2F_EventScript_FossilMonReady
# 64 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_StillRegenerating
# 65 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopDeviceToResurrectFossils, MSGBOX_DEFAULT
# 66 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	checkitem ITEM_ROOT_FOSSIL
# 67 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeRootFossil
# 68 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	checkitem ITEM_CLAW_FOSSIL
# 69 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeClawFossil
# 70 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 71 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 72 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 73 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
@ This whole section has needless duplication and could be condensed considerably
# 74 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_NoticeRootFossil::
# 75 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 76 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	playse SE_PIN
# 77 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
# 78 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmovement 0
# 79 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
# 80 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmovement 0
# 81 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
# 82 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil
# 83 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	checkitem ITEM_CLAW_FOSSIL
# 84 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
# 85 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_GiveRootFossil
# 86 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 87 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 88 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_GiveRootFossil::
# 89 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_ROOT_FOSSIL
# 90 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
# 91 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	removeitem ITEM_ROOT_FOSSIL
# 92 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
# 93 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_WHICH_FOSSIL_REVIVED, 1
# 94 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 95 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 96 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 97 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_NoticeClawFossil::
# 98 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 99 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	playse SE_PIN
# 100 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
# 101 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmovement 0
# 102 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
# 103 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmovement 0
# 104 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
# 105 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil
# 106 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	checkitem ITEM_ROOT_FOSSIL
# 107 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
# 108 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_GiveClawFossil
# 109 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 110 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 111 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_GiveClawFossil::
# 112 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_CLAW_FOSSIL
# 113 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
# 114 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	removeitem ITEM_CLAW_FOSSIL
# 115 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
# 116 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_WHICH_FOSSIL_REVIVED, 2
# 117 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 118 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 119 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 120 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil::
# 121 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_OhIsThatSo, MSGBOX_DEFAULT
# 122 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 123 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 124 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 125 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_StillRegenerating::
# 126 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_FossilRegeneratorTakesTime, MSGBOX_DEFAULT
# 127 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 128 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 129 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 130 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_FossilMonReady::
# 131 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 1, RustboroCity_DevonCorp_2F_EventScript_LileepReady
# 132 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 2, RustboroCity_DevonCorp_2F_EventScript_AnorithReady
# 133 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 134 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 135 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_LileepReady::
# 136 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_LILEEP
# 137 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
# 138 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveLileep
# 139 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 140 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 141 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_AnorithReady::
# 142 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_ANORITH
# 143 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
# 144 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorith
# 145 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 146 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 147 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveLileep::
# 148 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LILEEP
# 149 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	randompercentage 25
# 150 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_LILEEP, 20, isShiny=VAR_RESULT
# 151 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepParty
# 152 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepPC
# 153 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 154 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 155 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 156 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepParty::
# 157 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedLileepFanfare
# 158 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 159 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep
# 160 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 161 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 162 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep
# 163 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 164 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 165 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepPC::
# 166 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedLileepFanfare
# 167 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 168 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_TransferLileepToPC
# 169 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 170 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_TransferLileepToPC
# 171 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 172 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 173 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_TransferLileepToPC::
# 174 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_TransferredToPC
# 175 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep
# 176 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 177 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 178 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceivedLileepFanfare::
# 179 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_LILEEP
# 180 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 181 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	message RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher
# 182 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmessage
# 183 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitfanfare
# 184 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_LILEEP
# 185 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	return
# 186 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 187 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep::
# 188 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
# 189 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
# 190 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 191 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 192 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 193 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorith::
# 194 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ANORITH
# 195 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	randompercentage 25
# 196 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_ANORITH, 20, isShiny=VAR_RESULT
# 197 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithParty
# 198 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithPC
# 199 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 200 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 201 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 202 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithParty::
# 203 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedAnorithFanfare
# 204 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 205 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith
# 206 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 207 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 208 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith
# 209 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 210 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 211 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithPC::
# 212 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedAnorithFanfare
# 213 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 214 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_TransferAnorithToPC
# 215 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 216 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_TransferAnorithToPC
# 217 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 218 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 219 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_TransferAnorithToPC::
# 220 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_TransferredToPC
# 221 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith
# 222 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 223 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 224 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceivedAnorithFanfare::
# 225 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_ANORITH
# 226 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 227 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	message RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher
# 228 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmessage
# 229 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitfanfare
# 230 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ANORITH
# 231 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	return
# 232 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 233 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith::
# 234 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
# 235 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
# 236 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 237 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 238 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 239 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ChooseFossil::
# 240 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	message RustboroCity_DevonCorp_2F_Text_TwoFossilsPickOne
# 241 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmessage
# 242 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	multichoice 17, 6, MULTI_FOSSIL, FALSE
# 243 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	switch VAR_RESULT
# 244 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 0, RustboroCity_DevonCorp_2F_EventScript_ChooseClawFossil
# 245 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 1, RustboroCity_DevonCorp_2F_EventScript_ChooseRootFossil
# 246 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 2, RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect
# 247 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case MULTI_B_PRESSED, RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect
# 248 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 249 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 250 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ChooseClawFossil::
# 251 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_GiveClawFossil
# 252 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 253 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 254 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ChooseRootFossil::
# 255 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_GiveRootFossil
# 256 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 257 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 258 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect::
# 259 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 260 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 261 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 262 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_MatchCallScientist::
# 263 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 264 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 265 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 266 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_ge VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_DevonCorp_2F_EventScript_WorkOnNext
# 267 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopNewPokenavFeature, MSGBOX_DEFAULT
# 268 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 269 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 270 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 271 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_WorkOnNext::
# 272 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WhatToWorkOnNext, MSGBOX_DEFAULT
# 273 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 274 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 275 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 276 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DeviceForTalkingToPokemon:
# 277 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "We're developing a device for talking\n"
# 278 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "with POKéMON.\p"
# 279 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But we haven't had much success…$"
# 280 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 281 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DevelopingNewBalls:
# 282 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I'm developing new kinds of\n"
# 283 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "POKé BALLS…\p"
# 284 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But I haven't made much headway…$"
# 285 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 286 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_WeFinallyMadeNewBalls:
# 287 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "We finally made new kinds of\n"
# 288 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "POKé BALLS!\p"
# 289 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "The REPEAT BALL makes it easier to\n"
# 290 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "catch POKéMON you've caught before.\p"
# 291 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "The TIMER BALL gets better at catching\n"
# 292 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "POKéMON the longer a battle runs.\p"
# 293 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Both are proudly developed by\n"
# 294 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "the DEVON CORPORATION.\p"
# 295 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Please give them a try!$"
# 296 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 297 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_IMadePokenav:
# 298 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I made the POKéNAV!\p"
# 299 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "As an engineer, I feel blessed to have\n"
# 300 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "made something so great!$"
# 301 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 302 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_WowThatsAPokenav:
# 303 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Oh, wow!\n"
# 304 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "That's a POKéNAV!\p"
# 305 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "It came about as a result of our\n"
# 306 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "PRESIDENT's desire to learn about\l"
# 307 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "the feelings of POKéMON.\p"
# 308 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Would you like me to describe its\n"
# 309 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "features in detail?\p"
# 310 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "No, no. I think you'll find out just by\n"
# 311 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "trying the POKéNAV out.$"
# 312 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 313 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DeviceToVisualizePokemonDreams:
# 314 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I'm trying to develop a device that\n"
# 315 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "visually reproduces the dreams of\l"
# 316 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "POKéMON…\p"
# 317 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But it's not going well.$"
# 318 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 319 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DevelopDeviceToResurrectFossils:
# 320 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I've been trying to develop a device\n"
# 321 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "that resurrects POKéMON from fossils…\p"
# 322 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "And, it's working!$"
# 323 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 324 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife:
# 325 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Wait! That thing you have there…\n"
# 326 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Is that a POKéMON fossil?\p"
# 327 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Would you like to bring that POKéMON\n"
# 328 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "back to life?\p"
# 329 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I can with my newly developed\n"
# 330 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "FOSSIL REGENERATOR.$"
# 331 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 332 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_OhIsThatSo:
# 333 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Oh, is that so?\p"
# 334 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "DEVON's technological expertise\n"
# 335 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "is outstanding, I tell you.$"
# 336 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 337 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_TwoFossilsPickOne:
# 338 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Oh, now that's a surprise!\n"
# 339 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "You have not one, but two, fossils?\p"
# 340 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Unfortunately, my machine can only\n"
# 341 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "regenerate one POKéMON at a time.\p"
# 342 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Would you like to pick one of your\n"
# 343 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "fossils for regeneration?$"
# 344 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 345 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher:
# 346 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Excellent!\n"
# 347 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Let's do this right away.\p"
# 348 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "{PLAYER} handed the {STR_VAR_1} to\n"
# 349 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "the DEVON RESEARCHER.$"
# 350 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 351 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_FossilRegeneratorTakesTime:
# 352 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "The FOSSIL REGENERATOR, which I made,\n"
# 353 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "is incredible.\p"
# 354 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But it has one drawback--it takes\n"
# 355 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "a long time to work.\p"
# 356 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "So, uh… How about you go for a stroll\n"
# 357 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "and look around for a while?$"
# 358 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 359 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife:
# 360 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Thanks for waiting!\p"
# 361 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Your fossilized POKéMON has been\n"
# 362 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "brought back to life!\p"
# 363 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "The fossil was an ancient POKéMON.\n"
# 364 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "{STR_VAR_2}, it was!$"
# 365 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 366 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher:
# 367 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "{PLAYER} received {STR_VAR_2} from\n"
# 368 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "the DEVON RESEARCHER.$"
# 369 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 370 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
@ Unused
# 371 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_TooManyPokemon:
# 372 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Uh-oh, you've got too many POKéMON.\n"
# 373 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "You have no room for this one.$"
# 374 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 375 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DevelopNewPokenavFeature:
# 376 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I'm trying to develop a new feature\n"
# 377 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "for the POKéNAV…\p"
# 378 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But it's not going well.$"
# 379 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 380 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_WhatToWorkOnNext:
# 381 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Well, now what shall I work on\n"
# 382 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "developing next?\p"
# 383 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Our company allows us to make our\n"
# 384 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "inspirations into reality.\p"
# 385 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "One couldn't ask for a better\n"
# 386 "data//maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "environment as an engineer.$"
