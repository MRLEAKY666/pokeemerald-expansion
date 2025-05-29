# 1 "data//maps/SlateportCity/scripts.pory"

# 2 "data//maps/SlateportCity/scripts.pory"
SlateportCity_MapScripts::
# 3 "data//maps/SlateportCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OnTransition
# 4 "data//maps/SlateportCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_OnFrame
# 5 "data//maps/SlateportCity/scripts.pory"
	.byte 0
# 6 "data//maps/SlateportCity/scripts.pory"

# 7 "data//maps/SlateportCity/scripts.pory"
SlateportCity_OnTransition:
# 8 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0
# 9 "data//maps/SlateportCity/scripts.pory"
	call SlateportCity_EventScript_EnterSlateport
# 10 "data//maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_MovePeopleForSternInterview
# 11 "data//maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_SetReadyForScottScene
# 12 "data//maps/SlateportCity/scripts.pory"
	end
# 13 "data//maps/SlateportCity/scripts.pory"

# 14 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_EnterSlateport::
# 15 "data//maps/SlateportCity/scripts.pory"
	setflag FLAG_VISITED_SLATEPORT_CITY
# 16 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_CONTEST_HALL_STATE, 0
# 17 "data//maps/SlateportCity/scripts.pory"
	setflag FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER
# 18 "data//maps/SlateportCity/scripts.pory"
	return
# 19 "data//maps/SlateportCity/scripts.pory"

# 20 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_MovePeopleForSternInterview::
# 21 "data//maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SLATEPORT_CAPT_STERN, 28, 13
# 22 "data//maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SLATEPORT_OLD_WOMAN, 25, 13
# 23 "data//maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SLATEPORT_RICH_BOY, 25, 14
# 24 "data//maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SLATEPORT_COOK, 27, 16
# 25 "data//maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SLATEPORT_GIRL, 28, 16
# 26 "data//maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SLATEPORT_FAT_MAN, 29, 16
# 27 "data//maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SLATEPORT_MAN_1, 31, 14
# 28 "data//maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SLATEPORT_CAPT_STERN, MOVEMENT_TYPE_FACE_DOWN
# 29 "data//maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SLATEPORT_OLD_WOMAN, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
# 30 "data//maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SLATEPORT_RICH_BOY, MOVEMENT_TYPE_FACE_UP_AND_RIGHT
# 31 "data//maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SLATEPORT_COOK, MOVEMENT_TYPE_FACE_UP
# 32 "data//maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SLATEPORT_GIRL, MOVEMENT_TYPE_FACE_UP
# 33 "data//maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SLATEPORT_FAT_MAN, MOVEMENT_TYPE_FACE_UP
# 34 "data//maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SLATEPORT_MAN_1, MOVEMENT_TYPE_FACE_LEFT
# 35 "data//maps/SlateportCity/scripts.pory"
	return
# 36 "data//maps/SlateportCity/scripts.pory"

# 37 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_SetReadyForScottScene::
# 38 "data//maps/SlateportCity/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 39 "data//maps/SlateportCity/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 40 "data//maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_0x8004, 30, SlateportCity_EventScript_MoveScottLeft
# 41 "data//maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 23, 27
# 42 "data//maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
# 43 "data//maps/SlateportCity/scripts.pory"
	return
# 44 "data//maps/SlateportCity/scripts.pory"

# 45 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_MoveScottLeft::
# 46 "data//maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 22, 27
# 47 "data//maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
# 48 "data//maps/SlateportCity/scripts.pory"
	return
# 49 "data//maps/SlateportCity/scripts.pory"

# 50 "data//maps/SlateportCity/scripts.pory"
SlateportCity_OnFrame:
# 51 "data//maps/SlateportCity/scripts.pory"
	map_script_2 VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_ScottScene
# 52 "data//maps/SlateportCity/scripts.pory"
	.2byte 0
# 53 "data//maps/SlateportCity/scripts.pory"

# 54 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ScottScene::
# 55 "data//maps/SlateportCity/scripts.pory"
	lockall
# 56 "data//maps/SlateportCity/scripts.pory"
	addobject LOCALID_SLATEPORT_SCOTT
# 57 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerFaceScott
# 58 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottApproachPlayer
# 59 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 60 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_YouDroveTeamAquaAway, MSGBOX_DEFAULT
# 61 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 62 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_SCOTT, Common_Movement_WalkInPlaceFasterLeft
# 63 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 64 "data//maps/SlateportCity/scripts.pory"
	delay 60
# 65 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_MaybeThisTrainer, MSGBOX_DEFAULT
# 66 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_SCOTT, Common_Movement_WalkInPlaceFasterRight
# 67 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 68 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_LetsRegisterEachOther, MSGBOX_DEFAULT
# 69 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 70 "data//maps/SlateportCity/scripts.pory"
	delay 30
# 71 "data//maps/SlateportCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 72 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_RegisteredScott, MSGBOX_DEFAULT
# 73 "data//maps/SlateportCity/scripts.pory"
	waitfanfare
# 74 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 75 "data//maps/SlateportCity/scripts.pory"
	delay 30
# 76 "data//maps/SlateportCity/scripts.pory"
	setflag FLAG_ENABLE_SCOTT_MATCH_CALL
# 77 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou, MSGBOX_DEFAULT
# 78 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 79 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExit
# 80 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 81 "data//maps/SlateportCity/scripts.pory"
	removeobject LOCALID_SLATEPORT_SCOTT
# 82 "data//maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 10, 12
# 83 "data//maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_DOWN
# 84 "data//maps/SlateportCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 85 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 2
# 86 "data//maps/SlateportCity/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 87 "data//maps/SlateportCity/scripts.pory"
	releaseall
# 88 "data//maps/SlateportCity/scripts.pory"
	end
# 89 "data//maps/SlateportCity/scripts.pory"

# 90 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Movement_PlayerFaceScott:
# 91 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 92 "data//maps/SlateportCity/scripts.pory"
	delay_8
# 93 "data//maps/SlateportCity/scripts.pory"
	walk_in_place_faster_left
# 94 "data//maps/SlateportCity/scripts.pory"
	step_end
# 95 "data//maps/SlateportCity/scripts.pory"

# 96 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Movement_ScottApproachPlayer:
# 97 "data//maps/SlateportCity/scripts.pory"
	walk_right
# 98 "data//maps/SlateportCity/scripts.pory"
	walk_right
# 99 "data//maps/SlateportCity/scripts.pory"
	walk_right
# 100 "data//maps/SlateportCity/scripts.pory"
	walk_right
# 101 "data//maps/SlateportCity/scripts.pory"
	walk_right
# 102 "data//maps/SlateportCity/scripts.pory"
	walk_right
# 103 "data//maps/SlateportCity/scripts.pory"
	walk_right
# 104 "data//maps/SlateportCity/scripts.pory"
	step_end
# 105 "data//maps/SlateportCity/scripts.pory"

# 106 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Movement_ScottExit:
# 107 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 108 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 109 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 110 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 111 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 112 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 113 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 114 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 115 "data//maps/SlateportCity/scripts.pory"
	step_end
# 116 "data//maps/SlateportCity/scripts.pory"

# 117 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_EnergyGuru::
# 118 "data//maps/SlateportCity/scripts.pory"
	lock
# 119 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 120 "data//maps/SlateportCity/scripts.pory"
	message SlateportCity_Text_EnergyGuruSellWhatYouNeed
# 121 "data//maps/SlateportCity/scripts.pory"
	waitmessage
# 122 "data//maps/SlateportCity/scripts.pory"
	pokemart SlateportCity_Pokemart_EnergyGuru
# 123 "data//maps/SlateportCity/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 124 "data//maps/SlateportCity/scripts.pory"
	release
# 125 "data//maps/SlateportCity/scripts.pory"
	end
# 126 "data//maps/SlateportCity/scripts.pory"

# 127 "data//maps/SlateportCity/scripts.pory"
	.align 2
# 128 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Pokemart_EnergyGuru:
# 129 "data//maps/SlateportCity/scripts.pory"
	.2byte ITEM_PROTEIN
# 130 "data//maps/SlateportCity/scripts.pory"
	.2byte ITEM_IRON
# 131 "data//maps/SlateportCity/scripts.pory"
	.2byte ITEM_CARBOS
# 132 "data//maps/SlateportCity/scripts.pory"
	.2byte ITEM_ZINC
# 133 "data//maps/SlateportCity/scripts.pory"
	.2byte ITEM_CALCIUM
# 134 "data//maps/SlateportCity/scripts.pory"
	.2byte ITEM_HP_UP
# 135 "data//maps/SlateportCity/scripts.pory"
	.2byte ITEM_PP_UP
# 136 "data//maps/SlateportCity/scripts.pory"
	.2byte ITEM_NONE
# 137 "data//maps/SlateportCity/scripts.pory"
	release
# 138 "data//maps/SlateportCity/scripts.pory"
	end
# 139 "data//maps/SlateportCity/scripts.pory"

# 140 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_EffortRibbonWoman::
# 141 "data//maps/SlateportCity/scripts.pory"
	lock
# 142 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 143 "data//maps/SlateportCity/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 144 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_OhYourPokemon, MSGBOX_DEFAULT
# 145 "data//maps/SlateportCity/scripts.pory"
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
# 146 "data//maps/SlateportCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, SlateportCity_EventScript_MonHasEffortRibbon
# 147 "data//maps/SlateportCity/scripts.pory"
	specialvar VAR_RESULT, Special_AreLeadMonEVsMaxedOut
# 148 "data//maps/SlateportCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_MonEVsNotMaxed
# 149 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_PleaseGiveItThisEffortRibbon, MSGBOX_DEFAULT
# 150 "data//maps/SlateportCity/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 151 "data//maps/SlateportCity/scripts.pory"
	message SlateportCity_Text_ReceivedEffortRibbon
# 152 "data//maps/SlateportCity/scripts.pory"
	waitfanfare
# 153 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_PutEffortRibbonOnMon, MSGBOX_DEFAULT
# 154 "data//maps/SlateportCity/scripts.pory"
	special GiveLeadMonEffortRibbon
# 155 "data//maps/SlateportCity/scripts.pory"
	release
# 156 "data//maps/SlateportCity/scripts.pory"
	end
# 157 "data//maps/SlateportCity/scripts.pory"

# 158 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_MonEVsNotMaxed::
# 159 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GoForItLittleHarder, MSGBOX_DEFAULT
# 160 "data//maps/SlateportCity/scripts.pory"
	release
# 161 "data//maps/SlateportCity/scripts.pory"
	end
# 162 "data//maps/SlateportCity/scripts.pory"

# 163 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_MonHasEffortRibbon::
# 164 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_EffortRibbonLooksGoodOnIt, MSGBOX_DEFAULT
# 165 "data//maps/SlateportCity/scripts.pory"
	release
# 166 "data//maps/SlateportCity/scripts.pory"
	end
# 167 "data//maps/SlateportCity/scripts.pory"

# 168 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Cook::
# 169 "data//maps/SlateportCity/scripts.pory"
	lock
# 170 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 171 "data//maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_CookSternInterview
# 172 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SeaweedFullOfLife, MSGBOX_DEFAULT
# 173 "data//maps/SlateportCity/scripts.pory"
	release
# 174 "data//maps/SlateportCity/scripts.pory"
	end
# 175 "data//maps/SlateportCity/scripts.pory"

# 176 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_CookSternInterview::
# 177 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_CaptainComeBackWithBigFish, MSGBOX_DEFAULT
# 178 "data//maps/SlateportCity/scripts.pory"
	release
