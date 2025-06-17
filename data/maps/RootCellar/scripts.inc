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
	setmetatile 2, 2, METATILE_Cave_RootCellar_Shelf_Empty, TRUE
# 171 "data//maps/RootCellar/scripts.pory"
	setvar VAR_ROOT_CELLAR_SHELF_1, 2
# 172 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_TEMP_5, SPECIES_APPLIN, RootCellar_EventScript_ApplinAttacks
# 173 "data//maps/RootCellar/scripts.pory"
	giveitem VAR_TEMP_5
# 174 "data//maps/RootCellar/scripts.pory"
	special DrawWholeMapView
# 175 "data//maps/RootCellar/scripts.pory"
	closemessage
# 176 "data//maps/RootCellar/scripts.pory"
	release
# 177 "data//maps/RootCellar/scripts.pory"
	end
# 178 "data//maps/RootCellar/scripts.pory"

# 179 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_Shelf1GiveItem1::
# 180 "data//maps/RootCellar/scripts.pory"
	setmetatile 2, 2, METATILE_Cave_RootCellar_Shelf_B_Half, TRUE
# 181 "data//maps/RootCellar/scripts.pory"
	setvar VAR_ROOT_CELLAR_SHELF_1, 1
# 182 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_TEMP_5, SPECIES_APPLIN, RootCellar_EventScript_ApplinAttacks
# 183 "data//maps/RootCellar/scripts.pory"
	giveitem VAR_TEMP_5
# 184 "data//maps/RootCellar/scripts.pory"
	special DrawWholeMapView
# 185 "data//maps/RootCellar/scripts.pory"
	closemessage
# 186 "data//maps/RootCellar/scripts.pory"
	release
# 187 "data//maps/RootCellar/scripts.pory"
	end
# 188 "data//maps/RootCellar/scripts.pory"

# 189 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_Shelf2::
# 190 "data//maps/RootCellar/scripts.pory"
	lock
# 191 "data//maps/RootCellar/scripts.pory"
	goto_if_ge VAR_ROOT_CELLAR_SHELF_2, 2, RootCellar_EventScript_ShelfIsEmpty
# 192 "data//maps/RootCellar/scripts.pory"
	call_if_unset FLAG_DISCOVERED_ROOT_CELLAR, RootCellar_EventScript_FoundAShelf
# 193 "data//maps/RootCellar/scripts.pory"
	call_if_set FLAG_DISCOVERED_ROOT_CELLAR, RootCellar_EventScript_FoundBerryMastersShelf
# 194 "data//maps/RootCellar/scripts.pory"
	call RootCellar_EventScript_RandomiseRootCellarItem
# 195 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_ROOT_CELLAR_SHELF_2, 1, RootCellar_EventScript_Shelf2GiveItem2
# 196 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_ROOT_CELLAR_SHELF_2, 0, RootCellar_EventScript_Shelf2GiveItem1
# 197 "data//maps/RootCellar/scripts.pory"
	release
# 198 "data//maps/RootCellar/scripts.pory"
	end
# 199 "data//maps/RootCellar/scripts.pory"

# 200 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_Shelf2GiveItem2::
# 201 "data//maps/RootCellar/scripts.pory"
	setmetatile 10, 2, METATILE_Cave_RootCellar_Shelf_Empty, TRUE
# 202 "data//maps/RootCellar/scripts.pory"
	setvar VAR_ROOT_CELLAR_SHELF_2, 2
# 203 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_TEMP_5, SPECIES_APPLIN, RootCellar_EventScript_ApplinAttacks
# 204 "data//maps/RootCellar/scripts.pory"
	giveitem VAR_TEMP_5
# 205 "data//maps/RootCellar/scripts.pory"
	special DrawWholeMapView
# 206 "data//maps/RootCellar/scripts.pory"
	closemessage
# 207 "data//maps/RootCellar/scripts.pory"
	release
# 208 "data//maps/RootCellar/scripts.pory"
	end
# 209 "data//maps/RootCellar/scripts.pory"

