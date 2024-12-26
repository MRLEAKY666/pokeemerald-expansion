# 1 "data//maps/SlateportCity/scripts.pory"

# 2 "data//maps/SlateportCity/scripts.pory"
.set LOCALID_FAT_MAN, 1
# 3 "data//maps/SlateportCity/scripts.pory"
.set LOCALID_MAN_1, 2
# 4 "data//maps/SlateportCity/scripts.pory"
.set LOCALID_RICH_BOY, 3
# 5 "data//maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_1, 5
# 6 "data//maps/SlateportCity/scripts.pory"
.set LOCALID_COOK, 6
# 7 "data//maps/SlateportCity/scripts.pory"
.set LOCALID_OLD_WOMAN, 7
# 8 "data//maps/SlateportCity/scripts.pory"
.set LOCALID_GIRL, 8
# 9 "data//maps/SlateportCity/scripts.pory"
.set LOCALID_TY, 9
# 10 "data//maps/SlateportCity/scripts.pory"
.set LOCALID_GABBY, 10
# 11 "data//maps/SlateportCity/scripts.pory"
.set LOCALID_CAPT_STERN, 11
# 12 "data//maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_2, 18
# 13 "data//maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_3, 19
# 14 "data//maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_4, 26
# 15 "data//maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_5, 27
# 16 "data//maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_6, 28
# 17 "data//maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_7, 29
# 18 "data//maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_8, 30
# 19 "data//maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_9, 31
# 20 "data//maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_11, 33
# 21 "data//maps/SlateportCity/scripts.pory"
.set LOCALID_SCOTT, 35
# 22 "data//maps/SlateportCity/scripts.pory"

# 23 "data//maps/SlateportCity/scripts.pory"
@ Note: LOCALID_SLATEPORT_ENERGY_GURU is a local id for this map used elsewhere. It's defined in event_objects.h
# 24 "data//maps/SlateportCity/scripts.pory"

# 25 "data//maps/SlateportCity/scripts.pory"
SlateportCity_MapScripts::
# 26 "data//maps/SlateportCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OnTransition
# 27 "data//maps/SlateportCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_OnFrame
# 28 "data//maps/SlateportCity/scripts.pory"
	.byte 0
# 29 "data//maps/SlateportCity/scripts.pory"

# 30 "data//maps/SlateportCity/scripts.pory"
SlateportCity_OnTransition:
# 31 "data//maps/SlateportCity/scripts.pory"
	setflag FLAG_SYS_SAVE_GET
# 32 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0
# 33 "data//maps/SlateportCity/scripts.pory"
	call SlateportCity_EventScript_EnterSlateport
# 34 "data//maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_MovePeopleForSternInterview
# 35 "data//maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_SetReadyForScottScene
# 36 "data//maps/SlateportCity/scripts.pory"
	end
# 37 "data//maps/SlateportCity/scripts.pory"

# 38 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_EnterSlateport::
# 39 "data//maps/SlateportCity/scripts.pory"
	setflag FLAG_VISITED_SLATEPORT_CITY
# 40 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_CONTEST_HALL_STATE, 0
# 41 "data//maps/SlateportCity/scripts.pory"
	setflag FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER
# 42 "data//maps/SlateportCity/scripts.pory"
	return
# 43 "data//maps/SlateportCity/scripts.pory"

# 44 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_MovePeopleForSternInterview::
# 45 "data//maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_CAPT_STERN, 28, 13
# 46 "data//maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_OLD_WOMAN, 25, 13
# 47 "data//maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_RICH_BOY, 25, 14
# 48 "data//maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_COOK, 27, 16
# 49 "data//maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_GIRL, 28, 16
# 50 "data//maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_FAT_MAN, 29, 16
# 51 "data//maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_MAN_1, 31, 14
# 52 "data//maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_CAPT_STERN, MOVEMENT_TYPE_FACE_DOWN
# 53 "data//maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_OLD_WOMAN, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
# 54 "data//maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_RICH_BOY, MOVEMENT_TYPE_FACE_UP_AND_RIGHT
# 55 "data//maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_COOK, MOVEMENT_TYPE_FACE_UP
# 56 "data//maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_GIRL, MOVEMENT_TYPE_FACE_UP
# 57 "data//maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_FAT_MAN, MOVEMENT_TYPE_FACE_UP
# 58 "data//maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_MAN_1, MOVEMENT_TYPE_FACE_LEFT
# 59 "data//maps/SlateportCity/scripts.pory"
	return
# 60 "data//maps/SlateportCity/scripts.pory"

# 61 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_SetReadyForScottScene::
# 62 "data//maps/SlateportCity/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 63 "data//maps/SlateportCity/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 64 "data//maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_0x8004, 30, SlateportCity_EventScript_MoveScottLeft
# 65 "data//maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SCOTT, 23, 27
# 66 "data//maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
# 67 "data//maps/SlateportCity/scripts.pory"
	return
# 68 "data//maps/SlateportCity/scripts.pory"

# 69 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_MoveScottLeft::
# 70 "data//maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SCOTT, 22, 27
# 71 "data//maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
# 72 "data//maps/SlateportCity/scripts.pory"
	return
# 73 "data//maps/SlateportCity/scripts.pory"

# 74 "data//maps/SlateportCity/scripts.pory"
SlateportCity_OnFrame:
# 75 "data//maps/SlateportCity/scripts.pory"
	map_script_2 VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_ScottScene
# 76 "data//maps/SlateportCity/scripts.pory"
	.2byte 0
# 77 "data//maps/SlateportCity/scripts.pory"

# 78 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ScottScene::
# 79 "data//maps/SlateportCity/scripts.pory"
	lockall
# 80 "data//maps/SlateportCity/scripts.pory"
	addobject LOCALID_SCOTT
# 81 "data//maps/SlateportCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerFaceScott
# 82 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottApproachPlayer
# 83 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 84 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_YouDroveTeamAquaAway, MSGBOX_DEFAULT
# 85 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 86 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterLeft
# 87 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 88 "data//maps/SlateportCity/scripts.pory"
	delay 60
# 89 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_MaybeThisTrainer, MSGBOX_DEFAULT
# 90 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterRight
# 91 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 92 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_LetsRegisterEachOther, MSGBOX_DEFAULT
# 93 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 94 "data//maps/SlateportCity/scripts.pory"
	delay 30
# 95 "data//maps/SlateportCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 96 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_RegisteredScott, MSGBOX_DEFAULT
# 97 "data//maps/SlateportCity/scripts.pory"
	waitfanfare
# 98 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 99 "data//maps/SlateportCity/scripts.pory"
	delay 30
# 100 "data//maps/SlateportCity/scripts.pory"
	setflag FLAG_ENABLE_SCOTT_MATCH_CALL
# 101 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou, MSGBOX_DEFAULT
# 102 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 103 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExit
# 104 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 105 "data//maps/SlateportCity/scripts.pory"
	removeobject LOCALID_SCOTT
# 106 "data//maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SCOTT, 10, 12
# 107 "data//maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_DOWN
# 108 "data//maps/SlateportCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 109 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 2
# 110 "data//maps/SlateportCity/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 111 "data//maps/SlateportCity/scripts.pory"
	releaseall
# 112 "data//maps/SlateportCity/scripts.pory"
	end
# 113 "data//maps/SlateportCity/scripts.pory"

# 114 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Movement_PlayerFaceScott:
# 115 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 116 "data//maps/SlateportCity/scripts.pory"
	delay_8
# 117 "data//maps/SlateportCity/scripts.pory"
	walk_in_place_faster_left
# 118 "data//maps/SlateportCity/scripts.pory"
	step_end
# 119 "data//maps/SlateportCity/scripts.pory"

# 120 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Movement_ScottApproachPlayer:
# 121 "data//maps/SlateportCity/scripts.pory"
	walk_right
# 122 "data//maps/SlateportCity/scripts.pory"
	walk_right
# 123 "data//maps/SlateportCity/scripts.pory"
	walk_right
# 124 "data//maps/SlateportCity/scripts.pory"
	walk_right
# 125 "data//maps/SlateportCity/scripts.pory"
	walk_right
# 126 "data//maps/SlateportCity/scripts.pory"
	walk_right
# 127 "data//maps/SlateportCity/scripts.pory"
	walk_right
# 128 "data//maps/SlateportCity/scripts.pory"
	step_end
# 129 "data//maps/SlateportCity/scripts.pory"

# 130 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Movement_ScottExit:
# 131 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 132 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 133 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 134 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 135 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 136 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 137 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 138 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 139 "data//maps/SlateportCity/scripts.pory"
	step_end
# 140 "data//maps/SlateportCity/scripts.pory"

# 141 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_EnergyGuru::
# 142 "data//maps/SlateportCity/scripts.pory"
	lock
# 143 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 144 "data//maps/SlateportCity/scripts.pory"
	message SlateportCity_Text_EnergyGuruSellWhatYouNeed
# 145 "data//maps/SlateportCity/scripts.pory"
	waitmessage
# 146 "data//maps/SlateportCity/scripts.pory"
	pokemart SlateportCity_Pokemart_EnergyGuru
# 147 "data//maps/SlateportCity/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 148 "data//maps/SlateportCity/scripts.pory"
	release
# 149 "data//maps/SlateportCity/scripts.pory"
	end
# 150 "data//maps/SlateportCity/scripts.pory"

# 151 "data//maps/SlateportCity/scripts.pory"
	.align 2
# 152 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Pokemart_EnergyGuru:
# 153 "data//maps/SlateportCity/scripts.pory"
	.2byte ITEM_PROTEIN
# 154 "data//maps/SlateportCity/scripts.pory"
	.2byte ITEM_IRON
# 155 "data//maps/SlateportCity/scripts.pory"
	.2byte ITEM_CARBOS
# 156 "data//maps/SlateportCity/scripts.pory"
	.2byte ITEM_ZINC
# 157 "data//maps/SlateportCity/scripts.pory"
	.2byte ITEM_CALCIUM
# 158 "data//maps/SlateportCity/scripts.pory"
	.2byte ITEM_HP_UP
# 159 "data//maps/SlateportCity/scripts.pory"
	.2byte ITEM_PP_UP
# 160 "data//maps/SlateportCity/scripts.pory"
	.2byte ITEM_NONE
# 161 "data//maps/SlateportCity/scripts.pory"
	release
# 162 "data//maps/SlateportCity/scripts.pory"
	end
# 163 "data//maps/SlateportCity/scripts.pory"

# 164 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_EffortRibbonWoman::
# 165 "data//maps/SlateportCity/scripts.pory"
	lock
# 166 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 167 "data//maps/SlateportCity/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 168 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_OhYourPokemon, MSGBOX_DEFAULT
# 169 "data//maps/SlateportCity/scripts.pory"
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
# 170 "data//maps/SlateportCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, SlateportCity_EventScript_MonHasEffortRibbon
# 171 "data//maps/SlateportCity/scripts.pory"
	specialvar VAR_RESULT, Special_AreLeadMonEVsMaxedOut
# 172 "data//maps/SlateportCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_MonEVsNotMaxed
# 173 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_PleaseGiveItThisEffortRibbon, MSGBOX_DEFAULT
# 174 "data//maps/SlateportCity/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 175 "data//maps/SlateportCity/scripts.pory"
	message SlateportCity_Text_ReceivedEffortRibbon
# 176 "data//maps/SlateportCity/scripts.pory"
	waitfanfare
# 177 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_PutEffortRibbonOnMon, MSGBOX_DEFAULT
# 178 "data//maps/SlateportCity/scripts.pory"
	special GiveLeadMonEffortRibbon
# 179 "data//maps/SlateportCity/scripts.pory"
	release
# 180 "data//maps/SlateportCity/scripts.pory"
	end
# 181 "data//maps/SlateportCity/scripts.pory"

