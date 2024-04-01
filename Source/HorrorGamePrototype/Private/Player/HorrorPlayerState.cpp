


#include "Player/HorrorPlayerState.h"

#include "AbilitySystem/HorrorAbilitySystemComponent.h"
#include "AbilitySystem/HorrorAttributeSet.h"

AHorrorPlayerState::AHorrorPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UHorrorAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
	AttributeSet = CreateDefaultSubobject<UHorrorAttributeSet>("AttributeSet");
	
	//update client frequency to sync with server
	NetUpdateFrequency = 100.f;
	
}

UAbilitySystemComponent* AHorrorPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
