#include "CozyGameInstance.h"

FCozyItemData UCozyGameInstance::GetItem(const FName& ItemID) const
{
    if (ItemDatabase != nullptr)
    {
        FCozyItemData* Item = ItemDatabase->FindRow<FCozyItemData>(ItemID, TEXT("Item Data"), true);
        if(Item != nullptr)
        {
            return *Item;
        }
    }

    return FCozyItemData();
}
