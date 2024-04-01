

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "Enemy.generated.h"

/**
 * 
 */
UCLASS()
class HORRORGAMEPROTOTYPE_API AEnemy : public ACharacterBase
{
	GENERATED_BODY()

public:
	AEnemy();

protected:
	virtual void BeginPlay() override;
};