# 182 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_MonEVsNotMaxed::
# 183 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GoForItLittleHarder, MSGBOX_DEFAULT
# 184 "data//maps/SlateportCity/scripts.pory"
	release
# 185 "data//maps/SlateportCity/scripts.pory"
	end
# 186 "data//maps/SlateportCity/scripts.pory"

# 187 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_MonHasEffortRibbon::
# 188 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_EffortRibbonLooksGoodOnIt, MSGBOX_DEFAULT
# 189 "data//maps/SlateportCity/scripts.pory"
	release
# 190 "data//maps/SlateportCity/scripts.pory"
	end
# 191 "data//maps/SlateportCity/scripts.pory"

# 192 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Cook::
# 193 "data//maps/SlateportCity/scripts.pory"
	lock
# 194 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 195 "data//maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_CookSternInterview
# 196 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SeaweedFullOfLife, MSGBOX_DEFAULT
# 197 "data//maps/SlateportCity/scripts.pory"
	release
# 198 "data//maps/SlateportCity/scripts.pory"
	end
# 199 "data//maps/SlateportCity/scripts.pory"

# 200 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_CookSternInterview::
# 201 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_CaptainComeBackWithBigFish, MSGBOX_DEFAULT
# 202 "data//maps/SlateportCity/scripts.pory"
	release
# 203 "data//maps/SlateportCity/scripts.pory"
	end
# 204 "data//maps/SlateportCity/scripts.pory"

# 205 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_OldWoman::
# 206 "data//maps/SlateportCity/scripts.pory"
	lock
# 207 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 208 "data//maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_OldWomanSternInterview
# 209 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_HowTownIsBornAndGrows, MSGBOX_DEFAULT
# 210 "data//maps/SlateportCity/scripts.pory"
	release
# 211 "data//maps/SlateportCity/scripts.pory"
	end
# 212 "data//maps/SlateportCity/scripts.pory"

# 213 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_OldWomanSternInterview::
# 214 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_CaptSternBeingInterviewed, MSGBOX_DEFAULT
# 215 "data//maps/SlateportCity/scripts.pory"
	release
# 216 "data//maps/SlateportCity/scripts.pory"
	end
# 217 "data//maps/SlateportCity/scripts.pory"

# 218 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Girl::
# 219 "data//maps/SlateportCity/scripts.pory"
	lock
# 220 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 221 "data//maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_GirlSternInterview
# 222 "data//maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_GirlSecretBase
# 223 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SlateportWonderfulPlace, MSGBOX_DEFAULT
# 224 "data//maps/SlateportCity/scripts.pory"
	release
# 225 "data//maps/SlateportCity/scripts.pory"
	end
# 226 "data//maps/SlateportCity/scripts.pory"

# 227 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_GirlSternInterview::
# 228 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_InterviewerSoCool, MSGBOX_DEFAULT
# 229 "data//maps/SlateportCity/scripts.pory"
	release
# 230 "data//maps/SlateportCity/scripts.pory"
	end
# 231 "data//maps/SlateportCity/scripts.pory"

# 232 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_GirlSecretBase::
# 233 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BuyBricksSoDecorWontGetDirty, MSGBOX_DEFAULT
# 234 "data//maps/SlateportCity/scripts.pory"
	release
# 235 "data//maps/SlateportCity/scripts.pory"
	end
# 236 "data//maps/SlateportCity/scripts.pory"

# 237 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_RichBoy::
# 238 "data//maps/SlateportCity/scripts.pory"
	lock
# 239 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 240 "data//maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_RichBoySternInterview
# 241 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GoingToCompeteInBattleTent, MSGBOX_DEFAULT
# 242 "data//maps/SlateportCity/scripts.pory"
	release
# 243 "data//maps/SlateportCity/scripts.pory"
	end
# 244 "data//maps/SlateportCity/scripts.pory"

# 245 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_RichBoySternInterview::
# 246 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternSaysDiscoveredSomething, MSGBOX_DEFAULT
# 247 "data//maps/SlateportCity/scripts.pory"
	release
# 248 "data//maps/SlateportCity/scripts.pory"
	end
# 249 "data//maps/SlateportCity/scripts.pory"

# 250 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_FatMan::
# 251 "data//maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_FatManSternInterview
# 252 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BushedHikingFromMauville, MSGBOX_NPC
# 253 "data//maps/SlateportCity/scripts.pory"
	end
# 254 "data//maps/SlateportCity/scripts.pory"

# 255 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_FatManSternInterview::
# 256 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_AmIOnTV, MSGBOX_SIGN
# 257 "data//maps/SlateportCity/scripts.pory"
	end
# 258 "data//maps/SlateportCity/scripts.pory"

# 259 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Man1::
# 260 "data//maps/SlateportCity/scripts.pory"
	lock
# 261 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 262 "data//maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_Man1SternInterview
# 263 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_EveryoneCallsHimCaptStern, MSGBOX_DEFAULT
# 264 "data//maps/SlateportCity/scripts.pory"
	release
# 265 "data//maps/SlateportCity/scripts.pory"
	end
# 266 "data//maps/SlateportCity/scripts.pory"

# 267 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Man1SternInterview::
# 268 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_CaptainsACelebrity, MSGBOX_DEFAULT
# 269 "data//maps/SlateportCity/scripts.pory"
	release
# 270 "data//maps/SlateportCity/scripts.pory"
	end
# 271 "data//maps/SlateportCity/scripts.pory"

# 272 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Woman1::
# 273 "data//maps/SlateportCity/scripts.pory"
	lock
# 274 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 275 "data//maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_EventScript_Woman1AquaGone
# 276 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WhatsLongLineOverThere, MSGBOX_DEFAULT
# 277 "data//maps/SlateportCity/scripts.pory"
	release
# 278 "data//maps/SlateportCity/scripts.pory"
	end
# 279 "data//maps/SlateportCity/scripts.pory"

# 280 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Woman1AquaGone::
# 281 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_VisitedMuseumOften, MSGBOX_DEFAULT
# 282 "data//maps/SlateportCity/scripts.pory"
	release
# 283 "data//maps/SlateportCity/scripts.pory"
	end
# 284 "data//maps/SlateportCity/scripts.pory"

# 285 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_BattleTentSign::
# 286 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BattleTentSign, MSGBOX_SIGN
# 287 "data//maps/SlateportCity/scripts.pory"
	end
# 288 "data//maps/SlateportCity/scripts.pory"

# 289 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_SternsShipyardSign::
# 290 "data//maps/SlateportCity/scripts.pory"
	lockall
# 291 "data//maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_SternsShipyardFerryComplete
# 292 "data//maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, SlateportCity_EventScript_SternsShipyardNearsCompletion
# 293 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternsShipyardWantedSign, MSGBOX_DEFAULT
# 294 "data//maps/SlateportCity/scripts.pory"
	releaseall
# 295 "data//maps/SlateportCity/scripts.pory"
	end
# 296 "data//maps/SlateportCity/scripts.pory"

# 297 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_SternsShipyardNearsCompletion::
# 298 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternsShipyardNearsCompletion, MSGBOX_DEFAULT
# 299 "data//maps/SlateportCity/scripts.pory"
	releaseall
# 300 "data//maps/SlateportCity/scripts.pory"
	end
# 301 "data//maps/SlateportCity/scripts.pory"

# 302 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_SternsShipyardFerryComplete::
# 303 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternsShipyardFerryComplete, MSGBOX_DEFAULT
# 304 "data//maps/SlateportCity/scripts.pory"
	releaseall
# 305 "data//maps/SlateportCity/scripts.pory"
	end
# 306 "data//maps/SlateportCity/scripts.pory"

# 307 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_PokemonFanClubSign::
# 308 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_PokemonFanClubSign, MSGBOX_SIGN
# 309 "data//maps/SlateportCity/scripts.pory"
	end
# 310 "data//maps/SlateportCity/scripts.pory"

# 311 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_OceanicMuseumSign::
# 312 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_OceanicMuseumSign, MSGBOX_SIGN
# 313 "data//maps/SlateportCity/scripts.pory"
	end
# 314 "data//maps/SlateportCity/scripts.pory"

# 315 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_CitySign::
# 316 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_CitySign, MSGBOX_SIGN
# 317 "data//maps/SlateportCity/scripts.pory"
	end
# 318 "data//maps/SlateportCity/scripts.pory"

# 319 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_MarketSign::
# 320 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_MarketSign, MSGBOX_SIGN
# 321 "data//maps/SlateportCity/scripts.pory"
	end
# 322 "data//maps/SlateportCity/scripts.pory"

# 323 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_HarborSign::
# 324 "data//maps/SlateportCity/scripts.pory"
	lockall
# 325 "data//maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_HarborSignFerryComplete
# 326 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_HarborFerryUnderConstruction, MSGBOX_DEFAULT
# 327 "data//maps/SlateportCity/scripts.pory"
	releaseall
# 328 "data//maps/SlateportCity/scripts.pory"
	end
# 329 "data//maps/SlateportCity/scripts.pory"

# 330 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_HarborSignFerryComplete::
# 331 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_HarborSign, MSGBOX_DEFAULT
# 332 "data//maps/SlateportCity/scripts.pory"
	releaseall
# 333 "data//maps/SlateportCity/scripts.pory"
	end
# 334 "data//maps/SlateportCity/scripts.pory"

# 335 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_NameRatersHouseSign::
# 336 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_NameRatersHouseSign, MSGBOX_SIGN
# 337 "data//maps/SlateportCity/scripts.pory"
	end
# 338 "data//maps/SlateportCity/scripts.pory"

# 339 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Maniac::
# 340 "data//maps/SlateportCity/scripts.pory"
	lock
# 341 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 342 "data//maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_ManiacSternInterview
# 343 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
# 344 "data//maps/SlateportCity/scripts.pory"
	release
# 345 "data//maps/SlateportCity/scripts.pory"
	end
# 346 "data//maps/SlateportCity/scripts.pory"

# 347 "data//maps/SlateportCity/scripts.pory"
@ Unclear if the text here was meant to be different, but its not
# 348 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ManiacSternInterview::
# 349 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
# 350 "data//maps/SlateportCity/scripts.pory"
	release
# 351 "data//maps/SlateportCity/scripts.pory"
	end
# 352 "data//maps/SlateportCity/scripts.pory"

# 353 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Woman2::
# 354 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_CantChangeTradeMonName, MSGBOX_NPC
# 355 "data//maps/SlateportCity/scripts.pory"
	end
# 356 "data//maps/SlateportCity/scripts.pory"

# 357 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Sailor1::
# 358 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SeaIsSoWet, MSGBOX_NPC
# 359 "data//maps/SlateportCity/scripts.pory"
	end
# 360 "data//maps/SlateportCity/scripts.pory"

# 361 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Sailor2::
# 362 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SinkOldBoats, MSGBOX_NPC
# 363 "data//maps/SlateportCity/scripts.pory"
	end
# 364 "data//maps/SlateportCity/scripts.pory"

# 365 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_PokefanF::
# 366 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BuyTooMuch, MSGBOX_NPC
# 367 "data//maps/SlateportCity/scripts.pory"
	end
# 368 "data//maps/SlateportCity/scripts.pory"

# 369 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Man2::
# 370 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BattleTentBuiltRecently, MSGBOX_NPC
# 371 "data//maps/SlateportCity/scripts.pory"
	end
# 372 "data//maps/SlateportCity/scripts.pory"

# 373 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt1::
# 374 "data//maps/SlateportCity/scripts.pory"
	lock
# 375 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 376 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_QuitPushing, MSGBOX_DEFAULT
# 377 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 378 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_1, Common_Movement_FaceOriginalDirection
# 379 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 380 "data//maps/SlateportCity/scripts.pory"
	release
# 381 "data//maps/SlateportCity/scripts.pory"
	end
