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
	goto_if_ge VAR_TEMP_F, 13, MistcladCove_EventScript_SetFog
# 30 "data//maps/MistcladCove/scripts.pory"
	end
# 31 "data//maps/MistcladCove/scripts.pory"

# 32 "data//maps/MistcladCove/scripts.pory"
MistcladCove_OnResume:
# 33 "data//maps/MistcladCove/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MistcladCove_EventScript_TryRemoveWildMons
# 34 "data//maps/MistcladCove/scripts.pory"
	end
# 35 "data//maps/MistcladCove/scripts.pory"

# 36 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_TryRemoveWildMons::
# 37 "data//maps/MistcladCove/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 38 "data//maps/MistcladCove/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 39 "data//maps/MistcladCove/scripts.pory"
	removeobject VAR_LAST_TALKED
# 40 "data//maps/MistcladCove/scripts.pory"
	return
# 41 "data//maps/MistcladCove/scripts.pory"

# 42 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_TrySetSun::
# 43 "data//maps/MistcladCove/scripts.pory"
	switch VAR_TIME_OF_DAY
# 44 "data//maps/MistcladCove/scripts.pory"
	case 0, MistcladCove_EventScript_ClearSun
# 45 "data//maps/MistcladCove/scripts.pory"
	case 1, MistcladCove_EventScript_ClearSun
# 46 "data//maps/MistcladCove/scripts.pory"
	case 2, MistcladCove_EventScript_SetSun
# 47 "data//maps/MistcladCove/scripts.pory"
	case 3, MistcladCove_EventScript_SetSun
# 48 "data//maps/MistcladCove/scripts.pory"
	call_if_ge VAR_TIME_OF_DAY, 4, MistcladCove_EventScript_ClearSun
# 49 "data//maps/MistcladCove/scripts.pory"
	end
# 50 "data//maps/MistcladCove/scripts.pory"

# 51 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_SetSun::
# 52 "data//maps/MistcladCove/scripts.pory"
	setweather WEATHER_SUNNY_CLOUDS
# 53 "data//maps/MistcladCove/scripts.pory"
	doweather
# 54 "data//maps/MistcladCove/scripts.pory"
	return
# 55 "data//maps/MistcladCove/scripts.pory"

# 56 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_ClearSun::
# 57 "data//maps/MistcladCove/scripts.pory"
	setweather WEATHER_NONE
# 58 "data//maps/MistcladCove/scripts.pory"
	doweather
# 59 "data//maps/MistcladCove/scripts.pory"
	return
# 60 "data//maps/MistcladCove/scripts.pory"

# 61 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_SetFog::
# 62 "data//maps/MistcladCove/scripts.pory"
	setweather WEATHER_FOG_HORIZONTAL
# 63 "data//maps/MistcladCove/scripts.pory"
	doweather
# 64 "data//maps/MistcladCove/scripts.pory"
	return
# 65 "data//maps/MistcladCove/scripts.pory"

# 66 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_Rival::
# 67 "data//maps/MistcladCove/scripts.pory"
	lock
# 68 "data//maps/MistcladCove/scripts.pory"
	faceplayer
# 69 "data//maps/MistcladCove/scripts.pory"
	fadeoutbgm 2
# 70 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_A, MSGBOX_DEFAULT
# 71 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 72 "data//maps/MistcladCove/scripts.pory"
	delay 60
# 73 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_B, MSGBOX_DEFAULT
# 74 "data//maps/MistcladCove/scripts.pory"
	getobjectfacingdirection LOCALID_MISTCLAD_COVE_RIVAL, VAR_RESULT
# 75 "data//maps/MistcladCove/scripts.pory"
	switch VAR_RESULT
# 76 "data//maps/MistcladCove/scripts.pory"
	case DIR_NORTH, MistcladCove_EventScript_RivalLeavesNorth
# 77 "data//maps/MistcladCove/scripts.pory"
	case DIR_SOUTH, MistcladCove_EventScript_RivalLeavesSouth
# 78 "data//maps/MistcladCove/scripts.pory"
	case DIR_EAST, MistcladCove_EventScript_RivalLeavesEast
# 79 "data//maps/MistcladCove/scripts.pory"
	case DIR_WEST, MistcladCove_EventScript_RivalLeavesWest
# 80 "data//maps/MistcladCove/scripts.pory"
	end
# 81 "data//maps/MistcladCove/scripts.pory"

# 82 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_RivalLeavesNorth::
# 83 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceRight
# 84 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 85 "data//maps/MistcladCove/scripts.pory"
	delay 20
# 86 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceLeft
# 87 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 88 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 89 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FacePlayer
# 90 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 91 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 92 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_C, MSGBOX_DEFAULT
# 93 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 94 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_WalkInPlaceUp
# 95 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 96 "data//maps/MistcladCove/scripts.pory"
	giveitem ITEM_DEVON_SCOPE
# 97 "data//maps/MistcladCove/scripts.pory"
	setflag FLAG_RECEIVED_DEVON_SCOPE
