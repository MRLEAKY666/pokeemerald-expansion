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
	call_if_le VAR_TIME_OF_DAY, 3, MistcladCove_EventScript_SetSun
# 42 "data//maps/MistcladCove/scripts.pory"
	call_if_ge VAR_TIME_OF_DAY, 4, MistcladCove_EventScript_ClearSun
# 43 "data//maps/MistcladCove/scripts.pory"
	end
# 44 "data//maps/MistcladCove/scripts.pory"

# 45 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_SetSun::
# 46 "data//maps/MistcladCove/scripts.pory"
	setweather WEATHER_SUNNY_CLOUDS
# 47 "data//maps/MistcladCove/scripts.pory"
	doweather
# 48 "data//maps/MistcladCove/scripts.pory"
	return
# 49 "data//maps/MistcladCove/scripts.pory"

# 50 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_ClearSun::
# 51 "data//maps/MistcladCove/scripts.pory"
	setweather WEATHER_NONE
# 52 "data//maps/MistcladCove/scripts.pory"
	doweather
# 53 "data//maps/MistcladCove/scripts.pory"
	return
# 54 "data//maps/MistcladCove/scripts.pory"

# 55 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_Rival::
# 56 "data//maps/MistcladCove/scripts.pory"
	lock
# 57 "data//maps/MistcladCove/scripts.pory"
	faceplayer
# 58 "data//maps/MistcladCove/scripts.pory"
	fadeoutbgm 2
# 59 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_A, MSGBOX_DEFAULT
# 60 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 61 "data//maps/MistcladCove/scripts.pory"
	delay 60
# 62 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_B, MSGBOX_DEFAULT
# 63 "data//maps/MistcladCove/scripts.pory"
	getobjectfacingdirection LOCALID_MISTCLAD_COVE_RIVAL, VAR_RESULT
# 64 "data//maps/MistcladCove/scripts.pory"
	switch VAR_RESULT
# 65 "data//maps/MistcladCove/scripts.pory"
	case DIR_NORTH, MistcladCove_EventScript_RivalLeavesNorth
# 66 "data//maps/MistcladCove/scripts.pory"
	case DIR_SOUTH, MistcladCove_EventScript_RivalLeavesSouth
# 67 "data//maps/MistcladCove/scripts.pory"
	case DIR_EAST, MistcladCove_EventScript_RivalLeavesEast
# 68 "data//maps/MistcladCove/scripts.pory"
	case DIR_WEST, MistcladCove_EventScript_RivalLeavesWest
# 69 "data//maps/MistcladCove/scripts.pory"
	end
# 70 "data//maps/MistcladCove/scripts.pory"

# 71 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_RivalLeavesNorth::
# 72 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceRight
# 73 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 74 "data//maps/MistcladCove/scripts.pory"
	delay 20
# 75 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceLeft
# 76 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 77 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 78 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FacePlayer
# 79 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 80 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 81 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_C, MSGBOX_DEFAULT
# 82 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 83 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_WalkInPlaceUp
# 84 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 85 "data//maps/MistcladCove/scripts.pory"
	giveitem ITEM_DEVON_SCOPE
# 86 "data//maps/MistcladCove/scripts.pory"
	setflag FLAG_RECEIVED_DEVON_SCOPE
# 87 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_D, MSGBOX_DEFAULT
# 88 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 89 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceDown
# 90 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 91 "data//maps/MistcladCove/scripts.pory"
	delay 60
# 92 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FacePlayer
# 93 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 94 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_E, MSGBOX_DEFAULT
# 95 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 96 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 97 "data//maps/MistcladCove/scripts.pory"
	setfieldeffectargument 0, 1
# 98 "data//maps/MistcladCove/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 99 "data//maps/MistcladCove/scripts.pory"
	delay 15
# 100 "data//maps/MistcladCove/scripts.pory"
	removeobject VAR_LAST_TALKED
# 101 "data//maps/MistcladCove/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 102 "data//maps/MistcladCove/scripts.pory"
	fadeinbgm 1
# 103 "data//maps/MistcladCove/scripts.pory"
	release
# 104 "data//maps/MistcladCove/scripts.pory"
	end
# 105 "data//maps/MistcladCove/scripts.pory"

# 106 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_RivalLeavesSouth::
# 107 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceRight
# 108 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 109 "data//maps/MistcladCove/scripts.pory"
	delay 20