# 179 "data//maps/SlateportCity/scripts.pory"
	end
# 180 "data//maps/SlateportCity/scripts.pory"

# 181 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_OldWoman::
# 182 "data//maps/SlateportCity/scripts.pory"
	lock
# 183 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 184 "data//maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_OldWomanSternInterview
# 185 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_HowTownIsBornAndGrows, MSGBOX_DEFAULT
# 186 "data//maps/SlateportCity/scripts.pory"
	release
# 187 "data//maps/SlateportCity/scripts.pory"
	end
# 188 "data//maps/SlateportCity/scripts.pory"

# 189 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_OldWomanSternInterview::
# 190 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_CaptSternBeingInterviewed, MSGBOX_DEFAULT
# 191 "data//maps/SlateportCity/scripts.pory"
	release
# 192 "data//maps/SlateportCity/scripts.pory"
	end
# 193 "data//maps/SlateportCity/scripts.pory"

# 194 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Girl::
# 195 "data//maps/SlateportCity/scripts.pory"
	lock
# 196 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 197 "data//maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_GirlSternInterview
# 198 "data//maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_GirlSecretBase
# 199 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SlateportWonderfulPlace, MSGBOX_DEFAULT
# 200 "data//maps/SlateportCity/scripts.pory"
	release
# 201 "data//maps/SlateportCity/scripts.pory"
	end
# 202 "data//maps/SlateportCity/scripts.pory"

# 203 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_GirlSternInterview::
# 204 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_InterviewerSoCool, MSGBOX_DEFAULT
# 205 "data//maps/SlateportCity/scripts.pory"
	release
# 206 "data//maps/SlateportCity/scripts.pory"
	end
# 207 "data//maps/SlateportCity/scripts.pory"

# 208 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_GirlSecretBase::
# 209 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BuyBricksSoDecorWontGetDirty, MSGBOX_DEFAULT
# 210 "data//maps/SlateportCity/scripts.pory"
	release
# 211 "data//maps/SlateportCity/scripts.pory"
	end
# 212 "data//maps/SlateportCity/scripts.pory"

# 213 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_RichBoy::
# 214 "data//maps/SlateportCity/scripts.pory"
	lock
# 215 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 216 "data//maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_RichBoySternInterview
# 217 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GoingToCompeteInBattleTent, MSGBOX_DEFAULT
# 218 "data//maps/SlateportCity/scripts.pory"
	release
# 219 "data//maps/SlateportCity/scripts.pory"
	end
# 220 "data//maps/SlateportCity/scripts.pory"

# 221 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_RichBoySternInterview::
# 222 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternSaysDiscoveredSomething, MSGBOX_DEFAULT
# 223 "data//maps/SlateportCity/scripts.pory"
	release
# 224 "data//maps/SlateportCity/scripts.pory"
	end
# 225 "data//maps/SlateportCity/scripts.pory"

# 226 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_FatMan::
# 227 "data//maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_FatManSternInterview
# 228 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BushedHikingFromMauville, MSGBOX_NPC
# 229 "data//maps/SlateportCity/scripts.pory"
	end
# 230 "data//maps/SlateportCity/scripts.pory"

# 231 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_FatManSternInterview::
# 232 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_AmIOnTV, MSGBOX_SIGN
# 233 "data//maps/SlateportCity/scripts.pory"
	end
# 234 "data//maps/SlateportCity/scripts.pory"

# 235 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Man1::
# 236 "data//maps/SlateportCity/scripts.pory"
	lock
# 237 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 238 "data//maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_Man1SternInterview
# 239 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_EveryoneCallsHimCaptStern, MSGBOX_DEFAULT
# 240 "data//maps/SlateportCity/scripts.pory"
	release
# 241 "data//maps/SlateportCity/scripts.pory"
	end
# 242 "data//maps/SlateportCity/scripts.pory"

# 243 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Man1SternInterview::
# 244 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_CaptainsACelebrity, MSGBOX_DEFAULT
# 245 "data//maps/SlateportCity/scripts.pory"
	release
# 246 "data//maps/SlateportCity/scripts.pory"
	end
# 247 "data//maps/SlateportCity/scripts.pory"

# 248 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Woman1::
# 249 "data//maps/SlateportCity/scripts.pory"
	lock
# 250 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 251 "data//maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_EventScript_Woman1AquaGone
# 252 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WhatsLongLineOverThere, MSGBOX_DEFAULT
# 253 "data//maps/SlateportCity/scripts.pory"
	release
# 254 "data//maps/SlateportCity/scripts.pory"
	end
# 255 "data//maps/SlateportCity/scripts.pory"

# 256 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Woman1AquaGone::
# 257 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_VisitedMuseumOften, MSGBOX_DEFAULT
# 258 "data//maps/SlateportCity/scripts.pory"
	release
# 259 "data//maps/SlateportCity/scripts.pory"
	end
# 260 "data//maps/SlateportCity/scripts.pory"

# 261 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_BattleTentSign::
# 262 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BattleTentSign, MSGBOX_SIGN
# 263 "data//maps/SlateportCity/scripts.pory"
	end
# 264 "data//maps/SlateportCity/scripts.pory"

# 265 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_SternsShipyardSign::
# 266 "data//maps/SlateportCity/scripts.pory"
	lockall
# 267 "data//maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_SternsShipyardFerryComplete
# 268 "data//maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, SlateportCity_EventScript_SternsShipyardNearsCompletion
# 269 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternsShipyardWantedSign, MSGBOX_DEFAULT
# 270 "data//maps/SlateportCity/scripts.pory"
	releaseall
# 271 "data//maps/SlateportCity/scripts.pory"
	end
# 272 "data//maps/SlateportCity/scripts.pory"

# 273 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_SternsShipyardNearsCompletion::
# 274 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternsShipyardNearsCompletion, MSGBOX_DEFAULT
# 275 "data//maps/SlateportCity/scripts.pory"
	releaseall
# 276 "data//maps/SlateportCity/scripts.pory"
	end
# 277 "data//maps/SlateportCity/scripts.pory"

# 278 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_SternsShipyardFerryComplete::
# 279 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternsShipyardFerryComplete, MSGBOX_DEFAULT
# 280 "data//maps/SlateportCity/scripts.pory"
	releaseall
# 281 "data//maps/SlateportCity/scripts.pory"
	end
# 282 "data//maps/SlateportCity/scripts.pory"

# 283 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_PokemonFanClubSign::
# 284 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_PokemonFanClubSign, MSGBOX_SIGN
# 285 "data//maps/SlateportCity/scripts.pory"
	end
# 286 "data//maps/SlateportCity/scripts.pory"

# 287 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_OceanicMuseumSign::
# 288 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_OceanicMuseumSign, MSGBOX_SIGN
# 289 "data//maps/SlateportCity/scripts.pory"
	end
# 290 "data//maps/SlateportCity/scripts.pory"

# 291 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_CitySign::
# 292 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_CitySign, MSGBOX_SIGN
# 293 "data//maps/SlateportCity/scripts.pory"
	end
# 294 "data//maps/SlateportCity/scripts.pory"

# 295 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_MarketSign::
# 296 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_MarketSign, MSGBOX_SIGN
# 297 "data//maps/SlateportCity/scripts.pory"
	end
# 298 "data//maps/SlateportCity/scripts.pory"

# 299 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_HarborSign::
# 300 "data//maps/SlateportCity/scripts.pory"
	lockall
# 301 "data//maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_HarborSignFerryComplete
# 302 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_HarborFerryUnderConstruction, MSGBOX_DEFAULT
# 303 "data//maps/SlateportCity/scripts.pory"
	releaseall
# 304 "data//maps/SlateportCity/scripts.pory"
	end
# 305 "data//maps/SlateportCity/scripts.pory"

# 306 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_HarborSignFerryComplete::
# 307 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_HarborSign, MSGBOX_DEFAULT
# 308 "data//maps/SlateportCity/scripts.pory"
	releaseall
# 309 "data//maps/SlateportCity/scripts.pory"
	end
# 310 "data//maps/SlateportCity/scripts.pory"

# 311 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_NameRatersHouseSign::
# 312 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_NameRatersHouseSign, MSGBOX_SIGN
# 313 "data//maps/SlateportCity/scripts.pory"
	end
# 314 "data//maps/SlateportCity/scripts.pory"

# 315 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Maniac::
# 316 "data//maps/SlateportCity/scripts.pory"
	lock
# 317 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 318 "data//maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_ManiacSternInterview
# 319 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
# 320 "data//maps/SlateportCity/scripts.pory"
	release
# 321 "data//maps/SlateportCity/scripts.pory"
	end
# 322 "data//maps/SlateportCity/scripts.pory"

# 323 "data//maps/SlateportCity/scripts.pory"
@ Unclear if the text here was meant to be different, but its not
# 324 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ManiacSternInterview::
# 325 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
# 326 "data//maps/SlateportCity/scripts.pory"
	release
# 327 "data//maps/SlateportCity/scripts.pory"
	end
# 328 "data//maps/SlateportCity/scripts.pory"

# 329 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Woman2::
# 330 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_CantChangeTradeMonName, MSGBOX_NPC
# 331 "data//maps/SlateportCity/scripts.pory"
	end
# 332 "data//maps/SlateportCity/scripts.pory"

# 333 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Sailor1::
# 334 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SeaIsSoWet, MSGBOX_NPC
# 335 "data//maps/SlateportCity/scripts.pory"
	end
# 336 "data//maps/SlateportCity/scripts.pory"

# 337 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Sailor2::
# 338 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SinkOldBoats, MSGBOX_NPC
# 339 "data//maps/SlateportCity/scripts.pory"
	end
# 340 "data//maps/SlateportCity/scripts.pory"

# 341 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_PokefanF::
# 342 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BuyTooMuch, MSGBOX_NPC
# 343 "data//maps/SlateportCity/scripts.pory"
	end
# 344 "data//maps/SlateportCity/scripts.pory"

# 345 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Man2::
# 346 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BattleTentBuiltRecently, MSGBOX_NPC
# 347 "data//maps/SlateportCity/scripts.pory"
	end
# 348 "data//maps/SlateportCity/scripts.pory"

# 349 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt1::
# 350 "data//maps/SlateportCity/scripts.pory"
	lock
# 351 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 352 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_QuitPushing, MSGBOX_DEFAULT
# 353 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 354 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_1, Common_Movement_FaceOriginalDirection
# 355 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 356 "data//maps/SlateportCity/scripts.pory"
	release
# 357 "data//maps/SlateportCity/scripts.pory"
	end
# 358 "data//maps/SlateportCity/scripts.pory"

# 359 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt2::
# 360 "data//maps/SlateportCity/scripts.pory"
	lock
# 361 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 362 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_AquaHasPolicy, MSGBOX_DEFAULT
# 363 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 364 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_2, Common_Movement_FaceOriginalDirection
# 365 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 366 "data//maps/SlateportCity/scripts.pory"
	release
# 367 "data//maps/SlateportCity/scripts.pory"
	end
# 368 "data//maps/SlateportCity/scripts.pory"

# 369 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt3::
# 370 "data//maps/SlateportCity/scripts.pory"
	lock
# 371 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 372 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BossIsBrilliant, MSGBOX_DEFAULT
# 373 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 374 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_3, Common_Movement_FaceOriginalDirection
# 375 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 376 "data//maps/SlateportCity/scripts.pory"
	release
# 377 "data//maps/SlateportCity/scripts.pory"
	end
# 378 "data//maps/SlateportCity/scripts.pory"