# 382 "data//maps/SlateportCity/scripts.pory"

# 383 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt2::
# 384 "data//maps/SlateportCity/scripts.pory"
	lock
# 385 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 386 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_AquaHasPolicy, MSGBOX_DEFAULT
# 387 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 388 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_2, Common_Movement_FaceOriginalDirection
# 389 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 390 "data//maps/SlateportCity/scripts.pory"
	release
# 391 "data//maps/SlateportCity/scripts.pory"
	end
# 392 "data//maps/SlateportCity/scripts.pory"

# 393 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt3::
# 394 "data//maps/SlateportCity/scripts.pory"
	lock
# 395 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 396 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BossIsBrilliant, MSGBOX_DEFAULT
# 397 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 398 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_3, Common_Movement_FaceOriginalDirection
# 399 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 400 "data//maps/SlateportCity/scripts.pory"
	release
# 401 "data//maps/SlateportCity/scripts.pory"
	end
# 402 "data//maps/SlateportCity/scripts.pory"

# 403 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt4::
# 404 "data//maps/SlateportCity/scripts.pory"
	lock
# 405 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 406 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WhatsNewSchemeIWonder, MSGBOX_DEFAULT
# 407 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 408 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_4, Common_Movement_FaceOriginalDirection
# 409 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 410 "data//maps/SlateportCity/scripts.pory"
	release
# 411 "data//maps/SlateportCity/scripts.pory"
	end
# 412 "data//maps/SlateportCity/scripts.pory"

# 413 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt5::
# 414 "data//maps/SlateportCity/scripts.pory"
	lock
# 415 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 416 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ShouldTakeItAll, MSGBOX_DEFAULT
# 417 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 418 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_5, Common_Movement_FaceOriginalDirection
# 419 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 420 "data//maps/SlateportCity/scripts.pory"
	release
# 421 "data//maps/SlateportCity/scripts.pory"
	end
# 422 "data//maps/SlateportCity/scripts.pory"

# 423 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt6::
# 424 "data//maps/SlateportCity/scripts.pory"
	lock
# 425 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 426 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_DontButtIn, MSGBOX_DEFAULT
# 427 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 428 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_6, Common_Movement_FaceOriginalDirection
# 429 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 430 "data//maps/SlateportCity/scripts.pory"
	release
# 431 "data//maps/SlateportCity/scripts.pory"
	end
# 432 "data//maps/SlateportCity/scripts.pory"

# 433 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt7::
# 434 "data//maps/SlateportCity/scripts.pory"
	lock
# 435 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 436 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_RemindsMeOfLongLineForGames, MSGBOX_DEFAULT
# 437 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 438 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_7, Common_Movement_FaceOriginalDirection
# 439 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 440 "data//maps/SlateportCity/scripts.pory"
	release
# 441 "data//maps/SlateportCity/scripts.pory"
	end
# 442 "data//maps/SlateportCity/scripts.pory"

# 443 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt8::
# 444 "data//maps/SlateportCity/scripts.pory"
	lock
# 445 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 446 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WhyAreWeLiningUp, MSGBOX_DEFAULT
# 447 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 448 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_8, Common_Movement_FaceOriginalDirection
# 449 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 450 "data//maps/SlateportCity/scripts.pory"
	release
# 451 "data//maps/SlateportCity/scripts.pory"
	end
# 452 "data//maps/SlateportCity/scripts.pory"

# 453 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt9::
# 454 "data//maps/SlateportCity/scripts.pory"
	lock
# 455 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 456 "data//maps/SlateportCity/scripts.pory"
	playse SE_PIN
# 457 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, Common_Movement_ExclamationMark
# 458 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 459 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, Common_Movement_Delay48
# 460 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 461 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WhatDoYouWant, MSGBOX_DEFAULT
# 462 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 463 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
# 464 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 465 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
# 466 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 467 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, Common_Movement_FacePlayer
# 468 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 469 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_IllReadSignForYou, MSGBOX_DEFAULT
# 470 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 471 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
# 472 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 473 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
# 474 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 475 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SaysSomethingLikeSeaIsEndless, MSGBOX_DEFAULT
# 476 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 477 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, Common_Movement_FacePlayer
# 478 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 479 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
# 480 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 481 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
# 482 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 483 "data//maps/SlateportCity/scripts.pory"
	release
# 484 "data//maps/SlateportCity/scripts.pory"
	end
# 485 "data//maps/SlateportCity/scripts.pory"

# 486 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Movement_DelayAquaGrunt:
# 487 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 488 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 489 "data//maps/SlateportCity/scripts.pory"
	step_end
# 490 "data//maps/SlateportCity/scripts.pory"

# 491 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt10::
# 492 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ShouldveBroughtMyGameBoy, MSGBOX_SIGN
# 493 "data//maps/SlateportCity/scripts.pory"
	end
# 494 "data//maps/SlateportCity/scripts.pory"

# 495 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt11::
# 496 "data//maps/SlateportCity/scripts.pory"
	lock
# 497 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 498 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_HotSpringsAfterOperation, MSGBOX_DEFAULT
# 499 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 500 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_11, Common_Movement_FaceOriginalDirection
# 501 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 502 "data//maps/SlateportCity/scripts.pory"
	release
# 503 "data//maps/SlateportCity/scripts.pory"
	end
# 504 "data//maps/SlateportCity/scripts.pory"

# 505 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_DollClerk::
# 506 "data//maps/SlateportCity/scripts.pory"
	lock
# 507 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 508 "data//maps/SlateportCity/scripts.pory"
	message gText_HowMayIServeYou
# 509 "data//maps/SlateportCity/scripts.pory"
	waitmessage
# 510 "data//maps/SlateportCity/scripts.pory"
	pokemartdecoration SlateportCity_PokemartDecor_Dolls
# 511 "data//maps/SlateportCity/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 512 "data//maps/SlateportCity/scripts.pory"
	release
# 513 "data//maps/SlateportCity/scripts.pory"
	end
# 514 "data//maps/SlateportCity/scripts.pory"

# 515 "data//maps/SlateportCity/scripts.pory"
	.align 2
# 516 "data//maps/SlateportCity/scripts.pory"
SlateportCity_PokemartDecor_Dolls:
# 517 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_AZURILL_DOLL
# 518 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_MARILL_DOLL
# 519 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_SKITTY_DOLL
# 520 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_NONE
# 521 "data//maps/SlateportCity/scripts.pory"
	release
# 522 "data//maps/SlateportCity/scripts.pory"
	end
# 523 "data//maps/SlateportCity/scripts.pory"

# 524 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ComeBackWithSecretPower::
# 525 "data//maps/SlateportCity/scripts.pory"
	msgbox gText_ComeBackWithSecretPower, MSGBOX_DEFAULT
# 526 "data//maps/SlateportCity/scripts.pory"
	release
# 527 "data//maps/SlateportCity/scripts.pory"
	end
# 528 "data//maps/SlateportCity/scripts.pory"

# 529 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_DecorClerk::
# 530 "data//maps/SlateportCity/scripts.pory"
	lock
# 531 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 532 "data//maps/SlateportCity/scripts.pory"
	goto_if_unset FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_ComeBackWithSecretPower
# 533 "data//maps/SlateportCity/scripts.pory"
	message gText_HowMayIServeYou
# 534 "data//maps/SlateportCity/scripts.pory"
	waitmessage
# 535 "data//maps/SlateportCity/scripts.pory"
	pokemartdecoration SlateportCity_PokemartDecor
# 536 "data//maps/SlateportCity/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 537 "data//maps/SlateportCity/scripts.pory"
	release
# 538 "data//maps/SlateportCity/scripts.pory"
	end
# 539 "data//maps/SlateportCity/scripts.pory"

# 540 "data//maps/SlateportCity/scripts.pory"
	.align 2
# 541 "data//maps/SlateportCity/scripts.pory"
SlateportCity_PokemartDecor:
# 542 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_RED_BRICK
# 543 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_BLUE_BRICK
# 544 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_YELLOW_BRICK
# 545 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_RED_BALLOON
# 546 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_BLUE_BALLOON
# 547 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_YELLOW_BALLOON
# 548 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_C_LOW_NOTE_MAT
# 549 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_D_NOTE_MAT
# 550 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_E_NOTE_MAT
# 551 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_F_NOTE_MAT
# 552 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_G_NOTE_MAT
# 553 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_A_NOTE_MAT
# 554 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_B_NOTE_MAT
# 555 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_C_HIGH_NOTE_MAT
# 556 "data//maps/SlateportCity/scripts.pory"
	.2byte DECOR_NONE
# 557 "data//maps/SlateportCity/scripts.pory"
	release
# 558 "data//maps/SlateportCity/scripts.pory"
	end
# 559 "data//maps/SlateportCity/scripts.pory"

# 560 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_PowerTMClerk::
# 561 "data//maps/SlateportCity/scripts.pory"
	lock
# 562 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 563 "data//maps/SlateportCity/scripts.pory"
	message gText_HowMayIServeYou
# 564 "data//maps/SlateportCity/scripts.pory"
	waitmessage
# 565 "data//maps/SlateportCity/scripts.pory"
	pokemart SlateportCity_Pokemart_PowerTMs
# 566 "data//maps/SlateportCity/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 567 "data//maps/SlateportCity/scripts.pory"
	release
# 568 "data//maps/SlateportCity/scripts.pory"
	end
# 569 "data//maps/SlateportCity/scripts.pory"

# 570 "data//maps/SlateportCity/scripts.pory"
	.align 2
# 571 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Pokemart_PowerTMs:
# 572 "data//maps/SlateportCity/scripts.pory"
	.2byte ITEM_TM_HIDDEN_POWER
# 573 "data//maps/SlateportCity/scripts.pory"
	.2byte ITEM_TM_SECRET_POWER
# 574 "data//maps/SlateportCity/scripts.pory"
	.2byte ITEM_NONE
# 575 "data//maps/SlateportCity/scripts.pory"
	release
# 576 "data//maps/SlateportCity/scripts.pory"
	end
# 577 "data//maps/SlateportCity/scripts.pory"

# 578 "data//maps/SlateportCity/scripts.pory"
@ Scene with Capt Sterns interview and Team Aqua announcing plans to steal Submarine
# 579 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_CaptStern::
# 580 "data//maps/SlateportCity/scripts.pory"
	lockall
# 581 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternMoveAheadWithExploration, MSGBOX_DEFAULT
# 582 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GabbyWonderfulThanksForInterview, MSGBOX_DEFAULT
# 583 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 584 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GABBY, Common_Movement_WalkInPlaceFasterRight
# 585 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 586 "data//maps/SlateportCity/scripts.pory"
	delay 10
# 587 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_TY, Common_Movement_WalkInPlaceFasterDown
# 588 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 589 "data//maps/SlateportCity/scripts.pory"
	delay 25
# 590 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_CAPT_STERN, SlateportCity_Movement_SternWatchGabbyAndTyExit
# 591 "data//maps/SlateportCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerFaceStern
# 592 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GABBY, SlateportCity_Movement_GabbyExit
# 593 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_TY, SlateportCity_Movement_TyExit
# 594 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 595 "data//maps/SlateportCity/scripts.pory"
	removeobject LOCALID_GABBY
# 596 "data//maps/SlateportCity/scripts.pory"
	removeobject LOCALID_TY
# 597 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternWhewFirstInterview, MSGBOX_DEFAULT
# 598 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
# 599 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 600 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_OhPlayerWeMadeDiscovery, MSGBOX_DEFAULT
# 601 "data//maps/SlateportCity/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 602 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_AquaWillAssumeControlOfSubmarine, MSGBOX_DEFAULT
# 603 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_COOK, Common_Movement_WalkInPlaceFasterLeft
# 604 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_FAT_MAN, Common_Movement_WalkInPlaceFasterLeft
# 605 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_OLD_WOMAN, SlateportCity_Movement_OldWomanConcern
# 606 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_RICH_BOY, Common_Movement_QuestionMark
# 607 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_MAN_1, SlateportCity_Movement_ManConcern
# 608 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 609 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterDown
# 610 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 611 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternWhatWasAllThat, MSGBOX_DEFAULT
# 612 "data//maps/SlateportCity/scripts.pory"
	playse SE_PIN
