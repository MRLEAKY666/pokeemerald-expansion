KiriKiriMountain_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, KiriKiriMountain_OnTransition
	.byte 0

KiriKiriMountain_OnTransition:
	clearflag FLAG_SYS_SAVE_GET
	call KiriKiriMountain_EventScript_ResetWildMons
	end

KiriKiriMountain_EventScript_Snorlax::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SNORLAX, CRY_MODE_ENCOUNTER
	msgbox KiriKiriMountain_Text_Snorlax, MSGBOX_DEFAULT
	delay 10
	waitmoncry
	setwildbattle SPECIES_SNORLAX, 60
	dowildbattle
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

KiriKiriMountain_EventScript_ResetWildMons::
	clearflag FLAG_KIRIKIRI_MOUNTAIN_SNORLAX
	end

KiriKiriMountain_Text_Snorlax:
	.string "Snooooooooo!$"