# 98 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_D, MSGBOX_DEFAULT
# 99 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 100 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceDown
# 101 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 102 "data//maps/MistcladCove/scripts.pory"
	delay 60
# 103 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FacePlayer
# 104 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 105 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_E, MSGBOX_DEFAULT
# 106 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 107 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 108 "data//maps/MistcladCove/scripts.pory"
	setfieldeffectargument 0, 1
# 109 "data//maps/MistcladCove/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 110 "data//maps/MistcladCove/scripts.pory"
	delay 15
# 111 "data//maps/MistcladCove/scripts.pory"
	removeobject VAR_LAST_TALKED
# 112 "data//maps/MistcladCove/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 113 "data//maps/MistcladCove/scripts.pory"
	fadeinbgm 1
# 114 "data//maps/MistcladCove/scripts.pory"
	release
# 115 "data//maps/MistcladCove/scripts.pory"
	end
# 116 "data//maps/MistcladCove/scripts.pory"

# 117 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_RivalLeavesSouth::
# 118 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceRight
# 119 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 120 "data//maps/MistcladCove/scripts.pory"
	delay 20
# 121 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceLeft
# 122 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 123 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 124 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FacePlayer
# 125 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 126 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 127 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_C, MSGBOX_DEFAULT
# 128 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 129 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_WalkInPlaceDown
# 130 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 131 "data//maps/MistcladCove/scripts.pory"
	giveitem ITEM_DEVON_SCOPE
# 132 "data//maps/MistcladCove/scripts.pory"
	setflag FLAG_RECEIVED_DEVON_SCOPE
# 133 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_D, MSGBOX_DEFAULT
# 134 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 135 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceUp
# 136 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 137 "data//maps/MistcladCove/scripts.pory"
	delay 60
# 138 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FacePlayer
# 139 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 140 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_E, MSGBOX_DEFAULT
# 141 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 142 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 143 "data//maps/MistcladCove/scripts.pory"
	setfieldeffectargument 0, 1
# 144 "data//maps/MistcladCove/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 145 "data//maps/MistcladCove/scripts.pory"
	delay 15
# 146 "data//maps/MistcladCove/scripts.pory"
	removeobject VAR_LAST_TALKED
# 147 "data//maps/MistcladCove/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 148 "data//maps/MistcladCove/scripts.pory"
	fadeinbgm 1
# 149 "data//maps/MistcladCove/scripts.pory"
	release
# 150 "data//maps/MistcladCove/scripts.pory"
	end
# 151 "data//maps/MistcladCove/scripts.pory"

# 152 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_RivalLeavesEast::
# 153 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceUp
# 154 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 155 "data//maps/MistcladCove/scripts.pory"
	delay 20
# 156 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceDown
# 157 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 158 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 159 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FacePlayer
# 160 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 161 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 162 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_C, MSGBOX_DEFAULT
# 163 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 164 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_WalkInPlaceRight
# 165 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 166 "data//maps/MistcladCove/scripts.pory"
	giveitem ITEM_DEVON_SCOPE
# 167 "data//maps/MistcladCove/scripts.pory"
	setflag FLAG_RECEIVED_DEVON_SCOPE
# 168 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_D, MSGBOX_DEFAULT
# 169 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 170 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceLeft
# 171 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 172 "data//maps/MistcladCove/scripts.pory"
	delay 60
# 173 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FacePlayer
# 174 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 175 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_E, MSGBOX_DEFAULT
# 176 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 177 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 178 "data//maps/MistcladCove/scripts.pory"
	setfieldeffectargument 0, 1
# 179 "data//maps/MistcladCove/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 180 "data//maps/MistcladCove/scripts.pory"
	delay 15
# 181 "data//maps/MistcladCove/scripts.pory"
	removeobject VAR_LAST_TALKED
# 182 "data//maps/MistcladCove/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 183 "data//maps/MistcladCove/scripts.pory"
	fadeinbgm 1
# 184 "data//maps/MistcladCove/scripts.pory"
	release
# 185 "data//maps/MistcladCove/scripts.pory"
	end
# 186 "data//maps/MistcladCove/scripts.pory"

# 187 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_RivalLeavesWest::
# 188 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceUp
# 189 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 190 "data//maps/MistcladCove/scripts.pory"
	delay 20
# 191 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceDown
# 192 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 193 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 194 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FacePlayer
# 195 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 196 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 197 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_C, MSGBOX_DEFAULT
# 198 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 199 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_WalkInPlaceLeft
# 200 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 201 "data//maps/MistcladCove/scripts.pory"
	giveitem ITEM_DEVON_SCOPE
# 202 "data//maps/MistcladCove/scripts.pory"
	setflag FLAG_RECEIVED_DEVON_SCOPE
# 203 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_D, MSGBOX_DEFAULT
# 204 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 205 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceRight
# 206 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 207 "data//maps/MistcladCove/scripts.pory"
	delay 60
