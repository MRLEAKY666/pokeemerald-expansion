# 1 "data//maps/FortreeCity/scripts.pory"

# 2 "data//maps/FortreeCity/scripts.pory"
FortreeCity_MapScripts::
# 3 "data//maps/FortreeCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_OnTransition
# 4 "data//maps/FortreeCity/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_OnResume
# 5 "data//maps/FortreeCity/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, FortreeCity_OnLoad
# 6 "data//maps/FortreeCity/scripts.pory"
	.byte 0
# 7 "data//maps/FortreeCity/scripts.pory"

# 8 "data//maps/FortreeCity/scripts.pory"
FortreeCity_OnTransition:
# 9 "data//maps/FortreeCity/scripts.pory"
	setflag FLAG_VISITED_FORTREE_CITY
# 10 "data//maps/FortreeCity/scripts.pory"
	end
# 11 "data//maps/FortreeCity/scripts.pory"

# 12 "data//maps/FortreeCity/scripts.pory"
FortreeCity_OnResume:
# 13 "data//maps/FortreeCity/scripts.pory"
	setstepcallback STEP_CB_FORTREE_BRIDGE
# 14 "data//maps/FortreeCity/scripts.pory"
	end
# 15 "data//maps/FortreeCity/scripts.pory"

# 16 "data//maps/FortreeCity/scripts.pory"
FortreeCity_OnLoad:
# 17 "data//maps/FortreeCity/scripts.pory"
	setflag FLAG_FORTREE_LOCKED_GYM_SIGN
# 18 "data//maps/FortreeCity/scripts.pory"
	call_if_eq VAR_WINONA_LOCATION, 0, FortreeCity_EventScript_LockGymDoors
# 19 "data//maps/FortreeCity/scripts.pory"
	end
# 20 "data//maps/FortreeCity/scripts.pory"

# 21 "data//maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_LockGymDoors::
# 22 "data//maps/FortreeCity/scripts.pory"
	setmetatile 22, 11, METATILE_Fortree_Door_Gym_Locked, TRUE
# 23 "data//maps/FortreeCity/scripts.pory"
	clearflag FLAG_FORTREE_LOCKED_GYM_SIGN
# 24 "data//maps/FortreeCity/scripts.pory"
	return
# 25 "data//maps/FortreeCity/scripts.pory"

# 26 "data//maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_Man::
# 27 "data//maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_SawGiganticPokemonInSky, MSGBOX_NPC
# 28 "data//maps/FortreeCity/scripts.pory"
	end
# 29 "data//maps/FortreeCity/scripts.pory"

# 30 "data//maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_Woman::
# 31 "data//maps/FortreeCity/scripts.pory"
	lock
# 32 "data//maps/FortreeCity/scripts.pory"
	faceplayer
# 33 "data//maps/FortreeCity/scripts.pory"
	goto_if_set FLAG_KECLEON_FLED_FORTREE, FortreeCity_EventScript_WomanGymAccessible
# 34 "data//maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_SomethingBlockingGym, MSGBOX_DEFAULT
# 35 "data//maps/FortreeCity/scripts.pory"
	release
# 36 "data//maps/FortreeCity/scripts.pory"
	end
# 37 "data//maps/FortreeCity/scripts.pory"

# 38 "data//maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_WomanGymAccessible::
# 39 "data//maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_ThisTimeIllBeatWinona, MSGBOX_DEFAULT
# 40 "data//maps/FortreeCity/scripts.pory"
	release
# 41 "data//maps/FortreeCity/scripts.pory"
	end
# 42 "data//maps/FortreeCity/scripts.pory"

# 43 "data//maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_Girl::
# 44 "data//maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_TreesGrowByDrinkingRainwater, MSGBOX_NPC
# 45 "data//maps/FortreeCity/scripts.pory"
	end
# 46 "data//maps/FortreeCity/scripts.pory"

# 47 "data//maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_OldMan::
# 48 "data//maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_EveryoneHealthyAndLively, MSGBOX_NPC
# 49 "data//maps/FortreeCity/scripts.pory"
	end