# 379 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt4::
# 380 "data//maps/SlateportCity/scripts.pory"
	lock
# 381 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 382 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WhatsNewSchemeIWonder, MSGBOX_DEFAULT
# 383 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 384 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_4, Common_Movement_FaceOriginalDirection
# 385 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 386 "data//maps/SlateportCity/scripts.pory"
	release
# 387 "data//maps/SlateportCity/scripts.pory"
	end
# 388 "data//maps/SlateportCity/scripts.pory"

# 389 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt5::
# 390 "data//maps/SlateportCity/scripts.pory"
	lock
# 391 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 392 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ShouldTakeItAll, MSGBOX_DEFAULT
# 393 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 394 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_5, Common_Movement_FaceOriginalDirection
# 395 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 396 "data//maps/SlateportCity/scripts.pory"
	release
# 397 "data//maps/SlateportCity/scripts.pory"
	end
# 398 "data//maps/SlateportCity/scripts.pory"

# 399 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt6::
# 400 "data//maps/SlateportCity/scripts.pory"
	lock
# 401 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 402 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_DontButtIn, MSGBOX_DEFAULT
# 403 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 404 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_6, Common_Movement_FaceOriginalDirection
# 405 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 406 "data//maps/SlateportCity/scripts.pory"
	release
# 407 "data//maps/SlateportCity/scripts.pory"
	end
# 408 "data//maps/SlateportCity/scripts.pory"

# 409 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt7::
# 410 "data//maps/SlateportCity/scripts.pory"
	lock
# 411 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 412 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_RemindsMeOfLongLineForGames, MSGBOX_DEFAULT
# 413 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 414 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_7, Common_Movement_FaceOriginalDirection
# 415 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 416 "data//maps/SlateportCity/scripts.pory"
	release
# 417 "data//maps/SlateportCity/scripts.pory"
	end
# 418 "data//maps/SlateportCity/scripts.pory"

# 419 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt8::
# 420 "data//maps/SlateportCity/scripts.pory"
	lock
# 421 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 422 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WhyAreWeLiningUp, MSGBOX_DEFAULT
# 423 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 424 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_8, Common_Movement_FaceOriginalDirection
# 425 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 426 "data//maps/SlateportCity/scripts.pory"
	release
# 427 "data//maps/SlateportCity/scripts.pory"
	end
# 428 "data//maps/SlateportCity/scripts.pory"

# 429 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt9::
# 430 "data//maps/SlateportCity/scripts.pory"
	lock
# 431 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 432 "data//maps/SlateportCity/scripts.pory"
	playse SE_PIN
# 433 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_ExclamationMark
# 434 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 435 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_Delay48
# 436 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 437 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WhatDoYouWant, MSGBOX_DEFAULT
# 438 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 439 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
# 440 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 441 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
# 442 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 443 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FacePlayer
# 444 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 445 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_IllReadSignForYou, MSGBOX_DEFAULT
# 446 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 447 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
# 448 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 449 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
# 450 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 451 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SaysSomethingLikeSeaIsEndless, MSGBOX_DEFAULT
# 452 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 453 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FacePlayer
# 454 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 455 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
# 456 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 457 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
# 458 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 459 "data//maps/SlateportCity/scripts.pory"
	release
# 460 "data//maps/SlateportCity/scripts.pory"
	end
# 461 "data//maps/SlateportCity/scripts.pory"

# 462 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Movement_DelayAquaGrunt:
# 463 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 464 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 465 "data//maps/SlateportCity/scripts.pory"
	step_end
# 466 "data//maps/SlateportCity/scripts.pory"

# 467 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt10::
# 468 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ShouldveBroughtMyGameBoy, MSGBOX_SIGN
# 469 "data//maps/SlateportCity/scripts.pory"
	end
# 470 "data//maps/SlateportCity/scripts.pory"

# 471 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt11::
# 472 "data//maps/SlateportCity/scripts.pory"
	lock
# 473 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 474 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_HotSpringsAfterOperation, MSGBOX_DEFAULT
# 475 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 476 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_11, Common_Movement_FaceOriginalDirection
# 477 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 478 "data//maps/SlateportCity/scripts.pory"
	release
# 479 "data//maps/SlateportCity/scripts.pory"
	end
# 480 "data//maps/SlateportCity/scripts.pory"

# 481 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_DollClerk::
# 482 "data//maps/SlateportCity/scripts.pory"
	lock
# 483 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 484 "data//maps/SlateportCity/scripts.pory"
	message gText_HowMayIServeYou
# 485 "data//maps/SlateportCity/scripts.pory"
	waitmessage
# 486 "data//maps/SlateportCity/scripts.pory"
	pokemartdecoration SlateportCity_PokemartDecor_Dolls
# 487 "data//maps/SlateportCity/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 488 "data//maps/SlateportCity/scripts.pory"
	release
# 489 "data//maps/SlateportCity/scripts.pory"
	end
# 490 "data//maps/SlateportCity/scripts.pory"

# 491 "data//maps/SlateportCity/scripts.pory"
	.align 2
# 492 "data//maps/SlateportCity/scripts.pory"
SlateportCity_PokemartDecor_Dolls:
# 493 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_AZURILL_DOLL
# 494 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_MARILL_DOLL
# 495 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_SKITTY_DOLL
# 496 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_NONE
# 497 "data//maps/SlateportCity/scripts.pory"
	release
# 498 "data//maps/SlateportCity/scripts.pory"
	end
# 499 "data//maps/SlateportCity/scripts.pory"

# 500 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ComeBackWithSecretPower::
# 501 "data//maps/SlateportCity/scripts.pory"
	msgbox gText_ComeBackWithSecretPower, MSGBOX_DEFAULT
# 502 "data//maps/SlateportCity/scripts.pory"
	release
# 503 "data//maps/SlateportCity/scripts.pory"
	end
# 504 "data//maps/SlateportCity/scripts.pory"

# 505 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_DecorClerk::
# 506 "data//maps/SlateportCity/scripts.pory"
	lock
# 507 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 508 "data//maps/SlateportCity/scripts.pory"
	goto_if_unset FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_ComeBackWithSecretPower
# 509 "data//maps/SlateportCity/scripts.pory"
	message gText_HowMayIServeYou
# 510 "data//maps/SlateportCity/scripts.pory"
	waitmessage
# 511 "data//maps/SlateportCity/scripts.pory"
	pokemartdecoration SlateportCity_PokemartDecor
# 512 "data//maps/SlateportCity/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 513 "data//maps/SlateportCity/scripts.pory"
	release
# 514 "data//maps/SlateportCity/scripts.pory"
	end
# 515 "data//maps/SlateportCity/scripts.pory"

# 516 "data//maps/SlateportCity/scripts.pory"
	.align 2
# 517 "data//maps/SlateportCity/scripts.pory"
SlateportCity_PokemartDecor:
# 518 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_RED_BRICK
# 519 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_BLUE_BRICK
# 520 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_YELLOW_BRICK
# 521 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_RED_BALLOON
# 522 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_BLUE_BALLOON
# 523 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_YELLOW_BALLOON
# 524 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_C_LOW_NOTE_MAT
# 525 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_D_NOTE_MAT
# 526 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_E_NOTE_MAT
# 527 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_F_NOTE_MAT
# 528 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_G_NOTE_MAT
# 529 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_A_NOTE_MAT
# 530 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_B_NOTE_MAT
# 531 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_C_HIGH_NOTE_MAT
# 532 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_NONE
# 533 "data//maps/SlateportCity/scripts.pory"
	release
# 534 "data//maps/SlateportCity/scripts.pory"
	end
# 535 "data//maps/SlateportCity/scripts.pory"

# 536 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_PowerTMClerk::
# 537 "data//maps/SlateportCity/scripts.pory"
	lock
# 538 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 539 "data//maps/SlateportCity/scripts.pory"
	message gText_HowMayIServeYou
# 540 "data//maps/SlateportCity/scripts.pory"
	waitmessage
# 541 "data//maps/SlateportCity/scripts.pory"
	pokemart SlateportCity_Pokemart_PowerTMs
# 542 "data//maps/SlateportCity/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 543 "data//maps/SlateportCity/scripts.pory"
	release
# 544 "data//maps/SlateportCity/scripts.pory"
	end
# 545 "data//maps/SlateportCity/scripts.pory"

# 546 "data//maps/SlateportCity/scripts.pory"
	.align 2
# 547 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Pokemart_PowerTMs:
# 548 "data//maps/SlateportCity/scripts.pory"
	.2byte ITEM_TM_HIDDEN_POWER
# 549 "data//maps/SlateportCity/scripts.pory"
	.2byte ITEM_TM_SECRET_POWER
# 550 "data//maps/SlateportCity/scripts.pory"
	.2byte ITEM_NONE
# 551 "data//maps/SlateportCity/scripts.pory"
	release
# 552 "data//maps/SlateportCity/scripts.pory"
	end
# 553 "data//maps/SlateportCity/scripts.pory"

# 554 "data//maps/SlateportCity/scripts.pory"
@ Scene with Capt Sterns interview and Team Aqua announcing plans to steal Submarine
# 555 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_CaptStern::
# 556 "data//maps/SlateportCity/scripts.pory"
	lockall
# 557 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternMoveAheadWithExploration, MSGBOX_DEFAULT
# 558 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GabbyWonderfulThanksForInterview, MSGBOX_DEFAULT
# 559 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 560 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GABBY, Common_Movement_WalkInPlaceFasterRight
# 561 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 562 "data//maps/SlateportCity/scripts.pory"
	delay 10
# 563 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_TY, Common_Movement_WalkInPlaceFasterDown
# 564 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 565 "data//maps/SlateportCity/scripts.pory"
	delay 25
# 566 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_CAPT_STERN, SlateportCity_Movement_SternWatchGabbyAndTyExit
# 567 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerFaceStern
# 568 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GABBY, SlateportCity_Movement_GabbyExit
# 569 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_TY, SlateportCity_Movement_TyExit
# 570 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 571 "data//maps/SlateportCity/scripts.pory"
	removeobject LOCALID_SLATEPORT_GABBY
# 572 "data//maps/SlateportCity/scripts.pory"
	removeobject LOCALID_SLATEPORT_TY
# 573 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternWhewFirstInterview, MSGBOX_DEFAULT
# 574 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
# 575 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 576 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_OhPlayerWeMadeDiscovery, MSGBOX_DEFAULT
# 577 "data//maps/SlateportCity/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 578 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_AquaWillAssumeControlOfSubmarine, MSGBOX_DEFAULT
# 579 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_COOK, Common_Movement_WalkInPlaceFasterLeft
# 580 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_FAT_MAN, Common_Movement_WalkInPlaceFasterLeft
# 581 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_OLD_WOMAN, SlateportCity_Movement_OldWomanConcern
# 582 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_RICH_BOY, Common_Movement_QuestionMark
# 583 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_MAN_1, SlateportCity_Movement_ManConcern
# 584 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 585 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterDown
# 586 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 587 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternWhatWasAllThat, MSGBOX_DEFAULT
# 588 "data//maps/SlateportCity/scripts.pory"
	playse SE_PIN
# 589 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_ExclamationMark
# 590 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 591 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_Delay48
# 592 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 593 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
# 594 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 595 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_FromHarborTryingToTakeSub, MSGBOX_DEFAULT
# 596 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
# 597 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 598 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_CAPT_STERN, SlateportCity_Movement_SternEnterHarbor
# 599 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerEnterHarbor
# 600 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 601 "data//maps/SlateportCity/scripts.pory"
	removeobject LOCALID_SLATEPORT_CAPT_STERN
