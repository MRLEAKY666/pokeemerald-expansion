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
	showmonpic SPECIES_ENTEI, 0, 0
# 71 "data//maps/SootopolisCity_House3/scripts.pory"
	setseenmon SPECIES_ENTEI
# 72 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_IntroEntei, MSGBOX_DEFAULT
# 73 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 74 "data//maps/SootopolisCity_House3/scripts.pory"
	hidemonpic
# 75 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 76 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 77 "data//maps/SootopolisCity_House3/scripts.pory"

# 78 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SpawnNewEntei::
# 79 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 0
# 80 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_UNUSED_0x8014, 0
# 81 "data//maps/SootopolisCity_House3/scripts.pory"
	special InitRoamer
# 82 "data//maps/SootopolisCity_House3/scripts.pory"
	clearflag FLAG_NO_ACTIVE_BEAST
# 83 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_ENTEI
# 84 "data//maps/SootopolisCity_House3/scripts.pory"
	return
# 85 "data//maps/SootopolisCity_House3/scripts.pory"

# 86 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SuicuneSpeech::
# 87 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_SuicuneSpeech, MSGBOX_DEFAULT
# 88 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 89 "data//maps/SootopolisCity_House3/scripts.pory"
	getseenmon SPECIES_SUICUNE
# 90 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_SeenSuicune
# 91 "data//maps/SootopolisCity_House3/scripts.pory"
	return
# 92 "data//maps/SootopolisCity_House3/scripts.pory"

# 93 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SeenSuicune::
# 94 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_SeenSuicune, MSGBOX_DEFAULT
# 95 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 96 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_CAUGHT_ROAMING_SUICUNE, SootopolisCity_House3_EventScript_CaughtSuicune
# 97 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ShowMeSuicune, MSGBOX_DEFAULT
# 98 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 99 "data//maps/SootopolisCity_House3/scripts.pory"
	call_if_set FLAG_NO_ACTIVE_BEAST SootopolisCity_House3_EventScript_SpawnNewSuicune
# 100 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 101 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 102 "data//maps/SootopolisCity_House3/scripts.pory"

# 103 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_CaughtSuicune::
# 104 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_CaughtSuicune, MSGBOX_DEFAULT
# 105 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 106 "data//maps/SootopolisCity_House3/scripts.pory"
	checkspecies SPECIES_SUICUNE, NO_PARTY_SCREEN
# 107 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_ShowSuicune
# 108 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ShowMeSuicune, MSGBOX_DEFAULT
# 109 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 110 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 111 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 112 "data//maps/SootopolisCity_House3/scripts.pory"

# 113 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_ShowSuicune::
# 114 "data//maps/SootopolisCity_House3/scripts.pory"
	@ checkspecies SPECIES_SUICUNE, OPEN_PARTY_SCREEN
# 115 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_ROAMING_BEASTS_CAUGHT, SootopolisCity_House3_EventScript_WallaceGiveTicketSuicune
# 116 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_SpawnFirstRaikou
# 117 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_AlwaysHunting, MSGBOX_DEFAULT
# 118 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 119 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 120 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 121 "data//maps/SootopolisCity_House3/scripts.pory"

# 122 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SpawnFirstSuicune::
# 123 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 1
# 124 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_UNUSED_0x8014, 0
# 125 "data//maps/SootopolisCity_House3/scripts.pory"
	special InitRoamer
# 126 "data//maps/SootopolisCity_House3/scripts.pory"
	clearflag FLAG_NO_ACTIVE_BEAST
# 127 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_SUICUNE
# 128 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ThatsEntei, MSGBOX_DEFAULT
# 129 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 130 "data//maps/SootopolisCity_House3/scripts.pory"
	showmonpic SPECIES_SUICUNE, 0, 0
# 131 "data//maps/SootopolisCity_House3/scripts.pory"
	setseenmon SPECIES_SUICUNE
# 132 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_IntroSuicune, MSGBOX_DEFAULT
# 133 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 134 "data//maps/SootopolisCity_House3/scripts.pory"
	hidemonpic
# 135 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 136 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 137 "data//maps/SootopolisCity_House3/scripts.pory"

# 138 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SpawnNewSuicune::
# 139 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 1
# 140 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_UNUSED_0x8014, 0
# 141 "data//maps/SootopolisCity_House3/scripts.pory"
	special InitRoamer
