#include "UI/CozyPlayerMainWidget.h"

void UCozyPlayerMainWidget::NativeConstruct()
{
    if(StorageWidget != nullptr)
    {
        StorageWidget->SetVisibility(ESlateVisibility::Collapsed);
    }
}
