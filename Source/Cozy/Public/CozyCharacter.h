#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Items/CozyItemStorageComponent.h"
#include "CozyCharacter.generated.h"

UCLASS(config=Game)
class ACozyCharacter : public ACharacter
{
	GENERATED_BODY()
	
public:
	ACozyCharacter();
	class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	UCozyItemStorageComponent* GetInventory() const { return InventoryStorage; }

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void TurnAtRate(float Rate);
	void LookUpAtRate(float Rate);
	
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCozyItemStorageComponent* InventoryStorage;
};

