# 1 "data//maps/MistcladCove/scripts.pory"

# 2 "data//maps/MistcladCove/scripts.pory"

# 3 "data//maps/MistcladCove/scripts.pory"
MistcladCove_MapScripts::
# 4 "data//maps/MistcladCove/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MistcladCove_OnTransition
# 5 "data//maps/MistcladCove/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, MistcladCove_OnResume
# 6 "data//maps/MistcladCove/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MistcladCove_OnFrame
# 7 "data//maps/MistcladCove/scripts.pory"
	.byte 0
# 8 "data//maps/MistcladCove/scripts.pory"

# 9 "data//maps/MistcladCove/scripts.pory"
MistcladCove_OnFrame:
# 10 "data//maps/MistcladCove/scripts.pory"
	map_script_2 VAR_TIME_OF_DAY, 2, MistcladCove_EventScript_SwitchToDaytime
# 11 "data//maps/MistcladCove/scripts.pory"
	map_script_2 VAR_TIME_OF_DAY, 4, MistcladCove_EventScript_SwitchToNighttime
# 12 "data//maps/MistcladCove/scripts.pory"
	.2byte 0
# 13 "data//maps/MistcladCove/scripts.pory"

# 14 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_SwitchToDaytime::
# 15 "data//maps/MistcladCove/scripts.pory"
	addvar VAR_TIME_OF_DAY, 1
# 16 "data//maps/MistcladCove/scripts.pory"
	getplayerxy VAR_TEMP_E, VAR_TEMP_F
# 17 "data//maps/MistcladCove/scripts.pory"
	goto_if_le VAR_TEMP_F, 16, MistcladCove_EventScript_SetSun
# 18 "data//maps/MistcladCove/scripts.pory"
	end
# 19 "data//maps/MistcladCove/scripts.pory"

# 20 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_SwitchToNighttime::
# 21 "data//maps/MistcladCove/scripts.pory"
	addvar VAR_TIME_OF_DAY, 1
# 22 "data//maps/MistcladCove/scripts.pory"
	getplayerxy VAR_TEMP_E, VAR_TEMP_F
# 23 "data//maps/MistcladCove/scripts.pory"
	goto_if_le VAR_TEMP_F, 16, MistcladCove_EventScript_ClearSun
# 24 "data//maps/MistcladCove/scripts.pory"
	end
# 25 "data//maps/MistcladCove/scripts.pory"

# 26 "data//maps/MistcladCove/scripts.pory"
MistcladCove_OnTransition::
# 27 "data//maps/MistcladCove/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 28 "data//maps/MistcladCove/scripts.pory"
	end
# 29 "data//maps/MistcladCove/scripts.pory"

# 30 "data//maps/MistcladCove/scripts.pory"
MistcladCove_OnResume:
# 31 "data//maps/MistcladCove/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MistcladCove_EventScript_TryRemoveWildMons
# 32 "data//maps/MistcladCove/scripts.pory"
	end
# 33 "data//maps/MistcladCove/scripts.pory"

# 34 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_TryRemoveWildMons::
# 35 "data//maps/MistcladCove/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 36 "data//maps/MistcladCove/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 37 "data//maps/MistcladCove/scripts.pory"
	removeobject VAR_LAST_TALKED
# 38 "data//maps/MistcladCove/scripts.pory"
	return
# 39 "data//maps/MistcladCove/scripts.pory"

# 40 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_TrySetSun::
# 41 "data//maps/MistcladCove/scripts.pory"
	switch VAR_TIME_OF_DAY
# 42 "data//maps/MistcladCove/scripts.pory"
	case 0, MistcladCove_EventScript_ClearSun
# 43 "data//maps/MistcladCove/scripts.pory"
	case 1, MistcladCove_EventScript_ClearSun
# 44 "data//maps/MistcladCove/scripts.pory"
	case 2, MistcladCove_EventScript_SetSun
# 45 "data//maps/MistcladCove/scripts.pory"
	case 3, MistcladCove_EventScript_SetSun
# 46 "data//maps/MistcladCove/scripts.pory"
	call_if_ge VAR_TIME_OF_DAY, 4, MistcladCove_EventScript_ClearSun
# 47 "data//maps/MistcladCove/scripts.pory"
	end
