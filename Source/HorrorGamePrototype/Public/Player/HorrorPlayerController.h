

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "HorrorPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

struct FInputActionValue;
/**
 * 
 */
UCLASS()
class HORRORGAMEPROTOTYPE_API AHorrorPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AHorrorPlayerController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MovementSpeed = 1.0f;
	bool bIsSprinting = false;


protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> HorrorContext;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> CameraRotationAction;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> SprintAction;
	
	void CameraRotation(const FInputActionValue& InputActionValue);
	void Move(const FInputActionValue& InputActionValue);
	
	void SetMaxWalkSpeed(float NewMaxWalkSpeed);
	void Sprint();
	void SprintEnd();
};
