


#include "UI/HUD/HorrorHUD.h"

#include "UI/Widget/HorrorUserWidget.h"

void AHorrorHUD::BeginPlay()
{
	Super::BeginPlay();
	//
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	Widget->AddToViewport();
}