# 50 "data//maps/FortreeCity/scripts.pory"

# 51 "data//maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_Boy::
# 52 "data//maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_BugPokemonComeThroughWindow, MSGBOX_NPC
# 53 "data//maps/FortreeCity/scripts.pory"
	end
# 54 "data//maps/FortreeCity/scripts.pory"

# 55 "data//maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_GameboyKid::
# 56 "data//maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_PokemonThatEvolveWhenTraded, MSGBOX_NPC
# 57 "data//maps/FortreeCity/scripts.pory"
	end
# 58 "data//maps/FortreeCity/scripts.pory"

# 59 "data//maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_CitySign::
# 60 "data//maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_CitySign, MSGBOX_SIGN
# 61 "data//maps/FortreeCity/scripts.pory"
	end
# 62 "data//maps/FortreeCity/scripts.pory"

# 63 "data//maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_GymSign::
# 64 "data//maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_GymSign, MSGBOX_SIGN
# 65 "data//maps/FortreeCity/scripts.pory"
	end
# 66 "data//maps/FortreeCity/scripts.pory"

# 67 "data//maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_Kecleon::
# 68 "data//maps/FortreeCity/scripts.pory"
	lock
# 69 "data//maps/FortreeCity/scripts.pory"
	faceplayer
# 70 "data//maps/FortreeCity/scripts.pory"
	checkitem ITEM_DEVON_SCOPE
# 71 "data//maps/FortreeCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_EventScript_AskUseDevonScope
# 72 "data//maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_SomethingUnseeable, MSGBOX_DEFAULT
# 73 "data//maps/FortreeCity/scripts.pory"
	release
# 74 "data//maps/FortreeCity/scripts.pory"
	end
# 75 "data//maps/FortreeCity/scripts.pory"

# 76 "data//maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_AskUseDevonScope::
# 77 "data//maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_UnseeableUseDevonScope, MSGBOX_YESNO
# 78 "data//maps/FortreeCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, FortreeCity_EventScript_UseDevonScope
# 79 "data//maps/FortreeCity/scripts.pory"
	release
# 80 "data//maps/FortreeCity/scripts.pory"
	end
# 81 "data//maps/FortreeCity/scripts.pory"

# 82 "data//maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_UseDevonScope::
# 83 "data//maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_UsedDevonScopePokemonFled, MSGBOX_DEFAULT
# 84 "data//maps/FortreeCity/scripts.pory"
	closemessage
# 85 "data//maps/FortreeCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Movement_KecleonAppears
# 86 "data//maps/FortreeCity/scripts.pory"
	waitmovement 0
# 87 "data//maps/FortreeCity/scripts.pory"
	waitse
# 88 "data//maps/FortreeCity/scripts.pory"
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
# 89 "data//maps/FortreeCity/scripts.pory"
	delay 40
# 90 "data//maps/FortreeCity/scripts.pory"
	waitmoncry
# 91 "data//maps/FortreeCity/scripts.pory"
	applymovement VAR_LAST_TALKED, FortreeCity_Movement_KecleonFlee
# 92 "data//maps/FortreeCity/scripts.pory"
	waitmovement 0
# 93 "data//maps/FortreeCity/scripts.pory"
	removeobject VAR_LAST_TALKED
# 94 "data//maps/FortreeCity/scripts.pory"
	setflag FLAG_KECLEON_FLED_FORTREE
# 95 "data//maps/FortreeCity/scripts.pory"
	release
# 96 "data//maps/FortreeCity/scripts.pory"
	end
# 97 "data//maps/FortreeCity/scripts.pory"

# 98 "data//maps/FortreeCity/scripts.pory"
FortreeCity_Movement_KecleonFlee:
# 99 "data//maps/FortreeCity/scripts.pory"
	walk_right
# 100 "data//maps/FortreeCity/scripts.pory"
	step_end
