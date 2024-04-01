


#include "Character/PlayerCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/HorrorPlayerState.h"

APlayerCharacter::APlayerCharacter()
{
	
}

void APlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	//For server
	InitAbilityActorInfo();
	
}

void APlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	//For client
	InitAbilityActorInfo();
	
}

void APlayerCharacter::InitAbilityActorInfo()
{
	AHorrorPlayerState* HorrorPlayerState = GetPlayerState<AHorrorPlayerState>();
	check(HorrorPlayerState);
	HorrorPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(HorrorPlayerState, this);
	AbilitySystemComponent = HorrorPlayerState->GetAbilitySystemComponent();
	AttributeSet = HorrorPlayerState->GetAttributeSet();
}