# 613 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_CAPT_STERN, Common_Movement_ExclamationMark
# 614 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 615 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_CAPT_STERN, Common_Movement_Delay48
# 616 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 617 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
# 618 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 619 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_FromHarborTryingToTakeSub, MSGBOX_DEFAULT
# 620 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
# 621 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 622 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_CAPT_STERN, SlateportCity_Movement_SternEnterHarbor
# 623 "data//maps/SlateportCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerEnterHarbor
# 624 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 625 "data//maps/SlateportCity/scripts.pory"
	removeobject LOCALID_CAPT_STERN
# 626 "data//maps/SlateportCity/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
# 627 "data//maps/SlateportCity/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW
# 628 "data//maps/SlateportCity/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT
# 629 "data//maps/SlateportCity/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE
# 630 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_SLATEPORT_CITY_STATE, 2
# 631 "data//maps/SlateportCity/scripts.pory"
	warp MAP_SLATEPORT_CITY_HARBOR, 11, 14
# 632 "data//maps/SlateportCity/scripts.pory"
	waitstate
# 633 "data//maps/SlateportCity/scripts.pory"
	releaseall
# 634 "data//maps/SlateportCity/scripts.pory"
	end
# 635 "data//maps/SlateportCity/scripts.pory"

# 636 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Movement_OldWomanConcern:
# 637 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 638 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 639 "data//maps/SlateportCity/scripts.pory"
	emote_question_mark
# 640 "data//maps/SlateportCity/scripts.pory"
	walk_in_place_faster_right
# 641 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 642 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 643 "data//maps/SlateportCity/scripts.pory"
	walk_in_place_faster_left
# 644 "data//maps/SlateportCity/scripts.pory"
	step_end
# 645 "data//maps/SlateportCity/scripts.pory"

# 646 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Movement_ManConcern:
# 647 "data//maps/SlateportCity/scripts.pory"
	emote_question_mark
# 648 "data//maps/SlateportCity/scripts.pory"
	walk_in_place_faster_up
# 649 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 650 "data//maps/SlateportCity/scripts.pory"
	walk_in_place_faster_down
# 651 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 652 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 653 "data//maps/SlateportCity/scripts.pory"
	walk_in_place_faster_left
# 654 "data//maps/SlateportCity/scripts.pory"
	step_end
# 655 "data//maps/SlateportCity/scripts.pory"

# 656 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Movement_GabbyExit:
# 657 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 658 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 659 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 660 "data//maps/SlateportCity/scripts.pory"
	walk_down
# 661 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 662 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 663 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 664 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 665 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 666 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 667 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 668 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 669 "data//maps/SlateportCity/scripts.pory"
	step_end
# 670 "data//maps/SlateportCity/scripts.pory"

# 671 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Movement_TyExit:
# 672 "data//maps/SlateportCity/scripts.pory"
	walk_down
# 673 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 674 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 675 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 676 "data//maps/SlateportCity/scripts.pory"
	walk_down
# 677 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 678 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 679 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 680 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 681 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 682 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 683 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 684 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 685 "data//maps/SlateportCity/scripts.pory"
	step_end
# 686 "data//maps/SlateportCity/scripts.pory"

# 687 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Movement_Unused:
# 688 "data//maps/SlateportCity/scripts.pory"
	walk_down
# 689 "data//maps/SlateportCity/scripts.pory"
	walk_in_place_faster_up
# 690 "data//maps/SlateportCity/scripts.pory"
	step_end
# 691 "data//maps/SlateportCity/scripts.pory"

# 692 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Movement_SternEnterHarbor:
# 693 "data//maps/SlateportCity/scripts.pory"
	walk_right
# 694 "data//maps/SlateportCity/scripts.pory"
	walk_up
# 695 "data//maps/SlateportCity/scripts.pory"
	walk_up
# 696 "data//maps/SlateportCity/scripts.pory"
	set_invisible
# 697 "data//maps/SlateportCity/scripts.pory"
	step_end
# 698 "data//maps/SlateportCity/scripts.pory"

# 699 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Movement_SternWatchGabbyAndTyExit:
# 700 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 701 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 702 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 703 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 704 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 705 "data//maps/SlateportCity/scripts.pory"
	walk_down
# 706 "data//maps/SlateportCity/scripts.pory"
	walk_left
# 707 "data//maps/SlateportCity/scripts.pory"
	step_end
# 708 "data//maps/SlateportCity/scripts.pory"

# 709 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Movement_PlayerEnterHarbor:
# 710 "data//maps/SlateportCity/scripts.pory"
	walk_in_place_faster_right
# 711 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 712 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 713 "data//maps/SlateportCity/scripts.pory"
	walk_right
# 714 "data//maps/SlateportCity/scripts.pory"
	walk_up
# 715 "data//maps/SlateportCity/scripts.pory"
	step_end
# 716 "data//maps/SlateportCity/scripts.pory"

# 717 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Movement_PlayerFaceStern:
# 718 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 719 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 720 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 721 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 722 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 723 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 724 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 725 "data//maps/SlateportCity/scripts.pory"
	walk_in_place_faster_down
# 726 "data//maps/SlateportCity/scripts.pory"
	step_end
# 727 "data//maps/SlateportCity/scripts.pory"

# 728 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Ty::
# 729 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BigSmileForCamera, MSGBOX_SIGN
# 730 "data//maps/SlateportCity/scripts.pory"
	end
# 731 "data//maps/SlateportCity/scripts.pory"

# 732 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Gabby::
# 733 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_MostInvaluableExperience, MSGBOX_SIGN
# 734 "data//maps/SlateportCity/scripts.pory"
	end
# 735 "data//maps/SlateportCity/scripts.pory"

# 736 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Man3::
# 737 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WonderIfLighthouseStartlesPokemon, MSGBOX_NPC
# 738 "data//maps/SlateportCity/scripts.pory"
	end
# 739 "data//maps/SlateportCity/scripts.pory"

# 740 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_BerryPowderClerk::
# 741 "data//maps/SlateportCity/scripts.pory"
	lock
# 742 "data//maps/SlateportCity/scripts.pory"
	faceplayer
# 743 "data//maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_POWDER_JAR, SlateportCity_EventScript_ReceivedPowderJar
# 744 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ExplainBerries, MSGBOX_DEFAULT
# 745 "data//maps/SlateportCity/scripts.pory"
	giveitem ITEM_POWDER_JAR
# 746 "data//maps/SlateportCity/scripts.pory"
	setflag FLAG_RECEIVED_POWDER_JAR
# 747 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
# 748 "data//maps/SlateportCity/scripts.pory"
	release
# 749 "data//maps/SlateportCity/scripts.pory"
	end
# 750 "data//maps/SlateportCity/scripts.pory"

# 751 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ReceivedPowderJar::
# 752 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8004, 1
# 753 "data//maps/SlateportCity/scripts.pory"
	specialvar VAR_RESULT, HasEnoughBerryPowder
# 754 "data//maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_ExplainBerryPowder
# 755 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BroughtMeSomeBerryPowder, MSGBOX_DEFAULT
# 756 "data//maps/SlateportCity/scripts.pory"
	special DisplayBerryPowderVendorMenu
# 757 "data//maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_ChooseBerryPowderItem
# 758 "data//maps/SlateportCity/scripts.pory"
	end
# 759 "data//maps/SlateportCity/scripts.pory"

# 760 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ExplainBerryPowder::
# 761 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
# 762 "data//maps/SlateportCity/scripts.pory"
	release
# 763 "data//maps/SlateportCity/scripts.pory"
	end
# 764 "data//maps/SlateportCity/scripts.pory"

# 765 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ChooseBerryPowderItem::
# 766 "data//maps/SlateportCity/scripts.pory"
	message SlateportCity_Text_ExchangeWhatWithIt
# 767 "data//maps/SlateportCity/scripts.pory"
	waitmessage
# 768 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
# 769 "data//maps/SlateportCity/scripts.pory"
	special ShowScrollableMultichoice
# 770 "data//maps/SlateportCity/scripts.pory"
	waitstate
# 771 "data//maps/SlateportCity/scripts.pory"
	switch VAR_RESULT
# 772 "data//maps/SlateportCity/scripts.pory"
	case 0, SlateportCity_EventScript_EnergyPowder
# 773 "data//maps/SlateportCity/scripts.pory"
	case 1, SlateportCity_EventScript_EnergyRoot
# 774 "data//maps/SlateportCity/scripts.pory"
	case 2, SlateportCity_EventScript_HealPowder
# 775 "data//maps/SlateportCity/scripts.pory"
	case 3, SlateportCity_EventScript_RevivalHerb
# 776 "data//maps/SlateportCity/scripts.pory"
	case 4, SlateportCity_EventScript_Protein
# 777 "data//maps/SlateportCity/scripts.pory"
	case 5, SlateportCity_EventScript_Iron
# 778 "data//maps/SlateportCity/scripts.pory"
	case 6, SlateportCity_EventScript_Carbos
# 779 "data//maps/SlateportCity/scripts.pory"
	case 7, SlateportCity_EventScript_Calcium
# 780 "data//maps/SlateportCity/scripts.pory"
	case 8, SlateportCity_EventScript_Zinc
# 781 "data//maps/SlateportCity/scripts.pory"
	case 9, SlateportCity_EventScript_HPUp
# 782 "data//maps/SlateportCity/scripts.pory"
	case 10, SlateportCity_EventScript_PPUp
# 783 "data//maps/SlateportCity/scripts.pory"
	case 11, SlateportCity_EventScript_CancelPowderItemSelect
# 784 "data//maps/SlateportCity/scripts.pory"
	case MULTI_B_PRESSED, SlateportCity_EventScript_CancelPowderItemSelect
# 785 "data//maps/SlateportCity/scripts.pory"
	end
# 786 "data//maps/SlateportCity/scripts.pory"

# 787 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_EnergyPowder::
# 788 "data//maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_ENERGY_POWDER
# 789 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
# 790 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 50
# 791 "data//maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 792 "data//maps/SlateportCity/scripts.pory"
	end
# 793 "data//maps/SlateportCity/scripts.pory"

# 794 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_EnergyRoot::
# 795 "data//maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_ENERGY_ROOT
# 796 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
# 797 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 80
# 798 "data//maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 799 "data//maps/SlateportCity/scripts.pory"
	end
# 800 "data//maps/SlateportCity/scripts.pory"

# 801 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_HealPowder::
# 802 "data//maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_HEAL_POWDER
# 803 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_HEAL_POWDER
# 804 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 50
# 805 "data//maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 806 "data//maps/SlateportCity/scripts.pory"
	end
# 807 "data//maps/SlateportCity/scripts.pory"

# 808 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_RevivalHerb::
# 809 "data//maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_REVIVAL_HERB
# 810 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
# 811 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 300
# 812 "data//maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 813 "data//maps/SlateportCity/scripts.pory"
	end
# 814 "data//maps/SlateportCity/scripts.pory"

# 815 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Protein::
# 816 "data//maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_PROTEIN
# 817 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_PROTEIN
# 818 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 819 "data//maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 820 "data//maps/SlateportCity/scripts.pory"
	end
# 821 "data//maps/SlateportCity/scripts.pory"

# 822 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Iron::
# 823 "data//maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_IRON
# 824 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_IRON
# 825 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 826 "data//maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 827 "data//maps/SlateportCity/scripts.pory"
	end
# 828 "data//maps/SlateportCity/scripts.pory"