# 110 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceLeft
# 111 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 112 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 113 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FacePlayer
# 114 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 115 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 116 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_C, MSGBOX_DEFAULT
# 117 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 118 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_WalkInPlaceDown
# 119 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 120 "data//maps/MistcladCove/scripts.pory"
	giveitem ITEM_DEVON_SCOPE
# 121 "data//maps/MistcladCove/scripts.pory"
	setflag FLAG_RECEIVED_DEVON_SCOPE
# 122 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_D, MSGBOX_DEFAULT
# 123 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 124 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceUp
# 125 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 126 "data//maps/MistcladCove/scripts.pory"
	delay 60
# 127 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FacePlayer
# 128 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 129 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_E, MSGBOX_DEFAULT
# 130 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 131 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 132 "data//maps/MistcladCove/scripts.pory"
	setfieldeffectargument 0, 1
# 133 "data//maps/MistcladCove/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 134 "data//maps/MistcladCove/scripts.pory"
	delay 15
# 135 "data//maps/MistcladCove/scripts.pory"
	removeobject VAR_LAST_TALKED
# 136 "data//maps/MistcladCove/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 137 "data//maps/MistcladCove/scripts.pory"
	fadeinbgm 1
# 138 "data//maps/MistcladCove/scripts.pory"
	release
# 139 "data//maps/MistcladCove/scripts.pory"
	end
# 140 "data//maps/MistcladCove/scripts.pory"

# 141 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_RivalLeavesEast::
# 142 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceUp
# 143 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 144 "data//maps/MistcladCove/scripts.pory"
	delay 20
# 145 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceDown
# 146 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 147 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 148 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FacePlayer
# 149 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 150 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 151 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_C, MSGBOX_DEFAULT
# 152 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 153 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_WalkInPlaceRight
# 154 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 155 "data//maps/MistcladCove/scripts.pory"
	giveitem ITEM_DEVON_SCOPE
# 156 "data//maps/MistcladCove/scripts.pory"
	setflag FLAG_RECEIVED_DEVON_SCOPE
# 157 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_D, MSGBOX_DEFAULT
# 158 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 159 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceLeft
# 160 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 161 "data//maps/MistcladCove/scripts.pory"
	delay 60
# 162 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FacePlayer
# 163 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 164 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_E, MSGBOX_DEFAULT
# 165 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 166 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 167 "data//maps/MistcladCove/scripts.pory"
	setfieldeffectargument 0, 1
# 168 "data//maps/MistcladCove/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 169 "data//maps/MistcladCove/scripts.pory"
	delay 15
# 170 "data//maps/MistcladCove/scripts.pory"
	removeobject VAR_LAST_TALKED
# 171 "data//maps/MistcladCove/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 172 "data//maps/MistcladCove/scripts.pory"
	fadeinbgm 1
# 173 "data//maps/MistcladCove/scripts.pory"
	release
# 174 "data//maps/MistcladCove/scripts.pory"
	end
# 175 "data//maps/MistcladCove/scripts.pory"

# 176 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_RivalLeavesWest::
# 177 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceUp
# 178 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 179 "data//maps/MistcladCove/scripts.pory"
	delay 20
# 180 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceDown
# 181 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 182 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 183 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FacePlayer
# 184 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 185 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 186 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_C, MSGBOX_DEFAULT
# 187 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 188 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_WalkInPlaceLeft
# 189 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 190 "data//maps/MistcladCove/scripts.pory"
	giveitem ITEM_DEVON_SCOPE
# 191 "data//maps/MistcladCove/scripts.pory"
	setflag FLAG_RECEIVED_DEVON_SCOPE
# 192 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_D, MSGBOX_DEFAULT
# 193 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 194 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FaceRight
# 195 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 196 "data//maps/MistcladCove/scripts.pory"
	delay 60
# 197 "data//maps/MistcladCove/scripts.pory"
	applymovement LOCALID_MISTCLAD_COVE_RIVAL, Common_Movement_FacePlayer
# 198 "data//maps/MistcladCove/scripts.pory"
	waitmovement
# 199 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Rival_E, MSGBOX_DEFAULT
# 200 "data//maps/MistcladCove/scripts.pory"
	closemessage
# 201 "data//maps/MistcladCove/scripts.pory"
	delay 30
# 202 "data//maps/MistcladCove/scripts.pory"
	setfieldeffectargument 0, 1
# 203 "data//maps/MistcladCove/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 204 "data//maps/MistcladCove/scripts.pory"
	delay 15
# 205 "data//maps/MistcladCove/scripts.pory"
	removeobject VAR_LAST_TALKED
# 206 "data//maps/MistcladCove/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 207 "data//maps/MistcladCove/scripts.pory"
	fadeinbgm 1
