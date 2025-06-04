# 1 "data//maps/FortreeCliffs/scripts.pory"

# 2 "data//maps/FortreeCliffs/scripts.pory"

# 3 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_MapScripts::
# 4 "data//maps/FortreeCliffs/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, FortreeCliffs_OnResume
# 5 "data//maps/FortreeCliffs/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCliffs_OnTransition
# 6 "data//maps/FortreeCliffs/scripts.pory"
	.byte 0
# 7 "data//maps/FortreeCliffs/scripts.pory"

# 8 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_OnResume:
# 9 "data//maps/FortreeCliffs/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, FortreeCliffs_EventScript_TryRemoveWildMons
# 10 "data//maps/FortreeCliffs/scripts.pory"
	end
# 11 "data//maps/FortreeCliffs/scripts.pory"

# 12 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_TryRemoveWildMons::
# 13 "data//maps/FortreeCliffs/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 14 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 15 "data//maps/FortreeCliffs/scripts.pory"
	removeobject VAR_LAST_TALKED
# 16 "data//maps/FortreeCliffs/scripts.pory"
	return
# 17 "data//maps/FortreeCliffs/scripts.pory"

# 18 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_OnTransition:
# 19 "data//maps/FortreeCliffs/scripts.pory"
	@ call FortreeCliffs_EventScript_ResetWildMons
# 20 "data//maps/FortreeCliffs/scripts.pory"
	end
# 21 "data//maps/FortreeCliffs/scripts.pory"

# 22 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_ResetWildMons::
# 23 "data//maps/FortreeCliffs/scripts.pory"
	end
# 24 "data//maps/FortreeCliffs/scripts.pory"

# 25 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BadVibeRock::
# 26 "data//maps/FortreeCliffs/scripts.pory"
	lock
# 27 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BadVibeRock, MSGBOX_DEFAULT
# 28 "data//maps/FortreeCliffs/scripts.pory"
	release
# 29 "data//maps/FortreeCliffs/scripts.pory"
	end
# 30 "data//maps/FortreeCliffs/scripts.pory"

# 31 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja1::
# 32 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_1, FortreeCliffs_Text_Ninja1Intro, FortreeCliffs_Text_Ninja1Defeat
# 33 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja1PostBattle, MSGBOX_AUTOCLOSE
# 34 "data//maps/FortreeCliffs/scripts.pory"
	end
# 35 "data//maps/FortreeCliffs/scripts.pory"

# 36 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja2::
# 37 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_2, FortreeCliffs_Text_Ninja2Intro, FortreeCliffs_Text_Ninja2Defeat
# 38 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja2PostBattle, MSGBOX_AUTOCLOSE
# 39 "data//maps/FortreeCliffs/scripts.pory"
	end
# 40 "data//maps/FortreeCliffs/scripts.pory"

# 41 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja3::
# 42 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_3, FortreeCliffs_Text_Ninja3Intro, FortreeCliffs_Text_Ninja3Defeat
# 43 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja3PostBattle, MSGBOX_AUTOCLOSE
# 44 "data//maps/FortreeCliffs/scripts.pory"
	end
# 45 "data//maps/FortreeCliffs/scripts.pory"

# 46 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Expert1::
# 47 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_EXPERT_1, FortreeCliffs_Text_Expert1Intro, FortreeCliffs_Text_Expert1Defeat
# 48 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Expert1PostBattle, MSGBOX_AUTOCLOSE
# 49 "data//maps/FortreeCliffs/scripts.pory"
	end
# 50 "data//maps/FortreeCliffs/scripts.pory"

# 51 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja4::
# 52 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_4, FortreeCliffs_Text_Ninja4Intro, FortreeCliffs_Text_Ninja4Defeat
# 53 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja4PostBattle, MSGBOX_AUTOCLOSE
# 54 "data//maps/FortreeCliffs/scripts.pory"
	end
# 55 "data//maps/FortreeCliffs/scripts.pory"

# 56 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja5::
# 57 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_5, FortreeCliffs_Text_Ninja5Intro, FortreeCliffs_Text_Ninja5Defeat
# 58 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja5PostBattle, MSGBOX_AUTOCLOSE
# 59 "data//maps/FortreeCliffs/scripts.pory"
	end
# 60 "data//maps/FortreeCliffs/scripts.pory"