# 829 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Carbos::
# 830 "data//maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_CARBOS
# 831 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_CARBOS
# 832 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 833 "data//maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 834 "data//maps/SlateportCity/scripts.pory"
	end
# 835 "data//maps/SlateportCity/scripts.pory"

# 836 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Calcium::
# 837 "data//maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_CALCIUM
# 838 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_CALCIUM
# 839 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 840 "data//maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 841 "data//maps/SlateportCity/scripts.pory"
	end
# 842 "data//maps/SlateportCity/scripts.pory"

# 843 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Zinc::
# 844 "data//maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_ZINC
# 845 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_ZINC
# 846 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 847 "data//maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 848 "data//maps/SlateportCity/scripts.pory"
	end
# 849 "data//maps/SlateportCity/scripts.pory"

# 850 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_HPUp::
# 851 "data//maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_HP_UP
# 852 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_HP_UP
# 853 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 854 "data//maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 855 "data//maps/SlateportCity/scripts.pory"
	end
# 856 "data//maps/SlateportCity/scripts.pory"

# 857 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_PPUp::
# 858 "data//maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_PP_UP
# 859 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_PP_UP
# 860 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 3000
# 861 "data//maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 862 "data//maps/SlateportCity/scripts.pory"
	end
# 863 "data//maps/SlateportCity/scripts.pory"

# 864 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_CancelPowderItemSelect::
# 865 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ComeBackToTradeBerryPowder, MSGBOX_DEFAULT
# 866 "data//maps/SlateportCity/scripts.pory"
	special RemoveBerryPowderVendorMenu
# 867 "data//maps/SlateportCity/scripts.pory"
	release
# 868 "data//maps/SlateportCity/scripts.pory"
	end
# 869 "data//maps/SlateportCity/scripts.pory"

# 870 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_TryBuyBerryPowderItem::
# 871 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ExchangeBerryPowderForItem, MSGBOX_YESNO
# 872 "data//maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SlateportCity_EventScript_ChooseBerryPowderItem
# 873 "data//maps/SlateportCity/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8009
# 874 "data//maps/SlateportCity/scripts.pory"
	specialvar VAR_RESULT, HasEnoughBerryPowder
# 875 "data//maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NotEnoughBerryPowder
# 876 "data//maps/SlateportCity/scripts.pory"
	giveitem VAR_0x8008
# 877 "data//maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NoRoomForBerryPowderItem
# 878 "data//maps/SlateportCity/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8009
# 879 "data//maps/SlateportCity/scripts.pory"
	special TakeBerryPowder
# 880 "data//maps/SlateportCity/scripts.pory"
	special PrintPlayerBerryPowderAmount
# 881 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_FineBerryPowderTradeSomethingElse, MSGBOX_YESNO
# 882 "data//maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SlateportCity_EventScript_ChooseBerryPowderItem
# 883 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WhenYouGetMoreBringItToMe, MSGBOX_DEFAULT
# 884 "data//maps/SlateportCity/scripts.pory"
	special RemoveBerryPowderVendorMenu
# 885 "data//maps/SlateportCity/scripts.pory"
	release
# 886 "data//maps/SlateportCity/scripts.pory"
	end
# 887 "data//maps/SlateportCity/scripts.pory"

# 888 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_NoRoomForBerryPowderItem::
# 889 "data//maps/SlateportCity/scripts.pory"
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
# 890 "data//maps/SlateportCity/scripts.pory"
	special RemoveBerryPowderVendorMenu
# 891 "data//maps/SlateportCity/scripts.pory"
	release
# 892 "data//maps/SlateportCity/scripts.pory"
	end
# 893 "data//maps/SlateportCity/scripts.pory"

# 894 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_NotEnoughBerryPowder::
# 895 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_DontHaveEnoughBerryPowder, MSGBOX_DEFAULT
# 896 "data//maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_ChooseBerryPowderItem
# 897 "data//maps/SlateportCity/scripts.pory"
	end
# 898 "data//maps/SlateportCity/scripts.pory"

# 899 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ScottBattleTentScene::
# 900 "data//maps/SlateportCity/scripts.pory"
	lockall
# 901 "data//maps/SlateportCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 902 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 903 "data//maps/SlateportCity/scripts.pory"
	opendoor 10, 12
# 904 "data//maps/SlateportCity/scripts.pory"
	waitdooranim
# 905 "data//maps/SlateportCity/scripts.pory"
	addobject LOCALID_SCOTT
# 906 "data//maps/SlateportCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PushPlayerDown
# 907 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExitBattleTent
# 908 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 909 "data//maps/SlateportCity/scripts.pory"
	closedoor 10, 12
# 910 "data//maps/SlateportCity/scripts.pory"
	waitdooranim
# 911 "data//maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_TakingBattleTentChallenge, MSGBOX_DEFAULT
# 912 "data//maps/SlateportCity/scripts.pory"
	closemessage
# 913 "data//maps/SlateportCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerWatchScottExit
# 914 "data//maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExitAfterBattleTent
# 915 "data//maps/SlateportCity/scripts.pory"
	waitmovement 0
# 916 "data//maps/SlateportCity/scripts.pory"
	removeobject LOCALID_SCOTT
# 917 "data//maps/SlateportCity/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 918 "data//maps/SlateportCity/scripts.pory"
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
# 919 "data//maps/SlateportCity/scripts.pory"
	releaseall
# 920 "data//maps/SlateportCity/scripts.pory"
	end
# 921 "data//maps/SlateportCity/scripts.pory"

# 922 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Movement_PushPlayerDown:
# 923 "data//maps/SlateportCity/scripts.pory"
	lock_facing_direction
# 924 "data//maps/SlateportCity/scripts.pory"
	walk_down
# 925 "data//maps/SlateportCity/scripts.pory"
	unlock_facing_direction
# 926 "data//maps/SlateportCity/scripts.pory"
	step_end
# 927 "data//maps/SlateportCity/scripts.pory"

# 928 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Movement_PlayerWatchScottExit:
# 929 "data//maps/SlateportCity/scripts.pory"
	delay_16
# 930 "data//maps/SlateportCity/scripts.pory"
	walk_in_place_faster_right
# 931 "data//maps/SlateportCity/scripts.pory"
	step_end
# 932 "data//maps/SlateportCity/scripts.pory"

# 933 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Movement_ScottExitBattleTent:
# 934 "data//maps/SlateportCity/scripts.pory"
	delay_8
# 935 "data//maps/SlateportCity/scripts.pory"
	walk_down
# 936 "data//maps/SlateportCity/scripts.pory"
	step_end
# 937 "data//maps/SlateportCity/scripts.pory"

# 938 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Movement_ScottExitAfterBattleTent:
# 939 "data//maps/SlateportCity/scripts.pory"
	walk_right
# 940 "data//maps/SlateportCity/scripts.pory"
	walk_right
# 941 "data//maps/SlateportCity/scripts.pory"
	walk_right
# 942 "data//maps/SlateportCity/scripts.pory"
	walk_right
# 943 "data//maps/SlateportCity/scripts.pory"
	walk_right
# 944 "data//maps/SlateportCity/scripts.pory"
	walk_right
# 945 "data//maps/SlateportCity/scripts.pory"
	walk_right
# 946 "data//maps/SlateportCity/scripts.pory"
	walk_right
# 947 "data//maps/SlateportCity/scripts.pory"
	step_end
# 948 "data//maps/SlateportCity/scripts.pory"

# 949 "data//maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_BerryCrushRankingsSign::
# 950 "data//maps/SlateportCity/scripts.pory"
	lockall
# 951 "data//maps/SlateportCity/scripts.pory"
	special ShowBerryCrushRankings
# 952 "data//maps/SlateportCity/scripts.pory"
	waitstate
# 953 "data//maps/SlateportCity/scripts.pory"
	releaseall
# 954 "data//maps/SlateportCity/scripts.pory"
	end
# 955 "data//maps/SlateportCity/scripts.pory"

# 956 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_EnergyGuruSellWhatYouNeed:
# 957 "data//maps/SlateportCity/scripts.pory"
	.string "I'm the ENERGY GURU! I'll go for it and\n"
# 958 "data//maps/SlateportCity/scripts.pory"
	.string "sell you what you need!$"
# 959 "data//maps/SlateportCity/scripts.pory"

# 960 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_OhYourPokemon:
# 961 "data//maps/SlateportCity/scripts.pory"
	.string "Oh?\n"
# 962 "data//maps/SlateportCity/scripts.pory"
	.string "Your {STR_VAR_1}…$"
# 963 "data//maps/SlateportCity/scripts.pory"

# 964 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_PleaseGiveItThisEffortRibbon:
# 965 "data//maps/SlateportCity/scripts.pory"
	.string "Went for it stupendously!\p"
# 966 "data//maps/SlateportCity/scripts.pory"
	.string "As its reward, please give it this\n"
# 967 "data//maps/SlateportCity/scripts.pory"
	.string "EFFORT RIBBON.$"
# 968 "data//maps/SlateportCity/scripts.pory"

# 969 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_ReceivedEffortRibbon:
# 970 "data//maps/SlateportCity/scripts.pory"
	.string "{PLAYER} received the EFFORT RIBBON.$"
# 971 "data//maps/SlateportCity/scripts.pory"

# 972 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_PutEffortRibbonOnMon:
# 973 "data//maps/SlateportCity/scripts.pory"
	.string "{PLAYER} put the EFFORT RIBBON\n"
# 974 "data//maps/SlateportCity/scripts.pory"
	.string "on {STR_VAR_1}.$"
# 975 "data//maps/SlateportCity/scripts.pory"

# 976 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_GoForItLittleHarder:
# 977 "data//maps/SlateportCity/scripts.pory"
	.string "You have to go for it a little harder.\p"
# 978 "data//maps/SlateportCity/scripts.pory"
	.string "If you do, I'll give your POKéMON\n"
# 979 "data//maps/SlateportCity/scripts.pory"
	.string "something nice.$"
# 980 "data//maps/SlateportCity/scripts.pory"

# 981 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_EffortRibbonLooksGoodOnIt:
# 982 "data//maps/SlateportCity/scripts.pory"
	.string "Oh! Your {STR_VAR_1}, that EFFORT\n"
# 983 "data//maps/SlateportCity/scripts.pory"
	.string "RIBBON looks good on it!$"
# 984 "data//maps/SlateportCity/scripts.pory"

# 985 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_WonderIfLighthouseStartlesPokemon:
# 986 "data//maps/SlateportCity/scripts.pory"
	.string "The light of the lighthouse reaches\n"
# 987 "data//maps/SlateportCity/scripts.pory"
	.string "dozens of miles away.\p"
# 988 "data//maps/SlateportCity/scripts.pory"
	.string "I wonder if it doesn't startle POKéMON\n"
# 989 "data//maps/SlateportCity/scripts.pory"
	.string "in the sea.$"
# 990 "data//maps/SlateportCity/scripts.pory"

# 991 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_SeaweedFullOfLife:
# 992 "data//maps/SlateportCity/scripts.pory"
	.string "Ooh, look at this!\p"
# 993 "data//maps/SlateportCity/scripts.pory"
	.string "The seaweed you can get around these\n"
# 994 "data//maps/SlateportCity/scripts.pory"
	.string "parts is fresh and full of life.\p"
# 995 "data//maps/SlateportCity/scripts.pory"
	.string "Why, it looks like it can even rear up\n"
# 996 "data//maps/SlateportCity/scripts.pory"
	.string "and attack!$"
# 997 "data//maps/SlateportCity/scripts.pory"

# 998 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_HowTownIsBornAndGrows:
# 999 "data//maps/SlateportCity/scripts.pory"
	.string "Where the water is clean, the fruits\n"
# 1000 "data//maps/SlateportCity/scripts.pory"
	.string "of bountiful harvest gather.\p"
