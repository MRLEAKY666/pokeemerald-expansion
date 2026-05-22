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
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_ShowMonToBreeder
# 18 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_CancelMonSelect
# 19 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 20 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 21 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_BreederIntro::
# 22 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_PokemonBreederIntro, MSGBOX_DEFAULT
# 23 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	return
# 24 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 25 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder::
# 26 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon, MSGBOX_DEFAULT
# 27 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	return
# 28 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 29 "data//maps/BattleFrontier_Lounge1/scripts.pory"
@ BufferVarsForIVRater buffers the following values
# 30 "data//maps/BattleFrontier_Lounge1/scripts.pory"
@ VAR_0x8005: Sum of the mons IVs
# 31 "data//maps/BattleFrontier_Lounge1/scripts.pory"
@ VAR_0x8006: Stat id of highest IV stat
# 32 "data//maps/BattleFrontier_Lounge1/scripts.pory"
@ VAR_0x8007: IV of the highest IV stat
# 33 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_ShowMonToBreeder::
# 34 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 35 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge1_EventScript_ShowEggToBreeder
# 36 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	special BufferVarsForIVRater
# 37 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_le VAR_0x8005, 90, BattleFrontier_Lounge1_EventScript_AverageTotalIVs       @ Average of 15
# 38 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_le VAR_0x8005, 120, BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs @ Average of 20
# 39 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_le VAR_0x8005, 150, BattleFrontier_Lounge1_EventScript_HighTotalIVs         @ Average of 25
# 40 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_le VAR_0x8005, 180, BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs         
# 41 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_ge VAR_0x8005, 181, BattleFrontier_Lounge1_EventScript_NearlyPerfectTotalIVs     @ Average of > 25
# 42 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 43 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 44 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_ShowEggToBreeder::
# 45 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_EvenICantTell, MSGBOX_DEFAULT
# 46 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
# 47 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 48 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 49 "data//maps/BattleFrontier_Lounge1/scripts.pory"
@ Comment on the highest IV stat, START HERE TO ADD TIED STAT LIST
# 50 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighestIVStat::
# 51 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_eq VAR_0x8006, STAT_HP, BattleFrontier_Lounge1_EventScript_HighestIVHP
# 52 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_eq VAR_0x8006, STAT_ATK, BattleFrontier_Lounge1_EventScript_HighestIVAtk
# 53 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_eq VAR_0x8006, STAT_DEF, BattleFrontier_Lounge1_EventScript_HighestIVDef
# 54 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_eq VAR_0x8006, STAT_SPEED, BattleFrontier_Lounge1_EventScript_HighestIVSpeed
# 55 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_eq VAR_0x8006, STAT_SPATK, BattleFrontier_Lounge1_EventScript_HighestIVSpAtk
# 56 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_eq VAR_0x8006, STAT_SPDEF, BattleFrontier_Lounge1_EventScript_HighestIVSpDef
# 57 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 58 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 59 "data//maps/BattleFrontier_Lounge1/scripts.pory"
@ Comment on the highest IV value
# 60 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighestIVValue::
# 61 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_le VAR_0x8007, 15, BattleFrontier_Lounge1_EventScript_HighestIVLow
# 62 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_le VAR_0x8007, 25, BattleFrontier_Lounge1_EventScript_HighestIVMid
# 63 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_le VAR_0x8007, 30, BattleFrontier_Lounge1_EventScript_HighestIVHigh
# 64 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_ge VAR_0x8007, 31, BattleFrontier_Lounge1_EventScript_HighestIVMax
# 65 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 66 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 67 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_EndBreederComments::
# 68 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	release
# 69 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 70 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 71 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_AverageTotalIVs::
# 72 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_AverageAbility, MSGBOX_DEFAULT
# 73 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
# 74 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 75 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 76 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs::
# 77 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_BetterThanAverageAbility, MSGBOX_DEFAULT
# 78 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
# 79 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 80 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 81 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighTotalIVs::
# 82 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_ImpressiveAbility, MSGBOX_DEFAULT
# 83 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
# 84 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 85 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 86 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs::
# 87 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_OutstandingAbility, MSGBOX_DEFAULT
# 88 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
# 89 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 90 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 91 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_NearlyPerfectTotalIVs::
# 92 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_GeniusAbility, MSGBOX_DEFAULT
# 93 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
# 94 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 95 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 96 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighestIVHP::
# 97 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_BestAspectHP, MSGBOX_DEFAULT
# 98 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
# 99 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 100 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 101 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighestIVAtk::
# 102 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_BestAspectAtk, MSGBOX_DEFAULT
# 103 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
# 104 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 105 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 106 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighestIVDef::
# 107 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_BestAspectDef, MSGBOX_DEFAULT
# 108 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
# 109 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 110 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 111 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighestIVSpeed::
# 112 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpeed, MSGBOX_DEFAULT
# 113 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
# 114 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 115 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 116 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighestIVSpAtk::
# 117 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpAtk, MSGBOX_DEFAULT
# 118 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
# 119 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 120 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 121 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighestIVSpDef::
# 122 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpDef, MSGBOX_DEFAULT
# 123 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
# 124 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 125 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 126 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighestIVLow::
# 127 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_StatRelativelyGood, MSGBOX_DEFAULT
# 128 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
# 129 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 130 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 131 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighestIVMid::
# 132 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_StatImpressive, MSGBOX_DEFAULT
# 133 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
# 134 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 135 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 136 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighestIVHigh::
# 137 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_StatOutstanding, MSGBOX_DEFAULT
# 138 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
# 139 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 140 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 141 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighestIVMax::
# 142 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_StatFlawless, MSGBOX_DEFAULT
# 143 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
# 144 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 145 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 146 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_CancelMonSelect::
# 147 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_NoTimeForMyAdvice, MSGBOX_DEFAULT
# 148 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	release
# 149 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 150 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 151 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_Boy1::
# 152 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding, MSGBOX_NPC
# 153 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 154 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 155 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_Boy2::
# 156 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt, MSGBOX_NPC
# 157 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 158 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 159 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_PokemonBreederIntro:
# 160 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "For 70 years I have raised POKéMON!\n"
# 161 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "I am the man they revere as\l"
# 162 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "the legendary top POKéMON BREEDER!\p"
# 163 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "If you ever become as seasoned as me,\n"
# 164 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "you'll see the abilities of POKéMON\l"
# 165 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "at a glance.\p"
# 166 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "You're a TRAINER. Doesn't it interest\n"
# 167 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "you to know your own POKéMON's\l"
# 168 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "abilities?\p"
# 169 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Here!\n"
# 170 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Let's have a look at your POKéMON!$"
# 171 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 172 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_AverageAbility:
# 173 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "…Hmm…\p"
# 174 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "This one, overall, I would describe\n"
# 175 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "as being of average ability.$"
# 176 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 177 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_BetterThanAverageAbility:
# 178 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "…Hmm…\p"
# 179 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "This one, overall, I would describe as\n"
# 180 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "having better-than-average ability.$"
# 181 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 182 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_ImpressiveAbility:
# 183 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "…Hmm…\p"
# 184 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "This one, overall, I would say is\n"
# 185 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "quite impressive in ability!$"
# 186 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 187 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_OutstandingAbility:
# 188 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "…Hmm…\p"
# 189 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "This one, overall, I would say is\n"
# 190 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "wonderfully outstanding in ability!$"
# 191 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 192 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_GeniusAbility::
# 193 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "…Hmm…\p"
# 194 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "This one, overall, I would say is\n"
# 195 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "a godlike genius in ability!$"
# 196 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 197 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_BestAspectHP:
# 198 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Incidentally, the best aspect of it,\n"
# 199 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "I would say, is its HP…$"
# 200 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 201 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_BestAspectAtk:
# 202 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Incidentally, the best aspect of it,\n"
# 203 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "I would say, is its ATTACK…$"
# 204 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 205 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_BestAspectDef:
# 206 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Incidentally, the best aspect of it,\n"
# 207 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "I would say, is its DEFENSE…$"
# 208 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 209 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_BestAspectSpAtk:
# 210 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Incidentally, the best aspect of it,\n"
# 211 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "I would say, is its SPECIAL ATTACK…$"
# 212 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 213 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_BestAspectSpDef:
# 214 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Incidentally, the best aspect of it,\n"
# 215 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "I would say, is its SPECIAL DEFENSE…$"
# 216 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 217 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_BestAspectSpeed:
# 218 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Incidentally, the best aspect of it,\n"
# 219 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "I would say, is its SPEED…$"
# 220 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 221 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_StatRelativelyGood:
# 222 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "That stat is relatively good.\n"
# 223 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "…Hm… That's how I call it.$"
# 224 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 225 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_StatImpressive:
# 226 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "That stat is quite impressive.\n"
# 227 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "…Hm… That's how I call it.$"
# 228 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 229 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_StatOutstanding:
# 230 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "That stat is outstanding!\n"
# 231 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "…Hm… That's how I call it.$"
# 232 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 233 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_StatFlawless:
# 234 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "It's flawless! A thing of perfection!\n"
# 235 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "…Hm… That's how I call it.$"
# 236 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 237 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_NoTimeForMyAdvice:
# 238 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "What?\n"
# 239 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "You have no time for my advice?\p"
# 240 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "You should always be eager to learn\n"
# 241 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "from the experiences of your elders!$"
# 242 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 243 "data//maps/BattleFrontier_Lounge1/scripts.pory"
@ Unused
# 244 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_HaveBusinessNeedsTending:
# 245 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Yes, what is it now?\p"
# 246 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "I have business that needs tending!\n"
# 247 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Save it for next time!$"
# 248 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 249 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon:
# 250 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Ah, youngster! Do your POKéMON's\n"
# 251 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "abilities intrigue you?\p"
# 252 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Here, here!\n"
# 253 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Let's have a look at your POKéMON!$"
# 254 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 255 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_EvenICantTell:
# 256 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "An expert I am, but even I can't tell\n"
# 257 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "anything about an unhatched POKéMON!\p"
# 258 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Show me a POKéMON!\n"
# 259 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "A POKéMON is what I need to see!$"
# 260 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 261 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding:
# 262 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "He said my POKéMON is outstanding!\n"
# 263 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "I'm glad I raised it carefully!$"
# 264 "data//maps/BattleFrontier_Lounge1/scripts.pory"

# 265 "data//maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt:
# 266 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "He said my POKéMON is outstanding!\n"
# 267 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "But I didn't do anything special\l"
# 268 "data//maps/BattleFrontier_Lounge1/scripts.pory"
	.string "raising it…$"
