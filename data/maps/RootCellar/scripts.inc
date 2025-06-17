# 1 "data//maps/RootCellar/scripts.pory"

# 2 "data//maps/RootCellar/scripts.pory"
RootCellar_MapScripts::
# 3 "data//maps/RootCellar/scripts.pory"
    map_script MAP_SCRIPT_ON_RESUME, RootCellar_OnTransition
# 4 "data//maps/RootCellar/scripts.pory"
    map_script MAP_SCRIPT_ON_RESUME, RootCellar_OnResume
# 5 "data//maps/RootCellar/scripts.pory"
	.byte 0
# 6 "data//maps/RootCellar/scripts.pory"

# 7 "data//maps/RootCellar/scripts.pory"
RootCellar_OnTransition:
# 8 "data//maps/RootCellar/scripts.pory"
	call RootCellar_EventScript_SetShelf1State
# 9 "data//maps/RootCellar/scripts.pory"
	call RootCellar_EventScript_SetShelf2State
# 10 "data//maps/RootCellar/scripts.pory"
	call RootCellar_EventScript_SetShelf3State
# 11 "data//maps/RootCellar/scripts.pory"
	call RootCellar_EventScript_SetShelf4State
# 12 "data//maps/RootCellar/scripts.pory"
	end
# 13 "data//maps/RootCellar/scripts.pory"

# 14 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_SetShelf1State::
# 15 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_E, 2
# 16 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_F, 2
# 17 "data//maps/RootCellar/scripts.pory"
	switch VAR_ROOT_CELLAR_SHELF_1
# 18 "data//maps/RootCellar/scripts.pory"
	case 1, RootCellar_EventScript_SetShelfBHalf
# 19 "data//maps/RootCellar/scripts.pory"
	case 2, RootCellar_EventScript_SetShelfEmpty
# 20 "data//maps/RootCellar/scripts.pory"
	return
# 21 "data//maps/RootCellar/scripts.pory"

# 22 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_SetShelf2State::
# 23 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_E, 10
# 24 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_F, 2
# 25 "data//maps/RootCellar/scripts.pory"
	switch VAR_ROOT_CELLAR_SHELF_2
# 26 "data//maps/RootCellar/scripts.pory"
	case 1, RootCellar_EventScript_SetShelfAHalf
# 27 "data//maps/RootCellar/scripts.pory"
	case 2, RootCellar_EventScript_SetShelfEmpty
# 28 "data//maps/RootCellar/scripts.pory"
	return
# 29 "data//maps/RootCellar/scripts.pory"

# 30 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_SetShelf3State::
# 31 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_E, 2
# 32 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_F, 9
# 33 "data//maps/RootCellar/scripts.pory"
	switch VAR_ROOT_CELLAR_SHELF_3
# 34 "data//maps/RootCellar/scripts.pory"
	case 1, RootCellar_EventScript_SetShelfAHalf
# 35 "data//maps/RootCellar/scripts.pory"
	case 2, RootCellar_EventScript_SetShelfEmpty
# 36 "data//maps/RootCellar/scripts.pory"
	return
# 37 "data//maps/RootCellar/scripts.pory"

# 38 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_SetShelf4State::
# 39 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_E, 10
# 40 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_F, 12
# 41 "data//maps/RootCellar/scripts.pory"
	switch VAR_ROOT_CELLAR_SHELF_4
# 42 "data//maps/RootCellar/scripts.pory"
	case 1, RootCellar_EventScript_SetShelfBHalf
# 43 "data//maps/RootCellar/scripts.pory"
	case 2, RootCellar_EventScript_SetShelfEmpty
# 44 "data//maps/RootCellar/scripts.pory"
	return
# 45 "data//maps/RootCellar/scripts.pory"

# 46 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_SetShelfAHalf::
# 47 "data//maps/RootCellar/scripts.pory"
	setmetatile VAR_TEMP_E, VAR_TEMP_F, METATILE_Cave_RootCellar_Shelf_A_Half, TRUE
