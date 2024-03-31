


#include "Player/HorrorPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

AHorrorPlayerController::AHorrorPlayerController()
{
	bReplicates = true;
}

void AHorrorPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(HorrorContext);
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(HorrorContext, 0);

	bShowMouseCursor = false;

	const FInputModeGameOnly InputModeData;
	SetInputMode(InputModeData);
}

void AHorrorPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(CameraRotationAction, ETriggerEvent::Triggered, this, &AHorrorPlayerController::CameraRotation);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AHorrorPlayerController::Move);

}

void AHorrorPlayerController::CameraRotation(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	
	// Scale the input values to control rotation speed
	constexpr float Sensitivity = 2.0f; // Adjust sensitivity as needed
	const float YawInput = InputAxisVector.X * Sensitivity;
	const float PitchInput = InputAxisVector.Y * Sensitivity;

	// Get the current rotation of the player's controller
	FRotator NewRotation = GetControlRotation();

	// Update the yaw (horizontal rotation) based on mouse movement on the X-axis
	NewRotation.Yaw += YawInput;

	// Update the pitch (vertical rotation) based on mouse movement on the Y-axis
	NewRotation.Pitch = FMath::Clamp(NewRotation.Pitch - PitchInput, -80.0f, 80.0f); // Clamp the pitch to prevent flipping

	SetControlRotation(NewRotation);
}

void AHorrorPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();

	if(APawn* ControlledPawn = GetPawn<APawn>())
	{
		const FRotator Rotation = ControlledPawn->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);

	}
}