# 602 "data//maps/SlateportCity/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
# 603 "data//maps/SlateportCity/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW
# 604 "data//maps/SlateportCity/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT
# 605 "data//maps/SlateportCity/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE
# 606 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_SLATEPORT_CITY_STATE, 2
# 607 "data//maps/SlateportCity/scripts.pory"
	warp MAP_SLATEPORT_CITY_HARBOR, 11, 14
# 608 "data//maps/SlateportCity/scripts.pory"
	waitstate
# 609 "data//maps/SlateportCity/scripts.pory"
	releaseall
# 610 "data//maps/SlateportCity/scripts.pory"
	end
# 611 "data//maps/SlateportCity/scripts.pory"

# 612 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Movement_OldWomanConcern:
# 613 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 614 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 615 "data//maps/SlateportCity/scripts.pory"
	emote_question_mark
# 616 "data//maps/SlateportCity/scripts.pory"
	walk_in_place_faster_right
# 617 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 618 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 619 "data//maps/SlateportCity/scripts.pory"
	walk_in_place_faster_left
# 620 "data//maps/SlateportCity/scripts.pory"
	step_end
# 621 "data//maps/SlateportCity/scripts.pory"

# 622 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Movement_ManConcern:
# 623 "data//maps/SlateportCity/scripts.pory"
	emote_question_mark
# 624 "data//maps/SlateportCity/scripts.pory"
	walk_in_place_faster_up
# 625 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 626 "data//maps/SlateportCity/scripts.pory"
	walk_in_place_faster_down
# 627 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 628 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 629 "data//maps/SlateportCity/scripts.pory"
	walk_in_place_faster_left
# 630 "data//maps/SlateportCity/scripts.pory"
	step_end
# 631 "data//maps/SlateportCity/scripts.pory"

# 632 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Movement_GabbyExit:
# 633 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 634 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 635 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 636 "data//maps/SlateportCity/scripts.pory"
	walk_down
# 637 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 638 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 639 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 640 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 641 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 642 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 643 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 644 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 645 "data//maps/SlateportCity/scripts.pory"
	step_end
# 646 "data//maps/SlateportCity/scripts.pory"

# 647 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Movement_TyExit:
# 648 "data//maps/SlateportCity/scripts.pory"
	walk_down
# 649 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 650 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 651 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 652 "data//maps/SlateportCity/scripts.pory"
	walk_down
# 653 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 654 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 655 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 656 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 657 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 658 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 659 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 660 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 661 "data//maps/SlateportCity/scripts.pory"
	step_end
# 662 "data//maps/SlateportCity/scripts.pory"

# 663 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Movement_Unused:
# 664 "data//maps/SlateportCity/scripts.pory"
	walk_down
# 665 "data//maps/SlateportCity/scripts.pory"
	walk_in_place_faster_up
# 666 "data//maps/SlateportCity/scripts.pory"
	step_end
# 667 "data//maps/SlateportCity/scripts.pory"

# 668 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Movement_SternEnterHarbor:
# 669 "data//maps/SlateportCity/scripts.pory"
	walk_right
# 670 "data//maps/SlateportCity/scripts.pory"
	walk_up
# 671 "data//maps/SlateportCity/scripts.pory"
	walk_up
# 672 "data//maps/SlateportCity/scripts.pory"
	set_invisible
# 673 "data//maps/SlateportCity/scripts.pory"
	step_end
# 674 "data//maps/SlateportCity/scripts.pory"

# 675 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Movement_SternWatchGabbyAndTyExit:
# 676 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 677 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 678 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 679 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 680 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 681 "data//maps/SlateportCity/scripts.pory"
	walk_down
# 682 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 683 "data//maps/SlateportCity/scripts.pory"
	step_end
# 684 "data//maps/SlateportCity/scripts.pory"

# 685 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Movement_PlayerEnterHarbor:
# 686 "data//maps/SlateportCity/scripts.pory"
	walk_in_place_faster_right
# 687 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 688 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 689 "data//maps/SlateportCity/scripts.pory"
	walk_right
# 690 "data//maps/SlateportCity/scripts.pory"
	walk_up
# 691 "data//maps/SlateportCity/scripts.pory"
	step_end
# 692 "data//maps/SlateportCity/scripts.pory"

# 693 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Movement_PlayerFaceStern:
# 694 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 695 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 696 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 697 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 698 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 699 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 700 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 701 "data//maps/SlateportCity/scripts.pory"
	walk_in_place_faster_down
# 702 "data//maps/SlateportCity/scripts.pory"
	step_end
# 703 "data//maps/SlateportCity/scripts.pory"

# 704 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Ty::
# 705 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BigSmileForCamera, MSGBOX_SIGN
# 706 "data//maps/SlateportCity/scripts.pory"
	end
# 707 "data//maps/SlateportCity/scripts.pory"

# 708 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Gabby::
# 709 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_MostInvaluableExperience, MSGBOX_SIGN
# 710 "data//maps/SlateportCity/scripts.pory"
	end
# 711 "data//maps/SlateportCity/scripts.pory"

# 712 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Man3::
# 713 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WonderIfLighthouseStartlesPokemon, MSGBOX_NPC
# 714 "data//maps/SlateportCity/scripts.pory"
	end
# 715 "data//maps/SlateportCity/scripts.pory"

# 716 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_BerryPowderClerk::
# 717 "data//maps/SlateportCity/scripts.pory"
	lock
# 718 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 719 "data//maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_POWDER_JAR, SlateportCity_EventScript_ReceivedPowderJar
# 720 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ExplainBerries, MSGBOX_DEFAULT
# 721 "data//maps/SlateportCity/scripts.pory"
	giveitem ITEM_POWDER_JAR
# 722 "data//maps/SlateportCity/scripts.pory"
	setflag FLAG_RECEIVED_POWDER_JAR
# 723 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
# 724 "data//maps/SlateportCity/scripts.pory"
	release
# 725 "data//maps/SlateportCity/scripts.pory"
	end
# 726 "data//maps/SlateportCity/scripts.pory"

# 727 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ReceivedPowderJar::
# 728 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8004, 1
# 729 "data//maps/SlateportCity/scripts.pory"
	specialvar VAR_RESULT, HasEnoughBerryPowder
# 730 "data//maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_ExplainBerryPowder
# 731 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BroughtMeSomeBerryPowder, MSGBOX_DEFAULT
# 732 "data//maps/SlateportCity/scripts.pory"
	special DisplayBerryPowderVendorMenu
# 733 "data//maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_ChooseBerryPowderItem
# 734 "data//maps/SlateportCity/scripts.pory"
	end
# 735 "data//maps/SlateportCity/scripts.pory"

# 736 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ExplainBerryPowder::
# 737 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
# 738 "data//maps/SlateportCity/scripts.pory"
	release
# 739 "data//maps/SlateportCity/scripts.pory"
	end
# 740 "data//maps/SlateportCity/scripts.pory"

# 741 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ChooseBerryPowderItem::
# 742 "data//maps/SlateportCity/scripts.pory"
	message SlateportCity_Text_ExchangeWhatWithIt
# 743 "data//maps/SlateportCity/scripts.pory"
	waitmessage
# 744 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
# 745 "data//maps/SlateportCity/scripts.pory"
	special ShowScrollableMultichoice
# 746 "data//maps/SlateportCity/scripts.pory"
	waitstate
# 747 "data//maps/SlateportCity/scripts.pory"
	switch VAR_RESULT
# 748 "data//maps/SlateportCity/scripts.pory"
	case 0, SlateportCity_EventScript_EnergyPowder
# 749 "data//maps/SlateportCity/scripts.pory"
	case 1, SlateportCity_EventScript_EnergyRoot
# 750 "data//maps/SlateportCity/scripts.pory"
	case 2, SlateportCity_EventScript_HealPowder
# 751 "data//maps/SlateportCity/scripts.pory"
	case 3, SlateportCity_EventScript_RevivalHerb
# 752 "data//maps/SlateportCity/scripts.pory"
	case 4, SlateportCity_EventScript_Protein
# 753 "data//maps/SlateportCity/scripts.pory"
	case 5, SlateportCity_EventScript_Iron
# 754 "data//maps/SlateportCity/scripts.pory"
	case 6, SlateportCity_EventScript_Carbos
# 755 "data//maps/SlateportCity/scripts.pory"
	case 7, SlateportCity_EventScript_Calcium
# 756 "data//maps/SlateportCity/scripts.pory"
	case 8, SlateportCity_EventScript_Zinc
# 757 "data//maps/SlateportCity/scripts.pory"
	case 9, SlateportCity_EventScript_HPUp
# 758 "data//maps/SlateportCity/scripts.pory"
	case 10, SlateportCity_EventScript_PPUp
# 759 "data//maps/SlateportCity/scripts.pory"
	case 11, SlateportCity_EventScript_CancelPowderItemSelect
# 760 "data//maps/SlateportCity/scripts.pory"
	case MULTI_B_PRESSED, SlateportCity_EventScript_CancelPowderItemSelect
# 761 "data//maps/SlateportCity/scripts.pory"
	end
# 762 "data//maps/SlateportCity/scripts.pory"

# 763 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_EnergyPowder::
# 764 "data//maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_ENERGY_POWDER
# 765 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
# 766 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 50
# 767 "data//maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 768 "data//maps/SlateportCity/scripts.pory"
	end
# 769 "data//maps/SlateportCity/scripts.pory"

# 770 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_EnergyRoot::
# 771 "data//maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_ENERGY_ROOT
# 772 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
# 773 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 80
# 774 "data//maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 775 "data//maps/SlateportCity/scripts.pory"
	end
# 776 "data//maps/SlateportCity/scripts.pory"

# 777 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_HealPowder::
# 778 "data//maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_HEAL_POWDER
# 779 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_HEAL_POWDER
# 780 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 50
# 781 "data//maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 782 "data//maps/SlateportCity/scripts.pory"
	end
# 783 "data//maps/SlateportCity/scripts.pory"

# 784 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_RevivalHerb::
# 785 "data//maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_REVIVAL_HERB
# 786 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
# 787 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 300
# 788 "data//maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 789 "data//maps/SlateportCity/scripts.pory"
	end
# 790 "data//maps/SlateportCity/scripts.pory"

# 791 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Protein::
# 792 "data//maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_PROTEIN
# 793 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_PROTEIN
# 794 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 795 "data//maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 796 "data//maps/SlateportCity/scripts.pory"
	end
# 797 "data//maps/SlateportCity/scripts.pory"

# 798 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Iron::
# 799 "data//maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_IRON
# 800 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_IRON
# 801 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 802 "data//maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 803 "data//maps/SlateportCity/scripts.pory"
	end
# 804 "data//maps/SlateportCity/scripts.pory"

# 805 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Carbos::
# 806 "data//maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_CARBOS
# 807 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_CARBOS
# 808 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 809 "data//maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 810 "data//maps/SlateportCity/scripts.pory"
	end
# 811 "data//maps/SlateportCity/scripts.pory"

# 812 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Calcium::
# 813 "data//maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_CALCIUM
# 814 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_CALCIUM
# 815 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 816 "data//maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 817 "data//maps/SlateportCity/scripts.pory"
	end
# 818 "data//maps/SlateportCity/scripts.pory"

# 819 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Zinc::
# 820 "data//maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_ZINC
# 821 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_ZINC
# 822 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 823 "data//maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 824 "data//maps/SlateportCity/scripts.pory"
	end
