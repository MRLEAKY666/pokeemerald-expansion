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
	waitse
# 174 "data//maps/RootCellar/scripts.pory"
	giveitem VAR_TEMP_5
# 175 "data//maps/RootCellar/scripts.pory"
	special DrawWholeMapView
# 176 "data//maps/RootCellar/scripts.pory"
	closemessage
# 177 "data//maps/RootCellar/scripts.pory"
	release
# 178 "data//maps/RootCellar/scripts.pory"
	end
# 179 "data//maps/RootCellar/scripts.pory"

# 180 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_Shelf1GiveItem1::
# 181 "data//maps/RootCellar/scripts.pory"
	setmetatile 2, 2, METATILE_Cave_RootCellar_Shelf_B_Half, TRUE
# 182 "data//maps/RootCellar/scripts.pory"
	setvar VAR_ROOT_CELLAR_SHELF_1, 1
# 183 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_TEMP_5, SPECIES_APPLIN, RootCellar_EventScript_ApplinAttacks
# 184 "data//maps/RootCellar/scripts.pory"
	waitse
# 185 "data//maps/RootCellar/scripts.pory"
	giveitem VAR_TEMP_5
# 186 "data//maps/RootCellar/scripts.pory"
	special DrawWholeMapView
# 187 "data//maps/RootCellar/scripts.pory"
	closemessage
# 188 "data//maps/RootCellar/scripts.pory"
	release
# 189 "data//maps/RootCellar/scripts.pory"
	end
# 190 "data//maps/RootCellar/scripts.pory"

# 191 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_Shelf2::
# 192 "data//maps/RootCellar/scripts.pory"
	lock
# 193 "data//maps/RootCellar/scripts.pory"
	goto_if_ge VAR_ROOT_CELLAR_SHELF_2, 2, RootCellar_EventScript_ShelfIsEmpty
# 194 "data//maps/RootCellar/scripts.pory"
	call_if_unset FLAG_DISCOVERED_ROOT_CELLAR, RootCellar_EventScript_FoundAShelf
# 195 "data//maps/RootCellar/scripts.pory"
	call_if_set FLAG_DISCOVERED_ROOT_CELLAR, RootCellar_EventScript_FoundBerryMastersShelf
# 196 "data//maps/RootCellar/scripts.pory"
	call RootCellar_EventScript_RandomiseRootCellarItem
# 197 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_ROOT_CELLAR_SHELF_2, 1, RootCellar_EventScript_Shelf2GiveItem2
# 198 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_ROOT_CELLAR_SHELF_2, 0, RootCellar_EventScript_Shelf2GiveItem1
# 199 "data//maps/RootCellar/scripts.pory"
	release
# 200 "data//maps/RootCellar/scripts.pory"
	end
# 201 "data//maps/RootCellar/scripts.pory"

# 202 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_Shelf2GiveItem2::
# 203 "data//maps/RootCellar/scripts.pory"
	setmetatile 10, 2, METATILE_Cave_RootCellar_Shelf_Empty, TRUE
# 204 "data//maps/RootCellar/scripts.pory"
	setvar VAR_ROOT_CELLAR_SHELF_2, 2
# 205 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_TEMP_5, SPECIES_APPLIN, RootCellar_EventScript_ApplinAttacks
# 206 "data//maps/RootCellar/scripts.pory"
	waitse
# 207 "data//maps/RootCellar/scripts.pory"
	giveitem VAR_TEMP_5
# 208 "data//maps/RootCellar/scripts.pory"
	special DrawWholeMapView
# 209 "data//maps/RootCellar/scripts.pory"
	closemessage
# 210 "data//maps/RootCellar/scripts.pory"
	release
# 211 "data//maps/RootCellar/scripts.pory"
	end
# 212 "data//maps/RootCellar/scripts.pory"

# 213 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_Shelf2GiveItem1::
# 214 "data//maps/RootCellar/scripts.pory"
	setmetatile 10, 2, METATILE_Cave_RootCellar_Shelf_A_Half, TRUE
# 215 "data//maps/RootCellar/scripts.pory"
	setvar VAR_ROOT_CELLAR_SHELF_2, 1
# 216 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_TEMP_5, SPECIES_APPLIN, RootCellar_EventScript_ApplinAttacks
# 217 "data//maps/RootCellar/scripts.pory"
	waitse