# 142 "data//maps/SootopolisCity_House3/scripts.pory"
	clearflag FLAG_NO_ACTIVE_BEAST
# 143 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_SUICUNE
# 144 "data//maps/SootopolisCity_House3/scripts.pory"
	return
# 145 "data//maps/SootopolisCity_House3/scripts.pory"

# 146 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_RaikouSpeech::
# 147 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_RaikouSpeech, MSGBOX_DEFAULT
# 148 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 149 "data//maps/SootopolisCity_House3/scripts.pory"
	getseenmon SPECIES_RAIKOU
# 150 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_SeenRaikou
# 151 "data//maps/SootopolisCity_House3/scripts.pory"
	return
# 152 "data//maps/SootopolisCity_House3/scripts.pory"

# 153 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SeenRaikou::
# 154 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_SeenRaikou, MSGBOX_DEFAULT
# 155 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 156 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_CAUGHT_ROAMING_RAIKOU, SootopolisCity_House3_EventScript_CaughtRaikou
# 157 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ShowMeRaikou, MSGBOX_DEFAULT
# 158 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 159 "data//maps/SootopolisCity_House3/scripts.pory"
	call_if_set FLAG_NO_ACTIVE_BEAST SootopolisCity_House3_EventScript_SpawnNewRaikou
# 160 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 161 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 162 "data//maps/SootopolisCity_House3/scripts.pory"

# 163 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_CaughtRaikou::
# 164 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_CaughtRaikou, MSGBOX_DEFAULT
# 165 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 166 "data//maps/SootopolisCity_House3/scripts.pory"
	checkspecies SPECIES_RAIKOU, NO_PARTY_SCREEN
# 167 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_ShowRaikou
# 168 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ShowMeRaikou, MSGBOX_DEFAULT
# 169 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 170 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 171 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 172 "data//maps/SootopolisCity_House3/scripts.pory"

# 173 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_ShowRaikou::
# 174 "data//maps/SootopolisCity_House3/scripts.pory"
	@ checkspecies SPECIES_RAIKOU, OPEN_PARTY_SCREEN
# 175 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_ROAMING_BEASTS_CAUGHT, SootopolisCity_House3_EventScript_WallaceGiveTicketRaikou
# 176 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_SpawnFirstEntei
# 177 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_AlwaysHunting, MSGBOX_DEFAULT
# 178 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 179 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 180 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 181 "data//maps/SootopolisCity_House3/scripts.pory"

# 182 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SpawnFirstRaikou::
# 183 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 2
# 184 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_UNUSED_0x8014, 0
# 185 "data//maps/SootopolisCity_House3/scripts.pory"
	special InitRoamer
# 186 "data//maps/SootopolisCity_House3/scripts.pory"
	clearflag FLAG_NO_ACTIVE_BEAST
# 187 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_RAIKOU
# 188 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ThatsSuicune, MSGBOX_DEFAULT
# 189 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 190 "data//maps/SootopolisCity_House3/scripts.pory"
	showmonpic SPECIES_RAIKOU, 0, 0
# 191 "data//maps/SootopolisCity_House3/scripts.pory"
	setseenmon SPECIES_RAIKOU
# 192 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_IntroRaikou, MSGBOX_DEFAULT
# 193 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 194 "data//maps/SootopolisCity_House3/scripts.pory"
	hidemonpic
# 195 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 196 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 197 "data//maps/SootopolisCity_House3/scripts.pory"

# 198 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SpawnNewRaikou::
# 199 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 2
# 200 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_UNUSED_0x8014, 0
# 201 "data//maps/SootopolisCity_House3/scripts.pory"
	special InitRoamer
# 202 "data//maps/SootopolisCity_House3/scripts.pory"
	clearflag FLAG_NO_ACTIVE_BEAST
# 203 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_RAIKOU
# 204 "data//maps/SootopolisCity_House3/scripts.pory"
	return
# 205 "data//maps/SootopolisCity_House3/scripts.pory"

# 206 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_Woman::
# 207 "data//maps/SootopolisCity_House3/scripts.pory"
	lock
# 208 "data//maps/SootopolisCity_House3/scripts.pory"
	faceplayer
# 209 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_JuanHasManyFansDoYou, MSGBOX_YESNO
# 210 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SootopolisCity_House3_EventScript_HaveFans
# 211 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_LonesomeTryWorkingHarder, MSGBOX_DEFAULT
# 212 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 213 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 214 "data//maps/SootopolisCity_House3/scripts.pory"

