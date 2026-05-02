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
	getplayerxy VAR_TEMP_E, VAR_TEMP_F
# 29 "data//maps/MistcladCove/scripts.pory"
	setflag FLAG_PROGRESS_BASED_LEVEL_SCALING
# 30 "data//maps/MistcladCove/scripts.pory"
	goto_if_ge VAR_TEMP_F, 13, MistcladCove_EventScript_SetFog
# 31 "data//maps/MistcladCove/scripts.pory"
	end
# 32 "data//maps/MistcladCove/scripts.pory"

# 33 "data//maps/MistcladCove/scripts.pory"
MistcladCove_OnResume:
# 34 "data//maps/MistcladCove/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MistcladCove_EventScript_TryRemoveWildMons
# 35 "data//maps/MistcladCove/scripts.pory"
	end
# 36 "data//maps/MistcladCove/scripts.pory"

# 37 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_TryRemoveWildMons::
# 38 "data//maps/MistcladCove/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 39 "data//maps/MistcladCove/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 40 "data//maps/MistcladCove/scripts.pory"
	removeobject VAR_LAST_TALKED
# 41 "data//maps/MistcladCove/scripts.pory"
	return
# 42 "data//maps/MistcladCove/scripts.pory"

# 43 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_TrySetSun::
# 44 "data//maps/MistcladCove/scripts.pory"
	switch VAR_TIME_OF_DAY
# 45 "data//maps/MistcladCove/scripts.pory"
	case 0, MistcladCove_EventScript_ClearSun
# 46 "data//maps/MistcladCove/scripts.pory"
	case 1, MistcladCove_EventScript_ClearSun
# 47 "data//maps/MistcladCove/scripts.pory"
	case 2, MistcladCove_EventScript_SetSun
# 48 "data//maps/MistcladCove/scripts.pory"
	case 3, MistcladCove_EventScript_SetSun
# 49 "data//maps/MistcladCove/scripts.pory"
	call_if_ge VAR_TIME_OF_DAY, 4, MistcladCove_EventScript_ClearSun
# 50 "data//maps/MistcladCove/scripts.pory"
	end
# 51 "data//maps/MistcladCove/scripts.pory"

# 52 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_SetSun::
# 53 "data//maps/MistcladCove/scripts.pory"
	setweather WEATHER_SUNNY_CLOUDS
# 54 "data//maps/MistcladCove/scripts.pory"
	doweather
# 55 "data//maps/MistcladCove/scripts.pory"
	return
# 56 "data//maps/MistcladCove/scripts.pory"

# 57 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_ClearSun::
# 58 "data//maps/MistcladCove/scripts.pory"
	setweather WEATHER_NONE
# 59 "data//maps/MistcladCove/scripts.pory"
	doweather
# 60 "data//maps/MistcladCove/scripts.pory"
	return
# 61 "data//maps/MistcladCove/scripts.pory"

# 62 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_SetFog::
# 63 "data//maps/MistcladCove/scripts.pory"
	setweather WEATHER_FOG_HORIZONTAL
# 64 "data//maps/MistcladCove/scripts.pory"
	doweather
# 65 "data//maps/MistcladCove/scripts.pory"
	return
# 66 "data//maps/MistcladCove/scripts.pory"

# 67 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_Rival::
# 68 "data//maps/MistcladCove/scripts.pory"
	lock
# 69 "data//maps/MistcladCove/scripts.pory"
	faceplayer
# 70 "data//maps/MistcladCove/scripts.pory"
	fadeoutbgm 2
# 71 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_A, MSGBOX_DEFAULT
# 72 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 73 "data//maps/MistcladCove/scripts.pory"
	delay 60
# 74 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_B, MSGBOX_DEFAULT
# 75 "data//maps/MistcladCove/scripts.pory"
	getobjectfacingdirection LOCALID_MISTCLAD_COVE_RIVAL, VAR_RESULT
# 76 "data//maps/MistcladCove/scripts.pory"
	switch VAR_RESULT
# 77 "data//maps/MistcladCove/scripts.pory"
	case DIR_NORTH, MistcladCove_EventScript_RivalLeavesNorth
# 78 "data//maps/MistcladCove/scripts.pory"
	case DIR_SOUTH, MistcladCove_EventScript_RivalLeavesSouth
# 79 "data//maps/MistcladCove/scripts.pory"
	case DIR_EAST, MistcladCove_EventScript_RivalLeavesEast
# 80 "data//maps/MistcladCove/scripts.pory"
	case DIR_WEST, MistcladCove_EventScript_RivalLeavesWest
# 81 "data//maps/MistcladCove/scripts.pory"
	end
# 82 "data//maps/MistcladCove/scripts.pory"

# 83 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_RivalLeavesNorth::
# 84 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceRight
# 85 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 86 "data//maps/MistcladCove/scripts.pory"
	delay 20
# 87 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceLeft
# 88 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 89 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 90 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FacePlayer
# 91 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 92 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 93 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_C, MSGBOX_DEFAULT
# 94 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 95 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_WalkInPlaceUp
# 96 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 97 "data//maps/MistcladCove/scripts.pory"
	giveitem ITEM_DEVON_SCOPE