# 61 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja6::
# 62 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_6, FortreeCliffs_Text_Ninja6Intro, FortreeCliffs_Text_Ninja6Defeat
# 63 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja6PostBattle, MSGBOX_AUTOCLOSE
# 64 "data//maps/FortreeCliffs/scripts.pory"
	end
# 65 "data//maps/FortreeCliffs/scripts.pory"

# 66 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BirdKeeper1::
# 67 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_BIRDKEEPER_1, FortreeCliffs_Text_BirdKeeper1Intro, FortreeCliffs_Text_BirdKeeper1Defeat
# 68 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BirdKeeper1PostBattle, MSGBOX_AUTOCLOSE
# 69 "data//maps/FortreeCliffs/scripts.pory"
	end
# 70 "data//maps/FortreeCliffs/scripts.pory"

# 71 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ranger1::
# 72 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_RANGER_1, FortreeCliffs_Text_Ranger1Intro, FortreeCliffs_Text_Ranger1Defeat
# 73 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ranger1PostBattle, MSGBOX_AUTOCLOSE
# 74 "data//maps/FortreeCliffs/scripts.pory"
	end
# 75 "data//maps/FortreeCliffs/scripts.pory"

# 76 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ranger2::
# 77 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_RANGER_2, FortreeCliffs_Text_Ranger2Intro, FortreeCliffs_Text_Ranger2Defeat
# 78 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ranger2PostBattle, MSGBOX_AUTOCLOSE
# 79 "data//maps/FortreeCliffs/scripts.pory"
	end
# 80 "data//maps/FortreeCliffs/scripts.pory"

# 81 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BadVibeRock:
# 82 "data//maps/FortreeCliffs/scripts.pory"
	.string "This rock gives off a bad vibe…$"
# 83 "data//maps/FortreeCliffs/scripts.pory"

# 84 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja1Intro:
# 85 "data//maps/FortreeCliffs/scripts.pory"
	.string "Our grandpa is annoying as heck!$"
# 86 "data//maps/FortreeCliffs/scripts.pory"

# 87 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja1PostBattle:
# 88 "data//maps/FortreeCliffs/scripts.pory"
	.string "Ha! Idiot!$"
# 89 "data//maps/FortreeCliffs/scripts.pory"

# 90 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja1Defeat:
# 91 "data//maps/FortreeCliffs/scripts.pory"
	.string "You're annoying too!$"
# 92 "data//maps/FortreeCliffs/scripts.pory"

# 93 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja2Intro:
# 94 "data//maps/FortreeCliffs/scripts.pory"
	.string "Our grandpa is annoying as heck!$"
# 95 "data//maps/FortreeCliffs/scripts.pory"

# 96 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja2PostBattle:
# 97 "data//maps/FortreeCliffs/scripts.pory"
	.string "Ha! Idiot!$"
# 98 "data//maps/FortreeCliffs/scripts.pory"

# 99 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja2Defeat:
# 100 "data//maps/FortreeCliffs/scripts.pory"
	.string "You're annoying too!$"
# 101 "data//maps/FortreeCliffs/scripts.pory"

# 102 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja3Intro:
# 103 "data//maps/FortreeCliffs/scripts.pory"
	.string "Our grandpa is annoying as heck!$"
# 104 "data//maps/FortreeCliffs/scripts.pory"

# 105 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja3PostBattle:
# 106 "data//maps/FortreeCliffs/scripts.pory"
	.string "Ha! Idiot!$"
# 107 "data//maps/FortreeCliffs/scripts.pory"

# 108 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja3Defeat:
# 109 "data//maps/FortreeCliffs/scripts.pory"
	.string "You're annoying too!$"
# 110 "data//maps/FortreeCliffs/scripts.pory"

# 111 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja4Intro:
# 112 "data//maps/FortreeCliffs/scripts.pory"
	.string "Surprise! I've been studying KECLEON!$"
# 113 "data//maps/FortreeCliffs/scripts.pory"

# 114 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja4PostBattle:
# 115 "data//maps/FortreeCliffs/scripts.pory"
	.string "My camouflage is perfect!$"
# 116 "data//maps/FortreeCliffs/scripts.pory"

# 117 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja4Defeat:
# 118 "data//maps/FortreeCliffs/scripts.pory"
	.string "$"
