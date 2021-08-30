#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Storage/CozyStorageWidget.h"
#include "CozyPlayerMainWidget.generated.h"


UCLASS()
class COZY_API UCozyPlayerMainWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;
	
public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UCozyStorageWidget* StorageWidget;
};