# 208 "data//maps/MistcladCove/scripts.pory"
	release
# 209 "data//maps/MistcladCove/scripts.pory"
	end
# 210 "data//maps/MistcladCove/scripts.pory"

# 211 "data//maps/MistcladCove/scripts.pory"
MistcladCove_EventScript_Ninja1::
# 212 "data//maps/MistcladCove/scripts.pory"
	trainerbattle_single TRAINER_MISTCLAD_COVE_NINJA_1, MistcladCove_Text_Ninja1Intro, MistcladCove_Text_Ninja1Defeat
# 213 "data//maps/MistcladCove/scripts.pory"
	msgbox MistcladCove_Text_Ninja1PostBattle, MSGBOX_AUTOCLOSE
# 214 "data//maps/MistcladCove/scripts.pory"
	end
# 215 "data//maps/MistcladCove/scripts.pory"

# 216 "data//maps/MistcladCove/scripts.pory"
MistcladCove_Text_Ninja1Intro:
# 217 "data//maps/MistcladCove/scripts.pory"
	.string "My cousins finally let me train\n"
# 218 "data//maps/MistcladCove/scripts.pory"
	.string "with them today!$"
# 219 "data//maps/MistcladCove/scripts.pory"

# 220 "data//maps/MistcladCove/scripts.pory"
MistcladCove_Text_Ninja1Defeat:
# 221 "data//maps/MistcladCove/scripts.pory"
	.string "Maybe I should have stayed home…$"
# 222 "data//maps/MistcladCove/scripts.pory"

# 223 "data//maps/MistcladCove/scripts.pory"
MistcladCove_Text_Ninja1PostBattle:
# 224 "data//maps/MistcladCove/scripts.pory"
	.string "I'm already the best!$"
# 225 "data//maps/MistcladCove/scripts.pory"

# 226 "data//maps/MistcladCove/scripts.pory"
MistcladCove_Text_Rival_A:
# 227 "data//maps/MistcladCove/scripts.pory"
	.string "{RIVAL}: … … … … … … … … … …$"
# 228 "data//maps/MistcladCove/scripts.pory"

# 229 "data//maps/MistcladCove/scripts.pory"
MistcladCove_Text_Rival_B:
# 230 "data//maps/MistcladCove/scripts.pory"
	.string "We just keep running into each\n"
# 231 "data//maps/MistcladCove/scripts.pory"
	.string "other, {PLAYER}.\p"
# 232 "data//maps/MistcladCove/scripts.pory"
	.string "I was headed back home, but I got\n"
# 233 "data//maps/MistcladCove/scripts.pory"
	.string "turned around in this thick mist.$"
# 234 "data//maps/MistcladCove/scripts.pory"

# 235 "data//maps/MistcladCove/scripts.pory"
MistcladCove_Text_Rival_C:
# 236 "data//maps/MistcladCove/scripts.pory"
	.string "I thought this would make it easier\n"
# 237 "data//maps/MistcladCove/scripts.pory"
	.string "get around out here, but I got\l"
# 238 "data//maps/MistcladCove/scripts.pory"
	.string "lost anyway…\p"
# 239 "data//maps/MistcladCove/scripts.pory"
	.string "You should use it instead.$"
# 240 "data//maps/MistcladCove/scripts.pory"

# 241 "data//maps/MistcladCove/scripts.pory"
MistcladCove_Text_Rival_D:
# 242 "data//maps/MistcladCove/scripts.pory"
	.string "You can use that to see the\n"
# 243 "data//maps/MistcladCove/scripts.pory"
	.string "invisible POKéMON who live here.$"
# 244 "data//maps/MistcladCove/scripts.pory"

# 245 "data//maps/MistcladCove/scripts.pory"
MistcladCove_Text_Rival_E:
# 246 "data//maps/MistcladCove/scripts.pory"
	.string "I'm just going to FLY back to\n"
# 247 "data//maps/MistcladCove/scripts.pory"
	.string "LITTLEROOT…\p"
# 248 "data//maps/MistcladCove/scripts.pory"
	.string "If you're tough enough to explore\n"
# 249 "data//maps/MistcladCove/scripts.pory"
	.string "here, make sure to collect a lot\l"
# 250 "data//maps/MistcladCove/scripts.pory"
	.string "of POKéDEX data!\p"
# 251 "data//maps/MistcladCove/scripts.pory"
	.string "Good luck, {PLAYER}…\p"
# 252 "data//maps/MistcladCove/scripts.pory"
	.string "See ya!$"