# 218 "data//maps/RootCellar/scripts.pory"
	giveitem VAR_TEMP_5
# 219 "data//maps/RootCellar/scripts.pory"
	special DrawWholeMapView
# 220 "data//maps/RootCellar/scripts.pory"
	closemessage
# 221 "data//maps/RootCellar/scripts.pory"
	release
# 222 "data//maps/RootCellar/scripts.pory"
	end
# 223 "data//maps/RootCellar/scripts.pory"

# 224 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_Shelf3::
# 225 "data//maps/RootCellar/scripts.pory"
	lock
# 226 "data//maps/RootCellar/scripts.pory"
	goto_if_ge VAR_ROOT_CELLAR_SHELF_3, 2, RootCellar_EventScript_ShelfIsEmpty
# 227 "data//maps/RootCellar/scripts.pory"
	call_if_unset FLAG_DISCOVERED_ROOT_CELLAR, RootCellar_EventScript_FoundAShelf
# 228 "data//maps/RootCellar/scripts.pory"
	call_if_set FLAG_DISCOVERED_ROOT_CELLAR, RootCellar_EventScript_FoundBerryMastersShelf
# 229 "data//maps/RootCellar/scripts.pory"
	call RootCellar_EventScript_RandomiseRootCellarItem
# 230 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_ROOT_CELLAR_SHELF_3, 1, RootCellar_EventScript_Shelf3GiveItem2
# 231 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_ROOT_CELLAR_SHELF_3, 0, RootCellar_EventScript_Shelf3GiveItem1
# 232 "data//maps/RootCellar/scripts.pory"
	release
# 233 "data//maps/RootCellar/scripts.pory"
	end
# 234 "data//maps/RootCellar/scripts.pory"

# 235 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_Shelf3GiveItem2::
# 236 "data//maps/RootCellar/scripts.pory"
	setmetatile 2, 9, METATILE_Cave_RootCellar_Shelf_Empty, TRUE
# 237 "data//maps/RootCellar/scripts.pory"
	setvar VAR_ROOT_CELLAR_SHELF_3, 2
# 238 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_TEMP_5, SPECIES_APPLIN, RootCellar_EventScript_ApplinAttacks
# 239 "data//maps/RootCellar/scripts.pory"
	giveitem VAR_TEMP_5
# 240 "data//maps/RootCellar/scripts.pory"
	special DrawWholeMapView
# 241 "data//maps/RootCellar/scripts.pory"
	closemessage
# 242 "data//maps/RootCellar/scripts.pory"
	release
# 243 "data//maps/RootCellar/scripts.pory"
	end
# 244 "data//maps/RootCellar/scripts.pory"

# 245 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_Shelf3GiveItem1::
# 246 "data//maps/RootCellar/scripts.pory"
	setmetatile 2, 9, METATILE_Cave_RootCellar_Shelf_A_Half, TRUE
# 247 "data//maps/RootCellar/scripts.pory"
	setvar VAR_ROOT_CELLAR_SHELF_3, 1
# 248 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_TEMP_5, SPECIES_APPLIN, RootCellar_EventScript_ApplinAttacks
# 249 "data//maps/RootCellar/scripts.pory"
	giveitem VAR_TEMP_5
# 250 "data//maps/RootCellar/scripts.pory"
	special DrawWholeMapView
# 251 "data//maps/RootCellar/scripts.pory"
	closemessage
# 252 "data//maps/RootCellar/scripts.pory"
	release
# 253 "data//maps/RootCellar/scripts.pory"
	end
# 254 "data//maps/RootCellar/scripts.pory"

# 255 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_Shelf4::
# 256 "data//maps/RootCellar/scripts.pory"
	lock
# 257 "data//maps/RootCellar/scripts.pory"
	goto_if_ge VAR_ROOT_CELLAR_SHELF_4, 2, RootCellar_EventScript_ShelfIsEmpty
# 258 "data//maps/RootCellar/scripts.pory"
	call_if_unset FLAG_DISCOVERED_ROOT_CELLAR, RootCellar_EventScript_FoundAShelf
# 259 "data//maps/RootCellar/scripts.pory"
	call_if_set FLAG_DISCOVERED_ROOT_CELLAR, RootCellar_EventScript_FoundBerryMastersShelf
