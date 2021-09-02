// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Storage/CozyStorageWidgetSlot.h"

void UCozyStorageWidgetSlot::SetItemData(const FCozyStorageItemData& InData)
{
	Data = InData;

	if(ItemIcon != nullptr)
	{
		ItemIcon->SetBrushFromTexture(Data.ItemData.ItemIcon);
	}

	if(ItemQuantity != nullptr)
	{
		const FString QuantityTextString = FString::Printf(TEXT("%d"), Data.Quantity);
		const FText QuantityText = FText::AsCultureInvariant(QuantityTextString);
		ItemQuantity->SetText(QuantityText);
	}
}
