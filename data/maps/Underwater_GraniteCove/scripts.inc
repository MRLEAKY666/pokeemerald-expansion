Underwater_GraniteCove_MapScripts::
	.byte 0


Underwater_GraniteCove_EventScript_BottomlessHole::
# 4 "data//maps/Underwater_GraniteCove/scripts.pory"
	lock
# 5 "data//maps/Underwater_GraniteCove/scripts.pory"
	message Underwater_GraniteCove_EventScript_BottomlessHole_Text_0
# 8 "data//maps/Underwater_GraniteCove/scripts.pory"
	waitmessage
# 9 "data//maps/Underwater_GraniteCove/scripts.pory"
	waitbuttonpress
# 10 "data//maps/Underwater_GraniteCove/scripts.pory"
	closemessage
# 11 "data//maps/Underwater_GraniteCove/scripts.pory"
	applymovement LOCALID_PLAYER, Underwater_GraniteCove_Movement_TurnBack
# 12 "data//maps/Underwater_GraniteCove/scripts.pory"
	waitmovement LOCALID_PLAYER
# 13 "data//maps/Underwater_GraniteCove/scripts.pory"
	release
	end


# 17 "data//maps/Underwater_GraniteCove/scripts.pory"
Underwater_GraniteCove_Movement_TurnBack:
# 18 "data//maps/Underwater_GraniteCove/scripts.pory"
	walk_up
	step_end

Underwater_GraniteCove_EventScript_BottomlessHole_Text_0:
# 6 "data//maps/Underwater_GraniteCove/scripts.pory"
	.string "There's a bottomless hole ahead!\pBetter turn back, who knows what's\ndown there…$"