# 48 "data//maps/RootCellar/scripts.pory"
	return
# 49 "data//maps/RootCellar/scripts.pory"

# 50 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_SetShelfBHalf::
# 51 "data//maps/RootCellar/scripts.pory"
	setmetatile VAR_TEMP_E, VAR_TEMP_F, METATILE_Cave_RootCellar_Shelf_B_Half, TRUE
# 52 "data//maps/RootCellar/scripts.pory"
	return
# 53 "data//maps/RootCellar/scripts.pory"

# 54 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_SetShelfEmpty::
# 55 "data//maps/RootCellar/scripts.pory"
	setmetatile VAR_TEMP_E, VAR_TEMP_F, METATILE_Cave_RootCellar_Shelf_Empty, TRUE
# 56 "data//maps/RootCellar/scripts.pory"
	return
# 57 "data//maps/RootCellar/scripts.pory"

# 58 "data//maps/RootCellar/scripts.pory"
RootCellar_OnResume:
# 59 "data//maps/RootCellar/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, RootCellar_EventScript_TryRemoveWildMon
# 60 "data//maps/RootCellar/scripts.pory"
	end
# 61 "data//maps/RootCellar/scripts.pory"

# 62 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_TryRemoveWildMon::
# 63 "data//maps/RootCellar/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 64 "data//maps/RootCellar/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 65 "data//maps/RootCellar/scripts.pory"
	removeobject VAR_LAST_TALKED
# 66 "data//maps/RootCellar/scripts.pory"
	return
# 67 "data//maps/RootCellar/scripts.pory"

# 68 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_Shuckle1::
# 69 "data//maps/RootCellar/scripts.pory"
	lock
# 70 "data//maps/RootCellar/scripts.pory"
	faceplayer
# 71 "data//maps/RootCellar/scripts.pory"
	waitse
# 72 "data//maps/RootCellar/scripts.pory"
	playmoncry SPECIES_SHUCKLE, CRY_MODE_ENCOUNTER
# 73 "data//maps/RootCellar/scripts.pory"
	delay 10
# 74 "data//maps/RootCellar/scripts.pory"
	waitmoncry
# 75 "data//maps/RootCellar/scripts.pory"
	setwildbattle SPECIES_SHUCKLE, 40
# 76 "data//maps/RootCellar/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 77 "data//maps/RootCellar/scripts.pory"
	dowildbattle
# 78 "data//maps/RootCellar/scripts.pory"
	@ waitstate
# 79 "data//maps/RootCellar/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 80 "data//maps/RootCellar/scripts.pory"
	setvar VAR_0x8004, SPECIES_SHUCKLE
# 81 "data//maps/RootCellar/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 82 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, RootCellar_EventScript_DefeatedWildMon
# 83 "data//maps/RootCellar/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, RootCellar_EventScript_RanWildMon
# 84 "data//maps/RootCellar/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, RootCellar_EventScript_RanWildMon
# 85 "data//maps/RootCellar/scripts.pory"
	release
# 86 "data//maps/RootCellar/scripts.pory"
	end
# 87 "data//maps/RootCellar/scripts.pory"

# 88 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_Shuckle2::
# 89 "data//maps/RootCellar/scripts.pory"
	lock
# 90 "data//maps/RootCellar/scripts.pory"
	faceplayer
# 91 "data//maps/RootCellar/scripts.pory"
	waitse
# 92 "data//maps/RootCellar/scripts.pory"
	playmoncry SPECIES_SHUCKLE, CRY_MODE_ENCOUNTER
# 93 "data//maps/RootCellar/scripts.pory"
	delay 10
# 94 "data//maps/RootCellar/scripts.pory"
	waitmoncry
# 95 "data//maps/RootCellar/scripts.pory"
	setwildbattle SPECIES_SHUCKLE, 40
# 96 "data//maps/RootCellar/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 97 "data//maps/RootCellar/scripts.pory"
	dowildbattle
