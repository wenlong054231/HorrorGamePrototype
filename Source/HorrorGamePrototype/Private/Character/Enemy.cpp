


#include "Character/Enemy.h"

#include "AbilitySystem/HorrorAbilitySystemComponent.h"
#include "AbilitySystem/HorrorAttributeSet.h"

AEnemy::AEnemy()
{
	AbilitySystemComponent = CreateDefaultSubobject<UHorrorAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UHorrorAttributeSet>("AttributeSet");
}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}