# 1001 "data//maps/SlateportCity/scripts.pory"
	.string "And where people gather, a market\n"
# 1002 "data//maps/SlateportCity/scripts.pory"
	.string "soon starts.\p"
# 1003 "data//maps/SlateportCity/scripts.pory"
	.string "That is how a town is born and grows.$"
# 1004 "data//maps/SlateportCity/scripts.pory"

# 1005 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_SlateportWonderfulPlace:
# 1006 "data//maps/SlateportCity/scripts.pory"
	.string "Shopping where you can breathe the\n"
# 1007 "data//maps/SlateportCity/scripts.pory"
	.string "scent of the ocean…\p"
# 1008 "data//maps/SlateportCity/scripts.pory"
	.string "SLATEPORT is such a wonderful place!$"
# 1009 "data//maps/SlateportCity/scripts.pory"

# 1010 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_BuyBricksSoDecorWontGetDirty:
# 1011 "data//maps/SlateportCity/scripts.pory"
	.string "If you put DOLLS or CUSHIONS on\n"
# 1012 "data//maps/SlateportCity/scripts.pory"
	.string "the floor, they'll get dirty.\p"
# 1013 "data//maps/SlateportCity/scripts.pory"
	.string "I'm going to buy some BRICKS so my\n"
# 1014 "data//maps/SlateportCity/scripts.pory"
	.string "DOLLS and CUSHIONS won't get dirty\l"
# 1015 "data//maps/SlateportCity/scripts.pory"
	.string "when I leave them out.$"
# 1016 "data//maps/SlateportCity/scripts.pory"

# 1017 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_GoingToCompeteInBattleTent:
# 1018 "data//maps/SlateportCity/scripts.pory"
	.string "Wroooar! I'm going to compete in\n"
# 1019 "data//maps/SlateportCity/scripts.pory"
	.string "the BATTLE TENT, too!\p"
# 1020 "data//maps/SlateportCity/scripts.pory"
	.string "But before that, I need to catch\n"
# 1021 "data//maps/SlateportCity/scripts.pory"
	.string "some POKéMON!$"
# 1022 "data//maps/SlateportCity/scripts.pory"

# 1023 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_BushedHikingFromMauville:
# 1024 "data//maps/SlateportCity/scripts.pory"
	.string "Whew… I'm just bushed…\p"
# 1025 "data//maps/SlateportCity/scripts.pory"
	.string "I hiked over from MAUVILLE CITY.\n"
# 1026 "data//maps/SlateportCity/scripts.pory"
	.string "But, boy, this city's huge.\p"
# 1027 "data//maps/SlateportCity/scripts.pory"
	.string "If I'd known this, I would've ridden\n"
# 1028 "data//maps/SlateportCity/scripts.pory"
	.string "my BIKE here.$"
# 1029 "data//maps/SlateportCity/scripts.pory"

# 1030 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_EveryoneCallsHimCaptStern:
# 1031 "data//maps/SlateportCity/scripts.pory"
	.string "STERN, the fellow who built the\n"
# 1032 "data//maps/SlateportCity/scripts.pory"
	.string "MUSEUM, also happens to be the leader\l"
# 1033 "data//maps/SlateportCity/scripts.pory"
	.string "of an undersea exploration team.\p"
# 1034 "data//maps/SlateportCity/scripts.pory"
	.string "So, everyone calls him CAPT. STERN.$"
# 1035 "data//maps/SlateportCity/scripts.pory"

# 1036 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_WhatsLongLineOverThere:
# 1037 "data//maps/SlateportCity/scripts.pory"
	.string "What is that over there?\n"
# 1038 "data//maps/SlateportCity/scripts.pory"
	.string "That long line…$"
# 1039 "data//maps/SlateportCity/scripts.pory"

# 1040 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_VisitedMuseumOften:
# 1041 "data//maps/SlateportCity/scripts.pory"
	.string "When I was a child, I visited\n"
# 1042 "data//maps/SlateportCity/scripts.pory"
	.string "the MUSEUM often.\p"
# 1043 "data//maps/SlateportCity/scripts.pory"
	.string "I used to dream about the mysteries of\n"
# 1044 "data//maps/SlateportCity/scripts.pory"
	.string "the sea after seeing the exhibits.$"
# 1045 "data//maps/SlateportCity/scripts.pory"

# 1046 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_QuitPushing:
# 1047 "data//maps/SlateportCity/scripts.pory"
	.string "Hey, there! Quit pushing!\n"
# 1048 "data//maps/SlateportCity/scripts.pory"
	.string "This is the line, can't you see?$"
# 1049 "data//maps/SlateportCity/scripts.pory"

# 1050 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_AquaHasPolicy:
# 1051 "data//maps/SlateportCity/scripts.pory"
	.string "TEAM AQUA has a policy of\n"
# 1052 "data//maps/SlateportCity/scripts.pory"
	.string "assembling and dispersing at\l"
# 1053 "data//maps/SlateportCity/scripts.pory"
	.string "the operation site.$"
# 1054 "data//maps/SlateportCity/scripts.pory"

# 1055 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_BossIsBrilliant:
# 1056 "data//maps/SlateportCity/scripts.pory"
	.string "Our BOSS is brilliant.\p"
# 1057 "data//maps/SlateportCity/scripts.pory"
	.string "What would he want to do with\n"
# 1058 "data//maps/SlateportCity/scripts.pory"
	.string "a MUSEUM now?$"
# 1059 "data//maps/SlateportCity/scripts.pory"

# 1060 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_WhatsNewSchemeIWonder:
# 1061 "data//maps/SlateportCity/scripts.pory"
	.string "What's the new scheme, I wonder?\p"
# 1062 "data//maps/SlateportCity/scripts.pory"
	.string "Our BOSS is scary when he's mad, so\n"
# 1063 "data//maps/SlateportCity/scripts.pory"
	.string "I'd better not screw things up…$"
# 1064 "data//maps/SlateportCity/scripts.pory"

# 1065 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_ShouldTakeItAll:
# 1066 "data//maps/SlateportCity/scripts.pory"
	.string "If there's something we need in\n"
# 1067 "data//maps/SlateportCity/scripts.pory"
	.string "the MUSEUM, we should take it all!$"
# 1068 "data//maps/SlateportCity/scripts.pory"

# 1069 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_DontButtIn:
# 1070 "data//maps/SlateportCity/scripts.pory"
	.string "Hey, you there!\n"
# 1071 "data//maps/SlateportCity/scripts.pory"
	.string "Don't butt in!$"
# 1072 "data//maps/SlateportCity/scripts.pory"

# 1073 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_RemindsMeOfLongLineForGames:
# 1074 "data//maps/SlateportCity/scripts.pory"
	.string "A long line, huh?\p"
# 1075 "data//maps/SlateportCity/scripts.pory"
	.string "It reminds me of the times I lined up to\n"
# 1076 "data//maps/SlateportCity/scripts.pory"
	.string "buy smash-hit games…$"
# 1077 "data//maps/SlateportCity/scripts.pory"

# 1078 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_WhyAreWeLiningUp:
# 1079 "data//maps/SlateportCity/scripts.pory"
	.string "Why are we even lining up and paying?\n"
# 1080 "data//maps/SlateportCity/scripts.pory"
	.string "We should just march in!$"
# 1081 "data//maps/SlateportCity/scripts.pory"

# 1082 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_WhatDoYouWant:
# 1083 "data//maps/SlateportCity/scripts.pory"
	.string "What?\n"
# 1084 "data//maps/SlateportCity/scripts.pory"
	.string "What do you want?$"
# 1085 "data//maps/SlateportCity/scripts.pory"

# 1086 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_IllReadSignForYou:
# 1087 "data//maps/SlateportCity/scripts.pory"
	.string "You want to read this sign?\n"
# 1088 "data//maps/SlateportCity/scripts.pory"
	.string "I'll read it for you!$"
# 1089 "data//maps/SlateportCity/scripts.pory"

# 1090 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_SaysSomethingLikeSeaIsEndless:
# 1091 "data//maps/SlateportCity/scripts.pory"
	.string "Let's see…\p"
# 1092 "data//maps/SlateportCity/scripts.pory"
	.string "Um… I think it says something like\n"
# 1093 "data//maps/SlateportCity/scripts.pory"
	.string "“the life in the sea is endless.”\p"
# 1094 "data//maps/SlateportCity/scripts.pory"
	.string "Yup, I'm pretty sure that's what\n"
# 1095 "data//maps/SlateportCity/scripts.pory"
	.string "it says.$"
# 1096 "data//maps/SlateportCity/scripts.pory"

# 1097 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_ShouldveBroughtMyGameBoy:
# 1098 "data//maps/SlateportCity/scripts.pory"
	.string "Grumble…\p"
# 1099 "data//maps/SlateportCity/scripts.pory"
	.string "I should've brought my Game Boy\n"
# 1100 "data//maps/SlateportCity/scripts.pory"
	.string "Advance so I wouldn't get bored in line…\p"
# 1101 "data//maps/SlateportCity/scripts.pory"
	.string "Grumble…$"
# 1102 "data//maps/SlateportCity/scripts.pory"

# 1103 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_HotSpringsAfterOperation:
# 1104 "data//maps/SlateportCity/scripts.pory"
	.string "When this operation's over, I'll take\n"
# 1105 "data//maps/SlateportCity/scripts.pory"
	.string "you to a hot spring spa!\p"
# 1106 "data//maps/SlateportCity/scripts.pory"
	.string "That's what our leader said.\n"
# 1107 "data//maps/SlateportCity/scripts.pory"
	.string "I can't wait!$"
# 1108 "data//maps/SlateportCity/scripts.pory"

# 1109 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_SeaIsSoWet:
# 1110 "data//maps/SlateportCity/scripts.pory"
	.string "The sea is just so vast…\p"
# 1111 "data//maps/SlateportCity/scripts.pory"
	.string "Could the sea have been made by\n"
# 1112 "data//maps/SlateportCity/scripts.pory"
	.string "the tears shed by POKéMON?$"
# 1113 "data//maps/SlateportCity/scripts.pory"

# 1114 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_SinkOldBoats:
# 1115 "data//maps/SlateportCity/scripts.pory"
	.string "Do you know what they do with old\n"
# 1116 "data//maps/SlateportCity/scripts.pory"
	.string "ships that become too creaky to sail?\p"
# 1117 "data//maps/SlateportCity/scripts.pory"
	.string "They sink them in the sea so they\n"
# 1118 "data//maps/SlateportCity/scripts.pory"
	.string "become habitats for POKéMON.$"
# 1119 "data//maps/SlateportCity/scripts.pory"

# 1120 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_BuyTooMuch:
# 1121 "data//maps/SlateportCity/scripts.pory"
	.string "Whenever I visit here, I get carried\n"
# 1122 "data//maps/SlateportCity/scripts.pory"
	.string "away and buy too much.$"
# 1123 "data//maps/SlateportCity/scripts.pory"

# 1124 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_GetNameRaterToHelpYou:
# 1125 "data//maps/SlateportCity/scripts.pory"
	.string "If you want to change your POKéMON's\n"
# 1126 "data//maps/SlateportCity/scripts.pory"
	.string "nickname, you'll have to get the NAME\l"
# 1127 "data//maps/SlateportCity/scripts.pory"
	.string "RATER to help you.$"
# 1128 "data//maps/SlateportCity/scripts.pory"

# 1129 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_CantChangeTradeMonName:
# 1130 "data//maps/SlateportCity/scripts.pory"
	.string "Any POKéMON you get in a trade,\n"
# 1131 "data//maps/SlateportCity/scripts.pory"
	.string "you can't change its nickname.\p"
# 1132 "data//maps/SlateportCity/scripts.pory"
	.string "The original TRAINER's love for that\n"
# 1133 "data//maps/SlateportCity/scripts.pory"
	.string "POKéMON is in the nickname.$"
