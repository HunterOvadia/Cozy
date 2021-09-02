#pragma once
#include "CozyItemData.h"
#include "CozyItemStorageComponent.generated.h"


USTRUCT(BlueprintType)
struct COZY_API FCozyStorageItemData
{
	GENERATED_BODY()

public:
	FCozyStorageItemData()
	{
		ItemID = "";
		ItemData = FCozyItemData();
		Quantity = 0;
	}
public:
	UPROPERTY(BlueprintReadWrite)
	FName ItemID;
	
	UPROPERTY(BlueprintReadWrite)
	FCozyItemData ItemData;

	UPROPERTY(BlueprintReadWrite)
	int32 Quantity;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStorageItemUpdated, const int32, Index);


UCLASS(BlueprintType)
class COZY_API UCozyItemStorageComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:
	UCozyItemStorageComponent();
	
	UFUNCTION(BlueprintCallable)
	TArray<FCozyStorageItemData>& GetStorage() { return Storage; }

	UFUNCTION(BlueprintCallable)
	void AddItem(const FName& ItemID, int32 Quantity = 1);

	UFUNCTION(BlueprintCallable)
	void RemoveItem(const FName& ItemID, int32 Quantity = 1);

public:
	UPROPERTY()
	FOnStorageItemUpdated OnItemUpdated;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int32 MaxSlots;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	int32 UsedSlots;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int32 SlotsPerRow;
	
private:
	UPROPERTY()
	TArray<FCozyStorageItemData> Storage;
};
