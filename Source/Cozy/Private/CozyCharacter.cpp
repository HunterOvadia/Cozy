#include "CozyCharacter.h"

#include "Blueprint/UserWidget.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

ACozyCharacter::ACozyCharacter()
{
	if(UCapsuleComponent* Capsule = GetCapsuleComponent())
	{
		Capsule->InitCapsuleSize(42.f, 96.0f);
	}

	if(UCharacterMovementComponent* Movement = GetCharacterMovement())
	{
		Movement->bOrientRotationToMovement = true; 
		Movement->RotationRate = FRotator(0.0f, 540.0f, 0.0f); 
		Movement->JumpZVelocity = 600.f;
		Movement->AirControl = 0.2f;
	}

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	if(FollowCamera != nullptr)
	{
		FollowCamera->SetupAttachment(RootComponent, USpringArmComponent::SocketName);
		FollowCamera->bUsePawnControlRotation = true;
	}

	if(USkeletalMeshComponent* MyMesh = GetMesh())
	{
		MyMesh->SetupAttachment(FollowCamera);
		MyMesh->SetOwnerNoSee(true);
	}

	InventoryStorage = CreateDefaultSubobject<UCozyItemStorageComponent>(TEXT("Inventory"));
	
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;
}

void ACozyCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAction("Inventory", IE_Pressed, this, &ACozyCharacter::ToggleInventory);

	
	PlayerInputComponent->BindAxis("MoveForward", this, &ACozyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACozyCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ACozyCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ACozyCharacter::LookUpAtRate);
}

void ACozyCharacter::BeginPlay()
{
	Super::BeginPlay();

	MainPlayerWidget = CreateWidget<UCozyPlayerMainWidget>(GetWorld(), MainWidgetClass);
	if(MainPlayerWidget != nullptr)
	{
		MainPlayerWidget->AddToViewport();
	}
}

void ACozyCharacter::TurnAtRate(const float Rate)
{
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ACozyCharacter::LookUpAtRate(const float Rate)
{
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ACozyCharacter::ToggleInventory()
{
	if(MainPlayerWidget != nullptr)
	{
		if(UCozyStorageWidget* Storage = MainPlayerWidget->StorageWidget)
		{
			if(Storage->GetVisibility() == ESlateVisibility::Collapsed)
			{
				Storage->InitializeStorage(InventoryStorage);
				Storage->SetVisibility(ESlateVisibility::Visible);
			}
			else
			{
				Storage->SetVisibility(ESlateVisibility::Collapsed);
				Storage->ResetStorage();
			}
		}
	}
}

void ACozyCharacter::MoveForward(const float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ACozyCharacter::MoveRight(const float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}
