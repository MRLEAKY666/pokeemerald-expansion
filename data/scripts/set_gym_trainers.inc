Common_EventScript_SetGymTrainers::
	switch VAR_0x8008
	case 1, RustboroCity_Gym_SetGymTrainers
	case 2, DewfordTown_Gym_SetGymTrainers
	case 3, MauvilleCity_Gym_SetGymTrainers
	case 4, LavaridgeTown_Gym_SetGymTrainers
	case 5, PetalburgCity_Gym_SetGymTrainers
	case 6, FortreeCity_Gym_SetGymTrainers
	case 7, MossdeepCity_Gym_SetGymTrainers
	case 8, SootopolisCity_Gym_SetGymTrainers
	end

Common_EventScript_ResetGymTrainers::
	switch VAR_0x8008
	case 1, RustboroCity_Gym_ResetGymTrainers
	case 2, DewfordTown_Gym_ResetGymTrainers
	case 3, MauvilleCity_Gym_ResetGymTrainers
	case 4, LavaridgeTown_Gym_ResetGymTrainers
	case 5, PetalburgCity_Gym_ResetGymTrainers
	case 6, FortreeCity_Gym_ResetGymTrainers
	case 7, MossdeepCity_Gym_ResetGymTrainers
	case 8, SootopolisCity_Gym_ResetGymTrainers
	end

RustboroCity_Gym_SetGymTrainers::
	settrainerflag TRAINER_JOSH
	settrainerflag TRAINER_TOMMY
	settrainerflag TRAINER_MARC
	return

DewfordTown_Gym_SetGymTrainers::
	settrainerflag TRAINER_TAKAO
	settrainerflag TRAINER_JOCELYN
	settrainerflag TRAINER_LAURA
	settrainerflag TRAINER_BRENDEN
	settrainerflag TRAINER_CRISTIAN
	settrainerflag TRAINER_LILITH
	return

MauvilleCity_Gym_SetGymTrainers::
	settrainerflag TRAINER_KIRK
	settrainerflag TRAINER_SHAWN
	settrainerflag TRAINER_BEN
	settrainerflag TRAINER_VIVIAN
	settrainerflag TRAINER_ANGELO
	return

LavaridgeTown_Gym_SetGymTrainers::
	settrainerflag TRAINER_COLE
	settrainerflag TRAINER_AXLE
	settrainerflag TRAINER_KEEGAN
	settrainerflag TRAINER_GERALD
	settrainerflag TRAINER_DANIELLE
	settrainerflag TRAINER_JACE
	settrainerflag TRAINER_JEFF
	settrainerflag TRAINER_ELI
	return

PetalburgCity_Gym_SetGymTrainers::
	settrainerflag TRAINER_RANDALL
	settrainerflag TRAINER_PARKER
	settrainerflag TRAINER_GEORGE
	settrainerflag TRAINER_BERKE
	settrainerflag TRAINER_MARY
	settrainerflag TRAINER_ALEXIA
	settrainerflag TRAINER_JODY
	return

FortreeCity_Gym_SetGymTrainers::
	settrainerflag TRAINER_JARED
	settrainerflag TRAINER_FLINT
	settrainerflag TRAINER_ASHLEY
	settrainerflag TRAINER_EDWARDO
	settrainerflag TRAINER_HUMBERTO
	settrainerflag TRAINER_DARIUS
	return

MossdeepCity_Gym_SetGymTrainers::
	settrainerflag TRAINER_PRESTON
	settrainerflag TRAINER_VIRGIL
	settrainerflag TRAINER_BLAKE
	settrainerflag TRAINER_HANNAH
	settrainerflag TRAINER_SAMANTHA
	settrainerflag TRAINER_MAURA
	settrainerflag TRAINER_SYLVIA
	settrainerflag TRAINER_NATE
	settrainerflag TRAINER_KATHLEEN
	settrainerflag TRAINER_CLIFFORD
	settrainerflag TRAINER_MACEY
	settrainerflag TRAINER_NICHOLAS
	return

