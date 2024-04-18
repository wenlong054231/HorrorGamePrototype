

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "HorrorHUD.generated.h"

class UHorrorUserWidget;
/**
 * 
 */
UCLASS()
class HORRORGAMEPROTOTYPE_API AHorrorHUD : public AHUD
{
	GENERATED_BODY()
public:
	UPROPERTY()
	TObjectPtr<UHorrorUserWidget> OverlayWidget;

protected:
	virtual void BeginPlay() override;
	
private:

	UPROPERTY(EditAnywhere)
	TSubclassOf<UHorrorUserWidget> OverlayWidgetClass;
};
