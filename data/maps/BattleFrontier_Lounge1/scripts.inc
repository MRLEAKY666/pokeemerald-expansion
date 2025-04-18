# 1 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 2 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_MapScripts::
# 3 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.byte 0
# 4 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 5 "data//maps/BattleFrontier_Lounge1/scripts.pory"
@ NPC that rates pokemon based on their IVs
# 6 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_Breeder::
# 7 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	lock
# 8 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	faceplayer
# 9 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	call_if_unset FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_BreederIntro
# 10 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	call_if_set FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder
# 11 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	setflag FLAG_MET_BATTLE_FRONTIER_BREEDER
# 12 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
# 13 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 14 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 15 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder::
# 16 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	special ChoosePartyMon
# 17 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	waitstate
# 18 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_ShowMonToBreeder
# 19 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_CancelMonSelect
# 20 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 21 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 22 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_BreederIntro::
# 23 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_PokemonBreederIntro, MSGBOX_DEFAULT
# 24 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	return
# 25 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 26 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder::
# 27 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon, MSGBOX_DEFAULT
# 28 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	return
# 29 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 30 "data//maps/BattleFrontier_Lounge1/scripts.pory"
@ BufferVarsForIVRater buffers the following values
# 31 "data//maps/BattleFrontier_Lounge1/scripts.pory"
@ VAR_0x8005: Sum of the mons IVs
# 32 "data//maps/BattleFrontier_Lounge1/scripts.pory"
@ VAR_0x8006: Stat id of highest IV stat
# 33 "data//maps/BattleFrontier_Lounge1/scripts.pory"
@ VAR_0x8007: IV of the highest IV stat
# 34 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_ShowMonToBreeder::
# 35 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 36 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge1_EventScript_ShowEggToBreeder
# 37 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	special BufferVarsForIVRater
# 38 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_le VAR_0x8005, 90, BattleFrontier_Lounge1_EventScript_AverageTotalIVs       @ Average of 15
# 39 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_le VAR_0x8005, 120, BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs @ Average of 20
# 40 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_le VAR_0x8005, 150, BattleFrontier_Lounge1_EventScript_HighTotalIVs         @ Average of 25
# 41 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_le VAR_0x8005, 180, BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs         
# 42 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_ge VAR_0x8005, 181, BattleFrontier_Lounge1_EventScript_NearlyPerfectTotalIVs     @ Average of > 25
# 43 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 44 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 45 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_ShowEggToBreeder::
# 46 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_EvenICantTell, MSGBOX_DEFAULT
# 47 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
# 48 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 49 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 50 "data//maps/BattleFrontier_Lounge1/scripts.pory"
@ Comment on the highest IV stat
# 51 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighestIVStat::
# 52 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_eq VAR_0x8006, STAT_HP, BattleFrontier_Lounge1_EventScript_HighestIVHP
# 53 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_eq VAR_0x8006, STAT_ATK, BattleFrontier_Lounge1_EventScript_HighestIVAtk
# 54 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_eq VAR_0x8006, STAT_DEF, BattleFrontier_Lounge1_EventScript_HighestIVDef
# 55 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_eq VAR_0x8006, STAT_SPEED, BattleFrontier_Lounge1_EventScript_HighestIVSpeed
# 56 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_eq VAR_0x8006, STAT_SPATK, BattleFrontier_Lounge1_EventScript_HighestIVSpAtk
# 57 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_eq VAR_0x8006, STAT_SPDEF, BattleFrontier_Lounge1_EventScript_HighestIVSpDef
# 58 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 59 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 60 "data//maps/BattleFrontier_Lounge1/scripts.pory"
@ Comment on the highest IV value
# 61 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighestIVValue::
# 62 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_le VAR_0x8007, 15, BattleFrontier_Lounge1_EventScript_HighestIVLow
# 63 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_le VAR_0x8007, 25, BattleFrontier_Lounge1_EventScript_HighestIVMid
# 64 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_le VAR_0x8007, 30, BattleFrontier_Lounge1_EventScript_HighestIVHigh
# 65 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_ge VAR_0x8007, 31, BattleFrontier_Lounge1_EventScript_HighestIVMax
# 66 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 67 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 68 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_EndBreederComments::
# 69 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	release
# 70 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 71 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 72 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_AverageTotalIVs::
# 73 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_AverageAbility, MSGBOX_DEFAULT
# 74 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
# 75 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 76 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 77 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs::
# 78 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_BetterThanAverageAbility, MSGBOX_DEFAULT
# 79 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
# 80 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 81 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 82 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighTotalIVs::
# 83 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_ImpressiveAbility, MSGBOX_DEFAULT
# 84 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
# 85 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 86 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 87 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs::
# 88 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_OutstandingAbility, MSGBOX_DEFAULT
# 89 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
# 90 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 91 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 92 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_NearlyPerfectTotalIVs::
# 93 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_GeniusAbility, MSGBOX_DEFAULT
# 94 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
# 95 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 96 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 97 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighestIVHP::
# 98 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_BestAspectHP, MSGBOX_DEFAULT
# 99 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
# 100 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 101 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 102 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighestIVAtk::
# 103 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_BestAspectAtk, MSGBOX_DEFAULT
# 104 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
# 105 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 106 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 107 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighestIVDef::
# 108 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_BestAspectDef, MSGBOX_DEFAULT
# 109 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
# 110 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 111 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 112 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighestIVSpeed::
# 113 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpeed, MSGBOX_DEFAULT
# 114 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
# 115 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 116 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 117 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighestIVSpAtk::
# 118 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpAtk, MSGBOX_DEFAULT
# 119 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
# 120 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 121 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 122 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighestIVSpDef::
# 123 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpDef, MSGBOX_DEFAULT
# 124 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
# 125 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 126 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 127 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighestIVLow::
# 128 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_StatRelativelyGood, MSGBOX_DEFAULT
# 129 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
# 130 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 131 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 132 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighestIVMid::
# 133 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_StatImpressive, MSGBOX_DEFAULT
# 134 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
# 135 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 136 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 137 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighestIVHigh::
# 138 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_StatOutstanding, MSGBOX_DEFAULT
# 139 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
# 140 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 141 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 142 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighestIVMax::
# 143 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_StatFlawless, MSGBOX_DEFAULT
# 144 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
# 145 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 146 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 147 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_CancelMonSelect::
# 148 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_NoTimeForMyAdvice, MSGBOX_DEFAULT
# 149 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	release
# 150 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 151 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 152 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_Boy1::
# 153 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding, MSGBOX_NPC
# 154 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 155 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 156 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_Boy2::
# 157 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt, MSGBOX_NPC
# 158 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 159 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 160 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_PokemonBreederIntro:
# 161 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "For 70 years I have raised POKéMON!\n"
# 162 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "I am the man they revere as\l"
# 163 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "the legendary top POKéMON BREEDER!\p"
# 164 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "If you ever become as seasoned as me,\n"
# 165 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "you'll see the abilities of POKéMON\l"
# 166 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "at a glance.\p"
# 167 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "You're a TRAINER. Doesn't it interest\n"
# 168 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "you to know your own POKéMON's\l"
# 169 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "abilities?\p"
# 170 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Here!\n"
# 171 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Let's have a look at your POKéMON!$"
# 172 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 173 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_AverageAbility:
# 174 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "…Hmm…\p"
# 175 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "This one, overall, I would describe\n"
# 176 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "as being of average ability.$"
# 177 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 178 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_BetterThanAverageAbility:
# 179 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "…Hmm…\p"
# 180 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "This one, overall, I would describe as\n"
# 181 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "having better-than-average ability.$"
# 182 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 183 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_ImpressiveAbility:
# 184 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "…Hmm…\p"
# 185 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "This one, overall, I would say is\n"
# 186 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "quite impressive in ability!$"
# 187 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 188 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_OutstandingAbility:
# 189 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "…Hmm…\p"
# 190 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "This one, overall, I would say is\n"
# 191 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "wonderfully outstanding in ability!$"
# 192 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 193 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_GeniusAbility::
# 194 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "…Hmm…\p"
# 195 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "This one, overall, I would say is\n"
# 196 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "a godlike genius in ability!$"
# 197 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 198 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_BestAspectHP:
# 199 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Incidentally, the best aspect of it,\n"
# 200 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "I would say, is its HP…$"
# 201 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 202 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_BestAspectAtk:
# 203 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Incidentally, the best aspect of it,\n"
# 204 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "I would say, is its ATTACK…$"
# 205 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 206 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_BestAspectDef:
# 207 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Incidentally, the best aspect of it,\n"
# 208 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "I would say, is its DEFENSE…$"
# 209 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 210 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_BestAspectSpAtk:
# 211 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Incidentally, the best aspect of it,\n"
# 212 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "I would say, is its SPECIAL ATTACK…$"
# 213 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 214 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_BestAspectSpDef:
# 215 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Incidentally, the best aspect of it,\n"
# 216 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "I would say, is its SPECIAL DEFENSE…$"
# 217 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 218 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_BestAspectSpeed:
# 219 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Incidentally, the best aspect of it,\n"
# 220 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "I would say, is its SPEED…$"
# 221 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 222 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_StatRelativelyGood:
# 223 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "That stat is relatively good.\n"
# 224 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "…Hm… That's how I call it.$"
# 225 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 226 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_StatImpressive:
# 227 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "That stat is quite impressive.\n"
# 228 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "…Hm… That's how I call it.$"
# 229 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 230 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_StatOutstanding:
# 231 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "That stat is outstanding!\n"
# 232 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "…Hm… That's how I call it.$"
# 233 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 234 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_StatFlawless:
# 235 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "It's flawless! A thing of perfection!\n"
# 236 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "…Hm… That's how I call it.$"
# 237 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 238 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_NoTimeForMyAdvice:
# 239 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "What?\n"
# 240 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "You have no time for my advice?\p"
# 241 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "You should always be eager to learn\n"
# 242 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "from the experiences of your elders!$"
# 243 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 244 "data//maps/BattleFrontier_Lounge1/scripts.pory"
@ Unused
# 245 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_HaveBusinessNeedsTending:
# 246 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Yes, what is it now?\p"
# 247 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "I have business that needs tending!\n"
# 248 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Save it for next time!$"
# 249 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 250 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon:
# 251 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Ah, youngster! Do your POKéMON's\n"
# 252 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "abilities intrigue you?\p"
# 253 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Here, here!\n"
# 254 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Let's have a look at your POKéMON!$"
# 255 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 256 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_EvenICantTell:
# 257 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "An expert I am, but even I can't tell\n"
# 258 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "anything about an unhatched POKéMON!\p"
# 259 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Show me a POKéMON!\n"
# 260 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "A POKéMON is what I need to see!$"
# 261 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 262 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding:
# 263 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "He said my POKéMON is outstanding!\n"
# 264 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "I'm glad I raised it carefully!$"
# 265 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 266 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt:
# 267 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "He said my POKéMON is outstanding!\n"
# 268 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "But I didn't do anything special\l"
# 269 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "raising it…$"