# 48 "data//maps/MistcladCove/scripts.pory"

# 49 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_SetSun::
# 50 "data//maps/MistcladCove/scripts.pory"
	setweather WEATHER_SUNNY_CLOUDS
# 51 "data//maps/MistcladCove/scripts.pory"
	doweather
# 52 "data//maps/MistcladCove/scripts.pory"
	return
# 53 "data//maps/MistcladCove/scripts.pory"

# 54 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_ClearSun::
# 55 "data//maps/MistcladCove/scripts.pory"
	setweather WEATHER_NONE
# 56 "data//maps/MistcladCove/scripts.pory"
	doweather
# 57 "data//maps/MistcladCove/scripts.pory"
	return
# 58 "data//maps/MistcladCove/scripts.pory"

# 59 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_Rival::
# 60 "data//maps/MistcladCove/scripts.pory"
	lock
# 61 "data//maps/MistcladCove/scripts.pory"
	faceplayer
# 62 "data//maps/MistcladCove/scripts.pory"
	fadeoutbgm 2
# 63 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_A, MSGBOX_DEFAULT
# 64 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 65 "data//maps/MistcladCove/scripts.pory"
	delay 60
# 66 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_B, MSGBOX_DEFAULT
# 67 "data//maps/MistcladCove/scripts.pory"
	getobjectfacingdirection LOCALID_MISTCLAD_COVE_RIVAL, VAR_RESULT
# 68 "data//maps/MistcladCove/scripts.pory"
	switch VAR_RESULT
# 69 "data//maps/MistcladCove/scripts.pory"
	case DIR_NORTH, MistcladCove_EventScript_RivalLeavesNorth
# 70 "data//maps/MistcladCove/scripts.pory"
	case DIR_SOUTH, MistcladCove_EventScript_RivalLeavesSouth
# 71 "data//maps/MistcladCove/scripts.pory"
	case DIR_EAST, MistcladCove_EventScript_RivalLeavesEast
# 72 "data//maps/MistcladCove/scripts.pory"
	case DIR_WEST, MistcladCove_EventScript_RivalLeavesWest
# 73 "data//maps/MistcladCove/scripts.pory"
	end
# 74 "data//maps/MistcladCove/scripts.pory"

# 75 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_RivalLeavesNorth::
# 76 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceRight
# 77 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 78 "data//maps/MistcladCove/scripts.pory"
	delay 20
# 79 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceLeft
# 80 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 81 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 82 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FacePlayer
# 83 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 84 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 85 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_C, MSGBOX_DEFAULT
# 86 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 87 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_WalkInPlaceUp
# 88 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 89 "data//maps/MistcladCove/scripts.pory"
	giveitem ITEM_DEVON_SCOPE
# 90 "data//maps/MistcladCove/scripts.pory"
	setflag FLAG_RECEIVED_DEVON_SCOPE
# 91 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_D, MSGBOX_DEFAULT
# 92 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 93 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceDown
# 94 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 95 "data//maps/MistcladCove/scripts.pory"
	delay 60
# 96 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FacePlayer
# 97 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 98 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_E, MSGBOX_DEFAULT
# 99 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 100 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 101 "data//maps/MistcladCove/scripts.pory"
	setfieldeffectargument 0, 1
# 102 "data//maps/MistcladCove/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 103 "data//maps/MistcladCove/scripts.pory"
	delay 15
# 104 "data//maps/MistcladCove/scripts.pory"
	removeobject VAR_LAST_TALKED
# 105 "data//maps/MistcladCove/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 106 "data//maps/MistcladCove/scripts.pory"
	fadeinbgm 1
# 107 "data//maps/MistcladCove/scripts.pory"
	release
# 108 "data//maps/MistcladCove/scripts.pory"
	end
# 109 "data//maps/MistcladCove/scripts.pory"

# 110 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_RivalLeavesSouth::
# 111 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceRight
# 112 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 113 "data//maps/MistcladCove/scripts.pory"
	delay 20
# 114 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceLeft
# 115 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 116 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 117 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FacePlayer
# 118 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 119 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 120 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_C, MSGBOX_DEFAULT
# 121 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 122 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_WalkInPlaceDown
# 123 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 124 "data//maps/MistcladCove/scripts.pory"
	giveitem ITEM_DEVON_SCOPE
