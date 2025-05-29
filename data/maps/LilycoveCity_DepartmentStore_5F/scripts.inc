# 1 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 2 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_MapScripts::
# 3 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LilycoveCity_DepartmentStore_5F_OnWarp
# 4 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.byte 0
# 5 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 6 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
@ During the abnormal weather from Kyogre/Groudon awakening the dept store rooftop is inaccessible
# 7 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
@ Likely done to avoid dealing with showing the weather. Technically the rooftop is indoors
# 8 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_OnWarp:
# 9 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 1, LilycoveCity_DepartmentStore_5F_EventScript_BlockRoofStairs
# 10 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 2, LilycoveCity_DepartmentStore_5F_EventScript_BlockRoofStairs
# 11 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 3, LilycoveCity_DepartmentStore_5F_EventScript_BlockRoofStairs
# 12 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte 0
# 13 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 14 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_EventScript_BlockRoofStairs::
# 15 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	setobjectxy LOCALID_DEPARTMENT_STORE_STAIRS_WOMAN, 16, 2
# 16 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	turnobject LOCALID_DEPARTMENT_STORE_STAIRS_WOMAN, DIR_NORTH
# 17 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	end
# 18 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 19 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_EventScript_ClerkFarLeft::
# 20 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	lock
# 21 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	faceplayer
# 22 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	message gText_HowMayIServeYou
# 23 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	waitmessage
# 24 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	pokemartdecoration2 LilycoveCity_DepartmentStore_5F_Pokemart_Dolls
# 25 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 26 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	release
# 27 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	end
# 28 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 29 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.align 2
# 30 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_Pokemart_Dolls:
# 31 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_PICHU_DOLL
# 32 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_PIKACHU_DOLL
# 33 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_MARILL_DOLL
# 34 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_JIGGLYPUFF_DOLL
# 35 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_DUSKULL_DOLL
# 36 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_WYNAUT_DOLL
# 37 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_BALTOY_DOLL
# 38 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_KECLEON_DOLL
# 39 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_AZURILL_DOLL
# 40 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_SKITTY_DOLL
# 41 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_SWABLU_DOLL
# 42 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_GULPIN_DOLL
# 43 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_NONE
# 44 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	release
# 45 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	end
# 46 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 47 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_EventScript_ClerkMidLeft::
# 48 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	lock
# 49 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	faceplayer
# 50 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	message gText_HowMayIServeYou
# 51 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	waitmessage
# 52 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	pokemartdecoration2 LilycoveCity_DepartmentStore_5F_Pokemart_Cushions
# 53 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 54 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	release
# 55 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	end
# 56 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 57 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.align 2
# 58 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_Pokemart_Cushions:
# 59 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_PIKA_CUSHION
# 60 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_ROUND_CUSHION
# 61 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_ZIGZAG_CUSHION
# 62 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_SPIN_CUSHION
# 63 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_DIAMOND_CUSHION
# 64 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_BALL_CUSHION
# 65 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_GRASS_CUSHION
# 66 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_FIRE_CUSHION
# 67 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_WATER_CUSHION
# 68 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_NONE
# 69 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	release
# 70 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	end
# 71 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 72 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_EventScript_ClerkMidRight::
# 73 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	lock
# 74 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	faceplayer
# 75 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	message gText_HowMayIServeYou
# 76 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	waitmessage
# 77 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	pokemartdecoration2 LilycoveCity_DepartmentStore_5F_Pokemart_Posters
# 78 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 79 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	release
# 80 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	end
# 81 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 82 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.align 2
# 83 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_Pokemart_Posters:
# 84 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_BALL_POSTER
# 85 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_GREEN_POSTER
# 86 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_RED_POSTER
# 87 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_BLUE_POSTER
# 88 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_CUTE_POSTER
# 89 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_PIKA_POSTER
# 90 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_LONG_POSTER
# 91 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_SEA_POSTER
# 92 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_SKY_POSTER
# 93 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_NONE
# 94 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	release
# 95 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	end
# 96 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 97 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_EventScript_ClerkFarRight::
# 98 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	lock
# 99 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	faceplayer
# 100 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	message gText_HowMayIServeYou
# 101 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	waitmessage
# 102 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	pokemartdecoration2 LilycoveCity_DepartmentStore_5F_Pokemart_Mats
# 103 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 104 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	release
# 105 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	end
# 106 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 107 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.align 2
# 108 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_Pokemart_Mats:
# 109 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_SURF_MAT
# 110 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_THUNDER_MAT
# 111 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_FIRE_BLAST_MAT
# 112 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_POWDER_SNOW_MAT
# 113 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_ATTRACT_MAT
# 114 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_FISSURE_MAT
# 115 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_SPIKES_MAT
# 116 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_GLITTER_MAT
# 117 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_JUMP_MAT
# 118 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_SPIN_MAT
# 119 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_NONE
# 120 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	release
# 121 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	end
# 122 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 123 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_EventScript_PokefanF::
# 124 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_5F_Text_PlaceFullOfCuteDolls, MSGBOX_NPC
# 125 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	end
# 126 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 127 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_EventScript_Woman::
# 128 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	lockall
# 129 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	applymovement LOCALID_DEPARTMENT_STORE_STAIRS_WOMAN, Common_Movement_FacePlayer
# 130 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	waitmovement 0
# 131 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0, LilycoveCity_DepartmentStore_5F_EventScript_WomanNormal
# 132 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 4, LilycoveCity_DepartmentStore_5F_EventScript_WomanNormal
# 133 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	goto LilycoveCity_DepartmentStore_5F_EventScript_WomanLegendaryWeather
# 134 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	end
# 135 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 136 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_EventScript_WomanNormal::
# 137 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_5F_Text_SellManyCuteMatsHere, MSGBOX_DEFAULT
# 138 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	closemessage
# 139 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	releaseall
# 140 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	end
# 141 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 142 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_EventScript_WomanLegendaryWeather::
# 143 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_5F_Text_ClosedRooftopForWeather, MSGBOX_DEFAULT
# 144 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	closemessage
# 145 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	applymovement LOCALID_DEPARTMENT_STORE_STAIRS_WOMAN, Common_Movement_WalkInPlaceFasterUp
# 146 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	waitmovement 0
# 147 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	releaseall
# 148 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	end
# 149 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 150 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_EventScript_LittleGirl::
# 151 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_5F_Text_GettingDollInsteadOfPokemon, MSGBOX_NPC
# 152 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	end
# 153 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 154 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_Text_PlaceFullOfCuteDolls:
# 155 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.string "This place is full of cute DOLLS.\p"
# 156 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.string "I should buy some for me, instead of\n"
# 157 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.string "just for my children.$"
# 158 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 159 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_Text_GettingDollInsteadOfPokemon:
# 160 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.string "I'm not big enough to raise POKéMON,\n"
# 161 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.string "so I'm getting a cute DOLL instead.$"
# 162 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 163 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_Text_SellManyCuteMatsHere:
# 164 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.string "They sell many cute MATS here.\p"
# 165 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.string "I wonder which one I should get?\n"
# 166 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.string "Maybe I'll buy them all…$"
# 167 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 168 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_Text_ClosedRooftopForWeather:
# 169 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.string "I think they closed the rooftop\n"
# 170 "data//maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.string "because the weather is wild today.$"