# 1134 "data//maps/SlateportCity/scripts.pory"

# 1135 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_BattleTentBuiltRecently:
# 1136 "data//maps/SlateportCity/scripts.pory"
	.string "Recently, a BATTLE TENT was built\n"
# 1137 "data//maps/SlateportCity/scripts.pory"
	.string "in SLATEPORT.\p"
# 1138 "data//maps/SlateportCity/scripts.pory"
	.string "GYMS are fun, but the BATTLE TENT's\n"
# 1139 "data//maps/SlateportCity/scripts.pory"
	.string "awesome in its own way.\p"
# 1140 "data//maps/SlateportCity/scripts.pory"
	.string "You should go find tough POKéMON\n"
# 1141 "data//maps/SlateportCity/scripts.pory"
	.string "for the BATTLE TENT!$"
# 1142 "data//maps/SlateportCity/scripts.pory"

# 1143 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_CaptSternBeingInterviewed:
# 1144 "data//maps/SlateportCity/scripts.pory"
	.string "I was hoping that it was a famous star\n"
# 1145 "data//maps/SlateportCity/scripts.pory"
	.string "so I could get an autograph.\p"
# 1146 "data//maps/SlateportCity/scripts.pory"
	.string "But who's that being interviewed?\n"
# 1147 "data//maps/SlateportCity/scripts.pory"
	.string "Isn't that CAPT. STERN?$"
# 1148 "data//maps/SlateportCity/scripts.pory"

# 1149 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_InterviewerSoCool:
# 1150 "data//maps/SlateportCity/scripts.pory"
	.string "That lady interviewer is so cool\n"
# 1151 "data//maps/SlateportCity/scripts.pory"
	.string "and pretty.\p"
# 1152 "data//maps/SlateportCity/scripts.pory"
	.string "When I grow up, I'm going to be\n"
# 1153 "data//maps/SlateportCity/scripts.pory"
	.string "an international journalist!$"
# 1154 "data//maps/SlateportCity/scripts.pory"

# 1155 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternSaysDiscoveredSomething:
# 1156 "data//maps/SlateportCity/scripts.pory"
	.string "CAPT. STERN says they discovered\n"
# 1157 "data//maps/SlateportCity/scripts.pory"
	.string "something at the bottom of the sea.\p"
# 1158 "data//maps/SlateportCity/scripts.pory"
	.string "I wonder what it is?\n"
# 1159 "data//maps/SlateportCity/scripts.pory"
	.string "What could it be?$"
# 1160 "data//maps/SlateportCity/scripts.pory"

# 1161 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_CaptainComeBackWithBigFish:
# 1162 "data//maps/SlateportCity/scripts.pory"
	.string "What's going on here?\p"
# 1163 "data//maps/SlateportCity/scripts.pory"
	.string "Did the good CAPTAIN come back with\n"
# 1164 "data//maps/SlateportCity/scripts.pory"
	.string "a big fish from the ocean floor?$"
# 1165 "data//maps/SlateportCity/scripts.pory"

# 1166 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_AmIOnTV:
# 1167 "data//maps/SlateportCity/scripts.pory"
	.string "Hey! Are you watching?\n"
# 1168 "data//maps/SlateportCity/scripts.pory"
	.string "Am I on TV?$"
# 1169 "data//maps/SlateportCity/scripts.pory"

# 1170 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_CaptainsACelebrity:
# 1171 "data//maps/SlateportCity/scripts.pory"
	.string "A TV interview! Here!\n"
# 1172 "data//maps/SlateportCity/scripts.pory"
	.string "The CAPTAIN's a celebrity!$"
# 1173 "data//maps/SlateportCity/scripts.pory"

# 1174 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_BigSmileForCamera:
# 1175 "data//maps/SlateportCity/scripts.pory"
	.string "TY: Okay, CAPT. STERN, a big smile\n"
# 1176 "data//maps/SlateportCity/scripts.pory"
	.string "for the camera!$"
# 1177 "data//maps/SlateportCity/scripts.pory"

# 1178 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_MostInvaluableExperience:
# 1179 "data//maps/SlateportCity/scripts.pory"
	.string "GABBY: I see, I see. You've had a most\n"
# 1180 "data//maps/SlateportCity/scripts.pory"
	.string "invaluable experience…$"
# 1181 "data//maps/SlateportCity/scripts.pory"

# 1182 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternMoveAheadWithExploration:
# 1183 "data//maps/SlateportCity/scripts.pory"
	.string "CAPT. STERN: Yes, indeed. We intend to\n"
# 1184 "data//maps/SlateportCity/scripts.pory"
	.string "move ahead with our exploration.$"
# 1185 "data//maps/SlateportCity/scripts.pory"

# 1186 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_GabbyWonderfulThanksForInterview:
# 1187 "data//maps/SlateportCity/scripts.pory"
	.string "GABBY: That's wonderful, CAPT. STERN!\n"
# 1188 "data//maps/SlateportCity/scripts.pory"
	.string "Thank you for taking the time from\l"
# 1189 "data//maps/SlateportCity/scripts.pory"
	.string "your busy schedule to talk to us.\p"
# 1190 "data//maps/SlateportCity/scripts.pory"
	.string "We hope we can interview you again\n"
# 1191 "data//maps/SlateportCity/scripts.pory"
	.string "with news of more discoveries!$"
# 1192 "data//maps/SlateportCity/scripts.pory"

# 1193 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternWhewFirstInterview:
# 1194 "data//maps/SlateportCity/scripts.pory"
	.string "CAPT. STERN: Whew…\p"
# 1195 "data//maps/SlateportCity/scripts.pory"
	.string "That was my first time to be filmed for\n"
# 1196 "data//maps/SlateportCity/scripts.pory"
	.string "TV. That was nerve-wracking.$"
# 1197 "data//maps/SlateportCity/scripts.pory"

# 1198 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_OhPlayerWeMadeDiscovery:
# 1199 "data//maps/SlateportCity/scripts.pory"
	.string "Oh! {PLAYER}{KUN}!\n"
# 1200 "data//maps/SlateportCity/scripts.pory"
	.string "You're looking great!\p"
# 1201 "data//maps/SlateportCity/scripts.pory"
	.string "We made a huge discovery on our last\n"
# 1202 "data//maps/SlateportCity/scripts.pory"
	.string "seafloor exploration.\p"
# 1203 "data//maps/SlateportCity/scripts.pory"
	.string "We found an underwater cavern on\n"
# 1204 "data//maps/SlateportCity/scripts.pory"
	.string "ROUTE 128.\p"
# 1205 "data//maps/SlateportCity/scripts.pory"
	.string "We think it's the habitat of a POKéMON\n"
# 1206 "data//maps/SlateportCity/scripts.pory"
	.string "that's said to have been long extinct.$"
# 1207 "data//maps/SlateportCity/scripts.pory"

# 1208 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_AquaWillAssumeControlOfSubmarine:
# 1209 "data//maps/SlateportCity/scripts.pory"
	.string "Fufufu…\n"
# 1210 "data//maps/SlateportCity/scripts.pory"
	.string "CAPT. STERN, I presume.\p"
# 1211 "data//maps/SlateportCity/scripts.pory"
	.string "We of TEAM AQUA will assume\n"
# 1212 "data//maps/SlateportCity/scripts.pory"
	.string "control of your submarine!\p"
# 1213 "data//maps/SlateportCity/scripts.pory"
	.string "Your objections are meaningless!\n"
# 1214 "data//maps/SlateportCity/scripts.pory"
	.string "We expect your total cooperation!\p"
# 1215 "data//maps/SlateportCity/scripts.pory"
	.string "Fufufu…\n"
# 1216 "data//maps/SlateportCity/scripts.pory"
	.string "Just watch and learn what TEAM\l"
# 1217 "data//maps/SlateportCity/scripts.pory"
	.string "AQUA has planned!$"
# 1218 "data//maps/SlateportCity/scripts.pory"

# 1219 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternWhatWasAllThat:
# 1220 "data//maps/SlateportCity/scripts.pory"
	.string "CAPT. STERN: What was that all about?\p"
# 1221 "data//maps/SlateportCity/scripts.pory"
	.string "It sounded like someone using\n"
# 1222 "data//maps/SlateportCity/scripts.pory"
	.string "a megaphone…\p"
# 1223 "data//maps/SlateportCity/scripts.pory"
	.string "Where did it come from?$"
# 1224 "data//maps/SlateportCity/scripts.pory"

# 1225 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_FromHarborTryingToTakeSub:
# 1226 "data//maps/SlateportCity/scripts.pory"
	.string "It's from the HARBOR!\p"
# 1227 "data//maps/SlateportCity/scripts.pory"
	.string "The submarine!\n"
# 1228 "data//maps/SlateportCity/scripts.pory"
	.string "They're trying to take it!$"
# 1229 "data//maps/SlateportCity/scripts.pory"

# 1230 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_PleaseComeWithMe:
# 1231 "data//maps/SlateportCity/scripts.pory"
	.string "{PLAYER}{KUN}!\n"
# 1232 "data//maps/SlateportCity/scripts.pory"
	.string "Please, come with me!$"
# 1233 "data//maps/SlateportCity/scripts.pory"

# 1234 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_BattleTentSign:
# 1235 "data//maps/SlateportCity/scripts.pory"
	.string "BATTLE TENT SLATEPORT SITE\n"
# 1236 "data//maps/SlateportCity/scripts.pory"
	.string "“Find it! The ultimate POKéMON!”$"
# 1237 "data//maps/SlateportCity/scripts.pory"

# 1238 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternsShipyardWantedSign:
# 1239 "data//maps/SlateportCity/scripts.pory"
	.string "STERN'S SHIPYARD\p"
# 1240 "data//maps/SlateportCity/scripts.pory"
	.string "“Wanted: A sailor capable of sailing\n"
# 1241 "data//maps/SlateportCity/scripts.pory"
	.string "in all currents.”$"
# 1242 "data//maps/SlateportCity/scripts.pory"

# 1243 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternsShipyardNearsCompletion:
# 1244 "data//maps/SlateportCity/scripts.pory"
	.string "STERN'S SHIPYARD\p"
# 1245 "data//maps/SlateportCity/scripts.pory"
	.string "“The ferry S.S. TIDAL nears\n"
# 1246 "data//maps/SlateportCity/scripts.pory"
	.string "completion for serving the ports of\l"
# 1247 "data//maps/SlateportCity/scripts.pory"
	.string "SLATEPORT and LILYCOVE.”$"
# 1248 "data//maps/SlateportCity/scripts.pory"

# 1249 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternsShipyardFerryComplete:
# 1250 "data//maps/SlateportCity/scripts.pory"
	.string "STERN'S SHIPYARD\p"
# 1251 "data//maps/SlateportCity/scripts.pory"
	.string "“Boarding of the SLATEPORT-LILYCOVE\n"
# 1252 "data//maps/SlateportCity/scripts.pory"
	.string "ferry S.S. TIDAL is handled at the\l"
# 1253 "data//maps/SlateportCity/scripts.pory"
	.string "HARBOR.”$"
# 1254 "data//maps/SlateportCity/scripts.pory"

# 1255 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_PokemonFanClubSign:
# 1256 "data//maps/SlateportCity/scripts.pory"
	.string "POKéMON FAN CLUB\n"
# 1257 "data//maps/SlateportCity/scripts.pory"
	.string "“Calling all fans of POKéMON!”$"
# 1258 "data//maps/SlateportCity/scripts.pory"

# 1259 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_OceanicMuseumSign:
# 1260 "data//maps/SlateportCity/scripts.pory"
	.string "“The endless sea sustains\n"
# 1261 "data//maps/SlateportCity/scripts.pory"
	.string "all life.”\p"
# 1262 "data//maps/SlateportCity/scripts.pory"
	.string "OCEANIC MUSEUM$"
# 1263 "data//maps/SlateportCity/scripts.pory"