# 98 "data//maps/RootCellar/scripts.pory"
	@ waitstate
# 99 "data//maps/RootCellar/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 100 "data//maps/RootCellar/scripts.pory"
	setvar VAR_0x8004, SPECIES_SHUCKLE
# 101 "data//maps/RootCellar/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 102 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, RootCellar_EventScript_DefeatedWildMon
# 103 "data//maps/RootCellar/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, RootCellar_EventScript_RanWildMon
# 104 "data//maps/RootCellar/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, RootCellar_EventScript_RanWildMon
# 105 "data//maps/RootCellar/scripts.pory"
	release
# 106 "data//maps/RootCellar/scripts.pory"
	end
# 107 "data//maps/RootCellar/scripts.pory"

# 108 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_Spinarak1::
# 109 "data//maps/RootCellar/scripts.pory"
	lock
# 110 "data//maps/RootCellar/scripts.pory"
	faceplayer
# 111 "data//maps/RootCellar/scripts.pory"
	waitse
# 112 "data//maps/RootCellar/scripts.pory"
	playmoncry SPECIES_SPINARAK, CRY_MODE_ENCOUNTER
# 113 "data//maps/RootCellar/scripts.pory"
	delay 10
# 114 "data//maps/RootCellar/scripts.pory"
	waitmoncry
# 115 "data//maps/RootCellar/scripts.pory"
	setwildbattle SPECIES_SPINARAK, 40
# 116 "data//maps/RootCellar/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 117 "data//maps/RootCellar/scripts.pory"
	dowildbattle
# 118 "data//maps/RootCellar/scripts.pory"
	@ waitstate
# 119 "data//maps/RootCellar/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 120 "data//maps/RootCellar/scripts.pory"
	setvar VAR_0x8004, SPECIES_SPINARAK
# 121 "data//maps/RootCellar/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 122 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, RootCellar_EventScript_DefeatedWildMon
# 123 "data//maps/RootCellar/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, RootCellar_EventScript_RanWildMon
# 124 "data//maps/RootCellar/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, RootCellar_EventScript_RanWildMon
# 125 "data//maps/RootCellar/scripts.pory"
	release
# 126 "data//maps/RootCellar/scripts.pory"
	end
# 127 "data//maps/RootCellar/scripts.pory"

# 128 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_Spinarak2::
# 129 "data//maps/RootCellar/scripts.pory"
	lock
# 130 "data//maps/RootCellar/scripts.pory"
	faceplayer
# 131 "data//maps/RootCellar/scripts.pory"
	waitse
# 132 "data//maps/RootCellar/scripts.pory"
	playmoncry SPECIES_SPINARAK, CRY_MODE_ENCOUNTER
# 133 "data//maps/RootCellar/scripts.pory"
	delay 10
# 134 "data//maps/RootCellar/scripts.pory"
	waitmoncry
# 135 "data//maps/RootCellar/scripts.pory"
	setwildbattle SPECIES_SPINARAK, 40
# 136 "data//maps/RootCellar/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 137 "data//maps/RootCellar/scripts.pory"
	dowildbattle
# 138 "data//maps/RootCellar/scripts.pory"
	@ waitstate
# 139 "data//maps/RootCellar/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 140 "data//maps/RootCellar/scripts.pory"
	setvar VAR_0x8004, SPECIES_SPINARAK
# 141 "data//maps/RootCellar/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 142 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, RootCellar_EventScript_DefeatedWildMon
# 143 "data//maps/RootCellar/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, RootCellar_EventScript_RanWildMon
# 144 "data//maps/RootCellar/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, RootCellar_EventScript_RanWildMon
# 145 "data//maps/RootCellar/scripts.pory"
	release
# 146 "data//maps/RootCellar/scripts.pory"
	end
# 147 "data//maps/RootCellar/scripts.pory"

# 148 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_DefeatedWildMon::
# 149 "data//maps/RootCellar/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 150 "data//maps/RootCellar/scripts.pory"
	release