# 215 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_HaveFans::
# 216 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_YouMustBePrettyStrong, MSGBOX_DEFAULT
# 217 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 218 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 219 "data//maps/SootopolisCity_House3/scripts.pory"

# 220 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_Girl::
# 221 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_TrainerFanClubWasWild, MSGBOX_NPC
# 222 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 223 "data//maps/SootopolisCity_House3/scripts.pory"

# 224 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_WallaceGiveTicketEntei::
# 225 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceFinalBeastEntei, MSGBOX_DEFAULT
# 226 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 227 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_unset FLAG_RECEIVED_MYSTIC_TICKET, SootopolisCity_House3_EventScript_WallaceGiveTicket
# 228 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceGiveHoohQuest2 MSGBOX_DEFAULT
# 229 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 230 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_HO_OH
# 231 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 232 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 233 "data//maps/SootopolisCity_House3/scripts.pory"

# 234 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_WallaceGiveTicketSuicune::
# 235 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceFinalBeastSuicune, MSGBOX_DEFAULT
# 236 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 237 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_unset FLAG_RECEIVED_MYSTIC_TICKET, SootopolisCity_House3_EventScript_WallaceGiveTicket
# 238 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceGiveHoohQuest2 MSGBOX_DEFAULT
# 239 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 240 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_HO_OH
# 241 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 242 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 243 "data//maps/SootopolisCity_House3/scripts.pory"

# 244 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_WallaceGiveTicketRaikou::
# 245 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceFinalBeastRaikou, MSGBOX_DEFAULT
# 246 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 247 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_unset FLAG_RECEIVED_MYSTIC_TICKET, SootopolisCity_House3_EventScript_WallaceGiveTicket
# 248 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceGiveHoohQuest2 MSGBOX_DEFAULT
# 249 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 250 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_HO_OH
# 251 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 252 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 253 "data//maps/SootopolisCity_House3/scripts.pory"

# 254 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_WallaceGiveTicket::
# 255 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceThreeBeasts, MSGBOX_DEFAULT
# 256 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 257 "data//maps/SootopolisCity_House3/scripts.pory"
	giveitem ITEM_MYSTIC_TICKET
# 258 "data//maps/SootopolisCity_House3/scripts.pory"
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
# 259 "data//maps/SootopolisCity_House3/scripts.pory"
	setflag FLAG_RECEIVED_MYSTIC_TICKET
# 260 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_HO_OH
# 261 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceGiveHoohQuest MSGBOX_DEFAULT
# 262 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 263 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 264 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 265 "data//maps/SootopolisCity_House3/scripts.pory"

# 266 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_WallaceMeetAtNavelRock::
# 267 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceGiveHoohQuest MSGBOX_DEFAULT
# 268 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 269 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 270 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 271 "data//maps/SootopolisCity_House3/scripts.pory"

# 272 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_ShowMeEntei:
# 273 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "If you can show me ENTEI, I'll be\n"
# 274 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "indebted to you once more, {PLAYER}.$"
# 275 "data//maps/SootopolisCity_House3/scripts.pory"

# 276 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_ShowMeSuicune:
# 277 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "If you can show me SUICUNE, I'll be\n"
# 278 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "indebted to you once more, {PLAYER}.$"
# 279 "data//maps/SootopolisCity_House3/scripts.pory"

# 280 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_ShowMeRaikou:
# 281 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "If you can show me RAIKOU, I'll be\n"
# 282 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "indebted to you once more, {PLAYER}.$"
# 283 "data//maps/SootopolisCity_House3/scripts.pory"

# 284 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_CaughtEntei:
# 285 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 286 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 287 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 288 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 289 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You've captured ENTEI?!$"
# 290 "data//maps/SootopolisCity_House3/scripts.pory"

# 291 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_CaughtSuicune:
# 292 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 293 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 294 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 295 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 296 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You've captured SUICUNE?!$"
# 297 "data//maps/SootopolisCity_House3/scripts.pory"

# 298 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_CaughtRaikou:
# 299 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 300 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 301 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 302 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 303 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You've captured RAIKOU?!$"
# 304 "data//maps/SootopolisCity_House3/scripts.pory"

# 305 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_SeenEntei:
# 306 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 307 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 308 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Oh! You've seen ENTEI?$"
# 309 "data//maps/SootopolisCity_House3/scripts.pory"