# 125 "data//maps/MistcladCove/scripts.pory"
	setflag FLAG_RECEIVED_DEVON_SCOPE
# 126 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_D, MSGBOX_DEFAULT
# 127 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 128 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceUp
# 129 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 130 "data//maps/MistcladCove/scripts.pory"
	delay 60
# 131 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FacePlayer
# 132 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 133 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_E, MSGBOX_DEFAULT
# 134 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 135 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 136 "data//maps/MistcladCove/scripts.pory"
	setfieldeffectargument 0, 1
# 137 "data//maps/MistcladCove/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 138 "data//maps/MistcladCove/scripts.pory"
	delay 15
# 139 "data//maps/MistcladCove/scripts.pory"
	removeobject VAR_LAST_TALKED
# 140 "data//maps/MistcladCove/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 141 "data//maps/MistcladCove/scripts.pory"
	fadeinbgm 1
# 142 "data//maps/MistcladCove/scripts.pory"
	release
# 143 "data//maps/MistcladCove/scripts.pory"
	end
# 144 "data//maps/MistcladCove/scripts.pory"

# 145 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_RivalLeavesEast::
# 146 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceUp
# 147 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 148 "data//maps/MistcladCove/scripts.pory"
	delay 20
# 149 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceDown
# 150 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 151 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 152 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FacePlayer
# 153 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 154 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 155 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_C, MSGBOX_DEFAULT
# 156 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 157 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_WalkInPlaceRight
# 158 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 159 "data//maps/MistcladCove/scripts.pory"
	giveitem ITEM_DEVON_SCOPE
# 160 "data//maps/MistcladCove/scripts.pory"
	setflag FLAG_RECEIVED_DEVON_SCOPE
# 161 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_D, MSGBOX_DEFAULT
# 162 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 163 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceLeft
# 164 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 165 "data//maps/MistcladCove/scripts.pory"
	delay 60
# 166 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FacePlayer
# 167 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 168 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_E, MSGBOX_DEFAULT
# 169 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 170 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 171 "data//maps/MistcladCove/scripts.pory"
	setfieldeffectargument 0, 1
# 172 "data//maps/MistcladCove/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 173 "data//maps/MistcladCove/scripts.pory"
	delay 15
# 174 "data//maps/MistcladCove/scripts.pory"
	removeobject VAR_LAST_TALKED
# 175 "data//maps/MistcladCove/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 176 "data//maps/MistcladCove/scripts.pory"
	fadeinbgm 1
# 177 "data//maps/MistcladCove/scripts.pory"
	release
# 178 "data//maps/MistcladCove/scripts.pory"
	end
# 179 "data//maps/MistcladCove/scripts.pory"

# 180 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_RivalLeavesWest::
# 181 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceUp
# 182 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 183 "data//maps/MistcladCove/scripts.pory"
	delay 20
# 184 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceDown
# 185 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 186 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 187 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FacePlayer
# 188 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 189 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 190 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_C, MSGBOX_DEFAULT
# 191 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 192 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_WalkInPlaceLeft
# 193 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 194 "data//maps/MistcladCove/scripts.pory"
	giveitem ITEM_DEVON_SCOPE
# 195 "data//maps/MistcladCove/scripts.pory"
	setflag FLAG_RECEIVED_DEVON_SCOPE
# 196 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_D, MSGBOX_DEFAULT
# 197 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 198 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceRight
# 199 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 200 "data//maps/MistcladCove/scripts.pory"
	delay 60
# 201 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FacePlayer
# 202 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 203 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_E, MSGBOX_DEFAULT
# 204 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 205 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 206 "data//maps/MistcladCove/scripts.pory"
	setfieldeffectargument 0, 1
# 207 "data//maps/MistcladCove/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 208 "data//maps/MistcladCove/scripts.pory"
	delay 15
# 209 "data//maps/MistcladCove/scripts.pory"
	removeobject VAR_LAST_TALKED
# 210 "data//maps/MistcladCove/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 211 "data//maps/MistcladCove/scripts.pory"
	fadeinbgm 1
# 212 "data//maps/MistcladCove/scripts.pory"
	release