# 151 "data//maps/RootCellar/scripts.pory"
	end
# 152 "data//maps/RootCellar/scripts.pory"

# 153 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_RanWildMon::
# 154 "data//maps/RootCellar/scripts.pory"
	goto Common_EventScript_WildMonFled
# 155 "data//maps/RootCellar/scripts.pory"
	release
# 156 "data//maps/RootCellar/scripts.pory"
	end
# 157 "data//maps/RootCellar/scripts.pory"

# 158 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_Shelf1::
# 159 "data//maps/RootCellar/scripts.pory"
	lock
# 160 "data//maps/RootCellar/scripts.pory"
	goto_if_ge VAR_ROOT_CELLAR_SHELF_1, 2, RootCellar_EventScript_ShelfIsEmpty
# 161 "data//maps/RootCellar/scripts.pory"
	call_if_unset FLAG_DISCOVERED_ROOT_CELLAR, RootCellar_EventScript_FoundAShelf
# 162 "data//maps/RootCellar/scripts.pory"
	call_if_set FLAG_DISCOVERED_ROOT_CELLAR, RootCellar_EventScript_FoundBerryMastersShelf
# 163 "data//maps/RootCellar/scripts.pory"
	call RootCellar_EventScript_RandomiseRootCellarItem
# 164 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_ROOT_CELLAR_SHELF_1, 1, RootCellar_EventScript_Shelf1GiveItem2
# 165 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_ROOT_CELLAR_SHELF_1, 0, RootCellar_EventScript_Shelf1GiveItem1
# 166 "data//maps/RootCellar/scripts.pory"
	release
# 167 "data//maps/RootCellar/scripts.pory"
	end
# 168 "data//maps/RootCellar/scripts.pory"

# 169 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_Shelf1GiveItem2::
# 170 "data//maps/RootCellar/scripts.pory"
	giveitem VAR_TEMP_5
# 171 "data//maps/RootCellar/scripts.pory"
	closemessage
# 172 "data//maps/RootCellar/scripts.pory"
	setmetatile 2, 2, METATILE_Cave_RootCellar_Shelf_Empty, TRUE
# 173 "data//maps/RootCellar/scripts.pory"
	special DrawWholeMapView
# 174 "data//maps/RootCellar/scripts.pory"
	setvar VAR_ROOT_CELLAR_SHELF_1, 2
# 175 "data//maps/RootCellar/scripts.pory"
	release
# 176 "data//maps/RootCellar/scripts.pory"
	end
# 177 "data//maps/RootCellar/scripts.pory"

# 178 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_Shelf1GiveItem1::
# 179 "data//maps/RootCellar/scripts.pory"
	giveitem VAR_TEMP_5
# 180 "data//maps/RootCellar/scripts.pory"
	closemessage
# 181 "data//maps/RootCellar/scripts.pory"
	setmetatile 2, 2, METATILE_Cave_RootCellar_Shelf_B_Half, TRUE
# 182 "data//maps/RootCellar/scripts.pory"
	special DrawWholeMapView
# 183 "data//maps/RootCellar/scripts.pory"
	setvar VAR_ROOT_CELLAR_SHELF_1, 1
# 184 "data//maps/RootCellar/scripts.pory"
	release
# 185 "data//maps/RootCellar/scripts.pory"
	end
# 186 "data//maps/RootCellar/scripts.pory"

# 187 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_Shelf2::
# 188 "data//maps/RootCellar/scripts.pory"
	lock
# 189 "data//maps/RootCellar/scripts.pory"
	goto_if_ge VAR_ROOT_CELLAR_SHELF_2, 2, RootCellar_EventScript_ShelfIsEmpty
# 190 "data//maps/RootCellar/scripts.pory"
	call_if_unset FLAG_DISCOVERED_ROOT_CELLAR, RootCellar_EventScript_FoundAShelf
