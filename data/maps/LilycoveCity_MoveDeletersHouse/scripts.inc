# 1 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 2 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_MapScripts::
# 3 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.byte 0
# 4 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 5 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_EventScript_MoveDeleter::
# 6 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	lockall
# 7 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	applymovement LOCALID_MOVE_DELETER, Common_Movement_FacePlayer
# 8 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	waitmovement 0
# 9 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove, MSGBOX_YESNO
# 10 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	switch VAR_RESULT
# 11 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	case YES, LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
# 12 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	case NO, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
# 13 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	releaseall
# 14 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 15 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 16 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget::
# 17 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_WhichMonShouldForget, MSGBOX_DEFAULT
# 18 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special ChoosePartyMon
# 19 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
# 20 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special IsSelectedMonEgg
# 21 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_MoveDeletersHouse_EventScript_EggCantForgetMoves
# 22 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special GetNumMovesSelectedMonHas
# 23 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, 1, LilycoveCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove
# 24 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
# 25 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	fadescreen FADE_TO_BLACK
# 26 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special MoveDeleterChooseMoveToForget
# 27 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 28 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	goto_if_eq VAR_0x8005, MAX_MON_MOVES, LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
# 29 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special BufferMoveDeleterNicknameAndMove
# 30 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
# 31 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	switch VAR_RESULT
# 32 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	case YES, LilycoveCity_MoveDeletersHouse_EventScript_TryForgetMove
# 33 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	case NO, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
# 34 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	releaseall
# 35 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 36 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 37 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_EventScript_TryForgetMove::
# 38 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special IsLastMonThatKnowsSurf
# 39 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_MoveDeletersHouse_EventScript_LastMonWithSurf
# 40 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special MoveDeleterForgetMove
# 41 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	playfanfare MUS_MOVE_DELETED
# 42 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	waitfanfare
# 43 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonHasForgottenMove, MSGBOX_DEFAULT
# 44 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	releaseall
# 45 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 46 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 47 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove::
# 48 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special BufferMoveDeleterNicknameAndMove
# 49 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove, MSGBOX_DEFAULT
# 50 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	releaseall
# 51 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 52 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 53 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_EventScript_EggCantForgetMoves::
# 54 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_EggCantForgetMoves, MSGBOX_DEFAULT
# 55 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	releaseall
# 56 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 57 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 58 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain::
# 59 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_ComeAgain, MSGBOX_DEFAULT
# 60 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	releaseall
# 61 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 62 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 63 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_EventScript_LastMonWithSurf::
# 64 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special BufferMoveDeleterNicknameAndMove
# 65 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_CantForgetSurf, MSGBOX_DEFAULT
# 66 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	releaseall
# 67 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 68 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 69 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove:
# 70 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Uh…\n"
# 71 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Oh, yes, I'm the MOVE DELETER.\p"
# 72 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "I can make POKéMON forget their moves.\p"
# 73 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Would you like me to do that?$"
# 74 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 75 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_WhichMonShouldForget:
# 76 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Which POKéMON should forget a move?$"
# 77 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 78 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten:
# 79 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Which move should be forgotten?$"
# 80 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 81 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove:
# 82 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "{STR_VAR_1} knows only one move\n"
# 83 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "so it can't be forgotten…$"
# 84 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 85 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten:
# 86 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Hm! {STR_VAR_1}'s {STR_VAR_2}?\n"
# 87 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "That move should be forgotten?$"
# 88 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 89 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_MonHasForgottenMove:
# 90 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "It worked to perfection!\p"
# 91 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "{STR_VAR_1} has forgotten\n"
# 92 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "{STR_VAR_2} completely.$"
# 93 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 94 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_ComeAgain:
# 95 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Come again if there are moves that\n"
# 96 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "need to be forgotten.$"
# 97 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 98 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_EggCantForgetMoves:
# 99 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "What?\n"
# 100 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "No EGG should know any moves.$"
# 101 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 102 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_CantForgetSurf:
# 103 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Hm!\p"
# 104 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Your {STR_VAR_1} doesn't seem willing\n"
# 105 "data//maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "to forget SURF.$"