# 260 "data//maps/RootCellar/scripts.pory"
	call RootCellar_EventScript_RandomiseRootCellarItem
# 261 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_ROOT_CELLAR_SHELF_4, 1, RootCellar_EventScript_Shelf4GiveItem2
# 262 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_ROOT_CELLAR_SHELF_4, 0, RootCellar_EventScript_Shelf4GiveItem1
# 263 "data//maps/RootCellar/scripts.pory"
	release
# 264 "data//maps/RootCellar/scripts.pory"
	end
# 265 "data//maps/RootCellar/scripts.pory"

# 266 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_Shelf4GiveItem2::
# 267 "data//maps/RootCellar/scripts.pory"
	setmetatile 10, 12, METATILE_Cave_RootCellar_Shelf_Empty, TRUE
# 268 "data//maps/RootCellar/scripts.pory"
	setvar VAR_ROOT_CELLAR_SHELF_4, 2
# 269 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_TEMP_5, SPECIES_APPLIN, RootCellar_EventScript_ApplinAttacks
# 270 "data//maps/RootCellar/scripts.pory"
	giveitem VAR_TEMP_5
# 271 "data//maps/RootCellar/scripts.pory"
	special DrawWholeMapView
# 272 "data//maps/RootCellar/scripts.pory"
	closemessage
# 273 "data//maps/RootCellar/scripts.pory"
	release
# 274 "data//maps/RootCellar/scripts.pory"
	end
# 275 "data//maps/RootCellar/scripts.pory"

# 276 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_Shelf4GiveItem1::
# 277 "data//maps/RootCellar/scripts.pory"
	setmetatile 10, 12, METATILE_Cave_RootCellar_Shelf_B_Half, TRUE
# 278 "data//maps/RootCellar/scripts.pory"
	setvar VAR_ROOT_CELLAR_SHELF_4, 1
# 279 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_TEMP_5, SPECIES_APPLIN, RootCellar_EventScript_ApplinAttacks
# 280 "data//maps/RootCellar/scripts.pory"
	giveitem VAR_TEMP_5
# 281 "data//maps/RootCellar/scripts.pory"
	special DrawWholeMapView
# 282 "data//maps/RootCellar/scripts.pory"
	closemessage
# 283 "data//maps/RootCellar/scripts.pory"
	release
# 284 "data//maps/RootCellar/scripts.pory"
	end
# 285 "data//maps/RootCellar/scripts.pory"

# 286 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_FoundAShelf::
# 287 "data//maps/RootCellar/scripts.pory"
	msgbox RootCellar_Text_FoundAShelf, MSGBOX_YESNO
# 288 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RootCellar_EventScript_LeftShelfAlone
# 289 "data//maps/RootCellar/scripts.pory"
	return
# 290 "data//maps/RootCellar/scripts.pory"

# 291 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_FoundBerryMastersShelf::
# 292 "data//maps/RootCellar/scripts.pory"
	msgbox RootCellar_Text_FoundBerryMastersShelf, MSGBOX_YESNO
# 293 "data//maps/RootCellar/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RootCellar_EventScript_LeftShelfAlone
# 294 "data//maps/RootCellar/scripts.pory"
	return
# 295 "data//maps/RootCellar/scripts.pory"

# 296 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_ShelfIsEmpty::
# 297 "data//maps/RootCellar/scripts.pory"
	msgbox RootCellar_Text_ShelfIsEmpty, MSGBOX_DEFAULT
# 298 "data//maps/RootCellar/scripts.pory"
	closemessage
# 299 "data//maps/RootCellar/scripts.pory"
	release
# 300 "data//maps/RootCellar/scripts.pory"
	end
# 301 "data//maps/RootCellar/scripts.pory"

# 302 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_LeftShelfAlone::
# 303 "data//maps/RootCellar/scripts.pory"
	release
# 304 "data//maps/RootCellar/scripts.pory"
	end
# 305 "data//maps/RootCellar/scripts.pory"

# 306 "data//maps/RootCellar/scripts.pory"
RootCellar_EventScript_ApplinAttacks::
# 307 "data//maps/RootCellar/scripts.pory"
	message RootCellar_Text_APokemonAppeared
# 308 "data//maps/RootCellar/scripts.pory"
	waitmessage
# 309 "data//maps/RootCellar/scripts.pory"
	waitbuttonpress