# 98 "data//maps/MistcladCove/scripts.pory"
	setflag FLAG_RECEIVED_DEVON_SCOPE
# 99 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_D, MSGBOX_DEFAULT
# 100 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 101 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceDown
# 102 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 103 "data//maps/MistcladCove/scripts.pory"
	delay 60
# 104 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FacePlayer
# 105 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 106 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_E, MSGBOX_DEFAULT
# 107 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 108 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 109 "data//maps/MistcladCove/scripts.pory"
	setfieldeffectargument 0, 1
# 110 "data//maps/MistcladCove/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 111 "data//maps/MistcladCove/scripts.pory"
	delay 15
# 112 "data//maps/MistcladCove/scripts.pory"
	removeobject VAR_LAST_TALKED
# 113 "data//maps/MistcladCove/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 114 "data//maps/MistcladCove/scripts.pory"
	fadeinbgm 1
# 115 "data//maps/MistcladCove/scripts.pory"
	release
# 116 "data//maps/MistcladCove/scripts.pory"
	end
# 117 "data//maps/MistcladCove/scripts.pory"

# 118 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_RivalLeavesSouth::
# 119 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceRight
# 120 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 121 "data//maps/MistcladCove/scripts.pory"
	delay 20
# 122 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceLeft
# 123 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 124 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 125 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FacePlayer
# 126 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 127 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 128 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_C, MSGBOX_DEFAULT
# 129 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 130 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_WalkInPlaceDown
# 131 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 132 "data//maps/MistcladCove/scripts.pory"
	giveitem ITEM_DEVON_SCOPE
# 133 "data//maps/MistcladCove/scripts.pory"
	setflag FLAG_RECEIVED_DEVON_SCOPE
# 134 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_D, MSGBOX_DEFAULT
# 135 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 136 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceUp
# 137 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 138 "data//maps/MistcladCove/scripts.pory"
	delay 60
# 139 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FacePlayer
# 140 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 141 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_E, MSGBOX_DEFAULT
# 142 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 143 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 144 "data//maps/MistcladCove/scripts.pory"
	setfieldeffectargument 0, 1
# 145 "data//maps/MistcladCove/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 146 "data//maps/MistcladCove/scripts.pory"
	delay 15
# 147 "data//maps/MistcladCove/scripts.pory"
	removeobject VAR_LAST_TALKED
# 148 "data//maps/MistcladCove/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 149 "data//maps/MistcladCove/scripts.pory"
	fadeinbgm 1
# 150 "data//maps/MistcladCove/scripts.pory"
	release
# 151 "data//maps/MistcladCove/scripts.pory"
	end
# 152 "data//maps/MistcladCove/scripts.pory"

# 153 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_RivalLeavesEast::
# 154 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceUp
# 155 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 156 "data//maps/MistcladCove/scripts.pory"
	delay 20
# 157 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceDown
# 158 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 159 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 160 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FacePlayer
# 161 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 162 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 163 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_C, MSGBOX_DEFAULT
# 164 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 165 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_WalkInPlaceRight
# 166 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 167 "data//maps/MistcladCove/scripts.pory"
	giveitem ITEM_DEVON_SCOPE
# 168 "data//maps/MistcladCove/scripts.pory"
	setflag FLAG_RECEIVED_DEVON_SCOPE
# 169 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_D, MSGBOX_DEFAULT
# 170 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 171 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceLeft
# 172 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 173 "data//maps/MistcladCove/scripts.pory"
	delay 60
# 174 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FacePlayer
# 175 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 176 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_E, MSGBOX_DEFAULT
# 177 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 178 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 179 "data//maps/MistcladCove/scripts.pory"
	setfieldeffectargument 0, 1
# 180 "data//maps/MistcladCove/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 181 "data//maps/MistcladCove/scripts.pory"
	delay 15
# 182 "data//maps/MistcladCove/scripts.pory"
	removeobject VAR_LAST_TALKED
# 183 "data//maps/MistcladCove/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 184 "data//maps/MistcladCove/scripts.pory"
	fadeinbgm 1
# 185 "data//maps/MistcladCove/scripts.pory"
	release
# 186 "data//maps/MistcladCove/scripts.pory"
	end
# 187 "data//maps/MistcladCove/scripts.pory"

# 188 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_RivalLeavesWest::
# 189 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceUp
# 190 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 191 "data//maps/MistcladCove/scripts.pory"
	delay 20
# 192 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceDown
# 193 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 194 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 195 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FacePlayer
# 196 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 197 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 198 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_C, MSGBOX_DEFAULT
# 199 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 200 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_WalkInPlaceLeft
# 201 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 202 "data//maps/MistcladCove/scripts.pory"
	giveitem ITEM_DEVON_SCOPE
# 203 "data//maps/MistcladCove/scripts.pory"
	setflag FLAG_RECEIVED_DEVON_SCOPE
