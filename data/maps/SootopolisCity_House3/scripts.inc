# 1 "data//maps/SootopolisCity_House3/scripts.pory"

# 2 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_MapScripts::
# 3 "data//maps/SootopolisCity_House3/scripts.pory"
	.byte 0
# 4 "data//maps/SootopolisCity_House3/scripts.pory"

# 5 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_WallaceThanks::
# 6 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceThanks, MSGBOX_DEFAULT
# 7 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 8 "data//maps/SootopolisCity_House3/scripts.pory"
	setflag FLAG_MET_WALLACE_HOUSE
# 9 "data//maps/SootopolisCity_House3/scripts.pory"
	return
# 10 "data//maps/SootopolisCity_House3/scripts.pory"

# 11 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_Wallace::
# 12 "data//maps/SootopolisCity_House3/scripts.pory"
	lock
# 13 "data//maps/SootopolisCity_House3/scripts.pory"
	faceplayer
# 14 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_BEAST_SPECIES, SPECIES_HO_OH, SootopolisCity_House3_EventScript_WallaceMeetAtNavelRock
# 15 "data//maps/SootopolisCity_House3/scripts.pory"
	call_if_unset FLAG_MET_WALLACE_HOUSE, SootopolisCity_House3_EventScript_WallaceThanks
# 16 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceSearchingBeasts, MSGBOX_DEFAULT
# 17 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 18 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_BEAST_SPECIES, SPECIES_ENTEI, SootopolisCity_House3_EventScript_EnteiSpeech
# 19 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_BEAST_SPECIES, SPECIES_SUICUNE, SootopolisCity_House3_EventScript_SuicuneSpeech
# 20 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_BEAST_SPECIES, SPECIES_RAIKOU, SootopolisCity_House3_EventScript_RaikouSpeech
# 21 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_AlwaysHunting, MSGBOX_DEFAULT
# 22 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 23 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 24 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 25 "data//maps/SootopolisCity_House3/scripts.pory"

# 26 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_EnteiSpeech::
# 27 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_EnteiSpeech, MSGBOX_DEFAULT
# 28 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 29 "data//maps/SootopolisCity_House3/scripts.pory"
	getseenmon SPECIES_ENTEI
# 30 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_SeenEntei
# 31 "data//maps/SootopolisCity_House3/scripts.pory"
	return
# 32 "data//maps/SootopolisCity_House3/scripts.pory"

# 33 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SeenEntei::
# 34 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_SeenEntei, MSGBOX_DEFAULT
# 35 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 36 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_CAUGHT_ROAMING_ENTEI, SootopolisCity_House3_EventScript_CaughtEntei
# 37 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ShowMeEntei, MSGBOX_DEFAULT
# 38 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 39 "data//maps/SootopolisCity_House3/scripts.pory"
	call_if_set FLAG_NO_ACTIVE_BEAST SootopolisCity_House3_EventScript_SpawnNewEntei
# 40 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 41 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 42 "data//maps/SootopolisCity_House3/scripts.pory"

# 43 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_CaughtEntei::
# 44 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_CaughtEntei, MSGBOX_DEFAULT
# 45 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 46 "data//maps/SootopolisCity_House3/scripts.pory"
	checkspecies SPECIES_ENTEI, NO_PARTY_SCREEN
# 47 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_ShowEntei
# 48 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ShowMeEntei, MSGBOX_DEFAULT
# 49 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 50 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 51 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 52 "data//maps/SootopolisCity_House3/scripts.pory"

# 53 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_ShowEntei::
# 54 "data//maps/SootopolisCity_House3/scripts.pory"
	@ checkspecies SPECIES_ENTEI, OPEN_PARTY_SCREEN
# 55 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_ROAMING_BEASTS_CAUGHT, SootopolisCity_House3_EventScript_WallaceGiveTicketEntei
# 56 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_SpawnFirstSuicune
# 57 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_AlwaysHunting, MSGBOX_DEFAULT
# 58 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 59 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 60 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 61 "data//maps/SootopolisCity_House3/scripts.pory"

# 62 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SpawnFirstEntei::
# 63 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 0
# 64 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_UNUSED_0x8014, 0
# 65 "data//maps/SootopolisCity_House3/scripts.pory"
	special InitRoamer
# 66 "data//maps/SootopolisCity_House3/scripts.pory"
	clearflag FLAG_NO_ACTIVE_BEAST
