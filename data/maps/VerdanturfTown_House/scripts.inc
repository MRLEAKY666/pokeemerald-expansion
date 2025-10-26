# 1 "data//maps/VerdanturfTown_House/scripts.pory"

# 2 "data//maps/VerdanturfTown_House/scripts.pory"
VerdanturfTown_House_MapScripts::
# 3 "data//maps/VerdanturfTown_House/scripts.pory"
	.byte 0
# 4 "data//maps/VerdanturfTown_House/scripts.pory"

# 5 "data//maps/VerdanturfTown_House/scripts.pory"
VerdanturfTown_House_EventScript_Woman1::
# 6 "data//maps/VerdanturfTown_House/scripts.pory"
	lock
# 7 "data//maps/VerdanturfTown_House/scripts.pory"
	faceplayer
# 8 "data//maps/VerdanturfTown_House/scripts.pory"
	goto_if_eq VAR_BIKE_QUEST_STATE, 1, VerdanturfTown_House_EventScript_Woman1BikeQuest
# 9 "data//maps/VerdanturfTown_House/scripts.pory"
	msgbox VerdanturfTown_House_Text_TrainersGatherAtPokemonLeague, MSGBOX_DEFAULT
# 10 "data//maps/VerdanturfTown_House/scripts.pory"
	waitmessage
# 11 "data//maps/VerdanturfTown_House/scripts.pory"
	applymovement LOCALID_VERDANTURF_HOUSE_WOMAN1, Common_Movement_FaceOriginalDirection
# 12 "data//maps/VerdanturfTown_House/scripts.pory"
	waitmovement
# 13 "data//maps/VerdanturfTown_House/scripts.pory"
	release
# 14 "data//maps/VerdanturfTown_House/scripts.pory"
	end
# 15 "data//maps/VerdanturfTown_House/scripts.pory"

# 16 "data//maps/VerdanturfTown_House/scripts.pory"
VerdanturfTown_House_EventScript_Woman1BikeQuest::
# 17 "data//maps/VerdanturfTown_House/scripts.pory"
	msgbox VerdanturfTown_House_Text_BikeForMe, MSGBOX_DEFAULT
# 18 "data//maps/VerdanturfTown_House/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 19 "data//maps/VerdanturfTown_House/scripts.pory"
	message VerdanturfTown_House_Text_HandedOverBike
# 20 "data//maps/VerdanturfTown_House/scripts.pory"
	waitfanfare
# 21 "data//maps/VerdanturfTown_House/scripts.pory"
	removeitem ITEM_ACRO_BIKE
# 22 "data//maps/VerdanturfTown_House/scripts.pory"
	closemessage
# 23 "data//maps/VerdanturfTown_House/scripts.pory"
	delay 90
# 24 "data//maps/VerdanturfTown_House/scripts.pory"
	msgbox VerdanturfTown_House_Text_ThanksForBike, MSGBOX_DEFAULT
# 25 "data//maps/VerdanturfTown_House/scripts.pory"
	applymovement LOCALID_VERDANTURF_HOUSE_WOMAN1, Common_Movement_FaceOriginalDirection
# 26 "data//maps/VerdanturfTown_House/scripts.pory"
	waitmovement
# 27 "data//maps/VerdanturfTown_House/scripts.pory"
	setvar VAR_BIKE_QUEST_STATE, 2
# 28 "data//maps/VerdanturfTown_House/scripts.pory"
	release
# 29 "data//maps/VerdanturfTown_House/scripts.pory"
	end
# 30 "data//maps/VerdanturfTown_House/scripts.pory"

# 31 "data//maps/VerdanturfTown_House/scripts.pory"
VerdanturfTown_House_EventScript_Woman2::
# 32 "data//maps/VerdanturfTown_House/scripts.pory"
	lock
# 33 "data//maps/VerdanturfTown_House/scripts.pory"
	faceplayer
# 34 "data//maps/VerdanturfTown_House/scripts.pory"
	goto_if_eq VAR_BIKE_QUEST_STATE, 1, VerdanturfTown_House_EventScript_Woman2BikeQuest
# 35 "data//maps/VerdanturfTown_House/scripts.pory"
	msgbox VerdanturfTown_House_Text_DefeatEliteFourInARow, MSGBOX_DEFAULT
# 36 "data//maps/VerdanturfTown_House/scripts.pory"
	waitmessage
# 37 "data//maps/VerdanturfTown_House/scripts.pory"
	applymovement LOCALID_VERDANTURF_HOUSE_WOMAN2, Common_Movement_FaceOriginalDirection
# 38 "data//maps/VerdanturfTown_House/scripts.pory"
	waitmovement