# 119 "data//maps/FortreeCliffs/scripts.pory"

# 120 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja5Intro:
# 121 "data//maps/FortreeCliffs/scripts.pory"
	.string "I'm the star pupil!$"
# 122 "data//maps/FortreeCliffs/scripts.pory"

# 123 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja5PostBattle:
# 124 "data//maps/FortreeCliffs/scripts.pory"
	.string "That's why I'm Grandpa's favorite!$"
# 125 "data//maps/FortreeCliffs/scripts.pory"

# 126 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja5Defeat:
# 127 "data//maps/FortreeCliffs/scripts.pory"
	.string "I'm such a disappointment…$"
# 128 "data//maps/FortreeCliffs/scripts.pory"

# 129 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja6Intro:
# 130 "data//maps/FortreeCliffs/scripts.pory"
	.string "I'm trying to take it easy here!$"
# 131 "data//maps/FortreeCliffs/scripts.pory"

# 132 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja6PostBattle:
# 133 "data//maps/FortreeCliffs/scripts.pory"
	.string "Resting pays off just as much as training.$"
# 134 "data//maps/FortreeCliffs/scripts.pory"

# 135 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja6Defeat:
# 136 "data//maps/FortreeCliffs/scripts.pory"
	.string "I guess I should be trying harder…$"
# 137 "data//maps/FortreeCliffs/scripts.pory"

# 138 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Expert1Intro:
# 139 "data//maps/FortreeCliffs/scripts.pory"
	.string "Training my grandchildren is rewarding,\n"
# 140 "data//maps/FortreeCliffs/scripts.pory"
	.string "but they can also be quite irksome!$"
# 141 "data//maps/FortreeCliffs/scripts.pory"

# 142 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Expert1PostBattle:
# 143 "data//maps/FortreeCliffs/scripts.pory"
	.string "I'm always dealing with children…$"
# 144 "data//maps/FortreeCliffs/scripts.pory"

# 145 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Expert1Defeat:
# 146 "data//maps/FortreeCliffs/scripts.pory"
	.string "Finally, a fellow adult!$"
# 147 "data//maps/FortreeCliffs/scripts.pory"

# 148 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger1Intro:
# 149 "data//maps/FortreeCliffs/scripts.pory"
	.string "Do you have the right berries?$"
# 150 "data//maps/FortreeCliffs/scripts.pory"

# 151 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger1PostBattle:
# 152 "data//maps/FortreeCliffs/scripts.pory"
	.string "Collect more berries, and learn their\n"
# 153 "data//maps/FortreeCliffs/scripts.pory"
	.string "effects.$"
# 154 "data//maps/FortreeCliffs/scripts.pory"

# 155 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger1Defeat:
# 156 "data//maps/FortreeCliffs/scripts.pory"
	.string "I need more berries now!$"
# 157 "data//maps/FortreeCliffs/scripts.pory"

# 158 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger2Intro:
# 159 "data//maps/FortreeCliffs/scripts.pory"
	.string "Are you prepared for this terrain?$"
# 160 "data//maps/FortreeCliffs/scripts.pory"

# 161 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger2PostBattle:
# 162 "data//maps/FortreeCliffs/scripts.pory"
	.string "Before exploring far from town,\n"
# 163 "data//maps/FortreeCliffs/scripts.pory"
	.string "double check your supplies!$"
# 164 "data//maps/FortreeCliffs/scripts.pory"

# 165 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger2Defeat:
# 166 "data//maps/FortreeCliffs/scripts.pory"
	.string "I wasn't prepared for this!$"
# 167 "data//maps/FortreeCliffs/scripts.pory"

# 168 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BirdKeeper1Intro:
# 169 "data//maps/FortreeCliffs/scripts.pory"
	.string "WINONA trains here, on the highest cliffs!$"
# 170 "data//maps/FortreeCliffs/scripts.pory"

# 171 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BirdKeeper1PostBattle:
# 172 "data//maps/FortreeCliffs/scripts.pory"
	.string "I simply mirrored WINONA's training.$"
# 173 "data//maps/FortreeCliffs/scripts.pory"

# 174 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BirdKeeper1Defeat:
# 175 "data//maps/FortreeCliffs/scripts.pory"
	.string "How does WINONA fly so high?$"
