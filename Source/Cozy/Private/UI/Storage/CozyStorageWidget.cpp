#include "UI/Storage/CozyStorageWidget.h"

void UCozyStorageWidget::InitializeStorage(UCozyItemStorageComponent* InStorageComponent)
{
    StorageComponent = InStorageComponent;
    if(StorageComponent != nullptr)
    {
        AActor* StorageOwner = StorageComponent->GetOwner();
        if(StorageOwner != nullptr && StorageNameText != nullptr)
        {
            const FString StorageNameString = FString::Printf(TEXT("%s's Storage"), *StorageComponent->GetOwner()->GetName());
            const FText StorageName = FText::AsCultureInvariant(StorageNameString);
            StorageNameText->SetText(StorageName);
        }
    }
}
