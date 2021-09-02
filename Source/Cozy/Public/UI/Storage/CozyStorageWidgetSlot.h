#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Items/CozyItemStorageComponent.h"
#include "CozyStorageWidgetSlot.generated.h"

UCLASS()
class COZY_API UCozyStorageWidgetSlot : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetItemData(const FCozyStorageItemData& InData);
	
public:
	FCozyStorageItemData Data;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ItemIcon;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* ItemQuantity;
};