# 825 "data//maps/SlateportCity/scripts.pory"

# 826 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_HPUp::
# 827 "data//maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_HP_UP
# 828 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_HP_UP
# 829 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 830 "data//maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 831 "data//maps/SlateportCity/scripts.pory"
	end
# 832 "data//maps/SlateportCity/scripts.pory"

# 833 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_PPUp::
# 834 "data//maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_PP_UP
# 835 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_PP_UP
# 836 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 3000
# 837 "data//maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 838 "data//maps/SlateportCity/scripts.pory"
	end
# 839 "data//maps/SlateportCity/scripts.pory"

# 840 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_CancelPowderItemSelect::
# 841 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ComeBackToTradeBerryPowder, MSGBOX_DEFAULT
# 842 "data//maps/SlateportCity/scripts.pory"
	special RemoveBerryPowderVendorMenu
# 843 "data//maps/SlateportCity/scripts.pory"
	release
# 844 "data//maps/SlateportCity/scripts.pory"
	end
# 845 "data//maps/SlateportCity/scripts.pory"

# 846 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_TryBuyBerryPowderItem::
# 847 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ExchangeBerryPowderForItem, MSGBOX_YESNO
# 848 "data//maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SlateportCity_EventScript_ChooseBerryPowderItem
# 849 "data//maps/SlateportCity/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8009
# 850 "data//maps/SlateportCity/scripts.pory"
	specialvar VAR_RESULT, HasEnoughBerryPowder
# 851 "data//maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NotEnoughBerryPowder
# 852 "data//maps/SlateportCity/scripts.pory"
	giveitem VAR_0x8008
# 853 "data//maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NoRoomForBerryPowderItem
# 854 "data//maps/SlateportCity/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8009
# 855 "data//maps/SlateportCity/scripts.pory"
	special TakeBerryPowder
# 856 "data//maps/SlateportCity/scripts.pory"
	special PrintPlayerBerryPowderAmount
# 857 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_FineBerryPowderTradeSomethingElse, MSGBOX_YESNO
# 858 "data//maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SlateportCity_EventScript_ChooseBerryPowderItem
# 859 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WhenYouGetMoreBringItToMe, MSGBOX_DEFAULT
# 860 "data//maps/SlateportCity/scripts.pory"
	special RemoveBerryPowderVendorMenu
# 861 "data//maps/SlateportCity/scripts.pory"
	release
# 862 "data//maps/SlateportCity/scripts.pory"
	end
# 863 "data//maps/SlateportCity/scripts.pory"

# 864 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_NoRoomForBerryPowderItem::
# 865 "data//maps/SlateportCity/scripts.pory"
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
# 866 "data//maps/SlateportCity/scripts.pory"
	special RemoveBerryPowderVendorMenu
# 867 "data//maps/SlateportCity/scripts.pory"
	release
# 868 "data//maps/SlateportCity/scripts.pory"
	end
# 869 "data//maps/SlateportCity/scripts.pory"

# 870 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_NotEnoughBerryPowder::
# 871 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_DontHaveEnoughBerryPowder, MSGBOX_DEFAULT
# 872 "data//maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_ChooseBerryPowderItem
# 873 "data//maps/SlateportCity/scripts.pory"
	end
# 874 "data//maps/SlateportCity/scripts.pory"

# 875 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ScottBattleTentScene::
# 876 "data//maps/SlateportCity/scripts.pory"
	lockall
# 877 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 878 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 879 "data//maps/SlateportCity/scripts.pory"
	opendoor 10, 12
# 880 "data//maps/SlateportCity/scripts.pory"
	waitdooranim
# 881 "data//maps/SlateportCity/scripts.pory"
	addobject LOCALID_SLATEPORT_SCOTT
# 882 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PushPlayerDown
# 883 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExitBattleTent
# 884 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 885 "data//maps/SlateportCity/scripts.pory"
	closedoor 10, 12
# 886 "data//maps/SlateportCity/scripts.pory"
	waitdooranim
# 887 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_TakingBattleTentChallenge, MSGBOX_DEFAULT
# 888 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 889 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerWatchScottExit
# 890 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExitAfterBattleTent
# 891 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 892 "data//maps/SlateportCity/scripts.pory"
	removeobject LOCALID_SLATEPORT_SCOTT
# 893 "data//maps/SlateportCity/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 894 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
# 895 "data//maps/SlateportCity/scripts.pory"
	releaseall
# 896 "data//maps/SlateportCity/scripts.pory"
	end
# 897 "data//maps/SlateportCity/scripts.pory"

# 898 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Movement_PushPlayerDown:
# 899 "data//maps/SlateportCity/scripts.pory"
	lock_facing_direction
# 900 "data//maps/SlateportCity/scripts.pory"
	walk_down
# 901 "data//maps/SlateportCity/scripts.pory"
	unlock_facing_direction
# 902 "data//maps/SlateportCity/scripts.pory"
	step_end
# 903 "data//maps/SlateportCity/scripts.pory"

# 904 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Movement_PlayerWatchScottExit:
# 905 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 906 "data//maps/SlateportCity/scripts.pory"
	walk_in_place_faster_right
# 907 "data//maps/SlateportCity/scripts.pory"
	step_end
# 908 "data//maps/SlateportCity/scripts.pory"

# 909 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Movement_ScottExitBattleTent:
# 910 "data//maps/SlateportCity/scripts.pory"
	delay_8
# 911 "data//maps/SlateportCity/scripts.pory"
	walk_down
# 912 "data//maps/SlateportCity/scripts.pory"
	step_end
# 913 "data//maps/SlateportCity/scripts.pory"

# 914 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Movement_ScottExitAfterBattleTent:
# 915 "data//maps/SlateportCity/scripts.pory"
	walk_right
# 916 "data//maps/SlateportCity/scripts.pory"
	walk_right
# 917 "data//maps/SlateportCity/scripts.pory"
	walk_right
# 918 "data//maps/SlateportCity/scripts.pory"
	walk_right
# 919 "data//maps/SlateportCity/scripts.pory"
	walk_right
# 920 "data//maps/SlateportCity/scripts.pory"
	walk_right
# 921 "data//maps/SlateportCity/scripts.pory"
	walk_right
# 922 "data//maps/SlateportCity/scripts.pory"
	walk_right
# 923 "data//maps/SlateportCity/scripts.pory"
	step_end
# 924 "data//maps/SlateportCity/scripts.pory"

# 925 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_BerryCrushRankingsSign::
# 926 "data//maps/SlateportCity/scripts.pory"
	lockall
# 927 "data//maps/SlateportCity/scripts.pory"
	special ShowBerryCrushRankings
# 928 "data//maps/SlateportCity/scripts.pory"
	waitstate
# 929 "data//maps/SlateportCity/scripts.pory"
	releaseall
# 930 "data//maps/SlateportCity/scripts.pory"
	end
# 931 "data//maps/SlateportCity/scripts.pory"

# 932 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_EnergyGuruSellWhatYouNeed:
# 933 "data//maps/SlateportCity/scripts.pory"
	.string "I'm the ENERGY GURU! I'll go for it and\n"
# 934 "data//maps/SlateportCity/scripts.pory"
	.string "sell you what you need!$"
# 935 "data//maps/SlateportCity/scripts.pory"

# 936 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_OhYourPokemon:
# 937 "data//maps/SlateportCity/scripts.pory"
	.string "Oh?\n"
# 938 "data//maps/SlateportCity/scripts.pory"
	.string "Your {STR_VAR_1}…$"
# 939 "data//maps/SlateportCity/scripts.pory"

# 940 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_PleaseGiveItThisEffortRibbon:
# 941 "data//maps/SlateportCity/scripts.pory"
	.string "Went for it stupendously!\p"
# 942 "data//maps/SlateportCity/scripts.pory"
	.string "As its reward, please give it this\n"
# 943 "data//maps/SlateportCity/scripts.pory"
	.string "EFFORT RIBBON.$"
# 944 "data//maps/SlateportCity/scripts.pory"

# 945 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_ReceivedEffortRibbon:
# 946 "data//maps/SlateportCity/scripts.pory"
	.string "{PLAYER} received the EFFORT RIBBON.$"
# 947 "data//maps/SlateportCity/scripts.pory"

# 948 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_PutEffortRibbonOnMon:
# 949 "data//maps/SlateportCity/scripts.pory"
	.string "{PLAYER} put the EFFORT RIBBON\n"
# 950 "data//maps/SlateportCity/scripts.pory"
	.string "on {STR_VAR_1}.$"
# 951 "data//maps/SlateportCity/scripts.pory"

# 952 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_GoForItLittleHarder:
# 953 "data//maps/SlateportCity/scripts.pory"
	.string "You have to go for it a little harder.\p"
# 954 "data//maps/SlateportCity/scripts.pory"
	.string "If you do, I'll give your POKéMON\n"
# 955 "data//maps/SlateportCity/scripts.pory"
	.string "something nice.$"
# 956 "data//maps/SlateportCity/scripts.pory"

# 957 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_EffortRibbonLooksGoodOnIt:
# 958 "data//maps/SlateportCity/scripts.pory"
	.string "Oh! Your {STR_VAR_1}, that EFFORT\n"
# 959 "data//maps/SlateportCity/scripts.pory"
	.string "RIBBON looks good on it!$"
# 960 "data//maps/SlateportCity/scripts.pory"

# 961 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_WonderIfLighthouseStartlesPokemon:
# 962 "data//maps/SlateportCity/scripts.pory"
	.string "The light of the lighthouse reaches\n"
# 963 "data//maps/SlateportCity/scripts.pory"
	.string "dozens of miles away.\p"
# 964 "data//maps/SlateportCity/scripts.pory"
	.string "I wonder if it doesn't startle POKéMON\n"
# 965 "data//maps/SlateportCity/scripts.pory"
	.string "in the sea.$"
# 966 "data//maps/SlateportCity/scripts.pory"

# 967 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_SeaweedFullOfLife:
# 968 "data//maps/SlateportCity/scripts.pory"
	.string "Ooh, look at this!\p"
# 969 "data//maps/SlateportCity/scripts.pory"
	.string "The seaweed you can get around these\n"
# 970 "data//maps/SlateportCity/scripts.pory"
	.string "parts is fresh and full of life.\p"
# 971 "data//maps/SlateportCity/scripts.pory"
	.string "Why, it looks like it can even rear up\n"
# 972 "data//maps/SlateportCity/scripts.pory"
	.string "and attack!$"
# 973 "data//maps/SlateportCity/scripts.pory"

# 974 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_HowTownIsBornAndGrows:
# 975 "data//maps/SlateportCity/scripts.pory"
	.string "Where the water is clean, the fruits\n"
# 976 "data//maps/SlateportCity/scripts.pory"
	.string "of bountiful harvest gather.\p"
# 977 "data//maps/SlateportCity/scripts.pory"
	.string "And where people gather, a market\n"
# 978 "data//maps/SlateportCity/scripts.pory"
	.string "soon starts.\p"
# 979 "data//maps/SlateportCity/scripts.pory"
	.string "That is how a town is born and grows.$"
# 980 "data//maps/SlateportCity/scripts.pory"

# 981 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_SlateportWonderfulPlace:
# 982 "data//maps/SlateportCity/scripts.pory"
	.string "Shopping where you can breathe the\n"
# 983 "data//maps/SlateportCity/scripts.pory"
	.string "scent of the ocean…\p"
# 984 "data//maps/SlateportCity/scripts.pory"
	.string "SLATEPORT is such a wonderful place!$"
# 985 "data//maps/SlateportCity/scripts.pory"

