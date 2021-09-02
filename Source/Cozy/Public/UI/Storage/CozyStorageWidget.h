#pragma once

#include "CozyStorageWidgetSlot.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/UniformGridPanel.h"
#include "Items/CozyItemStorageComponent.h"
#include "CozyStorageWidget.generated.h"

UCLASS()
class COZY_API UCozyStorageWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void InitializeStorage(UCozyItemStorageComponent* InStorageComponent);

	UFUNCTION()
	void OnItemUpdated(const int32 Index);


private:
	void UpdateAvailabilityText() const;
	
public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* StorageNameText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* StorageAvailabilityText;
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UUniformGridPanel* StorageGrid;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UCozyStorageWidgetSlot> WidgetSlotClass;
	
private:
	UPROPERTY(Transient)
	UCozyItemStorageComponent* StorageComponent;
};