# 208 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FacePlayer
# 209 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 210 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_E, MSGBOX_DEFAULT
# 211 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 212 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 213 "data//maps/MistcladCove/scripts.pory"
	setfieldeffectargument 0, 1
# 214 "data//maps/MistcladCove/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 215 "data//maps/MistcladCove/scripts.pory"
	delay 15
# 216 "data//maps/MistcladCove/scripts.pory"
	removeobject VAR_LAST_TALKED
# 217 "data//maps/MistcladCove/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 218 "data//maps/MistcladCove/scripts.pory"
	fadeinbgm 1
# 219 "data//maps/MistcladCove/scripts.pory"
	release
# 220 "data//maps/MistcladCove/scripts.pory"
	end
# 221 "data//maps/MistcladCove/scripts.pory"

# 222 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_Ninja1::
# 223 "data//maps/MistcladCove/scripts.pory"
	trainerbattle_single TRAINER_MISTCLAD_COVE_NINJA_1, MistcladCove_Text_Ninja1Intro, MistcladCove_Text_Ninja1Defeat
# 224 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Ninja1PostBattle, MSGBOX_AUTOCLOSE
# 225 "data//maps/MistcladCove/scripts.pory"
	end
# 226 "data//maps/MistcladCove/scripts.pory"

# 227 "data//maps/MistcladCove/scripts.pory"
MistcladCove_Text_Ninja1Intro:
# 228 "data//maps/MistcladCove/scripts.pory"
	.string "My cousins finally let me train\n"
# 229 "data//maps/MistcladCove/scripts.pory"
	.string "with them today!$"
# 230 "data//maps/MistcladCove/scripts.pory"

# 231 "data//maps/MistcladCove/scripts.pory"
MistcladCove_Text_Ninja1Defeat:
# 232 "data//maps/MistcladCove/scripts.pory"
	.string "Maybe I should have stayed home…$"
# 233 "data//maps/MistcladCove/scripts.pory"

# 234 "data//maps/MistcladCove/scripts.pory"
MistcladCove_Text_Ninja1PostBattle:
# 235 "data//maps/MistcladCove/scripts.pory"
	.string "I'm already the best!$"
# 236 "data//maps/MistcladCove/scripts.pory"

# 237 "data//maps/MistcladCove/scripts.pory"
MistcladCove_Text_Rival_A:
# 238 "data//maps/MistcladCove/scripts.pory"
	.string "{RIVAL}: … … … … … … … … … …$"
# 239 "data//maps/MistcladCove/scripts.pory"

# 240 "data//maps/MistcladCove/scripts.pory"
MistcladCove_Text_Rival_B:
# 241 "data//maps/MistcladCove/scripts.pory"
	.string "We just keep running into each\n"
# 242 "data//maps/MistcladCove/scripts.pory"
	.string "other, {PLAYER}.\p"
# 243 "data//maps/MistcladCove/scripts.pory"
	.string "I was headed back home, but I got\n"
# 244 "data//maps/MistcladCove/scripts.pory"
	.string "turned around in this thick mist.$"
# 245 "data//maps/MistcladCove/scripts.pory"

# 246 "data//maps/MistcladCove/scripts.pory"
MistcladCove_Text_Rival_C:
# 247 "data//maps/MistcladCove/scripts.pory"
	.string "I thought with the DEVON SCOPE I could\n"
# 248 "data//maps/MistcladCove/scripts.pory"
	.string "find my way around out here,\l"
# 249 "data//maps/MistcladCove/scripts.pory"
	.string "but I got lost anyway…\p"
# 250 "data//maps/MistcladCove/scripts.pory"
	.string "You should use it instead.$"
# 251 "data//maps/MistcladCove/scripts.pory"

# 252 "data//maps/MistcladCove/scripts.pory"
MistcladCove_Text_Rival_D:
# 253 "data//maps/MistcladCove/scripts.pory"
	.string "You can use that to see the\n"
# 254 "data//maps/MistcladCove/scripts.pory"
	.string "invisible POKéMON who live here.$"
# 255 "data//maps/MistcladCove/scripts.pory"

# 256 "data//maps/MistcladCove/scripts.pory"
MistcladCove_Text_Rival_E:
# 257 "data//maps/MistcladCove/scripts.pory"
	.string "I'm just going to FLY back to\n"
# 258 "data//maps/MistcladCove/scripts.pory"
	.string "LITTLEROOT…\p"
# 259 "data//maps/MistcladCove/scripts.pory"
	.string "If you're tough enough to explore\n"
# 260 "data//maps/MistcladCove/scripts.pory"
	.string "here, make sure to collect a lot\l"
# 261 "data//maps/MistcladCove/scripts.pory"
	.string "of POKéDEX data!\p"
# 262 "data//maps/MistcladCove/scripts.pory"
	.string "Good luck, {PLAYER}…\p"
# 263 "data//maps/MistcladCove/scripts.pory"
	.string "See ya!$"