# 986 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_BuyBricksSoDecorWontGetDirty:
# 987 "data//maps/SlateportCity/scripts.pory"
	.string "If you put DOLLS or CUSHIONS on\n"
# 988 "data//maps/SlateportCity/scripts.pory"
	.string "the floor, they'll get dirty.\p"
# 989 "data//maps/SlateportCity/scripts.pory"
	.string "I'm going to buy some BRICKS so my\n"
# 990 "data//maps/SlateportCity/scripts.pory"
	.string "DOLLS and CUSHIONS won't get dirty\l"
# 991 "data//maps/SlateportCity/scripts.pory"
	.string "when I leave them out.$"
# 992 "data//maps/SlateportCity/scripts.pory"

# 993 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_GoingToCompeteInBattleTent:
# 994 "data//maps/SlateportCity/scripts.pory"
	.string "Wroooar! I'm going to compete in\n"
# 995 "data//maps/SlateportCity/scripts.pory"
	.string "the BATTLE TENT, too!\p"
# 996 "data//maps/SlateportCity/scripts.pory"
	.string "But before that, I need to catch\n"
# 997 "data//maps/SlateportCity/scripts.pory"
	.string "some POKéMON!$"
# 998 "data//maps/SlateportCity/scripts.pory"

# 999 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_BushedHikingFromMauville:
# 1000 "data//maps/SlateportCity/scripts.pory"
	.string "Whew… I'm just bushed…\p"
# 1001 "data//maps/SlateportCity/scripts.pory"
	.string "I hiked over from MAUVILLE CITY.\n"
# 1002 "data//maps/SlateportCity/scripts.pory"
	.string "But, boy, this city's huge.\p"
# 1003 "data//maps/SlateportCity/scripts.pory"
	.string "If I'd known this, I would've ridden\n"
# 1004 "data//maps/SlateportCity/scripts.pory"
	.string "my BIKE here.$"
# 1005 "data//maps/SlateportCity/scripts.pory"

# 1006 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_EveryoneCallsHimCaptStern:
# 1007 "data//maps/SlateportCity/scripts.pory"
	.string "STERN, the fellow who built the\n"
# 1008 "data//maps/SlateportCity/scripts.pory"
	.string "MUSEUM, also happens to be the leader\l"
# 1009 "data//maps/SlateportCity/scripts.pory"
	.string "of an undersea exploration team.\p"
# 1010 "data//maps/SlateportCity/scripts.pory"
	.string "So, everyone calls him CAPT. STERN.$"
# 1011 "data//maps/SlateportCity/scripts.pory"

# 1012 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_WhatsLongLineOverThere:
# 1013 "data//maps/SlateportCity/scripts.pory"
	.string "What is that over there?\n"
# 1014 "data//maps/SlateportCity/scripts.pory"
	.string "That long line…$"
# 1015 "data//maps/SlateportCity/scripts.pory"

# 1016 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_VisitedMuseumOften:
# 1017 "data//maps/SlateportCity/scripts.pory"
	.string "When I was a child, I visited\n"
# 1018 "data//maps/SlateportCity/scripts.pory"
	.string "the MUSEUM often.\p"
# 1019 "data//maps/SlateportCity/scripts.pory"
	.string "I used to dream about the mysteries of\n"
# 1020 "data//maps/SlateportCity/scripts.pory"
	.string "the sea after seeing the exhibits.$"
# 1021 "data//maps/SlateportCity/scripts.pory"

# 1022 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_QuitPushing:
# 1023 "data//maps/SlateportCity/scripts.pory"
	.string "Hey, there! Quit pushing!\n"
# 1024 "data//maps/SlateportCity/scripts.pory"
	.string "This is the line, can't you see?$"
# 1025 "data//maps/SlateportCity/scripts.pory"

# 1026 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_AquaHasPolicy:
# 1027 "data//maps/SlateportCity/scripts.pory"
	.string "TEAM AQUA has a policy of\n"
# 1028 "data//maps/SlateportCity/scripts.pory"
	.string "assembling and dispersing at\l"
# 1029 "data//maps/SlateportCity/scripts.pory"
	.string "the operation site.$"
# 1030 "data//maps/SlateportCity/scripts.pory"

# 1031 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_BossIsBrilliant:
# 1032 "data//maps/SlateportCity/scripts.pory"
	.string "Our BOSS is brilliant.\p"
# 1033 "data//maps/SlateportCity/scripts.pory"
	.string "What would he want to do with\n"
# 1034 "data//maps/SlateportCity/scripts.pory"
	.string "a MUSEUM now?$"
# 1035 "data//maps/SlateportCity/scripts.pory"

# 1036 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_WhatsNewSchemeIWonder:
# 1037 "data//maps/SlateportCity/scripts.pory"
	.string "What's the new scheme, I wonder?\p"
# 1038 "data//maps/SlateportCity/scripts.pory"
	.string "Our BOSS is scary when he's mad, so\n"
# 1039 "data//maps/SlateportCity/scripts.pory"
	.string "I'd better not screw things up…$"
# 1040 "data//maps/SlateportCity/scripts.pory"

# 1041 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_ShouldTakeItAll:
# 1042 "data//maps/SlateportCity/scripts.pory"
	.string "If there's something we need in\n"
# 1043 "data//maps/SlateportCity/scripts.pory"
	.string "the MUSEUM, we should take it all!$"
# 1044 "data//maps/SlateportCity/scripts.pory"

# 1045 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_DontButtIn:
# 1046 "data//maps/SlateportCity/scripts.pory"
	.string "Hey, you there!\n"
# 1047 "data//maps/SlateportCity/scripts.pory"
	.string "Don't butt in!$"
# 1048 "data//maps/SlateportCity/scripts.pory"

# 1049 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_RemindsMeOfLongLineForGames:
# 1050 "data//maps/SlateportCity/scripts.pory"
	.string "A long line, huh?\p"
# 1051 "data//maps/SlateportCity/scripts.pory"
	.string "It reminds me of the times I lined up to\n"
# 1052 "data//maps/SlateportCity/scripts.pory"
	.string "buy smash-hit games…$"
# 1053 "data//maps/SlateportCity/scripts.pory"

# 1054 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_WhyAreWeLiningUp:
# 1055 "data//maps/SlateportCity/scripts.pory"
	.string "Why are we even lining up and paying?\n"
# 1056 "data//maps/SlateportCity/scripts.pory"
	.string "We should just march in!$"
# 1057 "data//maps/SlateportCity/scripts.pory"

# 1058 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_WhatDoYouWant:
# 1059 "data//maps/SlateportCity/scripts.pory"
	.string "What?\n"
# 1060 "data//maps/SlateportCity/scripts.pory"
	.string "What do you want?$"
# 1061 "data//maps/SlateportCity/scripts.pory"

# 1062 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_IllReadSignForYou:
# 1063 "data//maps/SlateportCity/scripts.pory"
	.string "You want to read this sign?\n"
# 1064 "data//maps/SlateportCity/scripts.pory"
	.string "I'll read it for you!$"
# 1065 "data//maps/SlateportCity/scripts.pory"

# 1066 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_SaysSomethingLikeSeaIsEndless:
# 1067 "data//maps/SlateportCity/scripts.pory"
	.string "Let's see…\p"
# 1068 "data//maps/SlateportCity/scripts.pory"
	.string "Um… I think it says something like\n"
# 1069 "data//maps/SlateportCity/scripts.pory"
	.string "“the life in the sea is endless.”\p"
# 1070 "data//maps/SlateportCity/scripts.pory"
	.string "Yup, I'm pretty sure that's what\n"
# 1071 "data//maps/SlateportCity/scripts.pory"
	.string "it says.$"
# 1072 "data//maps/SlateportCity/scripts.pory"

# 1073 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_ShouldveBroughtMyGameBoy:
# 1074 "data//maps/SlateportCity/scripts.pory"
	.string "Grumble…\p"
# 1075 "data//maps/SlateportCity/scripts.pory"
	.string "I should've brought my Game Boy\n"
# 1076 "data//maps/SlateportCity/scripts.pory"
	.string "Advance so I wouldn't get bored in line…\p"
# 1077 "data//maps/SlateportCity/scripts.pory"
	.string "Grumble…$"
# 1078 "data//maps/SlateportCity/scripts.pory"

# 1079 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_HotSpringsAfterOperation:
# 1080 "data//maps/SlateportCity/scripts.pory"
	.string "When this operation's over, I'll take\n"
# 1081 "data//maps/SlateportCity/scripts.pory"
	.string "you to a hot spring spa!\p"
# 1082 "data//maps/SlateportCity/scripts.pory"
	.string "That's what our leader said.\n"
# 1083 "data//maps/SlateportCity/scripts.pory"
	.string "I can't wait!$"
# 1084 "data//maps/SlateportCity/scripts.pory"

# 1085 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_SeaIsSoWet:
# 1086 "data//maps/SlateportCity/scripts.pory"
	.string "The sea is just so vast…\p"
# 1087 "data//maps/SlateportCity/scripts.pory"
	.string "Could the sea have been made by\n"
# 1088 "data//maps/SlateportCity/scripts.pory"
	.string "the tears shed by POKéMON?$"
# 1089 "data//maps/SlateportCity/scripts.pory"

# 1090 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_SinkOldBoats:
# 1091 "data//maps/SlateportCity/scripts.pory"
	.string "Do you know what they do with old\n"
# 1092 "data//maps/SlateportCity/scripts.pory"
	.string "ships that become too creaky to sail?\p"
# 1093 "data//maps/SlateportCity/scripts.pory"
	.string "They sink them in the sea so they\n"
# 1094 "data//maps/SlateportCity/scripts.pory"
	.string "become habitats for POKéMON.$"
# 1095 "data//maps/SlateportCity/scripts.pory"

# 1096 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_BuyTooMuch:
# 1097 "data//maps/SlateportCity/scripts.pory"
	.string "Whenever I visit here, I get carried\n"
# 1098 "data//maps/SlateportCity/scripts.pory"
	.string "away and buy too much.$"
# 1099 "data//maps/SlateportCity/scripts.pory"

# 1100 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_GetNameRaterToHelpYou:
# 1101 "data//maps/SlateportCity/scripts.pory"
	.string "If you want to change your POKéMON's\n"
# 1102 "data//maps/SlateportCity/scripts.pory"
	.string "nickname, you'll have to get the NAME\l"
# 1103 "data//maps/SlateportCity/scripts.pory"
	.string "RATER to help you.$"
# 1104 "data//maps/SlateportCity/scripts.pory"

# 1105 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_CantChangeTradeMonName:
# 1106 "data//maps/SlateportCity/scripts.pory"
	.string "Any POKéMON you get in a trade,\n"
# 1107 "data//maps/SlateportCity/scripts.pory"
	.string "you can't change its nickname.\p"
# 1108 "data//maps/SlateportCity/scripts.pory"
	.string "The original TRAINER's love for that\n"
# 1109 "data//maps/SlateportCity/scripts.pory"
	.string "POKéMON is in the nickname.$"
# 1110 "data//maps/SlateportCity/scripts.pory"

# 1111 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_BattleTentBuiltRecently:
# 1112 "data//maps/SlateportCity/scripts.pory"
	.string "Recently, a BATTLE TENT was built\n"
# 1113 "data//maps/SlateportCity/scripts.pory"
	.string "in SLATEPORT.\p"
# 1114 "data//maps/SlateportCity/scripts.pory"
	.string "GYMS are fun, but the BATTLE TENT's\n"
# 1115 "data//maps/SlateportCity/scripts.pory"
	.string "awesome in its own way.\p"