# 191 "data//maps/RootCellar/scripts.pory"
	call_if_set FLAG_DISCOVERED_ROOT_CELLAR, RootCellar_EventScript_FoundBerryMastersShelf
# 192 "data//maps/RootCellar/scripts.pory"
	call RootCellar_EventScript_RandomiseRootCellarItem
# 193 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_ROOT_CELLAR_SHELF_2, 1, RootCellar_EventScript_Shelf2GiveItem2
# 194 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_ROOT_CELLAR_SHELF_2, 0, RootCellar_EventScript_Shelf2GiveItem1
# 195 "data//maps/RootCellar/scripts.pory"
	release
# 196 "data//maps/RootCellar/scripts.pory"
	end
# 197 "data//maps/RootCellar/scripts.pory"

# 198 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_Shelf2GiveItem2::
# 199 "data//maps/RootCellar/scripts.pory"
	giveitem VAR_TEMP_5
# 200 "data//maps/RootCellar/scripts.pory"
	closemessage
# 201 "data//maps/RootCellar/scripts.pory"
	setmetatile 10, 2, METATILE_Cave_RootCellar_Shelf_Empty, TRUE
# 202 "data//maps/RootCellar/scripts.pory"
	special DrawWholeMapView
# 203 "data//maps/RootCellar/scripts.pory"
	setvar VAR_ROOT_CELLAR_SHELF_2, 2
# 204 "data//maps/RootCellar/scripts.pory"
	release
# 205 "data//maps/RootCellar/scripts.pory"
	end
# 206 "data//maps/RootCellar/scripts.pory"

# 207 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_Shelf2GiveItem1::
# 208 "data//maps/RootCellar/scripts.pory"
	giveitem VAR_TEMP_5
# 209 "data//maps/RootCellar/scripts.pory"
	closemessage
# 210 "data//maps/RootCellar/scripts.pory"
	setmetatile 10, 2, METATILE_Cave_RootCellar_Shelf_A_Half, TRUE
# 211 "data//maps/RootCellar/scripts.pory"
	special DrawWholeMapView
# 212 "data//maps/RootCellar/scripts.pory"
	setvar VAR_ROOT_CELLAR_SHELF_2, 1
# 213 "data//maps/RootCellar/scripts.pory"
	release
# 214 "data//maps/RootCellar/scripts.pory"
	end
# 215 "data//maps/RootCellar/scripts.pory"

# 216 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_Shelf3::
# 217 "data//maps/RootCellar/scripts.pory"
	lock
# 218 "data//maps/RootCellar/scripts.pory"
	goto_if_ge VAR_ROOT_CELLAR_SHELF_3, 2, RootCellar_EventScript_ShelfIsEmpty
# 219 "data//maps/RootCellar/scripts.pory"
	call_if_unset FLAG_DISCOVERED_ROOT_CELLAR, RootCellar_EventScript_FoundAShelf
# 220 "data//maps/RootCellar/scripts.pory"
	call_if_set FLAG_DISCOVERED_ROOT_CELLAR, RootCellar_EventScript_FoundBerryMastersShelf
# 221 "data//maps/RootCellar/scripts.pory"
	call RootCellar_EventScript_RandomiseRootCellarItem
# 222 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_ROOT_CELLAR_SHELF_3, 1, RootCellar_EventScript_Shelf3GiveItem2
# 223 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_ROOT_CELLAR_SHELF_3, 0, RootCellar_EventScript_Shelf3GiveItem1
# 224 "data//maps/RootCellar/scripts.pory"
	release
# 225 "data//maps/RootCellar/scripts.pory"
	end
# 226 "data//maps/RootCellar/scripts.pory"

# 227 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_Shelf3GiveItem2::
# 228 "data//maps/RootCellar/scripts.pory"
	giveitem VAR_TEMP_5
# 229 "data//maps/RootCellar/scripts.pory"
	closemessage
# 230 "data//maps/RootCellar/scripts.pory"
	setmetatile 2, 9, METATILE_Cave_RootCellar_Shelf_Empty, TRUE
