


#include "AbilitySystem/HorrorAttributeSet.h"
#include "Net/UnrealNetwork.h"

UHorrorAttributeSet::UHorrorAttributeSet()
{
	InitHealth(50.f);
	InitMaxHealth(100.f);
	InitStamina(50.f);
	InitMaxStamina(100.f);
	
}

void UHorrorAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UHorrorAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UHorrorAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UHorrorAttributeSet, Stamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UHorrorAttributeSet, MaxStamina, COND_None, REPNOTIFY_Always);

}

void UHorrorAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHorrorAttributeSet, Health, OldHealth);
}

void UHorrorAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHorrorAttributeSet, MaxHealth, OldMaxHealth);
}

void UHorrorAttributeSet::OnRep_Stamina(const FGameplayAttributeData& OldStamina) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHorrorAttributeSet, Stamina, OldStamina);
}

void UHorrorAttributeSet::OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHorrorAttributeSet, MaxStamina, OldMaxStamina);

}
