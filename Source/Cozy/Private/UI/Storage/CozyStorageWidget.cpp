#include "UI/Storage/CozyStorageWidget.h"
#include "UI/Storage/CozyStorageWidgetSlot.h"

void UCozyStorageWidget::InitializeStorage(UCozyItemStorageComponent* InStorageComponent)
{
    StorageComponent = InStorageComponent;
    if(StorageComponent != nullptr)
    {
        AActor* StorageOwner = StorageComponent->GetOwner();
        if(StorageOwner != nullptr && StorageNameText != nullptr)
        {
            const FString StorageNameString = FString::Printf(TEXT("%s's Storage"), *StorageOwner->GetName());
            const FText StorageName = FText::AsCultureInvariant(StorageNameString);
            StorageNameText->SetText(StorageName);
        }

        if(StorageAvailabilityText != nullptr)
        {
            const FString AvailableTextString = FString::Printf(TEXT("%d/%d"), StorageComponent->UsedSlots, StorageComponent->MaxSlots);
            const FText AvailableText = FText::AsCultureInvariant(AvailableTextString);
            StorageAvailabilityText->SetText(AvailableText);
        }

        if(StorageGrid != nullptr)
        {
            int CurrentColumn = 0;
            for(int Index = 0; Index < StorageComponent->MaxSlots; ++Index)
            {
                UCozyStorageWidgetSlot* NewSlot = CreateWidget<UCozyStorageWidgetSlot>(this, WidgetSlotClass);
                if(NewSlot != nullptr)
                {
                    const int Modulo = (StorageComponent->SlotsPerRow + 1);
                    const int CurrentRow = (Index % Modulo);
                    if(CurrentRow == 0 && Index > 0)
                    {
                        ++CurrentColumn;
                    }
                    
                    StorageGrid->AddChildToUniformGrid(NewSlot, CurrentColumn, CurrentRow);
                }
            }
        }
    }
}

void UCozyStorageWidget::ResetStorage()
{
    if(StorageGrid != nullptr)
    {
        StorageGrid->ClearChildren();
    }
}