# 231 "data//maps/RootCellar/scripts.pory"
	special DrawWholeMapView
# 232 "data//maps/RootCellar/scripts.pory"
	setvar VAR_ROOT_CELLAR_SHELF_3, 2
# 233 "data//maps/RootCellar/scripts.pory"
	release
# 234 "data//maps/RootCellar/scripts.pory"
	end
# 235 "data//maps/RootCellar/scripts.pory"

# 236 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_Shelf3GiveItem1::
# 237 "data//maps/RootCellar/scripts.pory"
	giveitem VAR_TEMP_5
# 238 "data//maps/RootCellar/scripts.pory"
	closemessage
# 239 "data//maps/RootCellar/scripts.pory"
	setmetatile 2, 9, METATILE_Cave_RootCellar_Shelf_A_Half, TRUE
# 240 "data//maps/RootCellar/scripts.pory"
	special DrawWholeMapView
# 241 "data//maps/RootCellar/scripts.pory"
	setvar VAR_ROOT_CELLAR_SHELF_3, 1
# 242 "data//maps/RootCellar/scripts.pory"
	release
# 243 "data//maps/RootCellar/scripts.pory"
	end
# 244 "data//maps/RootCellar/scripts.pory"

# 245 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_Shelf4::
# 246 "data//maps/RootCellar/scripts.pory"
	lock
# 247 "data//maps/RootCellar/scripts.pory"
	goto_if_ge VAR_ROOT_CELLAR_SHELF_4, 2, RootCellar_EventScript_ShelfIsEmpty
# 248 "data//maps/RootCellar/scripts.pory"
	call_if_unset FLAG_DISCOVERED_ROOT_CELLAR, RootCellar_EventScript_FoundAShelf
# 249 "data//maps/RootCellar/scripts.pory"
	call_if_set FLAG_DISCOVERED_ROOT_CELLAR, RootCellar_EventScript_FoundBerryMastersShelf
# 250 "data//maps/RootCellar/scripts.pory"
	call RootCellar_EventScript_RandomiseRootCellarItem
# 251 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_ROOT_CELLAR_SHELF_4, 1, RootCellar_EventScript_Shelf4GiveItem2
# 252 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_ROOT_CELLAR_SHELF_4, 0, RootCellar_EventScript_Shelf4GiveItem1
# 253 "data//maps/RootCellar/scripts.pory"
	release
# 254 "data//maps/RootCellar/scripts.pory"
	end
# 255 "data//maps/RootCellar/scripts.pory"

# 256 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_Shelf4GiveItem2::
# 257 "data//maps/RootCellar/scripts.pory"
	giveitem VAR_TEMP_5
# 258 "data//maps/RootCellar/scripts.pory"
	closemessage
# 259 "data//maps/RootCellar/scripts.pory"
	setmetatile 10, 12, METATILE_Cave_RootCellar_Shelf_Empty, TRUE
# 260 "data//maps/RootCellar/scripts.pory"
	special DrawWholeMapView
# 261 "data//maps/RootCellar/scripts.pory"
	setvar VAR_ROOT_CELLAR_SHELF_4, 2
# 262 "data//maps/RootCellar/scripts.pory"
	release
# 263 "data//maps/RootCellar/scripts.pory"
	end
# 264 "data//maps/RootCellar/scripts.pory"

# 265 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_Shelf4GiveItem1::
# 266 "data//maps/RootCellar/scripts.pory"
	giveitem VAR_TEMP_5
# 267 "data//maps/RootCellar/scripts.pory"
	closemessage
# 268 "data//maps/RootCellar/scripts.pory"
	setmetatile 10, 12, METATILE_Cave_RootCellar_Shelf_B_Half, TRUE
# 269 "data//maps/RootCellar/scripts.pory"
	special DrawWholeMapView
# 270 "data//maps/RootCellar/scripts.pory"
	setvar VAR_ROOT_CELLAR_SHELF_4, 1