# 310 "data//maps/RootCellar/scripts.pory"
	waitse
# 311 "data//maps/RootCellar/scripts.pory"
	playmoncry SPECIES_SHUCKLE, CRY_MODE_ENCOUNTER
# 312 "data//maps/RootCellar/scripts.pory"
	delay 10
# 313 "data//maps/RootCellar/scripts.pory"
	waitmoncry
# 314 "data//maps/RootCellar/scripts.pory"
	setwildbattle SPECIES_APPLIN, 50
# 315 "data//maps/RootCellar/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 316 "data//maps/RootCellar/scripts.pory"
	dowildbattle
# 317 "data//maps/RootCellar/scripts.pory"
	release
# 318 "data//maps/RootCellar/scripts.pory"
	end
# 319 "data//maps/RootCellar/scripts.pory"
	
# 320 "data//maps/RootCellar/scripts.pory"
RootCellar_Text_ShelfIsEmpty:
# 321 "data//maps/RootCellar/scripts.pory"
	.string "This shelf has been depleted!$"
# 322 "data//maps/RootCellar/scripts.pory"

# 323 "data//maps/RootCellar/scripts.pory"
RootCellar_Text_FoundAShelf:
# 324 "data//maps/RootCellar/scripts.pory"
	.string "Someone has been stashing their\n"
# 325 "data//maps/RootCellar/scripts.pory"
	.string "BERRY JUICE and other natural\l"
# 326 "data//maps/RootCellar/scripts.pory"
	.string "remedies here.\p"
# 327 "data//maps/RootCellar/scripts.pory"
	.string "Take some for yourself?$"
# 328 "data//maps/RootCellar/scripts.pory"

# 329 "data//maps/RootCellar/scripts.pory"
RootCellar_Text_FoundBerryMastersShelf:
# 330 "data//maps/RootCellar/scripts.pory"
	.string "This must be the BERRY MASTER's\n"
# 331 "data//maps/RootCellar/scripts.pory"
	.string "secret stash of BERRY JUICE and\l"
# 332 "data//maps/RootCellar/scripts.pory"
	.string "other natural remedies.\p"
# 333 "data//maps/RootCellar/scripts.pory"
	.string "Take some for yourself?$"
# 334 "data//maps/RootCellar/scripts.pory"

# 335 "data//maps/RootCellar/scripts.pory"
RootCellar_Text_APokemonAppeared:
# 336 "data//maps/RootCellar/scripts.pory"
	.string "A Pokémon appeared!$"

RootCellar_EventScript_RandomiseRootCellarItem::
# 342 "data//maps/RootCellar/scripts.pory"
	randompercentage 50
# 343 "data//maps/RootCellar/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RootCellar_EventScript_RandomiseRootCellarItem_2
# 347 "data//maps/RootCellar/scripts.pory"
	random 100
# 348 "data//maps/RootCellar/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq RootCellar_EventScript_RandomiseRootCellarItem_5
# 351 "data//maps/RootCellar/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_le RootCellar_EventScript_RandomiseRootCellarItem_6
# 354 "data//maps/RootCellar/scripts.pory"
	compare VAR_RESULT, 16
	goto_if_le RootCellar_EventScript_RandomiseRootCellarItem_7
# 373 "data//maps/RootCellar/scripts.pory"
	compare VAR_RESULT, 32
	goto_if_le RootCellar_EventScript_RandomiseRootCellarItem_8
# 376 "data//maps/RootCellar/scripts.pory"
	compare VAR_RESULT, 64
	goto_if_le RootCellar_EventScript_RandomiseRootCellarItem_9
# 416 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_BERRY_JUICE
RootCellar_EventScript_RandomiseRootCellarItem_1:
	return

RootCellar_EventScript_RandomiseRootCellarItem_2:
# 344 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_BERRY_JUICE
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_5:
# 349 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_REVIVAL_HERB
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_6:
# 352 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_BIG_ROOT
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_7:
# 355 "data//maps/RootCellar/scripts.pory"
	randompercentage 50
# 356 "data//maps/RootCellar/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RootCellar_EventScript_RandomiseRootCellarItem_16
# 360 "data//maps/RootCellar/scripts.pory"
	random 4
# 361 "data//maps/RootCellar/scripts.pory"
	switch VAR_RESULT