# 1116 "data//maps/SlateportCity/scripts.pory"
	.string "You should go find tough POKéMON\n"
# 1117 "data//maps/SlateportCity/scripts.pory"
	.string "for the BATTLE TENT!$"
# 1118 "data//maps/SlateportCity/scripts.pory"

# 1119 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_CaptSternBeingInterviewed:
# 1120 "data//maps/SlateportCity/scripts.pory"
	.string "I was hoping that it was a famous star\n"
# 1121 "data//maps/SlateportCity/scripts.pory"
	.string "so I could get an autograph.\p"
# 1122 "data//maps/SlateportCity/scripts.pory"
	.string "But who's that being interviewed?\n"
# 1123 "data//maps/SlateportCity/scripts.pory"
	.string "Isn't that CAPT. STERN?$"
# 1124 "data//maps/SlateportCity/scripts.pory"

# 1125 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_InterviewerSoCool:
# 1126 "data//maps/SlateportCity/scripts.pory"
	.string "That lady interviewer is so cool\n"
# 1127 "data//maps/SlateportCity/scripts.pory"
	.string "and pretty.\p"
# 1128 "data//maps/SlateportCity/scripts.pory"
	.string "When I grow up, I'm going to be\n"
# 1129 "data//maps/SlateportCity/scripts.pory"
	.string "an international journalist!$"
# 1130 "data//maps/SlateportCity/scripts.pory"

# 1131 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternSaysDiscoveredSomething:
# 1132 "data//maps/SlateportCity/scripts.pory"
	.string "CAPT. STERN says they discovered\n"
# 1133 "data//maps/SlateportCity/scripts.pory"
	.string "something at the bottom of the sea.\p"
# 1134 "data//maps/SlateportCity/scripts.pory"
	.string "I wonder what it is?\n"
# 1135 "data//maps/SlateportCity/scripts.pory"
	.string "What could it be?$"
# 1136 "data//maps/SlateportCity/scripts.pory"

# 1137 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_CaptainComeBackWithBigFish:
# 1138 "data//maps/SlateportCity/scripts.pory"
	.string "What's going on here?\p"
# 1139 "data//maps/SlateportCity/scripts.pory"
	.string "Did the good CAPTAIN come back with\n"
# 1140 "data//maps/SlateportCity/scripts.pory"
	.string "a big fish from the ocean floor?$"
# 1141 "data//maps/SlateportCity/scripts.pory"

# 1142 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_AmIOnTV:
# 1143 "data//maps/SlateportCity/scripts.pory"
	.string "Hey! Are you watching?\n"
# 1144 "data//maps/SlateportCity/scripts.pory"
	.string "Am I on TV?$"
# 1145 "data//maps/SlateportCity/scripts.pory"

# 1146 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_CaptainsACelebrity:
# 1147 "data//maps/SlateportCity/scripts.pory"
	.string "A TV interview! Here!\n"
# 1148 "data//maps/SlateportCity/scripts.pory"
	.string "The CAPTAIN's a celebrity!$"
# 1149 "data//maps/SlateportCity/scripts.pory"

# 1150 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_BigSmileForCamera:
# 1151 "data//maps/SlateportCity/scripts.pory"
	.string "TY: Okay, CAPT. STERN, a big smile\n"
# 1152 "data//maps/SlateportCity/scripts.pory"
	.string "for the camera!$"
# 1153 "data//maps/SlateportCity/scripts.pory"

# 1154 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_MostInvaluableExperience:
# 1155 "data//maps/SlateportCity/scripts.pory"
	.string "GABBY: I see, I see. You've had a most\n"
# 1156 "data//maps/SlateportCity/scripts.pory"
	.string "invaluable experience…$"
# 1157 "data//maps/SlateportCity/scripts.pory"

# 1158 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternMoveAheadWithExploration:
# 1159 "data//maps/SlateportCity/scripts.pory"
	.string "CAPT. STERN: Yes, indeed. We intend to\n"
# 1160 "data//maps/SlateportCity/scripts.pory"
	.string "move ahead with our exploration.$"
# 1161 "data//maps/SlateportCity/scripts.pory"

# 1162 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_GabbyWonderfulThanksForInterview:
# 1163 "data//maps/SlateportCity/scripts.pory"
	.string "GABBY: That's wonderful, CAPT. STERN!\n"
# 1164 "data//maps/SlateportCity/scripts.pory"
	.string "Thank you for taking the time from\l"
# 1165 "data//maps/SlateportCity/scripts.pory"
	.string "your busy schedule to talk to us.\p"
# 1166 "data//maps/SlateportCity/scripts.pory"
	.string "We hope we can interview you again\n"
# 1167 "data//maps/SlateportCity/scripts.pory"
	.string "with news of more discoveries!$"
# 1168 "data//maps/SlateportCity/scripts.pory"

# 1169 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternWhewFirstInterview:
# 1170 "data//maps/SlateportCity/scripts.pory"
	.string "CAPT. STERN: Whew…\p"
# 1171 "data//maps/SlateportCity/scripts.pory"
	.string "That was my first time to be filmed for\n"
# 1172 "data//maps/SlateportCity/scripts.pory"
	.string "TV. That was nerve-wracking.$"
# 1173 "data//maps/SlateportCity/scripts.pory"

# 1174 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_OhPlayerWeMadeDiscovery:
# 1175 "data//maps/SlateportCity/scripts.pory"
	.string "Oh! {PLAYER}{KUN}!\n"
# 1176 "data//maps/SlateportCity/scripts.pory"
	.string "You're looking great!\p"
# 1177 "data//maps/SlateportCity/scripts.pory"
	.string "We made a huge discovery on our last\n"
# 1178 "data//maps/SlateportCity/scripts.pory"
	.string "seafloor exploration.\p"
# 1179 "data//maps/SlateportCity/scripts.pory"
	.string "We found an underwater cavern on\n"
# 1180 "data//maps/SlateportCity/scripts.pory"
	.string "ROUTE 128.\p"
# 1181 "data//maps/SlateportCity/scripts.pory"
	.string "We think it's the habitat of a POKéMON\n"
# 1182 "data//maps/SlateportCity/scripts.pory"
	.string "that's said to have been long extinct.$"
# 1183 "data//maps/SlateportCity/scripts.pory"

# 1184 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_AquaWillAssumeControlOfSubmarine:
# 1185 "data//maps/SlateportCity/scripts.pory"
	.string "Fufufu…\n"
# 1186 "data//maps/SlateportCity/scripts.pory"
	.string "CAPT. STERN, I presume.\p"
# 1187 "data//maps/SlateportCity/scripts.pory"
	.string "We of TEAM AQUA will assume\n"
# 1188 "data//maps/SlateportCity/scripts.pory"
	.string "control of your submarine!\p"
# 1189 "data//maps/SlateportCity/scripts.pory"
	.string "Your objections are meaningless!\n"
# 1190 "data//maps/SlateportCity/scripts.pory"
	.string "We expect your total cooperation!\p"
# 1191 "data//maps/SlateportCity/scripts.pory"
	.string "Fufufu…\n"
# 1192 "data//maps/SlateportCity/scripts.pory"
	.string "Just watch and learn what TEAM\l"
# 1193 "data//maps/SlateportCity/scripts.pory"
	.string "AQUA has planned!$"
# 1194 "data//maps/SlateportCity/scripts.pory"

# 1195 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternWhatWasAllThat:
# 1196 "data//maps/SlateportCity/scripts.pory"
	.string "CAPT. STERN: What was that all about?\p"
# 1197 "data//maps/SlateportCity/scripts.pory"
	.string "It sounded like someone using\n"
# 1198 "data//maps/SlateportCity/scripts.pory"
	.string "a megaphone…\p"
# 1199 "data//maps/SlateportCity/scripts.pory"
	.string "Where did it come from?$"
# 1200 "data//maps/SlateportCity/scripts.pory"

# 1201 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_FromHarborTryingToTakeSub:
# 1202 "data//maps/SlateportCity/scripts.pory"
	.string "It's from the HARBOR!\p"
# 1203 "data//maps/SlateportCity/scripts.pory"
	.string "The submarine!\n"
# 1204 "data//maps/SlateportCity/scripts.pory"
	.string "They're trying to take it!$"
# 1205 "data//maps/SlateportCity/scripts.pory"

# 1206 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_PleaseComeWithMe:
# 1207 "data//maps/SlateportCity/scripts.pory"
	.string "{PLAYER}{KUN}!\n"
# 1208 "data//maps/SlateportCity/scripts.pory"
	.string "Please, come with me!$"
# 1209 "data//maps/SlateportCity/scripts.pory"

# 1210 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_BattleTentSign:
# 1211 "data//maps/SlateportCity/scripts.pory"
	.string "BATTLE TENT SLATEPORT SITE\n"
# 1212 "data//maps/SlateportCity/scripts.pory"
	.string "“Find it! The ultimate POKéMON!”$"
# 1213 "data//maps/SlateportCity/scripts.pory"

# 1214 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternsShipyardWantedSign:
# 1215 "data//maps/SlateportCity/scripts.pory"
	.string "STERN'S SHIPYARD\p"
# 1216 "data//maps/SlateportCity/scripts.pory"
	.string "“Wanted: A sailor capable of sailing\n"
# 1217 "data//maps/SlateportCity/scripts.pory"
	.string "in all currents.”$"
# 1218 "data//maps/SlateportCity/scripts.pory"

# 1219 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternsShipyardNearsCompletion:
# 1220 "data//maps/SlateportCity/scripts.pory"
	.string "STERN'S SHIPYARD\p"
# 1221 "data//maps/SlateportCity/scripts.pory"
	.string "“The ferry S.S. TIDAL nears\n"
# 1222 "data//maps/SlateportCity/scripts.pory"
	.string "completion for serving the ports of\l"
# 1223 "data//maps/SlateportCity/scripts.pory"
	.string "SLATEPORT and LILYCOVE.”$"
# 1224 "data//maps/SlateportCity/scripts.pory"

# 1225 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternsShipyardFerryComplete:
# 1226 "data//maps/SlateportCity/scripts.pory"
	.string "STERN'S SHIPYARD\p"
# 1227 "data//maps/SlateportCity/scripts.pory"
	.string "“Boarding of the SLATEPORT-LILYCOVE\n"
# 1228 "data//maps/SlateportCity/scripts.pory"
	.string "ferry S.S. TIDAL is handled at the\l"
# 1229 "data//maps/SlateportCity/scripts.pory"
	.string "HARBOR.”$"
# 1230 "data//maps/SlateportCity/scripts.pory"

# 1231 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_PokemonFanClubSign:
# 1232 "data//maps/SlateportCity/scripts.pory"
	.string "POKéMON FAN CLUB\n"
# 1233 "data//maps/SlateportCity/scripts.pory"
	.string "“Calling all fans of POKéMON!”$"
# 1234 "data//maps/SlateportCity/scripts.pory"

# 1235 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_OceanicMuseumSign:
# 1236 "data//maps/SlateportCity/scripts.pory"
	.string "“The endless sea sustains\n"
# 1237 "data//maps/SlateportCity/scripts.pory"
	.string "all life.”\p"
# 1238 "data//maps/SlateportCity/scripts.pory"
	.string "OCEANIC MUSEUM$"
# 1239 "data//maps/SlateportCity/scripts.pory"

# 1240 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_CitySign:
# 1241 "data//maps/SlateportCity/scripts.pory"
	.string "SLATEPORT CITY\p"
# 1242 "data//maps/SlateportCity/scripts.pory"
	.string "“The port where people and POKéMON\n"