# 271 "data//maps/RootCellar/scripts.pory"
	release
# 272 "data//maps/RootCellar/scripts.pory"
	end
# 273 "data//maps/RootCellar/scripts.pory"

# 274 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_FoundAShelf::
# 275 "data//maps/RootCellar/scripts.pory"
	msgbox RootCellar_Text_FoundAShelf, MSGBOX_YESNO
# 276 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RootCellar_EventScript_LeftShelfAlone
# 277 "data//maps/RootCellar/scripts.pory"
	return
# 278 "data//maps/RootCellar/scripts.pory"

# 279 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_FoundBerryMastersShelf::
# 280 "data//maps/RootCellar/scripts.pory"
	msgbox RootCellar_Text_FoundBerryMastersShelf, MSGBOX_YESNO
# 281 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RootCellar_EventScript_LeftShelfAlone
# 282 "data//maps/RootCellar/scripts.pory"
	return
# 283 "data//maps/RootCellar/scripts.pory"

# 284 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_ShelfIsEmpty::
# 285 "data//maps/RootCellar/scripts.pory"
	msgbox RootCellar_Text_ShelfIsEmpty, MSGBOX_DEFAULT
# 286 "data//maps/RootCellar/scripts.pory"
	closemessage
# 287 "data//maps/RootCellar/scripts.pory"
	release
# 288 "data//maps/RootCellar/scripts.pory"
	end
# 289 "data//maps/RootCellar/scripts.pory"

# 290 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_LeftShelfAlone::
# 291 "data//maps/RootCellar/scripts.pory"
	release
# 292 "data//maps/RootCellar/scripts.pory"
	end
# 293 "data//maps/RootCellar/scripts.pory"
	
# 294 "data//maps/RootCellar/scripts.pory"
RootCellar_Text_ShelfIsEmpty:
# 295 "data//maps/RootCellar/scripts.pory"
	.string "This shelf has been depleted!$"
# 296 "data//maps/RootCellar/scripts.pory"

# 297 "data//maps/RootCellar/scripts.pory"
RootCellar_Text_FoundAShelf:
# 298 "data//maps/RootCellar/scripts.pory"
	.string "Someone has been stashing their\n"
# 299 "data//maps/RootCellar/scripts.pory"
	.string "BERRY JUICE and other natural\l"
# 300 "data//maps/RootCellar/scripts.pory"
	.string "remedies here.\p"
# 301 "data//maps/RootCellar/scripts.pory"
	.string "Take some for yourself?$"
# 302 "data//maps/RootCellar/scripts.pory"

# 303 "data//maps/RootCellar/scripts.pory"
RootCellar_Text_FoundBerryMastersShelf:
# 304 "data//maps/RootCellar/scripts.pory"
	.string "This must be the BERRY MASTER's\n"
# 305 "data//maps/RootCellar/scripts.pory"
	.string "secret stash of BERRY JUICE and\l"
# 306 "data//maps/RootCellar/scripts.pory"
	.string "other natural remedies.\p"
# 307 "data//maps/RootCellar/scripts.pory"
	.string "Take some for yourself?$"

RootCellar_EventScript_RandomiseRootCellarItem::
# 313 "data//maps/RootCellar/scripts.pory"
	randompercentage 50
# 314 "data//maps/RootCellar/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RootCellar_EventScript_RandomiseRootCellarItem_2
# 318 "data//maps/RootCellar/scripts.pory"
	random 100
# 319 "data//maps/RootCellar/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq RootCellar_EventScript_RandomiseRootCellarItem_5
# 322 "data//maps/RootCellar/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_le RootCellar_EventScript_RandomiseRootCellarItem_6
# 325 "data//maps/RootCellar/scripts.pory"
	compare VAR_RESULT, 16
	goto_if_le RootCellar_EventScript_RandomiseRootCellarItem_7
# 328 "data//maps/RootCellar/scripts.pory"
	compare VAR_RESULT, 32
	goto_if_le RootCellar_EventScript_RandomiseRootCellarItem_8