# 362 "data//maps/RootCellar/scripts.pory"
	case 0, RootCellar_EventScript_RandomiseRootCellarItem_38
# 364 "data//maps/RootCellar/scripts.pory"
	case 1, RootCellar_EventScript_RandomiseRootCellarItem_39
# 366 "data//maps/RootCellar/scripts.pory"
	case 2, RootCellar_EventScript_RandomiseRootCellarItem_40
# 368 "data//maps/RootCellar/scripts.pory"
	case 3, RootCellar_EventScript_RandomiseRootCellarItem_41
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_8:
# 374 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_ENERGY_ROOT
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_9:
# 377 "data//maps/RootCellar/scripts.pory"
	random 16
# 378 "data//maps/RootCellar/scripts.pory"
	switch VAR_RESULT
# 379 "data//maps/RootCellar/scripts.pory"
	case 0, RootCellar_EventScript_RandomiseRootCellarItem_20
# 381 "data//maps/RootCellar/scripts.pory"
	case 1, RootCellar_EventScript_RandomiseRootCellarItem_21
# 383 "data//maps/RootCellar/scripts.pory"
	case 2, RootCellar_EventScript_RandomiseRootCellarItem_22
# 385 "data//maps/RootCellar/scripts.pory"
	case 3, RootCellar_EventScript_RandomiseRootCellarItem_23
# 387 "data//maps/RootCellar/scripts.pory"
	case 4, RootCellar_EventScript_RandomiseRootCellarItem_24
# 389 "data//maps/RootCellar/scripts.pory"
	case 5, RootCellar_EventScript_RandomiseRootCellarItem_25
# 391 "data//maps/RootCellar/scripts.pory"
	case 6, RootCellar_EventScript_RandomiseRootCellarItem_26
# 393 "data//maps/RootCellar/scripts.pory"
	case 7, RootCellar_EventScript_RandomiseRootCellarItem_27
# 395 "data//maps/RootCellar/scripts.pory"
	case 8, RootCellar_EventScript_RandomiseRootCellarItem_28
# 397 "data//maps/RootCellar/scripts.pory"
	case 9, RootCellar_EventScript_RandomiseRootCellarItem_29
# 399 "data//maps/RootCellar/scripts.pory"
	case 10, RootCellar_EventScript_RandomiseRootCellarItem_30
# 401 "data//maps/RootCellar/scripts.pory"
	case 11, RootCellar_EventScript_RandomiseRootCellarItem_31
# 403 "data//maps/RootCellar/scripts.pory"
	case 12, RootCellar_EventScript_RandomiseRootCellarItem_32
# 405 "data//maps/RootCellar/scripts.pory"
	case 13, RootCellar_EventScript_RandomiseRootCellarItem_33
# 407 "data//maps/RootCellar/scripts.pory"
	case 14, RootCellar_EventScript_RandomiseRootCellarItem_34
# 409 "data//maps/RootCellar/scripts.pory"
	case 15, RootCellar_EventScript_RandomiseRootCellarItem_35
# 411 "data//maps/RootCellar/scripts.pory"
	case 16, RootCellar_EventScript_RandomiseRootCellarItem_36
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_16:
# 357 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, SPECIES_APPLIN
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_20:
# 380 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_OCCA_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_21:
# 382 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_PASSHO_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_22:
# 384 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_WACAN_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_23:
# 386 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_RINDO_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_24:
# 388 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_YACHE_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_25:
# 390 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_CHOPLE_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_26:
# 392 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_KEBIA_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_27:
# 394 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_SHUCA_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_28:
# 396 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_COBA_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_29:
# 398 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_PAYAPA_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_30:
# 400 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_TANGA_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_31:
# 402 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_CHARTI_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_32:
# 404 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_KASIB_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_33:
# 406 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_HABAN_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_34:
# 408 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_COLBUR_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_35:
# 410 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_BABIRI_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_36:
# 412 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_CHILAN_BERRY
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_38:
# 363 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_LEFTOVERS
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_39:
# 365 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_SWEET_APPLE
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_40:
# 367 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_TART_APPLE
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

RootCellar_EventScript_RandomiseRootCellarItem_41:
# 369 "data//maps/RootCellar/scripts.pory"
	setvar VAR_TEMP_5, ITEM_SYRUPY_APPLE
	goto RootCellar_EventScript_RandomiseRootCellarItem_1

