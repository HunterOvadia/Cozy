#pragma once
#include "CozyItemData.h"
#include "CozyItemStorageComponent.generated.h"


USTRUCT(BlueprintType)
struct COZY_API FCozyStorageItemData
{
	GENERATED_BODY()

public:	
	UPROPERTY(BlueprintReadWrite)
	FCozyItemData ItemData;

	UPROPERTY(BlueprintReadWrite)
	int32 Quantity;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnItemAddedDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnItemRemovedDelegate);


UCLASS(BlueprintType)
class COZY_API UCozyItemStorageComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:
	UCozyItemStorageComponent();

	UFUNCTION(BlueprintCallable)
	const TMap<FName, FCozyStorageItemData>& GetStorage() const { return Storage; }

	UFUNCTION(BlueprintCallable)
	void AddItem(const FName& ItemID, int32 Quantity = 1);

	UFUNCTION(BlueprintCallable)
	void RemoveItem(const FName& ItemID, int32 Quantity = 1);

public:
	FOnItemAddedDelegate OnItemAdded;
	FOnItemRemovedDelegate OnItemRemoved;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int32 MaxSlots;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	int32 UsedSlots;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int32 SlotsPerRow;
	
private:
	UPROPERTY()
	TMap<FName, FCozyStorageItemData> Storage;
};
