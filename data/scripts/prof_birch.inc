ProfBirch_EventScript_UpdateLocation::
	goto_if_eq VAR_PETALBURG_GYM_STATE, 0, Common_EventScript_NopReturn
	goto_if_set FLAG_SYS_GAME_CLEAR, ProfBirch_EventScript_MoveToLab
	call_if_eq VAR_BIRCH_STATE, 0, ProfBirch_EventScript_MoveToLab
	call_if_eq VAR_BIRCH_STATE, 1, ProfBirch_EventScript_MoveToLab
	call_if_eq VAR_BIRCH_STATE, 2, ProfBirch_EventScript_MoveToRoute101
	call_if_eq VAR_BIRCH_STATE, 3, ProfBirch_EventScript_MoveToRoute101
	call_if_eq VAR_BIRCH_STATE, 4, ProfBirch_EventScript_MoveToRoute103
	call_if_eq VAR_BIRCH_STATE, 5, ProfBirch_EventScript_MoveToRoute103
	call_if_eq VAR_BIRCH_STATE, 6, ProfBirch_EventScript_MoveToLab
	call_if_eq VAR_BIRCH_STATE, 7, ProfBirch_EventScript_MoveToLab
	return

ProfBirch_EventScript_MoveToLab::
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380
	setflag FLAG_HIDE_ROUTE_101_BIRCH
	setflag FLAG_HIDE_ROUTE_103_BIRCH
	return

ProfBirch_EventScript_MoveToRoute101::
	clearflag FLAG_HIDE_ROUTE_101_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380
	setflag FLAG_HIDE_ROUTE_103_BIRCH
	return

ProfBirch_EventScript_MoveToRoute103::
	clearflag FLAG_HIDE_ROUTE_103_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380
	return

ProfBirch_EventScript_RatePokedexOrRegister::
	lock
	faceplayer
	goto_if_unset FLAG_HAS_MATCH_CALL, ProfBirch_EventScript_AskRatePokedex
	goto_if_unset FLAG_ENABLE_PROF_BIRCH_MATCH_CALL, EventScript_RegisterProfBirch

ProfBirch_EventScript_AskRatePokedex::
	msgbox gBirchDexRatingText_AreYouCurious, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ProfBirch_EventScript_DeclineRating
	call ProfBirch_EventScript_RatePokedex
	release
	end

ProfBirch_EventScript_DeclineRating::
	msgbox gBirchDexRatingText_Cancel, MSGBOX_DEFAULT
	release
	end

ProfBirch_EventScript_ShowRatingMessage::
	copyvar VAR_0x8004, VAR_0x8009
	special ShowPokedexRatingMessage
	waitmessage
	waitbuttonpress
	return

ProfBirch_EventScript_RatePokedex::
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, ScriptGetPokedexInfo
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	copyvar VAR_0x800A, VAR_RESULT
	buffernumberstring STR_VAR_1, VAR_0x8008  @ Num Hoenn seen
	buffernumberstring STR_VAR_2, VAR_0x8009  @ Num Hoenn caught
	msgbox gBirchDexRatingText_SoYouveSeenAndCaught, MSGBOX_DEFAULT
	call ProfBirch_EventScript_ShowRatingMessage
	goto_if_eq VAR_0x800A, 0, Common_EventScript_NopReturn  @ National dex not enabled
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, ScriptGetPokedexInfo
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	buffernumberstring STR_VAR_1, VAR_0x8008  @ Num National seen
	buffernumberstring STR_VAR_2, VAR_0x8009  @ Num National caught
	msgbox gBirchDexRatingText_OnANationwideBasis, MSGBOX_DEFAULT
	@ goto_if_set FLAG_LATIOS_OR_LATIAS_ROAMING ProfBirch_EventScript_LatiSpeech
	waitmessage
	return

ProfBirch_EventScript_LatiSpeech::
	msgbox gBirchDexRatingText_LatiSpeech, MSGBOX_DEFAULT
	call_if_eq VAR_ROAMER_POKEMON, 0, ProfBirch_EventScript_BirchIfLatias
	call_if_ne VAR_ROAMER_POKEMON, 0, ProfBirch_EventScript_BirchIfLatios 
	return

ProfBirch_EventScript_BirchIfLatios::
	showmonpic SPECIES_LATIOS, 0, 0
	setseenmon SPECIES_LATIOS
	msgbox gBirchDexRatingText_LatiosSpeech, MSGBOX_DEFAULT
	waitmessage
	hidemonpic
	call_if_eq VAR_ROAMING_LATI_STATE, 2, ProfBirch_EventScript_TryBirchResetLati
	call_if_eq VAR_ROAMING_LATI_STATE, 1, ProfBirch_EventScript_TryGiveEonTicketLatios
	goto_if_eq VAR_BIRCH_LAB_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_PokemonAwait
	return

ProfBirch_EventScript_BirchIfLatias::
	showmonpic SPECIES_LATIAS, 0, 0
	setseenmon SPECIES_LATIAS
	msgbox gBirchDexRatingText_LatiasSpeech, MSGBOX_DEFAULT
	waitmessage
	hidemonpic
	call_if_eq VAR_ROAMING_LATI_STATE, 2, ProfBirch_EventScript_TryBirchResetLati
	call_if_eq VAR_ROAMING_LATI_STATE, 1, ProfBirch_EventScript_TryGiveEonTicketLatias
	goto_if_eq VAR_BIRCH_LAB_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_PokemonAwait
	return

ProfBirch_EventScript_TryGiveEonTicketLatios::
	goto_if_unset FLAG_RECEIVED_EON_TICKET, ProfBirch_EventScript_GiveEonTicketLatios
	return

ProfBirch_EventScript_GiveEonTicketLatios::
	msgbox gBirchDexRatingText_CaughtLatios, MSGBOX_DEFAULT
	giveitem ITEM_EON_TICKET
	setflag FLAG_RECEIVED_EON_TICKET
	setflag FLAG_ENABLE_SHIP_SOUTHERN_ISLAND
	@ setvar VAR_DISTRIBUTE_EON_TICKET, 0
	msgbox gBirchDexRatingText_AllowSouthernIsland, MSGBOX_DEFAULT
	release
	end

ProfBirch_EventScript_TryGiveEonTicketLatias::
	goto_if_unset FLAG_RECEIVED_EON_TICKET, ProfBirch_EventScript_GiveEonTicketLatias
	return

ProfBirch_EventScript_GiveEonTicketLatias::
	msgbox gBirchDexRatingText_CaughtLatias, MSGBOX_DEFAULT
	giveitem ITEM_EON_TICKET
	setflag FLAG_RECEIVED_EON_TICKET
	setflag FLAG_ENABLE_SHIP_SOUTHERN_ISLAND
	@ setvar VAR_DISTRIBUTE_EON_TICKET, 0
	msgbox gBirchDexRatingText_AllowSouthernIsland, MSGBOX_DEFAULT
	release
	end

ProfBirch_EventScript_TryBirchResetLati::
	setvar VAR_UNUSED_0x8014, 2
	copyvar VAR_0x8004, VAR_ROAMER_POKEMON
	special InitRoamer
	setvar VAR_ROAMING_LATI_STATE, 0
	return