# 210 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_Shelf2GiveItem1::
# 211 "data//maps/RootCellar/scripts.pory"
	setmetatile 10, 2, METATILE_Cave_RootCellar_Shelf_A_Half, TRUE
# 212 "data//maps/RootCellar/scripts.pory"
	setvar VAR_ROOT_CELLAR_SHELF_2, 1
# 213 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_TEMP_5, SPECIES_APPLIN, RootCellar_EventScript_ApplinAttacks
# 214 "data//maps/RootCellar/scripts.pory"
	giveitem VAR_TEMP_5
# 215 "data//maps/RootCellar/scripts.pory"
	special DrawWholeMapView
# 216 "data//maps/RootCellar/scripts.pory"
	closemessage
# 217 "data//maps/RootCellar/scripts.pory"
	release
# 218 "data//maps/RootCellar/scripts.pory"
	end
# 219 "data//maps/RootCellar/scripts.pory"

# 220 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_Shelf3::
# 221 "data//maps/RootCellar/scripts.pory"
	lock
# 222 "data//maps/RootCellar/scripts.pory"
	goto_if_ge VAR_ROOT_CELLAR_SHELF_3, 2, RootCellar_EventScript_ShelfIsEmpty
# 223 "data//maps/RootCellar/scripts.pory"
	call_if_unset FLAG_DISCOVERED_ROOT_CELLAR, RootCellar_EventScript_FoundAShelf
# 224 "data//maps/RootCellar/scripts.pory"
	call_if_set FLAG_DISCOVERED_ROOT_CELLAR, RootCellar_EventScript_FoundBerryMastersShelf
# 225 "data//maps/RootCellar/scripts.pory"
	call RootCellar_EventScript_RandomiseRootCellarItem
# 226 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_ROOT_CELLAR_SHELF_3, 1, RootCellar_EventScript_Shelf3GiveItem2
# 227 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_ROOT_CELLAR_SHELF_3, 0, RootCellar_EventScript_Shelf3GiveItem1
# 228 "data//maps/RootCellar/scripts.pory"
	release
# 229 "data//maps/RootCellar/scripts.pory"
	end
# 230 "data//maps/RootCellar/scripts.pory"

# 231 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_Shelf3GiveItem2::
# 232 "data//maps/RootCellar/scripts.pory"
	setmetatile 2, 9, METATILE_Cave_RootCellar_Shelf_Empty, TRUE
# 233 "data//maps/RootCellar/scripts.pory"
	setvar VAR_ROOT_CELLAR_SHELF_3, 2
# 234 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_TEMP_5, SPECIES_APPLIN, RootCellar_EventScript_ApplinAttacks
# 235 "data//maps/RootCellar/scripts.pory"
	giveitem VAR_TEMP_5
# 236 "data//maps/RootCellar/scripts.pory"
	special DrawWholeMapView
# 237 "data//maps/RootCellar/scripts.pory"
	closemessage
# 238 "data//maps/RootCellar/scripts.pory"
	release
# 239 "data//maps/RootCellar/scripts.pory"
	end
# 240 "data//maps/RootCellar/scripts.pory"

# 241 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_Shelf3GiveItem1::
# 242 "data//maps/RootCellar/scripts.pory"
	setmetatile 2, 9, METATILE_Cave_RootCellar_Shelf_A_Half, TRUE
# 243 "data//maps/RootCellar/scripts.pory"
	setvar VAR_ROOT_CELLAR_SHELF_3, 1
# 244 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_TEMP_5, SPECIES_APPLIN, RootCellar_EventScript_ApplinAttacks
# 245 "data//maps/RootCellar/scripts.pory"
	giveitem VAR_TEMP_5
# 246 "data//maps/RootCellar/scripts.pory"
	special DrawWholeMapView
# 247 "data//maps/RootCellar/scripts.pory"
	closemessage
# 248 "data//maps/RootCellar/scripts.pory"
	release
# 249 "data//maps/RootCellar/scripts.pory"
	end
# 250 "data//maps/RootCellar/scripts.pory"

# 251 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_Shelf4::
# 252 "data//maps/RootCellar/scripts.pory"
	lock