# 204 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_D, MSGBOX_DEFAULT
# 205 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 206 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceRight
# 207 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 208 "data//maps/MistcladCove/scripts.pory"
	delay 60
# 209 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FacePlayer
# 210 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 211 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_E, MSGBOX_DEFAULT
# 212 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 213 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 214 "data//maps/MistcladCove/scripts.pory"
	setfieldeffectargument 0, 1
# 215 "data//maps/MistcladCove/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 216 "data//maps/MistcladCove/scripts.pory"
	delay 15
# 217 "data//maps/MistcladCove/scripts.pory"
	removeobject VAR_LAST_TALKED
# 218 "data//maps/MistcladCove/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 219 "data//maps/MistcladCove/scripts.pory"
	fadeinbgm 1
# 220 "data//maps/MistcladCove/scripts.pory"
	release
# 221 "data//maps/MistcladCove/scripts.pory"
	end
# 222 "data//maps/MistcladCove/scripts.pory"

# 223 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_Ninja1::
# 224 "data//maps/MistcladCove/scripts.pory"
	trainerbattle_single TRAINER_MISTCLAD_COVE_NINJA_1, MistcladCove_Text_Ninja1Intro, MistcladCove_Text_Ninja1Defeat
# 225 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Ninja1PostBattle, MSGBOX_AUTOCLOSE
# 226 "data//maps/MistcladCove/scripts.pory"
	end
# 227 "data//maps/MistcladCove/scripts.pory"

# 228 "data//maps/MistcladCove/scripts.pory"
MistcladCove_Text_Ninja1Intro:
# 229 "data//maps/MistcladCove/scripts.pory"
	.string "My cousins finally let me train\n"
# 230 "data//maps/MistcladCove/scripts.pory"
	.string "with them today!$"
# 231 "data//maps/MistcladCove/scripts.pory"

# 232 "data//maps/MistcladCove/scripts.pory"
MistcladCove_Text_Ninja1Defeat:
# 233 "data//maps/MistcladCove/scripts.pory"
	.string "Maybe I should have stayed home…$"
# 234 "data//maps/MistcladCove/scripts.pory"

# 235 "data//maps/MistcladCove/scripts.pory"
MistcladCove_Text_Ninja1PostBattle:
# 236 "data//maps/MistcladCove/scripts.pory"
	.string "I'm already the best!$"
# 237 "data//maps/MistcladCove/scripts.pory"

# 238 "data//maps/MistcladCove/scripts.pory"
MistcladCove_Text_Rival_A:
# 239 "data//maps/MistcladCove/scripts.pory"
	.string "{RIVAL}: … … … … … … … … … …$"
# 240 "data//maps/MistcladCove/scripts.pory"

# 241 "data//maps/MistcladCove/scripts.pory"
MistcladCove_Text_Rival_B:
# 242 "data//maps/MistcladCove/scripts.pory"
	.string "We just keep running into each\n"
# 243 "data//maps/MistcladCove/scripts.pory"
	.string "other, {PLAYER}.\p"
# 244 "data//maps/MistcladCove/scripts.pory"
	.string "I was headed back home, but I got\n"
# 245 "data//maps/MistcladCove/scripts.pory"
	.string "turned around in this thick mist.$"
# 246 "data//maps/MistcladCove/scripts.pory"

# 247 "data//maps/MistcladCove/scripts.pory"
MistcladCove_Text_Rival_C:
# 248 "data//maps/MistcladCove/scripts.pory"
	.string "I thought with the DEVON SCOPE I could\n"
# 249 "data//maps/MistcladCove/scripts.pory"
	.string "find my way around out here,\l"
# 250 "data//maps/MistcladCove/scripts.pory"
	.string "but I got lost anyway…\p"
# 251 "data//maps/MistcladCove/scripts.pory"
	.string "You should use it instead.$"
# 252 "data//maps/MistcladCove/scripts.pory"

# 253 "data//maps/MistcladCove/scripts.pory"
MistcladCove_Text_Rival_D:
# 254 "data//maps/MistcladCove/scripts.pory"
	.string "You can use that to see the\n"
# 255 "data//maps/MistcladCove/scripts.pory"
	.string "invisible POKéMON who live here.$"
# 256 "data//maps/MistcladCove/scripts.pory"

# 257 "data//maps/MistcladCove/scripts.pory"
MistcladCove_Text_Rival_E:
# 258 "data//maps/MistcladCove/scripts.pory"
	.string "I'm just going to FLY back to\n"
# 259 "data//maps/MistcladCove/scripts.pory"
	.string "LITTLEROOT…\p"
# 260 "data//maps/MistcladCove/scripts.pory"
	.string "If you're tough enough to explore\n"
# 261 "data//maps/MistcladCove/scripts.pory"
	.string "here, make sure to collect a lot\l"
# 262 "data//maps/MistcladCove/scripts.pory"
	.string "of POKéDEX data!\p"
# 263 "data//maps/MistcladCove/scripts.pory"
	.string "Good luck, {PLAYER}…\p"
# 264 "data//maps/MistcladCove/scripts.pory"
	.string "See ya!$"
