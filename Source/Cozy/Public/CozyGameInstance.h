#pragma once
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Engine/DataTable.h"
#include "Items/CozyItemData.h"
#include "CozyGameInstance.generated.h"

UCLASS()
class COZY_API UCozyGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	FCozyItemData GetItem(const FName& ItemID) const;

public:
	UPROPERTY(EditDefaultsOnly)
	UDataTable* ItemDatabase;
};