# 101 "data//maps/FortreeCity/scripts.pory"

# 102 "data//maps/FortreeCity/scripts.pory"

# 103 "data//maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_LockedGymSign::
# 104 "data//maps/FortreeCity/scripts.pory"
	lock
# 105 "data//maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_LockedGymSign, MSGBOX_SIGN
# 106 "data//maps/FortreeCity/scripts.pory"
	release
# 107 "data//maps/FortreeCity/scripts.pory"
	end
# 108 "data//maps/FortreeCity/scripts.pory"

# 109 "data//maps/FortreeCity/scripts.pory"
FortreeCity_Text_SawGiganticPokemonInSky:
# 110 "data//maps/FortreeCity/scripts.pory"
	.string "No one believes me, but I saw this\n"
# 111 "data//maps/FortreeCity/scripts.pory"
	.string "gigantic POKéMON in the sky.\p"
# 112 "data//maps/FortreeCity/scripts.pory"
	.string "It seemed to squirm as it flew toward\n"
# 113 "data//maps/FortreeCity/scripts.pory"
	.string "ROUTE 131.\p"
# 114 "data//maps/FortreeCity/scripts.pory"
	.string "By the way… Sniff…\n"
# 115 "data//maps/FortreeCity/scripts.pory"
	.string "Um… You, uh…smell singed.\p"
# 116 "data//maps/FortreeCity/scripts.pory"
	.string "Were you at a volcano or something?$"
# 117 "data//maps/FortreeCity/scripts.pory"

# 118 "data//maps/FortreeCity/scripts.pory"
FortreeCity_Text_SomethingBlockingGym:
# 119 "data//maps/FortreeCity/scripts.pory"
	.string "I want to go to the POKéMON GYM,\n"
# 120 "data//maps/FortreeCity/scripts.pory"
	.string "but something's blocking the way.\p"
# 121 "data//maps/FortreeCity/scripts.pory"
	.string "After all the bother I went through\n"
# 122 "data//maps/FortreeCity/scripts.pory"
	.string "training on ROUTE 120…$"
# 123 "data//maps/FortreeCity/scripts.pory"

# 124 "data//maps/FortreeCity/scripts.pory"
FortreeCity_Text_ThisTimeIllBeatWinona:
# 125 "data//maps/FortreeCity/scripts.pory"
	.string "I've got my pride-and-joy POKéMON\n"
# 126 "data//maps/FortreeCity/scripts.pory"
	.string "with me. This time, I'll beat WINONA.$"
# 127 "data//maps/FortreeCity/scripts.pory"

# 128 "data//maps/FortreeCity/scripts.pory"
FortreeCity_Text_TreesGrowByDrinkingRainwater:
# 129 "data//maps/FortreeCity/scripts.pory"
	.string "The ground absorbs rainwater, and\n"
# 130 "data//maps/FortreeCity/scripts.pory"
	.string "trees grow by drinking that water…\p"
# 131 "data//maps/FortreeCity/scripts.pory"
	.string "Our FORTREE CITY exists because\n"
# 132 "data//maps/FortreeCity/scripts.pory"
	.string "there's both water and soil.$"
# 133 "data//maps/FortreeCity/scripts.pory"

# 134 "data//maps/FortreeCity/scripts.pory"
FortreeCity_Text_EveryoneHealthyAndLively:
# 135 "data//maps/FortreeCity/scripts.pory"
	.string "The CITY consists of homes built on\n"
# 136 "data//maps/FortreeCity/scripts.pory"
	.string "trees.\p"
# 137 "data//maps/FortreeCity/scripts.pory"
	.string "Perhaps because of that lifestyle,\n"
# 138 "data//maps/FortreeCity/scripts.pory"
	.string "everyone is healthy and lively.\p"
# 139 "data//maps/FortreeCity/scripts.pory"
	.string "Why, even myself--I feel as if I've\n"
# 140 "data//maps/FortreeCity/scripts.pory"
	.string "grown thirty years younger.$"
# 141 "data//maps/FortreeCity/scripts.pory"

