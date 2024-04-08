

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HorrorEffectActor.generated.h"

UCLASS()
class HORRORGAMEPROTOTYPE_API AHorrorEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AHorrorEffectActor();

protected:
	virtual void BeginPlay() override;

public:	

};
