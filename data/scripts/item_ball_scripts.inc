# 1 "data//scripts/item_ball_scripts.pory"

# 2 "data//scripts/item_ball_scripts.pory"
Common_EventScript_FindItem::
# 3 "data//scripts/item_ball_scripts.pory"
	callnative GetItemBallIdAndAmountFromTemplate
# 4 "data//scripts/item_ball_scripts.pory"
	finditem VAR_RESULT VAR_0x8009
# 5 "data//scripts/item_ball_scripts.pory"
	end

Common_EventScript_FindMysteryItem::
# 8 "data//scripts/item_ball_scripts.pory"
	call Common_EventScript_GenerateRandomItem
# 9 "data//scripts/item_ball_scripts.pory"
	finditem VAR_0x8008, 1
	end


Common_EventScript_GenerateRandomItem::
# 14 "data//scripts/item_ball_scripts.pory"
	random 10
# 15 "data//scripts/item_ball_scripts.pory"
	switch VAR_RESULT
# 16 "data//scripts/item_ball_scripts.pory"
	case 0, Common_EventScript_GenerateRandomItem_3
# 18 "data//scripts/item_ball_scripts.pory"
	case 1, Common_EventScript_GenerateRandomItem_4
# 20 "data//scripts/item_ball_scripts.pory"
	case 2, Common_EventScript_GenerateRandomItem_5
# 22 "data//scripts/item_ball_scripts.pory"
	case 3, Common_EventScript_GenerateRandomItem_6
# 24 "data//scripts/item_ball_scripts.pory"
	case 4, Common_EventScript_GenerateRandomItem_7
# 26 "data//scripts/item_ball_scripts.pory"
	case 5, Common_EventScript_GenerateRandomItem_8
# 28 "data//scripts/item_ball_scripts.pory"
	case 6, Common_EventScript_GenerateRandomItem_9
# 30 "data//scripts/item_ball_scripts.pory"
	case 7, Common_EventScript_GenerateRandomItem_10
# 32 "data//scripts/item_ball_scripts.pory"
	case 8, Common_EventScript_GenerateRandomItem_11
# 34 "data//scripts/item_ball_scripts.pory"
	case 9, Common_EventScript_GenerateRandomItem_12
Common_EventScript_GenerateRandomItem_1:
# 37 "data//scripts/item_ball_scripts.pory"
	setvar VAR_RESULT, 1
	return

Common_EventScript_GenerateRandomItem_3:
# 17 "data//scripts/item_ball_scripts.pory"
	getrandomitem VAR_0x8008, ITEM_GENERATOR_CONSUMABLE
	goto Common_EventScript_GenerateRandomItem_1

Common_EventScript_GenerateRandomItem_4:
# 19 "data//scripts/item_ball_scripts.pory"
	getrandomitem VAR_0x8008, ITEM_GENERATOR_CONSUMABLE
	goto Common_EventScript_GenerateRandomItem_1

Common_EventScript_GenerateRandomItem_5:
# 21 "data//scripts/item_ball_scripts.pory"
	getrandomitem VAR_0x8008, ITEM_GENERATOR_CONSUMABLE
	goto Common_EventScript_GenerateRandomItem_1

Common_EventScript_GenerateRandomItem_6:
# 23 "data//scripts/item_ball_scripts.pory"
	getrandomitem VAR_0x8008, ITEM_GENERATOR_TREASURE
	goto Common_EventScript_GenerateRandomItem_1

Common_EventScript_GenerateRandomItem_7:
# 25 "data//scripts/item_ball_scripts.pory"
	getrandomitem VAR_0x8008, ITEM_GENERATOR_TREASURE
	goto Common_EventScript_GenerateRandomItem_1

Common_EventScript_GenerateRandomItem_8:
# 27 "data//scripts/item_ball_scripts.pory"
	getrandomitem VAR_0x8008, ITEM_GENERATOR_HELD_ITEM
	goto Common_EventScript_GenerateRandomItem_1

