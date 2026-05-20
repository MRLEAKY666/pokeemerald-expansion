# 1 "data//maps/NavelRock_Bottom/scripts.pory"

# 2 "data//maps/NavelRock_Bottom/scripts.pory"
NavelRock_Bottom_MapScripts::
# 3 "data//maps/NavelRock_Bottom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_Bottom_OnTransition
# 4 "data//maps/NavelRock_Bottom/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, NavelRock_Bottom_OnResume
# 5 "data//maps/NavelRock_Bottom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NavelRock_Bottom_OnFrame
# 6 "data//maps/NavelRock_Bottom/scripts.pory"
	.byte 0
# 7 "data//maps/NavelRock_Bottom/scripts.pory"

# 8 "data//maps/NavelRock_Bottom/scripts.pory"
NavelRock_Bottom_OnFrame:
# 9 "data//maps/NavelRock_Bottom/scripts.pory"
	map_script_2 VAR_TEMP_1, 1, NavelRock_Bottom_EventScript_DoOakScene
# 10 "data//maps/NavelRock_Bottom/scripts.pory"
	.2byte 0

NavelRock_Bottom_EventScript_DoOakScene::
# 15 "data//maps/NavelRock_Bottom/scripts.pory"
	setvar VAR_TEMP_1, 0
# 16 "data//maps/NavelRock_Bottom/scripts.pory"
	delay 15
# 17 "data//maps/NavelRock_Bottom/scripts.pory"
	message NavelRock_Bottom_EventScript_DoOakScene_Text_0
# 18 "data//maps/NavelRock_Bottom/scripts.pory"
	waitmessage
# 19 "data//maps/NavelRock_Bottom/scripts.pory"
	delay 20
# 20 "data//maps/NavelRock_Bottom/scripts.pory"
	closemessage
# 21 "data//maps/NavelRock_Bottom/scripts.pory"
	hidefollower
# 22 "data//maps/NavelRock_Bottom/scripts.pory"
	playse SE_PIN
# 23 "data//maps/NavelRock_Bottom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 24 "data//maps/NavelRock_Bottom/scripts.pory"
	waitmovement
# 25 "data//maps/NavelRock_Bottom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceDown
# 26 "data//maps/NavelRock_Bottom/scripts.pory"
	waitmovement
# 27 "data//maps/NavelRock_Bottom/scripts.pory"
	delay 45
# 29 "data//maps/NavelRock_Bottom/scripts.pory"
	setobjectxyperm LOCALID_NAVELROCK_BOTTOM_OAK, 14, 19
# 30 "data//maps/NavelRock_Bottom/scripts.pory"
	addobject LOCALID_NAVELROCK_BOTTOM_OAK, MAP_NAVEL_ROCK_BOTTOM
# 31 "data//maps/NavelRock_Bottom/scripts.pory"
	applymovement LOCALID_NAVELROCK_BOTTOM_OAK, NavelRock_Bottom_Movement_OakApproachPlayer
# 32 "data//maps/NavelRock_Bottom/scripts.pory"
	delay 32
# 33 "data//maps/NavelRock_Bottom/scripts.pory"
	playse SE_EXIT
# 34 "data//maps/NavelRock_Bottom/scripts.pory"
	waitmovement
# 35 "data//maps/NavelRock_Bottom/scripts.pory"
	delay 15
# 36 "data//maps/NavelRock_Bottom/scripts.pory"
	applymovement LOCALID_NAVELROCK_BOTTOM_OAK, Common_Movement_WalkInPlaceUp
# 37 "data//maps/NavelRock_Bottom/scripts.pory"
	waitmovement
# 38 "data//maps/NavelRock_Bottom/scripts.pory"
	msgbox NavelRock_Bottom_EventScript_DoOakScene_Text_1, MSGBOX_DEFAULT
# 41 "data//maps/NavelRock_Bottom/scripts.pory"
	closemessage
# 42 "data//maps/NavelRock_Bottom/scripts.pory"
	delay 15
# 43 "data//maps/NavelRock_Bottom/scripts.pory"
	message LilycoveCity_CoveLilyMotel_2F_Text_Thinking
# 44 "data//maps/NavelRock_Bottom/scripts.pory"
	waitmessage
# 45 "data//maps/NavelRock_Bottom/scripts.pory"
	delay 45
# 46 "data//maps/NavelRock_Bottom/scripts.pory"
	msgbox NavelRock_Bottom_EventScript_DoOakScene_Text_2, MSGBOX_DEFAULT
# 49 "data//maps/NavelRock_Bottom/scripts.pory"
	closemessage
# 50 "data//maps/NavelRock_Bottom/scripts.pory"
	delay 15
# 51 "data//maps/NavelRock_Bottom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceDown
# 52 "data//maps/NavelRock_Bottom/scripts.pory"
	waitmovement