# 310 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_SeenSuicune:
# 311 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 312 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 313 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Oh! You've seen SUICUNE?$"
# 314 "data//maps/SootopolisCity_House3/scripts.pory"

# 315 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_SeenRaikou:
# 316 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 317 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 318 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Oh! You've seen RAIKOU?$"
# 319 "data//maps/SootopolisCity_House3/scripts.pory"

# 320 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_EnteiSpeech:
# 321 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Lately there have been rumors of\n"
# 322 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "sightings of one such POKéMON.\p"
# 323 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Yes, the POKéMON ENTEI has been\n"
# 324 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "seen recently around the HOENN region.$"
# 325 "data//maps/SootopolisCity_House3/scripts.pory"

# 326 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_SuicuneSpeech:
# 327 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Lately there have been rumors of\n"
# 328 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "sightings of one such POKéMON.\p"
# 329 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Yes, the POKéMON SUICUNE has been\n"
# 330 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "seen recently around the HOENN region.$"
# 331 "data//maps/SootopolisCity_House3/scripts.pory"

# 332 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_RaikouSpeech:
# 333 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Lately there have been rumors of\n"
# 334 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "sightings of one such POKéMON.\p"
# 335 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Yes, the POKéMON RAIKOU has been\n"
# 336 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "seen recently around the HOENN region.$"
# 337 "data//maps/SootopolisCity_House3/scripts.pory"

# 338 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_ThatsEntei:
# 339 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That POKéMON . . .\p"
# 340 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That's ENTEI!\p"
# 341 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "It's incredible to see a POKéMON as\n"
# 342 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "magnificent as this up close.\p"
# 343 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Maybe someday I will be able to see\n"
# 344 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "the other legendary beasts as well.\p"
# 345 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I've recently heard news of SUICUNE\n"
# 346 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "roaming around HOENN as well...$"
# 347 "data//maps/SootopolisCity_House3/scripts.pory"

# 348 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_IntroSuicune:
# 349 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "SUICUNE is the Aurora POKéMON.\p"
# 350 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "If you can capture SUICUNE and show it\n" 
# 351 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "to me, I'll be indebted to you once more.$"
# 352 "data//maps/SootopolisCity_House3/scripts.pory"

# 353 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_ThatsSuicune:
# 354 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That POKéMON . . .\p"
# 355 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That's SUICUNE!\p"
# 356 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "It's incredible to see a POKéMON as\n"
# 357 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "magnificent as this up close.\p"
# 358 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Maybe someday I will be able to see\n"
# 359 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "the other legendary beasts as well.\p"
# 360 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I've recently heard reports that RAIKOU\n"
# 361 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "has been spotted around HOENN as well...$"
# 362 "data//maps/SootopolisCity_House3/scripts.pory"

# 363 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_IntroRaikou:
# 364 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "RAIKOU is the Thunder POKéMON.\p"
# 365 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "If you can capture RAIKOU and show it\n" 
# 366 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "to me, I'll be indebted to you once more.$"
# 367 "data//maps/SootopolisCity_House3/scripts.pory"

# 368 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_ThatsRaikou:
# 369 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That POKéMON . . .\p"
# 370 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That's RAIKOU!\p"
# 371 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "It's incredible to see a POKéMON as\n"
# 372 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "magnificent as this up close.\p"
# 373 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Maybe someday I will be able to see\n"
# 374 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "the other legendary beasts as well.\p"
# 375 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I've recently heard reports that ENTEI\n"
# 376 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "has been spotted around HOENN as well...$"
# 377 "data//maps/SootopolisCity_House3/scripts.pory"

# 378 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_IntroEntei:
# 379 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "ENTEI is the Volcano POKéMON.\p"
# 380 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "If you can capture ENTEI and show it\n" 
# 381 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "to me, I'll be indebted to you once more.$"
# 382 "data//maps/SootopolisCity_House3/scripts.pory"

# 383 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceThanks:
# 384 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "WALLACE: Thanks for your help with\n"
# 385 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "that incident. Your help finding\l"
# 386 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "RAYQUAZA was invaluable.$"
# 387 "data//maps/SootopolisCity_House3/scripts.pory"