# 67 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_ENTEI
# 68 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ThatsRaikou, MSGBOX_DEFAULT
# 69 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 70 "data//maps/SootopolisCity_House3/scripts.pory"
	playmoncry SPECIES_ENTEI, CRY_MODE_NORMAL
# 71 "data//maps/SootopolisCity_House3/scripts.pory"
	showmonpic SPECIES_ENTEI, 0, 0
# 72 "data//maps/SootopolisCity_House3/scripts.pory"
	setseenmon SPECIES_ENTEI
# 73 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_IntroEntei, MSGBOX_DEFAULT
# 74 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 75 "data//maps/SootopolisCity_House3/scripts.pory"
	hidemonpic
# 76 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 77 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 78 "data//maps/SootopolisCity_House3/scripts.pory"

# 79 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SpawnNewEntei::
# 80 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 0
# 81 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_UNUSED_0x8014, 0
# 82 "data//maps/SootopolisCity_House3/scripts.pory"
	special InitRoamer
# 83 "data//maps/SootopolisCity_House3/scripts.pory"
	clearflag FLAG_NO_ACTIVE_BEAST
# 84 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_ENTEI
# 85 "data//maps/SootopolisCity_House3/scripts.pory"
	return
# 86 "data//maps/SootopolisCity_House3/scripts.pory"

# 87 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SuicuneSpeech::
# 88 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_SuicuneSpeech, MSGBOX_DEFAULT
# 89 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 90 "data//maps/SootopolisCity_House3/scripts.pory"
	getseenmon SPECIES_SUICUNE
# 91 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_SeenSuicune
# 92 "data//maps/SootopolisCity_House3/scripts.pory"
	return
# 93 "data//maps/SootopolisCity_House3/scripts.pory"

# 94 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SeenSuicune::
# 95 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_SeenSuicune, MSGBOX_DEFAULT
# 96 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 97 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_CAUGHT_ROAMING_SUICUNE, SootopolisCity_House3_EventScript_CaughtSuicune
# 98 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ShowMeSuicune, MSGBOX_DEFAULT
# 99 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 100 "data//maps/SootopolisCity_House3/scripts.pory"
	call_if_set FLAG_NO_ACTIVE_BEAST SootopolisCity_House3_EventScript_SpawnNewSuicune
# 101 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 102 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 103 "data//maps/SootopolisCity_House3/scripts.pory"

# 104 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_CaughtSuicune::
# 105 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_CaughtSuicune, MSGBOX_DEFAULT
# 106 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 107 "data//maps/SootopolisCity_House3/scripts.pory"
	checkspecies SPECIES_SUICUNE, NO_PARTY_SCREEN
# 108 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_ShowSuicune
# 109 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ShowMeSuicune, MSGBOX_DEFAULT
# 110 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 111 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 112 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 113 "data//maps/SootopolisCity_House3/scripts.pory"

# 114 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_ShowSuicune::
# 115 "data//maps/SootopolisCity_House3/scripts.pory"
	@ checkspecies SPECIES_SUICUNE, OPEN_PARTY_SCREEN
# 116 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_ROAMING_BEASTS_CAUGHT, SootopolisCity_House3_EventScript_WallaceGiveTicketSuicune
# 117 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_SpawnFirstRaikou
# 118 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_AlwaysHunting, MSGBOX_DEFAULT
# 119 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 120 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 121 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 122 "data//maps/SootopolisCity_House3/scripts.pory"

# 123 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SpawnFirstSuicune::
# 124 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 1
# 125 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_UNUSED_0x8014, 0
# 126 "data//maps/SootopolisCity_House3/scripts.pory"
	special InitRoamer
# 127 "data//maps/SootopolisCity_House3/scripts.pory"
	clearflag FLAG_NO_ACTIVE_BEAST
# 128 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_SUICUNE
# 129 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ThatsEntei, MSGBOX_DEFAULT
# 130 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 131 "data//maps/SootopolisCity_House3/scripts.pory"
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
# 132 "data//maps/SootopolisCity_House3/scripts.pory"
	showmonpic SPECIES_SUICUNE, 0, 0
# 133 "data//maps/SootopolisCity_House3/scripts.pory"
	setseenmon SPECIES_SUICUNE
# 134 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_IntroSuicune, MSGBOX_DEFAULT
# 135 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 136 "data//maps/SootopolisCity_House3/scripts.pory"
	hidemonpic
# 137 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 138 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 139 "data//maps/SootopolisCity_House3/scripts.pory"

