#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CozyItemData.generated.h"

USTRUCT(BlueprintType)
struct FCozyItemData : public FTableRowBase
{
	GENERATED_BODY()
	
public:
	FCozyItemData()
	{
		ItemIcon = nullptr;
	}

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText Name;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText Description;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UTexture2D* ItemIcon;
};