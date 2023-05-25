// Fill out your copyright notice in the Description page of Project Settings.


#include "Warrior.h"
#include "Components/InputComponent.h"
#include "GameFramework/PlayerInput.h"
#include "Components/CapsuleComponent.h"
#include "LearningGameModeBase.h"

// Sets default values
AWarrior::AWarrior()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	lastInput = FVector2D::ZeroVector;
}

// Called when the game starts or when spawned
void AWarrior::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWarrior::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float len = lastInput.Size();
	if (len > 1.0f) {
		lastInput /= len;
	}
	AddMovementInput(GetActorForwardVector(), lastInput.Y);
	AddMovementInput(GetActorRightVector(), lastInput.X);

	lastInput = FVector2D(0.0f, 0.0f);
}

// Called to bind functionality to input
void AWarrior::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Forward", this, &AWarrior::Forward);
	PlayerInputComponent->BindAxis("Backward", this, &AWarrior::Backward);
	PlayerInputComponent->BindAxis("Left", this, &AWarrior::Left);
	PlayerInputComponent->BindAxis("Right", this, &AWarrior::Right);
	
	//FInputAxisKeyMapping RightSecondary("RightSecondary", EKeys::L, 5.0f);
	//FInputActionKeyMapping JumpSecondary("JumpSecondary", EKeys::J, 0, 0, 0, 0);
	//auto Input = GetWorld()->GetFirstPlayerController()->PlayerInput;
	//Input->AddAxisMapping(RightSecondary);
	//Input->AddActionMapping(JumpSecondary);
	//UPlayerInput::AddEngineDefinedAxisMapping(RightSecondary);
	//UPlayerInput::AddEngineDefinedActionMapping(JumpSecondary);

	PlayerInputComponent->BindAction("Jump", IE_Pressed,this, &AWarrior::Jump);

	auto GameMode = Cast<ALearningGameModeBase>(GetWorld()->GetAuthGameMode());
	auto Func = &ALearningGameModeBase::ButtonClicked;;
	if (GameMode && Func) {
		PlayerInputComponent->BindAction("HotKey_UIButton_Spell", IE_Pressed, GameMode, Func);
	}
}

void AWarrior::Forward(float amount) {
	lastInput.Y += amount;
}

void AWarrior::Backward(float amount) {
	lastInput.Y -= amount;
}

void AWarrior::Left(float amount) {
	lastInput.X -= amount;
}

void AWarrior::Right(float amount) {
	lastInput.X += amount;
}

void AWarrior::OnOverlapBegin_Implementation(UPrimitiveComponent* Comp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	UE_LOG(LogTemp, Warning, TEXT("Overlaps warrior began"));
}

void AWarrior::OnOverlapEnd_Implementation(UPrimitiveComponent* Comp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
	UE_LOG(LogTemp, Warning, TEXT("Overlaps warrior ended"));
}

void AWarrior::PostInitializeComponents() {
	Super::PostInitializeComponents();
	if (RootComponent) {
		GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AWarrior::OnOverlapBegin);
		GetCapsuleComponent()->OnComponentEndOverlap.AddDynamic(this, &AWarrior::OnOverlapEnd);
	}
}