# 140 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SpawnNewSuicune::
# 141 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 1
# 142 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_UNUSED_0x8014, 0
# 143 "data//maps/SootopolisCity_House3/scripts.pory"
	special InitRoamer
# 144 "data//maps/SootopolisCity_House3/scripts.pory"
	clearflag FLAG_NO_ACTIVE_BEAST
# 145 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_SUICUNE
# 146 "data//maps/SootopolisCity_House3/scripts.pory"
	return
# 147 "data//maps/SootopolisCity_House3/scripts.pory"

# 148 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_RaikouSpeech::
# 149 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_RaikouSpeech, MSGBOX_DEFAULT
# 150 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 151 "data//maps/SootopolisCity_House3/scripts.pory"
	getseenmon SPECIES_RAIKOU
# 152 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_SeenRaikou
# 153 "data//maps/SootopolisCity_House3/scripts.pory"
	return
# 154 "data//maps/SootopolisCity_House3/scripts.pory"

# 155 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SeenRaikou::
# 156 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_SeenRaikou, MSGBOX_DEFAULT
# 157 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 158 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_CAUGHT_ROAMING_RAIKOU, SootopolisCity_House3_EventScript_CaughtRaikou
# 159 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ShowMeRaikou, MSGBOX_DEFAULT
# 160 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 161 "data//maps/SootopolisCity_House3/scripts.pory"
	call_if_set FLAG_NO_ACTIVE_BEAST SootopolisCity_House3_EventScript_SpawnNewRaikou
# 162 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 163 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 164 "data//maps/SootopolisCity_House3/scripts.pory"

# 165 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_CaughtRaikou::
# 166 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_CaughtRaikou, MSGBOX_DEFAULT
# 167 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 168 "data//maps/SootopolisCity_House3/scripts.pory"
	checkspecies SPECIES_RAIKOU, NO_PARTY_SCREEN
# 169 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_ShowRaikou
# 170 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ShowMeRaikou, MSGBOX_DEFAULT
# 171 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 172 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 173 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 174 "data//maps/SootopolisCity_House3/scripts.pory"

# 175 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_ShowRaikou::
# 176 "data//maps/SootopolisCity_House3/scripts.pory"
	@ checkspecies SPECIES_RAIKOU, OPEN_PARTY_SCREEN
# 177 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_ROAMING_BEASTS_CAUGHT, SootopolisCity_House3_EventScript_WallaceGiveTicketRaikou
# 178 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_SpawnFirstEntei
# 179 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_AlwaysHunting, MSGBOX_DEFAULT
# 180 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 181 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 182 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 183 "data//maps/SootopolisCity_House3/scripts.pory"

# 184 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SpawnFirstRaikou::
# 185 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 2
# 186 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_UNUSED_0x8014, 0
# 187 "data//maps/SootopolisCity_House3/scripts.pory"
	special InitRoamer
# 188 "data//maps/SootopolisCity_House3/scripts.pory"
	clearflag FLAG_NO_ACTIVE_BEAST
# 189 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_RAIKOU
# 190 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ThatsSuicune, MSGBOX_DEFAULT
# 191 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 192 "data//maps/SootopolisCity_House3/scripts.pory"
	playmoncry SPECIES_RAIKOU, CRY_MODE_NORMAL
# 193 "data//maps/SootopolisCity_House3/scripts.pory"
	showmonpic SPECIES_RAIKOU, 0, 0
# 194 "data//maps/SootopolisCity_House3/scripts.pory"
	setseenmon SPECIES_RAIKOU
# 195 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_IntroRaikou, MSGBOX_DEFAULT
# 196 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 197 "data//maps/SootopolisCity_House3/scripts.pory"
	hidemonpic
# 198 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 199 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 200 "data//maps/SootopolisCity_House3/scripts.pory"

# 201 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SpawnNewRaikou::
# 202 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 2
# 203 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_UNUSED_0x8014, 0
# 204 "data//maps/SootopolisCity_House3/scripts.pory"
	special InitRoamer
# 205 "data//maps/SootopolisCity_House3/scripts.pory"
	clearflag FLAG_NO_ACTIVE_BEAST
# 206 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_RAIKOU
# 207 "data//maps/SootopolisCity_House3/scripts.pory"
	return
# 208 "data//maps/SootopolisCity_House3/scripts.pory"

# 209 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_Woman::
# 210 "data//maps/SootopolisCity_House3/scripts.pory"
	lock
# 211 "data//maps/SootopolisCity_House3/scripts.pory"
	faceplayer