SootopolisCity_Gym_SetGymTrainers::
	settrainerflag TRAINER_ANDREA
	settrainerflag TRAINER_CRISSY
	settrainerflag TRAINER_BRIANNA
	settrainerflag TRAINER_CONNIE
	settrainerflag TRAINER_BRIDGET
	settrainerflag TRAINER_OLIVIA
	settrainerflag TRAINER_TIFFANY
	settrainerflag TRAINER_BETHANY
	settrainerflag TRAINER_ANNIKA
	settrainerflag TRAINER_DAPHNE
	return

RustboroCity_Gym_ResetGymTrainers::
	cleartrainerflag TRAINER_JOSH
	cleartrainerflag TRAINER_TOMMY
	cleartrainerflag TRAINER_MARC
	return

DewfordTown_Gym_ResetGymTrainers::
	cleartrainerflag TRAINER_TAKAO
	cleartrainerflag TRAINER_JOCELYN
	cleartrainerflag TRAINER_LAURA
	cleartrainerflag TRAINER_BRENDEN
	cleartrainerflag TRAINER_CRISTIAN
	cleartrainerflag TRAINER_LILITH
	return

MauvilleCity_Gym_ResetGymTrainers::
	cleartrainerflag TRAINER_KIRK
	cleartrainerflag TRAINER_SHAWN
	cleartrainerflag TRAINER_BEN
	cleartrainerflag TRAINER_VIVIAN
	cleartrainerflag TRAINER_ANGELO
	return

LavaridgeTown_Gym_ResetGymTrainers::
	cleartrainerflag TRAINER_COLE
	cleartrainerflag TRAINER_AXLE
	cleartrainerflag TRAINER_KEEGAN
	cleartrainerflag TRAINER_GERALD
	cleartrainerflag TRAINER_DANIELLE
	cleartrainerflag TRAINER_JACE
	cleartrainerflag TRAINER_JEFF
	cleartrainerflag TRAINER_ELI
	return

PetalburgCity_Gym_ResetGymTrainers::
	cleartrainerflag TRAINER_RANDALL
	cleartrainerflag TRAINER_PARKER
	cleartrainerflag TRAINER_GEORGE
	cleartrainerflag TRAINER_BERKE
	cleartrainerflag TRAINER_MARY
	cleartrainerflag TRAINER_ALEXIA
	cleartrainerflag TRAINER_JODY
	return

FortreeCity_Gym_ResetGymTrainers::
	cleartrainerflag TRAINER_JARED
	cleartrainerflag TRAINER_FLINT
	cleartrainerflag TRAINER_ASHLEY
	cleartrainerflag TRAINER_EDWARDO
	cleartrainerflag TRAINER_HUMBERTO
	cleartrainerflag TRAINER_DARIUS
	return

MossdeepCity_Gym_ResetGymTrainers::
	cleartrainerflag TRAINER_PRESTON
	cleartrainerflag TRAINER_VIRGIL
	cleartrainerflag TRAINER_BLAKE
	cleartrainerflag TRAINER_HANNAH
	cleartrainerflag TRAINER_SAMANTHA
	cleartrainerflag TRAINER_MAURA
	cleartrainerflag TRAINER_SYLVIA
	cleartrainerflag TRAINER_NATE
	cleartrainerflag TRAINER_KATHLEEN
	cleartrainerflag TRAINER_CLIFFORD
	cleartrainerflag TRAINER_MACEY
	cleartrainerflag TRAINER_NICHOLAS
	return

SootopolisCity_Gym_ResetGymTrainers::
	cleartrainerflag TRAINER_ANDREA
	cleartrainerflag TRAINER_CRISSY
	cleartrainerflag TRAINER_BRIANNA
	cleartrainerflag TRAINER_CONNIE
	cleartrainerflag TRAINER_BRIDGET
	cleartrainerflag TRAINER_OLIVIA
	cleartrainerflag TRAINER_TIFFANY
	cleartrainerflag TRAINER_BETHANY
	cleartrainerflag TRAINER_ANNIKA
	cleartrainerflag TRAINER_DAPHNE
	return