# 253 "data//maps/RootCellar/scripts.pory"
	goto_if_ge VAR_ROOT_CELLAR_SHELF_4, 2, RootCellar_EventScript_ShelfIsEmpty
# 254 "data//maps/RootCellar/scripts.pory"
	call_if_unset FLAG_DISCOVERED_ROOT_CELLAR, RootCellar_EventScript_FoundAShelf
# 255 "data//maps/RootCellar/scripts.pory"
	call_if_set FLAG_DISCOVERED_ROOT_CELLAR, RootCellar_EventScript_FoundBerryMastersShelf
# 256 "data//maps/RootCellar/scripts.pory"
	call RootCellar_EventScript_RandomiseRootCellarItem
# 257 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_ROOT_CELLAR_SHELF_4, 1, RootCellar_EventScript_Shelf4GiveItem2
# 258 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_ROOT_CELLAR_SHELF_4, 0, RootCellar_EventScript_Shelf4GiveItem1
# 259 "data//maps/RootCellar/scripts.pory"
	release
# 260 "data//maps/RootCellar/scripts.pory"
	end
# 261 "data//maps/RootCellar/scripts.pory"

# 262 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_Shelf4GiveItem2::
# 263 "data//maps/RootCellar/scripts.pory"
	setmetatile 10, 12, METATILE_Cave_RootCellar_Shelf_Empty, TRUE
# 264 "data//maps/RootCellar/scripts.pory"
	setvar VAR_ROOT_CELLAR_SHELF_4, 2
# 265 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_TEMP_5, SPECIES_APPLIN, RootCellar_EventScript_ApplinAttacks
# 266 "data//maps/RootCellar/scripts.pory"
	giveitem VAR_TEMP_5
# 267 "data//maps/RootCellar/scripts.pory"
	special DrawWholeMapView
# 268 "data//maps/RootCellar/scripts.pory"
	closemessage
# 269 "data//maps/RootCellar/scripts.pory"
	release
# 270 "data//maps/RootCellar/scripts.pory"
	end
# 271 "data//maps/RootCellar/scripts.pory"

# 272 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_Shelf4GiveItem1::
# 273 "data//maps/RootCellar/scripts.pory"
	setmetatile 10, 12, METATILE_Cave_RootCellar_Shelf_B_Half, TRUE
# 274 "data//maps/RootCellar/scripts.pory"
	setvar VAR_ROOT_CELLAR_SHELF_4, 1
# 275 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_TEMP_5, SPECIES_APPLIN, RootCellar_EventScript_ApplinAttacks
# 276 "data//maps/RootCellar/scripts.pory"
	giveitem VAR_TEMP_5
# 277 "data//maps/RootCellar/scripts.pory"
	special DrawWholeMapView
# 278 "data//maps/RootCellar/scripts.pory"
	closemessage
# 279 "data//maps/RootCellar/scripts.pory"
	release
# 280 "data//maps/RootCellar/scripts.pory"
	end
# 281 "data//maps/RootCellar/scripts.pory"

# 282 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_FoundAShelf::
# 283 "data//maps/RootCellar/scripts.pory"
	msgbox RootCellar_Text_FoundAShelf, MSGBOX_YESNO
# 284 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RootCellar_EventScript_LeftShelfAlone
# 285 "data//maps/RootCellar/scripts.pory"
	return
# 286 "data//maps/RootCellar/scripts.pory"

# 287 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_FoundBerryMastersShelf::
# 288 "data//maps/RootCellar/scripts.pory"
	msgbox RootCellar_Text_FoundBerryMastersShelf, MSGBOX_YESNO
# 289 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RootCellar_EventScript_LeftShelfAlone
# 290 "data//maps/RootCellar/scripts.pory"
	return
# 291 "data//maps/RootCellar/scripts.pory"

# 292 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_ShelfIsEmpty::
# 293 "data//maps/RootCellar/scripts.pory"
	msgbox RootCellar_Text_ShelfIsEmpty, MSGBOX_DEFAULT
# 294 "data//maps/RootCellar/scripts.pory"
	closemessage
# 295 "data//maps/RootCellar/scripts.pory"
	release
