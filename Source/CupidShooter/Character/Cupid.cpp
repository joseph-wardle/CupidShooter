#include "Character/Cupid.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

ACupid::ACupid()
{
    PrimaryActorTick.bCanEverTick = true;

    // Attach camera to the character mesh (first person)
    FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
    FirstPersonCamera->SetupAttachment(GetMesh(), FName("head")); // or RootComponent for now
    FirstPersonCamera->bUsePawnControlRotation = true;
}

void ACupid::BeginPlay()
{
    Super::BeginPlay();

    // Add the mapping context
    if (APlayerController* PC = Cast<APlayerController>(GetController()))
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
            ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
        {
            Subsystem->AddMappingContext(ControlsMappingContext, 0);
        }
    }
}

void ACupid::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ACupid::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        EIC->BindAction(JumpAction, ETriggerEvent::Started,  this, &ACharacter::Jump);
        EIC->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
        EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACupid::Move);
        EIC->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACupid::Look);
    }
}

void ACupid::Move(const FInputActionValue& Value)
{
    const FVector2D Axis = Value.Get<FVector2D>();
    if (Controller)
    {
        AddMovementInput(GetActorForwardVector(), Axis.Y);
        AddMovementInput(GetActorRightVector(),   Axis.X);
    }
}

void ACupid::Look(const FInputActionValue& Value)
{
    const FVector2D Axis = Value.Get<FVector2D>();
    if (Controller)
    {
        AddControllerYawInput(Axis.X);
        AddControllerPitchInput(Axis.Y);
    }
}