# 331 "data//maps/RootCellar/scripts.pory"
	compare VAR_RESULT, 64
	goto_if_le RootCellar_EventScript_RandomiseRootCellarItem_9
# 371 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_BERRY_JUICE
RootCellar_EventScript_RandomiseRootCellarItem_1:
	return

RootCellar_EventScript_RandomiseRootCellarItem_2:
# 315 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_BERRY_JUICE
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_5:
# 320 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_REVIVAL_HERB
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_6:
# 323 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_BIG_ROOT
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_7:
# 326 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_LEFTOVERS
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_8:
# 329 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_ENERGY_ROOT
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_9:
# 332 "data//maps/RootCellar/scripts.pory"
	random 16
# 333 "data//maps/RootCellar/scripts.pory"
	switch VAR_RESULT
# 334 "data//maps/RootCellar/scripts.pory"
	case 0, RootCellar_EventScript_RandomiseRootCellarItem_17
# 336 "data//maps/RootCellar/scripts.pory"
	case 1, RootCellar_EventScript_RandomiseRootCellarItem_18
# 338 "data//maps/RootCellar/scripts.pory"
	case 2, RootCellar_EventScript_RandomiseRootCellarItem_19
# 340 "data//maps/RootCellar/scripts.pory"
	case 3, RootCellar_EventScript_RandomiseRootCellarItem_20
# 342 "data//maps/RootCellar/scripts.pory"
	case 4, RootCellar_EventScript_RandomiseRootCellarItem_21
# 344 "data//maps/RootCellar/scripts.pory"
	case 5, RootCellar_EventScript_RandomiseRootCellarItem_22
# 346 "data//maps/RootCellar/scripts.pory"
	case 6, RootCellar_EventScript_RandomiseRootCellarItem_23
# 348 "data//maps/RootCellar/scripts.pory"
	case 7, RootCellar_EventScript_RandomiseRootCellarItem_24
# 350 "data//maps/RootCellar/scripts.pory"
	case 8, RootCellar_EventScript_RandomiseRootCellarItem_25
# 352 "data//maps/RootCellar/scripts.pory"
	case 9, RootCellar_EventScript_RandomiseRootCellarItem_26
# 354 "data//maps/RootCellar/scripts.pory"
	case 10, RootCellar_EventScript_RandomiseRootCellarItem_27
# 356 "data//maps/RootCellar/scripts.pory"
	case 11, RootCellar_EventScript_RandomiseRootCellarItem_28
# 358 "data//maps/RootCellar/scripts.pory"
	case 12, RootCellar_EventScript_RandomiseRootCellarItem_29
# 360 "data//maps/RootCellar/scripts.pory"
	case 13, RootCellar_EventScript_RandomiseRootCellarItem_30
# 362 "data//maps/RootCellar/scripts.pory"
	case 14, RootCellar_EventScript_RandomiseRootCellarItem_31
# 364 "data//maps/RootCellar/scripts.pory"
	case 15, RootCellar_EventScript_RandomiseRootCellarItem_32
# 366 "data//maps/RootCellar/scripts.pory"
	case 16, RootCellar_EventScript_RandomiseRootCellarItem_33
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_17:
# 335 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_OCCA_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_18:
# 337 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_PASSHO_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_19:
# 339 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_WACAN_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_20:
# 341 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_RINDO_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_21:
# 343 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_YACHE_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_22:
# 345 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_CHOPLE_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_23:
# 347 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_KEBIA_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_24:
# 349 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_SHUCA_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_25:
# 351 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_COBA_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_26:
# 353 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_PAYAPA_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_27:
# 355 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_TANGA_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_28:
# 357 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_CHARTI_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_29:
# 359 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_KASIB_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_30:
# 361 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_HABAN_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_31:
# 363 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_COLBUR_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_32:
# 365 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_BABIRI_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_33:
# 367 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_CHILAN_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

