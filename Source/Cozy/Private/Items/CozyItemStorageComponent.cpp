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
    if(!Storage.Contains(ItemID) && UsedSlots < MaxSlots)
    {
        FCozyStorageItemData ItemData;
        ItemData.ItemData = Item;
        ItemData.Quantity = Quantity;
        
        Storage.Add(ItemID, ItemData);
        ++UsedSlots;
    }
    else
    {
        Storage[ItemID].Quantity += Quantity;
    }
    
    OnItemAdded.Broadcast();
}

void UCozyItemStorageComponent::RemoveItem(const FName& ItemID, int32 Quantity)
{
    UCozyGameInstance* GI = Cast<UCozyGameInstance>(GetWorld()->GetGameInstance());
    if(!GI)
    {
        return;
    }

    if(Storage.Contains(ItemID))
    {
        FCozyStorageItemData& StorageItem = Storage[ItemID];
        if(StorageItem.Quantity > Quantity)
        {
            StorageItem.Quantity -= Quantity;
        }
        else
        {
            Storage.Remove(ItemID);
            --UsedSlots;
        }
    }
    
    OnItemRemoved.Broadcast();    
}