# 212 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_JuanHasManyFansDoYou, MSGBOX_YESNO
# 213 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SootopolisCity_House3_EventScript_HaveFans
# 214 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_LonesomeTryWorkingHarder, MSGBOX_DEFAULT
# 215 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 216 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 217 "data//maps/SootopolisCity_House3/scripts.pory"

# 218 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_HaveFans::
# 219 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_YouMustBePrettyStrong, MSGBOX_DEFAULT
# 220 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 221 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 222 "data//maps/SootopolisCity_House3/scripts.pory"

# 223 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_Girl::
# 224 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_TrainerFanClubWasWild, MSGBOX_NPC
# 225 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 226 "data//maps/SootopolisCity_House3/scripts.pory"

# 227 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_WallaceGiveTicketEntei::
# 228 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceFinalBeastEntei, MSGBOX_DEFAULT
# 229 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 230 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_unset FLAG_RECEIVED_MYSTIC_TICKET, SootopolisCity_House3_EventScript_WallaceGiveTicket
# 231 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceGiveHoohQuest2 MSGBOX_DEFAULT
# 232 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 233 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_HO_OH
# 234 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 235 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 236 "data//maps/SootopolisCity_House3/scripts.pory"

# 237 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_WallaceGiveTicketSuicune::
# 238 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceFinalBeastSuicune, MSGBOX_DEFAULT
# 239 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 240 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_unset FLAG_RECEIVED_MYSTIC_TICKET, SootopolisCity_House3_EventScript_WallaceGiveTicket
# 241 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceGiveHoohQuest2 MSGBOX_DEFAULT
# 242 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 243 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_HO_OH
# 244 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 245 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 246 "data//maps/SootopolisCity_House3/scripts.pory"

# 247 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_WallaceGiveTicketRaikou::
# 248 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceFinalBeastRaikou, MSGBOX_DEFAULT
# 249 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 250 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_unset FLAG_RECEIVED_MYSTIC_TICKET, SootopolisCity_House3_EventScript_WallaceGiveTicket
# 251 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceGiveHoohQuest2 MSGBOX_DEFAULT
# 252 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 253 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_HO_OH
# 254 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 255 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 256 "data//maps/SootopolisCity_House3/scripts.pory"

# 257 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_WallaceGiveTicket::
# 258 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceThreeBeasts, MSGBOX_DEFAULT
# 259 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 260 "data//maps/SootopolisCity_House3/scripts.pory"
	giveitem ITEM_MYSTIC_TICKET
# 261 "data//maps/SootopolisCity_House3/scripts.pory"
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
# 262 "data//maps/SootopolisCity_House3/scripts.pory"
	setflag FLAG_RECEIVED_MYSTIC_TICKET
# 263 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_HO_OH
# 264 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceGiveHoohQuest MSGBOX_DEFAULT
# 265 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 266 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 267 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 268 "data//maps/SootopolisCity_House3/scripts.pory"

# 269 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_WallaceMeetAtNavelRock::
# 270 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceGiveHoohQuest MSGBOX_DEFAULT
# 271 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 272 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 273 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 274 "data//maps/SootopolisCity_House3/scripts.pory"

# 275 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_ShowMeEntei:
# 276 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "If you can show me ENTEI, I'll be\n"
# 277 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "indebted to you once more, {PLAYER}.$"
# 278 "data//maps/SootopolisCity_House3/scripts.pory"

# 279 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_ShowMeSuicune:
# 280 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "If you can show me SUICUNE, I'll be\n"
# 281 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "indebted to you once more, {PLAYER}.$"
# 282 "data//maps/SootopolisCity_House3/scripts.pory"

# 283 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_ShowMeRaikou:
# 284 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "If you can show me RAIKOU, I'll be\n"
# 285 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "indebted to you once more, {PLAYER}.$"
# 286 "data//maps/SootopolisCity_House3/scripts.pory"

# 287 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_CaughtEntei:
# 288 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 289 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 290 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 291 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 292 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You've captured ENTEI?!$"
# 293 "data//maps/SootopolisCity_House3/scripts.pory"

# 294 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_CaughtSuicune:
# 295 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 296 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 297 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 298 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 299 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You've captured SUICUNE?!$"
# 300 "data//maps/SootopolisCity_House3/scripts.pory"

# 301 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_CaughtRaikou:
# 302 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 303 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 304 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 305 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 306 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You've captured RAIKOU?!$"
# 307 "data//maps/SootopolisCity_House3/scripts.pory"