# 213 "data//maps/MistcladCove/scripts.pory"
	end
# 214 "data//maps/MistcladCove/scripts.pory"

# 215 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_Ninja1::
# 216 "data//maps/MistcladCove/scripts.pory"
	trainerbattle_single TRAINER_MISTCLAD_COVE_NINJA_1, MistcladCove_Text_Ninja1Intro, MistcladCove_Text_Ninja1Defeat
# 217 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Ninja1PostBattle, MSGBOX_AUTOCLOSE
# 218 "data//maps/MistcladCove/scripts.pory"
	end
# 219 "data//maps/MistcladCove/scripts.pory"

# 220 "data//maps/MistcladCove/scripts.pory"
MistcladCove_Text_Ninja1Intro:
# 221 "data//maps/MistcladCove/scripts.pory"
	.string "My cousins finally let me train\n"
# 222 "data//maps/MistcladCove/scripts.pory"
	.string "with them today!$"
# 223 "data//maps/MistcladCove/scripts.pory"

# 224 "data//maps/MistcladCove/scripts.pory"
MistcladCove_Text_Ninja1Defeat:
# 225 "data//maps/MistcladCove/scripts.pory"
	.string "Maybe I should have stayed home…$"
# 226 "data//maps/MistcladCove/scripts.pory"

# 227 "data//maps/MistcladCove/scripts.pory"
MistcladCove_Text_Ninja1PostBattle:
# 228 "data//maps/MistcladCove/scripts.pory"
	.string "I'm already the best!$"
# 229 "data//maps/MistcladCove/scripts.pory"

# 230 "data//maps/MistcladCove/scripts.pory"
MistcladCove_Text_Rival_A:
# 231 "data//maps/MistcladCove/scripts.pory"
	.string "{RIVAL}: … … … … … … … … … …$"
# 232 "data//maps/MistcladCove/scripts.pory"

# 233 "data//maps/MistcladCove/scripts.pory"
MistcladCove_Text_Rival_B:
# 234 "data//maps/MistcladCove/scripts.pory"
	.string "We just keep running into each\n"
# 235 "data//maps/MistcladCove/scripts.pory"
	.string "other, {PLAYER}.\p"
# 236 "data//maps/MistcladCove/scripts.pory"
	.string "I was headed back home, but I got\n"
# 237 "data//maps/MistcladCove/scripts.pory"
	.string "turned around in this thick mist.$"
# 238 "data//maps/MistcladCove/scripts.pory"

# 239 "data//maps/MistcladCove/scripts.pory"
MistcladCove_Text_Rival_C:
# 240 "data//maps/MistcladCove/scripts.pory"
	.string "I thought this would make it easier\n"
# 241 "data//maps/MistcladCove/scripts.pory"
	.string "get around out here, but I got\l"
# 242 "data//maps/MistcladCove/scripts.pory"
	.string "lost anyway…\p"
# 243 "data//maps/MistcladCove/scripts.pory"
	.string "You should use it instead.$"
# 244 "data//maps/MistcladCove/scripts.pory"

# 245 "data//maps/MistcladCove/scripts.pory"
MistcladCove_Text_Rival_D:
# 246 "data//maps/MistcladCove/scripts.pory"
	.string "You can use that to see the\n"
# 247 "data//maps/MistcladCove/scripts.pory"
	.string "invisible POKéMON who live here.$"
# 248 "data//maps/MistcladCove/scripts.pory"

# 249 "data//maps/MistcladCove/scripts.pory"
MistcladCove_Text_Rival_E:
# 250 "data//maps/MistcladCove/scripts.pory"
	.string "I'm just going to FLY back to\n"
# 251 "data//maps/MistcladCove/scripts.pory"
	.string "LITTLEROOT…\p"
# 252 "data//maps/MistcladCove/scripts.pory"
	.string "If you're tough enough to explore\n"
# 253 "data//maps/MistcladCove/scripts.pory"
	.string "here, make sure to collect a lot\l"
# 254 "data//maps/MistcladCove/scripts.pory"
	.string "of POKéDEX data!\p"
# 255 "data//maps/MistcladCove/scripts.pory"
	.string "Good luck, {PLAYER}…\p"
# 256 "data//maps/MistcladCove/scripts.pory"
	.string "See ya!$"