# 1243 "data//maps/SlateportCity/scripts.pory"
	.string "cross paths.”$"
# 1244 "data//maps/SlateportCity/scripts.pory"

# 1245 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_MarketSign:
# 1246 "data//maps/SlateportCity/scripts.pory"
	.string "SLATEPORT MARKET\n"
# 1247 "data//maps/SlateportCity/scripts.pory"
	.string "“Unique items found nowhere else!”$"
# 1248 "data//maps/SlateportCity/scripts.pory"

# 1249 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_HarborFerryUnderConstruction:
# 1250 "data//maps/SlateportCity/scripts.pory"
	.string "SLATEPORT HARBOR\p"
# 1251 "data//maps/SlateportCity/scripts.pory"
	.string "“The ferry S.S. TIDAL is under\n"
# 1252 "data//maps/SlateportCity/scripts.pory"
	.string "construction in the SHIPYARD.\p"
# 1253 "data//maps/SlateportCity/scripts.pory"
	.string "“Service is scheduled to begin\n"
# 1254 "data//maps/SlateportCity/scripts.pory"
	.string "shortly.”$"
# 1255 "data//maps/SlateportCity/scripts.pory"

# 1256 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_HarborSign:
# 1257 "data//maps/SlateportCity/scripts.pory"
	.string "SLATEPORT HARBOR\p"
# 1258 "data//maps/SlateportCity/scripts.pory"
	.string "“Enjoy a delightful cruise on\n"
# 1259 "data//maps/SlateportCity/scripts.pory"
	.string "the ferry S.S. TIDAL.”$"
# 1260 "data//maps/SlateportCity/scripts.pory"

# 1261 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_NameRatersHouseSign:
# 1262 "data//maps/SlateportCity/scripts.pory"
	.string "NAME RATER'S HOUSE\n"
# 1263 "data//maps/SlateportCity/scripts.pory"
	.string "“POKéMON nicknames rated.”$"
# 1264 "data//maps/SlateportCity/scripts.pory"

# 1265 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_ExplainBerries:
# 1266 "data//maps/SlateportCity/scripts.pory"
	.string "If a wild POKéMON gets hurt, it heals\n"
# 1267 "data//maps/SlateportCity/scripts.pory"
	.string "itself by chewing on BERRIES.\p"
# 1268 "data//maps/SlateportCity/scripts.pory"
	.string "Did you know that?\p"
# 1269 "data//maps/SlateportCity/scripts.pory"
	.string "Somebody saw that and got the idea\n"
# 1270 "data//maps/SlateportCity/scripts.pory"
	.string "of making medicine from BERRIES.\p"
# 1271 "data//maps/SlateportCity/scripts.pory"
	.string "Did you know that?\p"
# 1272 "data//maps/SlateportCity/scripts.pory"
	.string "To turn BERRIES into medicine,\n"
# 1273 "data//maps/SlateportCity/scripts.pory"
	.string "they must be crushed into powder.\p"
# 1274 "data//maps/SlateportCity/scripts.pory"
	.string "Did you know that?\p"
# 1275 "data//maps/SlateportCity/scripts.pory"
	.string "You seem to have an interest\n"
# 1276 "data//maps/SlateportCity/scripts.pory"
	.string "in BERRIES!\p"
# 1277 "data//maps/SlateportCity/scripts.pory"
	.string "I've got something good for someone\n"
# 1278 "data//maps/SlateportCity/scripts.pory"
	.string "like you.$"
# 1279 "data//maps/SlateportCity/scripts.pory"

# 1280 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_ExplainBerryPowder:
# 1281 "data//maps/SlateportCity/scripts.pory"
	.string "I recently had machines installed at\n"
# 1282 "data//maps/SlateportCity/scripts.pory"
	.string "POKéMON CENTERS for crushing BERRIES.\p"
# 1283 "data//maps/SlateportCity/scripts.pory"
	.string "The BERRY CRUSH machines are at\n"
# 1284 "data//maps/SlateportCity/scripts.pory"
	.string "the DIRECT CORNER upstairs.\p"
# 1285 "data//maps/SlateportCity/scripts.pory"
	.string "Did you know?\p"
# 1286 "data//maps/SlateportCity/scripts.pory"
	.string "Could you make BERRY POWDER for\n"
# 1287 "data//maps/SlateportCity/scripts.pory"
	.string "me using those machines?\p"
# 1288 "data//maps/SlateportCity/scripts.pory"
	.string "I can make you all sorts of medicine\n"
# 1289 "data//maps/SlateportCity/scripts.pory"
	.string "if you bring me lots of BERRY POWDER.$"
# 1290 "data//maps/SlateportCity/scripts.pory"

# 1291 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_BroughtMeSomeBerryPowder:
# 1292 "data//maps/SlateportCity/scripts.pory"
	.string "Have you brought me some\n"
# 1293 "data//maps/SlateportCity/scripts.pory"
	.string "BERRY POWDER?$"
# 1294 "data//maps/SlateportCity/scripts.pory"

# 1295 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_ExchangeWhatWithIt:
# 1296 "data//maps/SlateportCity/scripts.pory"
	.string "What would you like to exchange\n"
# 1297 "data//maps/SlateportCity/scripts.pory"
	.string "it with?$"
# 1298 "data//maps/SlateportCity/scripts.pory"

# 1299 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_ExchangeBerryPowderForItem:
# 1300 "data//maps/SlateportCity/scripts.pory"
	.string "Okay, you want to exchange your\n"
# 1301 "data//maps/SlateportCity/scripts.pory"
	.string "BERRY POWDER for one {STR_VAR_1}?$"
# 1302 "data//maps/SlateportCity/scripts.pory"

# 1303 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_DontHaveEnoughBerryPowder:
# 1304 "data//maps/SlateportCity/scripts.pory"
	.string "Oh, dear. You don't have enough\n"
# 1305 "data//maps/SlateportCity/scripts.pory"
	.string "BERRY POWDER.$"
# 1306 "data//maps/SlateportCity/scripts.pory"

# 1307 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_FineBerryPowderTradeSomethingElse:
# 1308 "data//maps/SlateportCity/scripts.pory"
	.string "This is fine BERRY POWDER.\n"
# 1309 "data//maps/SlateportCity/scripts.pory"
	.string "It will make excellent medicine.\p"
# 1310 "data//maps/SlateportCity/scripts.pory"
	.string "Would you like to trade more of your\n"
# 1311 "data//maps/SlateportCity/scripts.pory"
	.string "BERRY POWDER for something else?$"
# 1312 "data//maps/SlateportCity/scripts.pory"

# 1313 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_WhenYouGetMoreBringItToMe:
# 1314 "data//maps/SlateportCity/scripts.pory"
	.string "Okay! When you get some more\n"
# 1315 "data//maps/SlateportCity/scripts.pory"
	.string "BERRY POWDER, bring it to me, please!$"
# 1316 "data//maps/SlateportCity/scripts.pory"

# 1317 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_ComeBackToTradeBerryPowder:
# 1318 "data//maps/SlateportCity/scripts.pory"
	.string "Come back if you'd like to trade your\n"
# 1319 "data//maps/SlateportCity/scripts.pory"
	.string "BERRY POWDER for some medicine.\p"
# 1320 "data//maps/SlateportCity/scripts.pory"
	.string "I'm always running a bazaar here.\p"
# 1321 "data//maps/SlateportCity/scripts.pory"
	.string "Did you know?$"
# 1322 "data//maps/SlateportCity/scripts.pory"

# 1323 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_YouDroveTeamAquaAway:
# 1324 "data//maps/SlateportCity/scripts.pory"
	.string "SCOTT: Huh?\n"
# 1325 "data//maps/SlateportCity/scripts.pory"
	.string "I'm sure I met you somewhere before.\p"
# 1326 "data//maps/SlateportCity/scripts.pory"
	.string "Have I introduced myself to you?\n"
# 1327 "data//maps/SlateportCity/scripts.pory"
	.string "If not, my name's SCOTT.\p"
# 1328 "data//maps/SlateportCity/scripts.pory"
	.string "I just saw TEAM AQUA run away from\n"
# 1329 "data//maps/SlateportCity/scripts.pory"
	.string "here like they were stung.\p"
# 1330 "data//maps/SlateportCity/scripts.pory"
	.string "Let me guess--you drove them away?$"
# 1331 "data//maps/SlateportCity/scripts.pory"

# 1332 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_MaybeThisTrainer:
# 1333 "data//maps/SlateportCity/scripts.pory"
	.string "SCOTT: Hmm…\n"
# 1334 "data//maps/SlateportCity/scripts.pory"
	.string "Maybe, just maybe, this TRAINER…$"
# 1335 "data//maps/SlateportCity/scripts.pory"

# 1336 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_LetsRegisterEachOther:
# 1337 "data//maps/SlateportCity/scripts.pory"
	.string "SCOTT: All right! I think you're going\n"
# 1338 "data//maps/SlateportCity/scripts.pory"
	.string "to become a good friend.\p"
# 1339 "data//maps/SlateportCity/scripts.pory"
	.string "So, let's register each other in our\n"
# 1340 "data//maps/SlateportCity/scripts.pory"
	.string "POKéNAVS.\p"
# 1341 "data//maps/SlateportCity/scripts.pory"
	.string "… … … … … …$"
# 1342 "data//maps/SlateportCity/scripts.pory"

# 1343 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_RegisteredScott:
# 1344 "data//maps/SlateportCity/scripts.pory"
	.string "Registered this SCOTT person\n"
# 1345 "data//maps/SlateportCity/scripts.pory"
	.string "in the POKéNAV.$"
# 1346 "data//maps/SlateportCity/scripts.pory"

# 1347 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou:
# 1348 "data//maps/SlateportCity/scripts.pory"
	.string "SCOTT: What I'd like to do is tag along\n"
# 1349 "data//maps/SlateportCity/scripts.pory"
	.string "with you, but I do want to keep an eye\l"
# 1350 "data//maps/SlateportCity/scripts.pory"
	.string "on the talents of other people, too.\p"
# 1351 "data//maps/SlateportCity/scripts.pory"
	.string "So, I'll be off to roam other towns\n"
# 1352 "data//maps/SlateportCity/scripts.pory"
	.string "a bit more.\p"
# 1353 "data//maps/SlateportCity/scripts.pory"
	.string "Be seeing you, {PLAYER}{KUN}!$"
# 1354 "data//maps/SlateportCity/scripts.pory"

# 1355 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_TakingBattleTentChallenge:
# 1356 "data//maps/SlateportCity/scripts.pory"
	.string "SCOTT: Oh, hey!\n"
# 1357 "data//maps/SlateportCity/scripts.pory"
	.string "If it isn't {PLAYER}{KUN}!\p"
# 1358 "data//maps/SlateportCity/scripts.pory"
	.string "{PLAYER}{KUN}, let me guess--you're going\n"
# 1359 "data//maps/SlateportCity/scripts.pory"
	.string "to take the BATTLE TENT challenge?\p"
# 1360 "data//maps/SlateportCity/scripts.pory"
	.string "Yeah! That's a good idea!\n"
# 1361 "data//maps/SlateportCity/scripts.pory"
	.string "That's a really great idea!\p"
# 1362 "data//maps/SlateportCity/scripts.pory"
	.string "After all, a tough TRAINER is\n"
# 1363 "data//maps/SlateportCity/scripts.pory"
	.string "the perfect fit for the BATTLE TENT!\p"
# 1364 "data//maps/SlateportCity/scripts.pory"
	.string "Give it your best effort!$"