# 296 "data//maps/RootCellar/scripts.pory"
	end
# 297 "data//maps/RootCellar/scripts.pory"

# 298 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_LeftShelfAlone::
# 299 "data//maps/RootCellar/scripts.pory"
	release
# 300 "data//maps/RootCellar/scripts.pory"
	end
# 301 "data//maps/RootCellar/scripts.pory"

# 302 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_ApplinAttacks::
# 303 "data//maps/RootCellar/scripts.pory"
	message RootCellar_Text_APokemonAppeared
# 304 "data//maps/RootCellar/scripts.pory"
	waitmessage
# 305 "data//maps/RootCellar/scripts.pory"
	waitbuttonpress
# 306 "data//maps/RootCellar/scripts.pory"
	waitse
# 307 "data//maps/RootCellar/scripts.pory"
	playmoncry SPECIES_SHUCKLE, CRY_MODE_ENCOUNTER
# 308 "data//maps/RootCellar/scripts.pory"
	delay 10
# 309 "data//maps/RootCellar/scripts.pory"
	waitmoncry
# 310 "data//maps/RootCellar/scripts.pory"
	setwildbattle SPECIES_APPLIN, 50
# 311 "data//maps/RootCellar/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 312 "data//maps/RootCellar/scripts.pory"
	dowildbattle
# 313 "data//maps/RootCellar/scripts.pory"
	release
# 314 "data//maps/RootCellar/scripts.pory"
	end
# 315 "data//maps/RootCellar/scripts.pory"
	
# 316 "data//maps/RootCellar/scripts.pory"
RootCellar_Text_ShelfIsEmpty:
# 317 "data//maps/RootCellar/scripts.pory"
	.string "This shelf has been depleted!$"
# 318 "data//maps/RootCellar/scripts.pory"

# 319 "data//maps/RootCellar/scripts.pory"
RootCellar_Text_FoundAShelf:
# 320 "data//maps/RootCellar/scripts.pory"
	.string "Someone has been stashing their\n"
# 321 "data//maps/RootCellar/scripts.pory"
	.string "BERRY JUICE and other natural\l"
# 322 "data//maps/RootCellar/scripts.pory"
	.string "remedies here.\p"
# 323 "data//maps/RootCellar/scripts.pory"
	.string "Take some for yourself?$"
# 324 "data//maps/RootCellar/scripts.pory"

# 325 "data//maps/RootCellar/scripts.pory"
RootCellar_Text_FoundBerryMastersShelf:
# 326 "data//maps/RootCellar/scripts.pory"
	.string "This must be the BERRY MASTER's\n"
# 327 "data//maps/RootCellar/scripts.pory"
	.string "secret stash of BERRY JUICE and\l"
# 328 "data//maps/RootCellar/scripts.pory"
	.string "other natural remedies.\p"
# 329 "data//maps/RootCellar/scripts.pory"
	.string "Take some for yourself?$"
# 330 "data//maps/RootCellar/scripts.pory"

# 331 "data//maps/RootCellar/scripts.pory"
RootCellar_Text_APokemonAppeared:
# 332 "data//maps/RootCellar/scripts.pory"
	.string "A Pokémon appeared!$"

RootCellar_EventScript_RandomiseRootCellarItem::
# 338 "data//maps/RootCellar/scripts.pory"
	randompercentage 50
# 339 "data//maps/RootCellar/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RootCellar_EventScript_RandomiseRootCellarItem_2
# 343 "data//maps/RootCellar/scripts.pory"
	random 100
# 344 "data//maps/RootCellar/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq RootCellar_EventScript_RandomiseRootCellarItem_5
# 347 "data//maps/RootCellar/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_le RootCellar_EventScript_RandomiseRootCellarItem_6
# 350 "data//maps/RootCellar/scripts.pory"
	compare VAR_RESULT, 16
	goto_if_le RootCellar_EventScript_RandomiseRootCellarItem_7
# 359 "data//maps/RootCellar/scripts.pory"
	compare VAR_RESULT, 32
	goto_if_le RootCellar_EventScript_RandomiseRootCellarItem_8
