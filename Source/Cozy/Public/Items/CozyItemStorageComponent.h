#pragma once
#include "CoreMinimal.h"
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
	
	
private:
	UPROPERTY()
	TMap<FName, FCozyStorageItemData> Storage;
};