# 53 "data//maps/NavelRock_Bottom/scripts.pory"
	applymovement LOCALID_NAVELROCK_BOTTOM_OAK, Common_Movement_WalkInPlaceUp
# 54 "data//maps/NavelRock_Bottom/scripts.pory"
	delay 30
# 55 "data//maps/NavelRock_Bottom/scripts.pory"
	applymovement LOCALID_NAVELROCK_BOTTOM_OAK, Common_Movement_WalkInPlaceUp
# 56 "data//maps/NavelRock_Bottom/scripts.pory"
	playse SE_PC_ON
# 57 "data//maps/NavelRock_Bottom/scripts.pory"
	waitse
# 58 "data//maps/NavelRock_Bottom/scripts.pory"
	message LilycoveCity_CoveLilyMotel_2F_Text_Thinking
# 59 "data//maps/NavelRock_Bottom/scripts.pory"
	waitmessage
# 60 "data//maps/NavelRock_Bottom/scripts.pory"
	delay 30
# 61 "data//maps/NavelRock_Bottom/scripts.pory"
	msgbox NavelRock_Bottom_EventScript_DoOakScene_Text_3, MSGBOX_DEFAULT
# 64 "data//maps/NavelRock_Bottom/scripts.pory"
	closemessage
# 65 "data//maps/NavelRock_Bottom/scripts.pory"
	delay 15
# 66 "data//maps/NavelRock_Bottom/scripts.pory"
	applymovement LOCALID_NAVELROCK_BOTTOM_OAK, NavelRock_Bottom_Movement_OakLeaves
# 67 "data//maps/NavelRock_Bottom/scripts.pory"
	delay 148
# 68 "data//maps/NavelRock_Bottom/scripts.pory"
	playse SE_EXIT
# 69 "data//maps/NavelRock_Bottom/scripts.pory"
	waitse
# 70 "data//maps/NavelRock_Bottom/scripts.pory"
	removeobject LOCALID_NAVELROCK_BOTTOM_OAK
# 71 "data//maps/NavelRock_Bottom/scripts.pory"
	release
	return


NavelRock_Bottom_Movement_OakApproachPlayer::
# 76 "data//maps/NavelRock_Bottom/scripts.pory"
	delay_16
# 77 "data//maps/NavelRock_Bottom/scripts.pory"
	delay_16
# 78 "data//maps/NavelRock_Bottom/scripts.pory"
	set_visible
# 79 "data//maps/NavelRock_Bottom/scripts.pory"
	delay_16
# 80 "data//maps/NavelRock_Bottom/scripts.pory"
	delay_16
# 81 "data//maps/NavelRock_Bottom/scripts.pory"
	walk_left
# 82 "data//maps/NavelRock_Bottom/scripts.pory"
	walk_left
# 83 "data//maps/NavelRock_Bottom/scripts.pory"
	walk_left
# 84 "data//maps/NavelRock_Bottom/scripts.pory"
	walk_up
# 85 "data//maps/NavelRock_Bottom/scripts.pory"
	walk_up
# 86 "data//maps/NavelRock_Bottom/scripts.pory"
	walk_up
# 87 "data//maps/NavelRock_Bottom/scripts.pory"
	walk_up
# 88 "data//maps/NavelRock_Bottom/scripts.pory"
	delay_16
# 89 "data//maps/NavelRock_Bottom/scripts.pory"
	delay_16
# 90 "data//maps/NavelRock_Bottom/scripts.pory"
	step_end
	return


NavelRock_Bottom_Movement_OakLeaves::
# 94 "data//maps/NavelRock_Bottom/scripts.pory"
	walk_down
# 95 "data//maps/NavelRock_Bottom/scripts.pory"
	walk_down
# 96 "data//maps/NavelRock_Bottom/scripts.pory"
	walk_down
# 97 "data//maps/NavelRock_Bottom/scripts.pory"
	walk_down
# 98 "data//maps/NavelRock_Bottom/scripts.pory"
	walk_right
# 99 "data//maps/NavelRock_Bottom/scripts.pory"
	walk_right
# 100 "data//maps/NavelRock_Bottom/scripts.pory"
	walk_right
# 101 "data//maps/NavelRock_Bottom/scripts.pory"
	delay_16
# 102 "data//maps/NavelRock_Bottom/scripts.pory"
	face_up
# 103 "data//maps/NavelRock_Bottom/scripts.pory"
	delay_16
# 104 "data//maps/NavelRock_Bottom/scripts.pory"
	set_invisible
# 105 "data//maps/NavelRock_Bottom/scripts.pory"
	step_end
	return


# 108 "data//maps/NavelRock_Bottom/scripts.pory"

# 109 "data//maps/NavelRock_Bottom/scripts.pory"