# 39 "data//maps/VerdanturfTown_House/scripts.pory"
	release
# 40 "data//maps/VerdanturfTown_House/scripts.pory"
	end
# 41 "data//maps/VerdanturfTown_House/scripts.pory"

# 42 "data//maps/VerdanturfTown_House/scripts.pory"
VerdanturfTown_House_EventScript_Woman2BikeQuest::
# 43 "data//maps/VerdanturfTown_House/scripts.pory"
	msgbox VerdanturfTown_House_Text_Woman2BikeQuest, MSGBOX_DEFAULT
# 44 "data//maps/VerdanturfTown_House/scripts.pory"
	applymovement LOCALID_VERDANTURF_HOUSE_WOMAN2, Common_Movement_FaceOriginalDirection
# 45 "data//maps/VerdanturfTown_House/scripts.pory"
	waitmovement
# 46 "data//maps/VerdanturfTown_House/scripts.pory"
	release
# 47 "data//maps/VerdanturfTown_House/scripts.pory"
	end
# 48 "data//maps/VerdanturfTown_House/scripts.pory"

# 49 "data//maps/VerdanturfTown_House/scripts.pory"
VerdanturfTown_House_Text_TrainersGatherAtPokemonLeague:
# 50 "data//maps/VerdanturfTown_House/scripts.pory"
	.string "Far away, deep in EVER GRANDE CITY,\n"
# 51 "data//maps/VerdanturfTown_House/scripts.pory"
	.string "is the POKéMON LEAGUE.\p"
# 52 "data//maps/VerdanturfTown_House/scripts.pory"
	.string "The TRAINERS who gather there are\n"
# 53 "data//maps/VerdanturfTown_House/scripts.pory"
	.string "all frighteningly well skilled.$"
# 54 "data//maps/VerdanturfTown_House/scripts.pory"

# 55 "data//maps/VerdanturfTown_House/scripts.pory"
VerdanturfTown_House_Text_BikeForMe:
# 56 "data//maps/VerdanturfTown_House/scripts.pory"
	.string "Far away, deep in EVER GRA--\l"
# 57 "data//maps/VerdanturfTown_House/scripts.pory"
	.string "Huh? You're here to deliver my BIKE?\p"
# 58 "data//maps/VerdanturfTown_House/scripts.pory"
	.string "Thank you!$"
# 59 "data//maps/VerdanturfTown_House/scripts.pory"

# 60 "data//maps/VerdanturfTown_House/scripts.pory"
VerdanturfTown_House_Text_HandedOverBike:
# 61 "data//maps/VerdanturfTown_House/scripts.pory"
	.string "{PLAYER} handed over the BIKE.$"
# 62 "data//maps/VerdanturfTown_House/scripts.pory"

# 63 "data//maps/VerdanturfTown_House/scripts.pory"
VerdanturfTown_House_Text_ThanksForBike:
# 64 "data//maps/VerdanturfTown_House/scripts.pory"
	.string "…\p"
# 65 "data//maps/VerdanturfTown_House/scripts.pory"
	.string "Were you expecting a tip or something?$"
# 66 "data//maps/VerdanturfTown_House/scripts.pory"

# 67 "data//maps/VerdanturfTown_House/scripts.pory"
VerdanturfTown_House_Text_Woman2BikeQuest:
# 68 "data//maps/VerdanturfTown_House/scripts.pory"
	.string "My sister ordered a BIKE from\n"
# 69 "data//maps/VerdanturfTown_House/scripts.pory"
	.string "MAUVILLE CITY…\p"
# 70 "data//maps/VerdanturfTown_House/scripts.pory"
	.string "I wonder when it will arrive…$"
# 71 "data//maps/VerdanturfTown_House/scripts.pory"

# 72 "data//maps/VerdanturfTown_House/scripts.pory"
VerdanturfTown_House_Text_DefeatEliteFourInARow:
# 73 "data//maps/VerdanturfTown_House/scripts.pory"
	.string "In the POKéMON LEAGUE, I think the\n"
# 74 "data//maps/VerdanturfTown_House/scripts.pory"
	.string "rules say that you have to battle the\l"
# 75 "data//maps/VerdanturfTown_House/scripts.pory"
	.string "ELITE FOUR all in a row.\p"
# 76 "data//maps/VerdanturfTown_House/scripts.pory"
	.string "If you lose to any of them, you have\n"
# 77 "data//maps/VerdanturfTown_House/scripts.pory"
	.string "to begin your challenge again from the\l"
# 78 "data//maps/VerdanturfTown_House/scripts.pory"
	.string "first one.$"