# 308 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_SeenEntei:
# 309 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 310 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 311 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Oh! You've seen ENTEI?$"
# 312 "data//maps/SootopolisCity_House3/scripts.pory"

# 313 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_SeenSuicune:
# 314 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 315 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 316 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Oh! You've seen SUICUNE?$"
# 317 "data//maps/SootopolisCity_House3/scripts.pory"

# 318 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_SeenRaikou:
# 319 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 320 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 321 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Oh! You've seen RAIKOU?$"
# 322 "data//maps/SootopolisCity_House3/scripts.pory"

# 323 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_EnteiSpeech:
# 324 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Lately there have been rumors of\n"
# 325 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "sightings of one such POKéMON.\p"
# 326 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Yes, the POKéMON ENTEI has been\n"
# 327 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "seen recently around the HOENN region.$"
# 328 "data//maps/SootopolisCity_House3/scripts.pory"

# 329 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_SuicuneSpeech:
# 330 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Lately there have been rumors of\n"
# 331 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "sightings of one such POKéMON.\p"
# 332 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Yes, the POKéMON SUICUNE has been\n"
# 333 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "seen recently around the HOENN region.$"
# 334 "data//maps/SootopolisCity_House3/scripts.pory"

# 335 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_RaikouSpeech:
# 336 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Lately there have been rumors of\n"
# 337 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "sightings of one such POKéMON.\p"
# 338 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Yes, the POKéMON RAIKOU has been\n"
# 339 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "seen recently around the HOENN region.$"
# 340 "data//maps/SootopolisCity_House3/scripts.pory"

# 341 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_ThatsEntei:
# 342 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That POKéMON . . .\p"
# 343 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That's ENTEI!\p"
# 344 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "It's incredible to see a POKéMON as\n"
# 345 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "magnificent as this up close.\p"
# 346 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Maybe someday I will be able to see\n"
# 347 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "the other legendary beasts as well.\p"
# 348 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I've recently heard news of SUICUNE\n"
# 349 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "roaming around HOENN as well...$"
# 350 "data//maps/SootopolisCity_House3/scripts.pory"

# 351 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_IntroSuicune:
# 352 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "SUICUNE is the Aurora POKéMON.\p"
# 353 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "If you can capture SUICUNE and show it\n" 
# 354 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "to me, I'll be indebted to you once more.$"
# 355 "data//maps/SootopolisCity_House3/scripts.pory"

# 356 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_ThatsSuicune:
# 357 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That POKéMON . . .\p"
# 358 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That's SUICUNE!\p"
# 359 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "It's incredible to see a POKéMON as\n"
# 360 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "magnificent as this up close.\p"
# 361 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Maybe someday I will be able to see\n"
# 362 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "the other legendary beasts as well.\p"
# 363 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I've recently heard reports that RAIKOU\n"
# 364 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "has been spotted around HOENN as well...$"
# 365 "data//maps/SootopolisCity_House3/scripts.pory"

# 366 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_IntroRaikou:
# 367 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "RAIKOU is the Thunder POKéMON.\p"
# 368 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "If you can capture RAIKOU and show it\n" 
# 369 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "to me, I'll be indebted to you once more.$"
# 370 "data//maps/SootopolisCity_House3/scripts.pory"

# 371 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_ThatsRaikou:
# 372 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That POKéMON . . .\p"
# 373 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That's RAIKOU!\p"
# 374 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "It's incredible to see a POKéMON as\n"
# 375 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "magnificent as this up close.\p"
# 376 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Maybe someday I will be able to see\n"
# 377 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "the other legendary beasts as well.\p"
# 378 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I've recently heard reports that ENTEI\n"
# 379 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "has been spotted around HOENN as well...$"
# 380 "data//maps/SootopolisCity_House3/scripts.pory"

# 381 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_IntroEntei:
# 382 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "ENTEI is the Volcano POKéMON.\p"
# 383 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "If you can capture ENTEI and show it\n" 
# 384 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "to me, I'll be indebted to you once more.$"
# 385 "data//maps/SootopolisCity_House3/scripts.pory"

# 386 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceThanks:
# 387 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "WALLACE: Thanks for your help with\n"
# 388 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "that incident. Your help finding\l"
# 389 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "RAYQUAZA was invaluable.$"
# 390 "data//maps/SootopolisCity_House3/scripts.pory"