# 110 "data//maps/NavelRock_Bottom/scripts.pory"
NavelRock_Bottom_OnTransition:
# 111 "data//maps/NavelRock_Bottom/scripts.pory"
	call_if_set FLAG_CAUGHT_LUGIA, NavelRock_Bottom_EventScript_HideLugia
# 112 "data//maps/NavelRock_Bottom/scripts.pory"
	call_if_unset FLAG_CAUGHT_LUGIA, NavelRock_Bottom_EventScript_TryShowLugia
# 113 "data//maps/NavelRock_Bottom/scripts.pory"
	end
# 114 "data//maps/NavelRock_Bottom/scripts.pory"

# 115 "data//maps/NavelRock_Bottom/scripts.pory"
NavelRock_Bottom_EventScript_HideLugia::
# 116 "data//maps/NavelRock_Bottom/scripts.pory"
	setflag FLAG_HIDE_LUGIA
# 117 "data//maps/NavelRock_Bottom/scripts.pory"
	return
# 118 "data//maps/NavelRock_Bottom/scripts.pory"

# 119 "data//maps/NavelRock_Bottom/scripts.pory"
NavelRock_Bottom_EventScript_TryShowLugia::
# 120 "data//maps/NavelRock_Bottom/scripts.pory"
	goto_if_set FLAG_DEFEATED_LUGIA, Common_EventScript_NopReturn
# 121 "data//maps/NavelRock_Bottom/scripts.pory"
	goto_if_not_defeated TRAINER_OAK_NAVEL_ROCK, NavelRock_Bottom_EventScript_HideLugia
# 122 "data//maps/NavelRock_Bottom/scripts.pory"
	clearflag FLAG_HIDE_LUGIA
# 123 "data//maps/NavelRock_Bottom/scripts.pory"
	return
# 124 "data//maps/NavelRock_Bottom/scripts.pory"

# 125 "data//maps/NavelRock_Bottom/scripts.pory"
NavelRock_Bottom_OnResume:
# 126 "data//maps/NavelRock_Bottom/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, NavelRock_Bottom_EventScript_TryRemoveLugia
# 127 "data//maps/NavelRock_Bottom/scripts.pory"
	end
# 128 "data//maps/NavelRock_Bottom/scripts.pory"

# 129 "data//maps/NavelRock_Bottom/scripts.pory"
NavelRock_Bottom_EventScript_TryRemoveLugia::
# 130 "data//maps/NavelRock_Bottom/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 131 "data//maps/NavelRock_Bottom/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 132 "data//maps/NavelRock_Bottom/scripts.pory"
	removeobject LOCALID_NAVEL_ROCK_LUGIA
# 133 "data//maps/NavelRock_Bottom/scripts.pory"
	return
# 134 "data//maps/NavelRock_Bottom/scripts.pory"

# 135 "data//maps/NavelRock_Bottom/scripts.pory"
NavelRock_Bottom_EventScript_Lugia::
# 136 "data//maps/NavelRock_Bottom/scripts.pory"
	lock
# 137 "data//maps/NavelRock_Bottom/scripts.pory"
	faceplayer
# 138 "data//maps/NavelRock_Bottom/scripts.pory"
	waitse
# 139 "data//maps/NavelRock_Bottom/scripts.pory"
	delay 20
# 140 "data//maps/NavelRock_Bottom/scripts.pory"
	playse SE_THUNDERSTORM_STOP
# 141 "data//maps/NavelRock_Bottom/scripts.pory"
	setvar VAR_0x8004, 0  @ vertical pan
# 142 "data//maps/NavelRock_Bottom/scripts.pory"
	setvar VAR_0x8005, 3  @ horizontal pan
# 143 "data//maps/NavelRock_Bottom/scripts.pory"
	setvar VAR_0x8006, 4  @ num shakes
# 144 "data//maps/NavelRock_Bottom/scripts.pory"
	setvar VAR_0x8007, 2  @ shake delay
# 145 "data//maps/NavelRock_Bottom/scripts.pory"
	special ShakeCamera
# 146 "data//maps/NavelRock_Bottom/scripts.pory"
	delay 30
# 147 "data//maps/NavelRock_Bottom/scripts.pory"
	playse SE_THUNDERSTORM_STOP
# 148 "data//maps/NavelRock_Bottom/scripts.pory"
	setvar VAR_0x8004, 0  @ vertical pan
# 149 "data//maps/NavelRock_Bottom/scripts.pory"
	setvar VAR_0x8005, 3  @ horizontal pan
# 150 "data//maps/NavelRock_Bottom/scripts.pory"
	setvar VAR_0x8006, 4  @ num shakes
# 151 "data//maps/NavelRock_Bottom/scripts.pory"
	setvar VAR_0x8007, 2  @ shake delay
