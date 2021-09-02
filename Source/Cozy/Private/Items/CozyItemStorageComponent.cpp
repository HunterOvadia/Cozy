#include "Items/CozyItemStorageComponent.h"

#include "CozyGameInstance.h"

UCozyItemStorageComponent::UCozyItemStorageComponent()
{
    MaxSlots = 49;
    UsedSlots = 0;
    SlotsPerRow = 7;
}

void UCozyItemStorageComponent::AddItem(const FName& ItemID, const int32 Quantity)
{
    UCozyGameInstance* GI = Cast<UCozyGameInstance>(GetWorld()->GetGameInstance());
    if(!GI)
    {
        return;
    }

    const FCozyItemData& Item = GI->GetItem(ItemID);

    bool bFoundItemToUpdate = false;
    int32 UpdatedIndex = -1;
    for(int Index = 0; Index < Storage.Num(); ++Index)
    {
        FCozyStorageItemData& StorageItemData = Storage[Index];
        if(StorageItemData.ItemID == ItemID)
        {
            StorageItemData.Quantity += Quantity;
            bFoundItemToUpdate = true;
            UpdatedIndex = Index;
            break;
        }
    }
    
    if(!bFoundItemToUpdate && MaxSlots > UsedSlots)
    {
        FCozyStorageItemData ItemData;
        ItemData.ItemID = ItemID;
        ItemData.ItemData = Item;
        ItemData.Quantity = Quantity;

        for(int Index = 0; Index < Storage.Num(); ++Index)
        {
            FCozyStorageItemData& StorageItemData = Storage[Index];
            if(StorageItemData.Quantity == 0)
            {
                StorageItemData = ItemData;
                UpdatedIndex = Index;
                break;
            }
        }
        
        ++UsedSlots;
    }

    if(UpdatedIndex > -1)
    {
        OnItemUpdated.Broadcast(UpdatedIndex);
    }
}

void UCozyItemStorageComponent::RemoveItem(const FName& ItemID, int32 Quantity)
{
    UCozyGameInstance* GI = Cast<UCozyGameInstance>(GetWorld()->GetGameInstance());
    if(!GI)
    {
        return;
    }

    int32 IndexToRemove = -1;
    for(int32 Index = 0; Index < Storage.Num(); ++Index)
    {
        FCozyStorageItemData& StorageItem = Storage[Index];
        if(StorageItem.ItemID == ItemID)
        {
            if(StorageItem.Quantity > Quantity)
            {
                StorageItem.Quantity -= Quantity;
            }
            else
            {
                StorageItem = FCozyStorageItemData();
            }

            IndexToRemove = Index;
            break;
        }
    }

    if(IndexToRemove > -1)
    {
        OnItemUpdated.Broadcast(IndexToRemove);
    }
}