# 391 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceSearchingBeasts:
# 392 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "WALLACE: I'm considered an expert\n"
# 393 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "on the mythology of super-ancient\l"
# 394 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "POKéMON because I've spent my life\l"
# 395 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "researching a POKéMON called SUICUNE.\p"
# 396 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Through my research and my travels,\n"
# 397 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I've learned quite a bit about the\l"
# 398 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "myths surrounding the super-ancient\l"
# 399 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "POKéMON called the legendary beasts.$"
# 400 "data//maps/SootopolisCity_House3/scripts.pory"

# 401 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_JuanHasManyFansDoYou:
# 402 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You're a POKéMON TRAINER, aren't you?\p"
# 403 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "SOOTOPOLIS's JUAN has many fans.\n"
# 404 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Even more than his student WALLACE!\p"
# 405 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Do you have any?$"
# 406 "data//maps/SootopolisCity_House3/scripts.pory"

# 407 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_YouMustBePrettyStrong:
# 408 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Oh, then you must be pretty strong.$"
# 409 "data//maps/SootopolisCity_House3/scripts.pory"

# 410 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_LonesomeTryWorkingHarder:
# 411 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Oh, dear…\n"
# 412 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That's a little lonesome.\p"
# 413 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Try working a little harder to get\n"
# 414 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "a fan following.$"
# 415 "data//maps/SootopolisCity_House3/scripts.pory"

# 416 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_TrainerFanClubWasWild:
# 417 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Dedicated fans come over from even\n"
# 418 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "outside of HOENN.\p"
# 419 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "It was really wild when I went to the\n"
# 420 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "TRAINER FAN CLUB in LILYCOVE.$"
# 421 "data//maps/SootopolisCity_House3/scripts.pory"

# 422 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_AlwaysHunting:
# 423 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I'm always hunting for more information\n"
# 424 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "regarding the legendary beasts ENTEI,\l"
# 425 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "SUICUNE, and RAIKOU.\p"
# 426 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "If you see one, please come back and\n"
# 427 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "let me know.$"
# 428 "data//maps/SootopolisCity_House3/scripts.pory"

# 429 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceFinalBeastEntei:
# 430 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That POKéMON . . .\p"
# 431 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That's ENTEI!\p"
# 432 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "It's incredible to see a POKéMON as\n"
# 433 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "magnificent as this up close.$"
# 434 "data//maps/SootopolisCity_House3/scripts.pory"

# 435 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceFinalBeastSuicune:
# 436 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That POKéMON . . .\p"
# 437 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That's SUICUNE!\p"
# 438 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "It's incredible to see a POKéMON as\n"
# 439 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "magnificent as this up close.$"
# 440 "data//maps/SootopolisCity_House3/scripts.pory"

# 441 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceFinalBeastRaikou:
# 442 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That POKéMON . . .\p"
# 443 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That's RAIKOU!\p"
# 444 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "It's incredible to see a POKéMON as\n"
# 445 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "magnificent as this up close.$"
# 446 "data//maps/SootopolisCity_House3/scripts.pory"

# 447 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceThreeBeasts:
# 448 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 449 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 450 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "{PLAYER} . . .\p"
# 451 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Thanks to you, I've been able to fulfill\n"
# 452 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "my life's dream of seeing all three of\l"
# 453 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "the legendary beast POKéMON . . .\p"
# 454 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 455 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 456 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Ultimately, though I dedicated my life\n"
# 457 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "to finding SUICUNE, it was you alone,\l"
# 458 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "{PLAYER} . . .\p"
# 459 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Yes, I, WALLACE, had nothing to do with\n"
# 460 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "your dazzling discovery . . .\p"
# 461 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "{PLAYER},\n"
# 462 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I'd like you to take this.$"
# 463 "data//maps/SootopolisCity_House3/scripts.pory"

# 464 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceGiveHoohQuest:
# 465 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "WALLACE: With the MYSTIC TICKET\n"
# 466 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "you can travel to NAVEL ROCK.\p"
# 467 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I want you to meet me there with the\n"
# 468 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "three legendary beast POKéMON you've\l"
# 469 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "caught.\p"
# 470 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "By assembling them all in that place...\n"
# 471 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Can we summon HO-OH?$" 
# 472 "data//maps/SootopolisCity_House3/scripts.pory"

# 473 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceGiveHoohQuest2:
# 474 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "{PLAYER} . . .\p"
# 475 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I want you to meet me at NAVEL ROCK with\n"
# 476 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "the three legendary beast POKéMON.\p"
# 477 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "By assembling them all in that place...\n"
# 478 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Can we summon HO-OH?$"