# 1264 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_CitySign:
# 1265 "data//maps/SlateportCity/scripts.pory"
	.string "SLATEPORT CITY\p"
# 1266 "data//maps/SlateportCity/scripts.pory"
	.string "“The port where people and POKéMON\n"
# 1267 "data//maps/SlateportCity/scripts.pory"
	.string "cross paths.”$"
# 1268 "data//maps/SlateportCity/scripts.pory"

# 1269 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_MarketSign:
# 1270 "data//maps/SlateportCity/scripts.pory"
	.string "SLATEPORT MARKET\n"
# 1271 "data//maps/SlateportCity/scripts.pory"
	.string "“Unique items found nowhere else!”$"
# 1272 "data//maps/SlateportCity/scripts.pory"

# 1273 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_HarborFerryUnderConstruction:
# 1274 "data//maps/SlateportCity/scripts.pory"
	.string "SLATEPORT HARBOR\p"
# 1275 "data//maps/SlateportCity/scripts.pory"
	.string "“The ferry S.S. TIDAL is under\n"
# 1276 "data//maps/SlateportCity/scripts.pory"
	.string "construction in the SHIPYARD.\p"
# 1277 "data//maps/SlateportCity/scripts.pory"
	.string "“Service is scheduled to begin\n"
# 1278 "data//maps/SlateportCity/scripts.pory"
	.string "shortly.”$"
# 1279 "data//maps/SlateportCity/scripts.pory"

# 1280 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_HarborSign:
# 1281 "data//maps/SlateportCity/scripts.pory"
	.string "SLATEPORT HARBOR\p"
# 1282 "data//maps/SlateportCity/scripts.pory"
	.string "“Enjoy a delightful cruise on\n"
# 1283 "data//maps/SlateportCity/scripts.pory"
	.string "the ferry S.S. TIDAL.”$"
# 1284 "data//maps/SlateportCity/scripts.pory"

# 1285 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_NameRatersHouseSign:
# 1286 "data//maps/SlateportCity/scripts.pory"
	.string "NAME RATER'S HOUSE\n"
# 1287 "data//maps/SlateportCity/scripts.pory"
	.string "“POKéMON nicknames rated.”$"
# 1288 "data//maps/SlateportCity/scripts.pory"

# 1289 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_ExplainBerries:
# 1290 "data//maps/SlateportCity/scripts.pory"
	.string "If a wild POKéMON gets hurt, it heals\n"
# 1291 "data//maps/SlateportCity/scripts.pory"
	.string "itself by chewing on BERRIES.\p"
# 1292 "data//maps/SlateportCity/scripts.pory"
	.string "Did you know that?\p"
# 1293 "data//maps/SlateportCity/scripts.pory"
	.string "Somebody saw that and got the idea\n"
# 1294 "data//maps/SlateportCity/scripts.pory"
	.string "of making medicine from BERRIES.\p"
# 1295 "data//maps/SlateportCity/scripts.pory"
	.string "Did you know that?\p"
# 1296 "data//maps/SlateportCity/scripts.pory"
	.string "To turn BERRIES into medicine,\n"
# 1297 "data//maps/SlateportCity/scripts.pory"
	.string "they must be crushed into powder.\p"
# 1298 "data//maps/SlateportCity/scripts.pory"
	.string "Did you know that?\p"
# 1299 "data//maps/SlateportCity/scripts.pory"
	.string "You seem to have an interest\n"
# 1300 "data//maps/SlateportCity/scripts.pory"
	.string "in BERRIES!\p"
# 1301 "data//maps/SlateportCity/scripts.pory"
	.string "I've got something good for someone\n"
# 1302 "data//maps/SlateportCity/scripts.pory"
	.string "like you.$"
# 1303 "data//maps/SlateportCity/scripts.pory"

# 1304 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_ExplainBerryPowder:
# 1305 "data//maps/SlateportCity/scripts.pory"
	.string "I recently had machines installed at\n"
# 1306 "data//maps/SlateportCity/scripts.pory"
	.string "POKéMON CENTERS for crushing BERRIES.\p"
# 1307 "data//maps/SlateportCity/scripts.pory"
	.string "The BERRY CRUSH machines are at\n"
# 1308 "data//maps/SlateportCity/scripts.pory"
	.string "the DIRECT CORNER upstairs.\p"
# 1309 "data//maps/SlateportCity/scripts.pory"
	.string "Did you know?\p"
# 1310 "data//maps/SlateportCity/scripts.pory"
	.string "Could you make BERRY POWDER for\n"
# 1311 "data//maps/SlateportCity/scripts.pory"
	.string "me using those machines?\p"
# 1312 "data//maps/SlateportCity/scripts.pory"
	.string "I can make you all sorts of medicine\n"
# 1313 "data//maps/SlateportCity/scripts.pory"
	.string "if you bring me lots of BERRY POWDER.$"
# 1314 "data//maps/SlateportCity/scripts.pory"

# 1315 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_BroughtMeSomeBerryPowder:
# 1316 "data//maps/SlateportCity/scripts.pory"
	.string "Have you brought me some\n"
# 1317 "data//maps/SlateportCity/scripts.pory"
	.string "BERRY POWDER?$"
# 1318 "data//maps/SlateportCity/scripts.pory"

# 1319 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_ExchangeWhatWithIt:
# 1320 "data//maps/SlateportCity/scripts.pory"
	.string "What would you like to exchange\n"
# 1321 "data//maps/SlateportCity/scripts.pory"
	.string "it with?$"
# 1322 "data//maps/SlateportCity/scripts.pory"

# 1323 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_ExchangeBerryPowderForItem:
# 1324 "data//maps/SlateportCity/scripts.pory"
	.string "Okay, you want to exchange your\n"
# 1325 "data//maps/SlateportCity/scripts.pory"
	.string "BERRY POWDER for one {STR_VAR_1}?$"
# 1326 "data//maps/SlateportCity/scripts.pory"

# 1327 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_DontHaveEnoughBerryPowder:
# 1328 "data//maps/SlateportCity/scripts.pory"
	.string "Oh, dear. You don't have enough\n"
# 1329 "data//maps/SlateportCity/scripts.pory"
	.string "BERRY POWDER.$"
# 1330 "data//maps/SlateportCity/scripts.pory"

# 1331 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_FineBerryPowderTradeSomethingElse:
# 1332 "data//maps/SlateportCity/scripts.pory"
	.string "This is fine BERRY POWDER.\n"
# 1333 "data//maps/SlateportCity/scripts.pory"
	.string "It will make excellent medicine.\p"
# 1334 "data//maps/SlateportCity/scripts.pory"
	.string "Would you like to trade more of your\n"
# 1335 "data//maps/SlateportCity/scripts.pory"
	.string "BERRY POWDER for something else?$"
# 1336 "data//maps/SlateportCity/scripts.pory"

# 1337 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_WhenYouGetMoreBringItToMe:
# 1338 "data//maps/SlateportCity/scripts.pory"
	.string "Okay! When you get some more\n"
# 1339 "data//maps/SlateportCity/scripts.pory"
	.string "BERRY POWDER, bring it to me, please!$"
# 1340 "data//maps/SlateportCity/scripts.pory"

# 1341 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_ComeBackToTradeBerryPowder:
# 1342 "data//maps/SlateportCity/scripts.pory"
	.string "Come back if you'd like to trade your\n"
# 1343 "data//maps/SlateportCity/scripts.pory"
	.string "BERRY POWDER for some medicine.\p"
# 1344 "data//maps/SlateportCity/scripts.pory"
	.string "I'm always running a bazaar here.\p"
# 1345 "data//maps/SlateportCity/scripts.pory"
	.string "Did you know?$"
# 1346 "data//maps/SlateportCity/scripts.pory"

# 1347 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_YouDroveTeamAquaAway:
# 1348 "data//maps/SlateportCity/scripts.pory"
	.string "SCOTT: Huh?\n"
# 1349 "data//maps/SlateportCity/scripts.pory"
	.string "I'm sure I met you somewhere before.\p"
# 1350 "data//maps/SlateportCity/scripts.pory"
	.string "Have I introduced myself to you?\n"
# 1351 "data//maps/SlateportCity/scripts.pory"
	.string "If not, my name's SCOTT.\p"
# 1352 "data//maps/SlateportCity/scripts.pory"
	.string "I just saw TEAM AQUA run away from\n"
# 1353 "data//maps/SlateportCity/scripts.pory"
	.string "here like they were stung.\p"
# 1354 "data//maps/SlateportCity/scripts.pory"
	.string "Let me guess--you drove them away?$"
# 1355 "data//maps/SlateportCity/scripts.pory"

# 1356 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_MaybeThisTrainer:
# 1357 "data//maps/SlateportCity/scripts.pory"
	.string "SCOTT: Hmm…\n"
# 1358 "data//maps/SlateportCity/scripts.pory"
	.string "Maybe, just maybe, this TRAINER…$"
# 1359 "data//maps/SlateportCity/scripts.pory"

# 1360 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_LetsRegisterEachOther:
# 1361 "data//maps/SlateportCity/scripts.pory"
	.string "SCOTT: All right! I think you're going\n"
# 1362 "data//maps/SlateportCity/scripts.pory"
	.string "to become a good friend.\p"
# 1363 "data//maps/SlateportCity/scripts.pory"
	.string "So, let's register each other in our\n"
# 1364 "data//maps/SlateportCity/scripts.pory"
	.string "POKéNAVS.\p"
# 1365 "data//maps/SlateportCity/scripts.pory"
	.string "… … … … … …$"
# 1366 "data//maps/SlateportCity/scripts.pory"

# 1367 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_RegisteredScott:
# 1368 "data//maps/SlateportCity/scripts.pory"
	.string "Registered this SCOTT person\n"
# 1369 "data//maps/SlateportCity/scripts.pory"
	.string "in the POKéNAV.$"
# 1370 "data//maps/SlateportCity/scripts.pory"

# 1371 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou:
# 1372 "data//maps/SlateportCity/scripts.pory"
	.string "SCOTT: What I'd like to do is tag along\n"
# 1373 "data//maps/SlateportCity/scripts.pory"
	.string "with you, but I do want to keep an eye\l"
# 1374 "data//maps/SlateportCity/scripts.pory"
	.string "on the talents of other people, too.\p"
# 1375 "data//maps/SlateportCity/scripts.pory"
	.string "So, I'll be off to roam other towns\n"
# 1376 "data//maps/SlateportCity/scripts.pory"
	.string "a bit more.\p"
# 1377 "data//maps/SlateportCity/scripts.pory"
	.string "Be seeing you, {PLAYER}{KUN}!$"
# 1378 "data//maps/SlateportCity/scripts.pory"

# 1379 "data//maps/SlateportCity/scripts.pory"
SlateportCity_Text_TakingBattleTentChallenge:
# 1380 "data//maps/SlateportCity/scripts.pory"
	.string "SCOTT: Oh, hey!\n"
# 1381 "data//maps/SlateportCity/scripts.pory"
	.string "If it isn't {PLAYER}{KUN}!\p"
# 1382 "data//maps/SlateportCity/scripts.pory"
	.string "{PLAYER}{KUN}, let me guess--you're going\n"
# 1383 "data//maps/SlateportCity/scripts.pory"
	.string "to take the BATTLE TENT challenge?\p"
# 1384 "data//maps/SlateportCity/scripts.pory"
	.string "Yeah! That's a good idea!\n"
# 1385 "data//maps/SlateportCity/scripts.pory"
	.string "That's a really great idea!\p"
# 1386 "data//maps/SlateportCity/scripts.pory"
	.string "After all, a tough TRAINER is\n"
# 1387 "data//maps/SlateportCity/scripts.pory"
	.string "the perfect fit for the BATTLE TENT!\p"
# 1388 "data//maps/SlateportCity/scripts.pory"
	.string "Give it your best effort!$"