Common_EventScript_GenerateRandomItem_9:
# 29 "data//scripts/item_ball_scripts.pory"
	getrandomitem VAR_0x8008, ITEM_GENERATOR_HELD_ITEM
	goto Common_EventScript_GenerateRandomItem_1

Common_EventScript_GenerateRandomItem_10:
# 31 "data//scripts/item_ball_scripts.pory"
	getrandomitem VAR_0x8008, ITEM_GENERATOR_MINT
	goto Common_EventScript_GenerateRandomItem_1

Common_EventScript_GenerateRandomItem_11:
# 33 "data//scripts/item_ball_scripts.pory"
	getrandomitem VAR_0x8008, ITEM_GENERATOR_TM
	goto Common_EventScript_GenerateRandomItem_1

Common_EventScript_GenerateRandomItem_12:
# 35 "data//scripts/item_ball_scripts.pory"
	getrandomitem VAR_0x8008, ITEM_GENERATOR_TM
	goto Common_EventScript_GenerateRandomItem_1


Common_EventScript_FindMysteryTM::
# 42 "data//scripts/item_ball_scripts.pory"
	getrandomitem VAR_0x8008, ITEM_GENERATOR_TM
# 43 "data//scripts/item_ball_scripts.pory"
	random 3
# 44 "data//scripts/item_ball_scripts.pory"
	addvar VAR_RESULT, 1
# 45 "data//scripts/item_ball_scripts.pory"
	finditem VAR_0x8008, VAR_RESULT
	end


Common_EventScript_FindHiddenItem::
# 50 "data//scripts/item_ball_scripts.pory"
	call Common_EventScript_GenerateHiddenItem
# 51 "data//scripts/item_ball_scripts.pory"
	copyvar VAR_0x8005, VAR_0x8008
	return


Common_EventScript_GenerateHiddenItem::
# 56 "data//scripts/item_ball_scripts.pory"
	random 5
# 57 "data//scripts/item_ball_scripts.pory"
	switch VAR_RESULT
# 58 "data//scripts/item_ball_scripts.pory"
	case 0, Common_EventScript_GenerateHiddenItem_3
# 60 "data//scripts/item_ball_scripts.pory"
	case 1, Common_EventScript_GenerateHiddenItem_4
# 62 "data//scripts/item_ball_scripts.pory"
	case 2, Common_EventScript_GenerateHiddenItem_5
# 64 "data//scripts/item_ball_scripts.pory"
	case 3, Common_EventScript_GenerateHiddenItem_6
# 66 "data//scripts/item_ball_scripts.pory"
	case 4, Common_EventScript_GenerateHiddenItem_7
Common_EventScript_GenerateHiddenItem_1:
# 69 "data//scripts/item_ball_scripts.pory"
	setvar VAR_RESULT, 1
	return

Common_EventScript_GenerateHiddenItem_3:
# 59 "data//scripts/item_ball_scripts.pory"
	getrandomitem VAR_0x8008, ITEM_GENERATOR_TRASH
	goto Common_EventScript_GenerateHiddenItem_1

Common_EventScript_GenerateHiddenItem_4:
# 61 "data//scripts/item_ball_scripts.pory"
	getrandomitem VAR_0x8008, ITEM_GENERATOR_TRASH
	goto Common_EventScript_GenerateHiddenItem_1

Common_EventScript_GenerateHiddenItem_5:
# 63 "data//scripts/item_ball_scripts.pory"
	getrandomitem VAR_0x8008, ITEM_GENERATOR_TRASH
	goto Common_EventScript_GenerateHiddenItem_1

Common_EventScript_GenerateHiddenItem_6:
# 65 "data//scripts/item_ball_scripts.pory"
	getrandomitem VAR_0x8008, ITEM_GENERATOR_TREASURE
	goto Common_EventScript_GenerateHiddenItem_1

Common_EventScript_GenerateHiddenItem_7:
# 67 "data//scripts/item_ball_scripts.pory"
	getrandomitem VAR_0x8008, ITEM_GENERATOR_MINT
	goto Common_EventScript_GenerateHiddenItem_1

