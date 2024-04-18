


#include "UI/Widget/HorrorUserWidget.h"

void UHorrorUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}