# 142 "data//maps/FortreeCity/scripts.pory"
FortreeCity_Text_BugPokemonComeThroughWindow:
# 143 "data//maps/FortreeCity/scripts.pory"
	.string "Living on top of trees is okay.\p"
# 144 "data//maps/FortreeCity/scripts.pory"
	.string "But sometimes BUG POKéMON come in\n"
# 145 "data//maps/FortreeCity/scripts.pory"
	.string "through windows.\l"
# 146 "data//maps/FortreeCity/scripts.pory"
	.string "It can be really startling.$"
# 147 "data//maps/FortreeCity/scripts.pory"

# 148 "data//maps/FortreeCity/scripts.pory"
FortreeCity_Text_PokemonThatEvolveWhenTraded:
# 149 "data//maps/FortreeCity/scripts.pory"
	.string "There are POKéMON that evolve when\n"
# 150 "data//maps/FortreeCity/scripts.pory"
	.string "you trade them! That's what I heard.$"
# 151 "data//maps/FortreeCity/scripts.pory"

# 152 "data//maps/FortreeCity/scripts.pory"
FortreeCity_Text_SomethingUnseeable:
# 153 "data//maps/FortreeCity/scripts.pory"
	.string "Something unseeable is in the way.$"
# 154 "data//maps/FortreeCity/scripts.pory"

# 155 "data//maps/FortreeCity/scripts.pory"
FortreeCity_Text_UnseeableUseDevonScope:
# 156 "data//maps/FortreeCity/scripts.pory"
	.string "Something unseeable is in the way.\p"
# 157 "data//maps/FortreeCity/scripts.pory"
	.string "Want to use the DEVON SCOPE?$"
# 158 "data//maps/FortreeCity/scripts.pory"

# 159 "data//maps/FortreeCity/scripts.pory"
FortreeCity_Text_UsedDevonScopePokemonFled:
# 160 "data//maps/FortreeCity/scripts.pory"
	.string "{PLAYER} used the DEVON SCOPE.\p"
# 161 "data//maps/FortreeCity/scripts.pory"
	.string "An invisible POKéMON became completely\n"
# 162 "data//maps/FortreeCity/scripts.pory"
	.string "visible!\p"
# 163 "data//maps/FortreeCity/scripts.pory"
	.string "The startled POKéMON fled!$"
# 164 "data//maps/FortreeCity/scripts.pory"

# 165 "data//maps/FortreeCity/scripts.pory"
FortreeCity_Text_CitySign:
# 166 "data//maps/FortreeCity/scripts.pory"
	.string "FORTREE CITY\n"
# 167 "data//maps/FortreeCity/scripts.pory"
	.string "“The treetop city that frolics with\l"
# 168 "data//maps/FortreeCity/scripts.pory"
	.string "nature.”$"
# 169 "data//maps/FortreeCity/scripts.pory"

# 170 "data//maps/FortreeCity/scripts.pory"
FortreeCity_Text_GymSign:
# 171 "data//maps/FortreeCity/scripts.pory"
	.string "FORTREE CITY POKéMON GYM\n"
# 172 "data//maps/FortreeCity/scripts.pory"
	.string "LEADER: WINONA\p"
# 173 "data//maps/FortreeCity/scripts.pory"
	.string "“The bird user taking flight into\n"
# 174 "data//maps/FortreeCity/scripts.pory"
	.string "the world.”$"
# 175 "data//maps/FortreeCity/scripts.pory"

# 176 "data//maps/FortreeCity/scripts.pory"
FortreeCity_Text_LockedGymSign:
# 177 "data//maps/FortreeCity/scripts.pory"
	.string "There's a note on the door…\p"
# 178 "data//maps/FortreeCity/scripts.pory"
	.string "I left to do some training to the South\n"
# 179 "data//maps/FortreeCity/scripts.pory"
	.string "of the city. Come back later.\l"
# 180 "data//maps/FortreeCity/scripts.pory"
	.string "- WINONA$"