# 362 "data//maps/RootCellar/scripts.pory"
	compare VAR_RESULT, 64
	goto_if_le RootCellar_EventScript_RandomiseRootCellarItem_9
# 402 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_BERRY_JUICE
RootCellar_EventScript_RandomiseRootCellarItem_1:
	return

RootCellar_EventScript_RandomiseRootCellarItem_2:
# 340 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_BERRY_JUICE
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_5:
# 345 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_REVIVAL_HERB
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_6:
# 348 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_BIG_ROOT
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_7:
# 351 "data//maps/RootCellar/scripts.pory"
	randompercentage 50
# 352 "data//maps/RootCellar/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RootCellar_EventScript_RandomiseRootCellarItem_16
# 356 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_LEFTOVERS
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_8:
# 360 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_ENERGY_ROOT
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_9:
# 363 "data//maps/RootCellar/scripts.pory"
	random 16
# 364 "data//maps/RootCellar/scripts.pory"
	switch VAR_RESULT
# 365 "data//maps/RootCellar/scripts.pory"
	case 0, RootCellar_EventScript_RandomiseRootCellarItem_20
# 367 "data//maps/RootCellar/scripts.pory"
	case 1, RootCellar_EventScript_RandomiseRootCellarItem_21
# 369 "data//maps/RootCellar/scripts.pory"
	case 2, RootCellar_EventScript_RandomiseRootCellarItem_22
# 371 "data//maps/RootCellar/scripts.pory"
	case 3, RootCellar_EventScript_RandomiseRootCellarItem_23
# 373 "data//maps/RootCellar/scripts.pory"
	case 4, RootCellar_EventScript_RandomiseRootCellarItem_24
# 375 "data//maps/RootCellar/scripts.pory"
	case 5, RootCellar_EventScript_RandomiseRootCellarItem_25
# 377 "data//maps/RootCellar/scripts.pory"
	case 6, RootCellar_EventScript_RandomiseRootCellarItem_26
# 379 "data//maps/RootCellar/scripts.pory"
	case 7, RootCellar_EventScript_RandomiseRootCellarItem_27
# 381 "data//maps/RootCellar/scripts.pory"
	case 8, RootCellar_EventScript_RandomiseRootCellarItem_28
# 383 "data//maps/RootCellar/scripts.pory"
	case 9, RootCellar_EventScript_RandomiseRootCellarItem_29
# 385 "data//maps/RootCellar/scripts.pory"
	case 10, RootCellar_EventScript_RandomiseRootCellarItem_30
# 387 "data//maps/RootCellar/scripts.pory"
	case 11, RootCellar_EventScript_RandomiseRootCellarItem_31
# 389 "data//maps/RootCellar/scripts.pory"
	case 12, RootCellar_EventScript_RandomiseRootCellarItem_32
# 391 "data//maps/RootCellar/scripts.pory"
	case 13, RootCellar_EventScript_RandomiseRootCellarItem_33
# 393 "data//maps/RootCellar/scripts.pory"
	case 14, RootCellar_EventScript_RandomiseRootCellarItem_34
# 395 "data//maps/RootCellar/scripts.pory"
	case 15, RootCellar_EventScript_RandomiseRootCellarItem_35
# 397 "data//maps/RootCellar/scripts.pory"
	case 16, RootCellar_EventScript_RandomiseRootCellarItem_36
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_16:
# 353 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, SPECIES_APPLIN
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_20:
# 366 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_OCCA_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_21:
# 368 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_PASSHO_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_22:
# 370 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_WACAN_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_23:
# 372 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_RINDO_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_24:
# 374 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_YACHE_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_25:
# 376 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_CHOPLE_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_26:
# 378 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_KEBIA_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_27:
# 380 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_SHUCA_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_28:
# 382 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_COBA_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_29:
# 384 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_PAYAPA_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_30:
# 386 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_TANGA_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_31:
# 388 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_CHARTI_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_32:
# 390 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_KASIB_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_33:
# 392 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_HABAN_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_34:
# 394 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_COLBUR_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_35:
# 396 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_BABIRI_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_36:
# 398 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_CHILAN_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