# 152 "data//maps/NavelRock_Bottom/scripts.pory"
	special ShakeCamera
# 153 "data//maps/NavelRock_Bottom/scripts.pory"
	delay 30
# 154 "data//maps/NavelRock_Bottom/scripts.pory"
	delay 50
# 155 "data//maps/NavelRock_Bottom/scripts.pory"
	waitse
# 156 "data//maps/NavelRock_Bottom/scripts.pory"
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
# 157 "data//maps/NavelRock_Bottom/scripts.pory"
	waitmoncry
# 158 "data//maps/NavelRock_Bottom/scripts.pory"
	delay 20
# 159 "data//maps/NavelRock_Bottom/scripts.pory"
	seteventmon SPECIES_LUGIA, 70
# 160 "data//maps/NavelRock_Bottom/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 161 "data//maps/NavelRock_Bottom/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 162 "data//maps/NavelRock_Bottom/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 163 "data//maps/NavelRock_Bottom/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 164 "data//maps/NavelRock_Bottom/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NavelRock_Bottom_EventScript_DefeatedLugia
# 165 "data//maps/NavelRock_Bottom/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NavelRock_Bottom_EventScript_RanFromLugia
# 166 "data//maps/NavelRock_Bottom/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NavelRock_Bottom_EventScript_RanFromLugia
# 167 "data//maps/NavelRock_Bottom/scripts.pory"
	setflag FLAG_CAUGHT_LUGIA
# 168 "data//maps/NavelRock_Bottom/scripts.pory"
	setflag FLAG_HIDE_NAVEL_ROCK_OAK
# 169 "data//maps/NavelRock_Bottom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 170 "data//maps/NavelRock_Bottom/scripts.pory"
	release
# 171 "data//maps/NavelRock_Bottom/scripts.pory"
	end
# 172 "data//maps/NavelRock_Bottom/scripts.pory"

# 173 "data//maps/NavelRock_Bottom/scripts.pory"
NavelRock_Bottom_EventScript_DefeatedLugia::
# 174 "data//maps/NavelRock_Bottom/scripts.pory"
	setflag FLAG_DEFEATED_LUGIA
# 175 "data//maps/NavelRock_Bottom/scripts.pory"
	setvar VAR_0x8004, SPECIES_LUGIA
# 176 "data//maps/NavelRock_Bottom/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 177 "data//maps/NavelRock_Bottom/scripts.pory"
	end
# 178 "data//maps/NavelRock_Bottom/scripts.pory"

# 179 "data//maps/NavelRock_Bottom/scripts.pory"
NavelRock_Bottom_EventScript_RanFromLugia::
# 180 "data//maps/NavelRock_Bottom/scripts.pory"
	setvar VAR_0x8004, SPECIES_LUGIA
# 181 "data//maps/NavelRock_Bottom/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 182 "data//maps/NavelRock_Bottom/scripts.pory"
	end

NavelRock_Bottom_EventScript_DoOakScene_Text_0:
# 17 "data//maps/NavelRock_Bottom/scripts.pory"
	.string "{PLAYER} … {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}!$"

NavelRock_Bottom_EventScript_DoOakScene_Text_1:
# 38 "data//maps/NavelRock_Bottom/scripts.pory"
	.string "PROF. OAK: {PLAYER} … {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}…\p"
	.string "I finally … {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}…\n"
	.string "made it down here … {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}…\p"
	.string "to the bottom … {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}…\l"
	.string "of this confounded cavern!$"

NavelRock_Bottom_EventScript_DoOakScene_Text_2:
# 46 "data//maps/NavelRock_Bottom/scripts.pory"
	.string "Hmm?\l"
	.string "It's already over?\p"
	.string "You actually caught LUGIA??\p"
	.string "{PLAYER}…\p"
	.string "A discovery like this is once in a\n"
	.string "lifetime!\p"
	.string "The POKéDEX data from this capture will\n"
	.string "be a great boon to POKéMON research!\p"
	.string "You don't mind if I just take a look here\n"
	.string "and copy that data over, do you?$"

NavelRock_Bottom_EventScript_DoOakScene_Text_3:
# 61 "data//maps/NavelRock_Bottom/scripts.pory"
	.string "Done!\l"
	.string "Many thanks, {PLAYER}\p"
	.string "Whatever knowledge and innovation\n"
	.string "comes from this, you can take pride\l"
	.string "knowing that you were a part of it!\p"
	.string "{PAUSE 20}{PAUSE 20}{PAUSE 20}Well, {PAUSE 20}I'd better get moving if I'm going\n"
	.string "to make it out of this deep cave\l"
	.string "anytime this decade…\p"
	.string "I hope to cross paths with you again,\n"
	.string "{PLAYER}.$"