# 388 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceSearchingBeasts:
# 389 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "WALLACE: I'm considered an expert\n"
# 390 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "on the mythology of super-ancient\l"
# 391 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "POKéMON because I've spent my life\l"
# 392 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "researching a POKéMON called SUICUNE.\p"
# 393 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Through my research and my travels,\n"
# 394 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I've learned quite a bit about the\l"
# 395 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "myths surrounding the super-ancient\l"
# 396 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "POKéMON called the legendary beasts.$"
# 397 "data//maps/SootopolisCity_House3/scripts.pory"

# 398 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_JuanHasManyFansDoYou:
# 399 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You're a POKéMON TRAINER, aren't you?\p"
# 400 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "SOOTOPOLIS's JUAN has many fans.\n"
# 401 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Even more than his student WALLACE!\p"
# 402 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Do you have any?$"
# 403 "data//maps/SootopolisCity_House3/scripts.pory"

# 404 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_YouMustBePrettyStrong:
# 405 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Oh, then you must be pretty strong.$"
# 406 "data//maps/SootopolisCity_House3/scripts.pory"

# 407 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_LonesomeTryWorkingHarder:
# 408 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Oh, dear…\n"
# 409 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That's a little lonesome.\p"
# 410 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Try working a little harder to get\n"
# 411 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "a fan following.$"
# 412 "data//maps/SootopolisCity_House3/scripts.pory"

# 413 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_TrainerFanClubWasWild:
# 414 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Dedicated fans come over from even\n"
# 415 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "outside of HOENN.\p"
# 416 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "It was really wild when I went to the\n"
# 417 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "TRAINER FAN CLUB in LILYCOVE.$"
# 418 "data//maps/SootopolisCity_House3/scripts.pory"

# 419 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_AlwaysHunting:
# 420 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I'm always hunting for more information\n"
# 421 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "regarding the legendary beasts ENTEI,\l"
# 422 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "SUICUNE, and RAIKOU.\p"
# 423 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "If you see one, please come back and\n"
# 424 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "let me know.$"
# 425 "data//maps/SootopolisCity_House3/scripts.pory"

# 426 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceFinalBeastEntei:
# 427 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That POKéMON . . .\p"
# 428 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That's ENTEI!\p"
# 429 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "It's incredible to see a POKéMON as\n"
# 430 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "magnificent as this up close.$"
# 431 "data//maps/SootopolisCity_House3/scripts.pory"

# 432 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceFinalBeastSuicune:
# 433 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That POKéMON . . .\p"
# 434 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That's SUICUNE!\p"
# 435 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "It's incredible to see a POKéMON as\n"
# 436 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "magnificent as this up close.$"
# 437 "data//maps/SootopolisCity_House3/scripts.pory"

# 438 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceFinalBeastRaikou:
# 439 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That POKéMON . . .\p"
# 440 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That's RAIKOU!\p"
# 441 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "It's incredible to see a POKéMON as\n"
# 442 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "magnificent as this up close.$"
# 443 "data//maps/SootopolisCity_House3/scripts.pory"

# 444 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceThreeBeasts:
# 445 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 446 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 447 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "{PLAYER} . . .\p"
# 448 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Thanks to you, I've been able to fulfill\n"
# 449 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "my life's dream of seeing all three of\l"
# 450 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "the legendary beast POKéMON . . .\p"
# 451 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 452 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 453 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Ultimately, though I dedicated my life\n"
# 454 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "to finding SUICUNE, it was you alone,\l"
# 455 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "{PLAYER} . . .\p"
# 456 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Yes, I, WALLACE, had nothing to do with\n"
# 457 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "your dazzling discovery . . .\p"
# 458 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "{PLAYER},\n"
# 459 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I'd like you to take this.$"
# 460 "data//maps/SootopolisCity_House3/scripts.pory"

# 461 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceGiveHoohQuest:
# 462 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "WALLACE: With the MYSTIC TICKET\n"
# 463 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "you can travel to NAVEL ROCK.\p"
# 464 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I want you to meet me there with the\n"
# 465 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "three legendary beast POKéMON you've\l"
# 466 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "caught.\p"
# 467 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "By assembling them all in that place...\n"
# 468 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Can we summon HO-OH?$" 
# 469 "data//maps/SootopolisCity_House3/scripts.pory"

# 470 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceGiveHoohQuest2:
# 471 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "{PLAYER} . . .\p"
# 472 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I want you to meet me at NAVEL ROCK with\n"
# 473 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "the three legendary beast POKéMON.\p"
# 474 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "By assembling them all in that place...\n"
# 475 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Can we summon HO-OH?$"
