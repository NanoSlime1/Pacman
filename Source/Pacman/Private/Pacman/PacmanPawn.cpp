// Fill out your copyright notice in the Description page of Project Settings.


#include "PacmanPawn.h"

#include "Foodie.h"
#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
APacmanPawn::APacmanPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>("FloatingPawnMovement");

}

// Called when the game starts or when spawned
void APacmanPawn::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &APacmanPawn::OnOverlapBegin);
}

void APacmanPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(!Frozen)
	{
		AddMovementInput(GetActorForwardVector());
	}

}

void APacmanPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APacmanPawn::SetDirection(const FVector Direction)
{
	if(Direction == FVector::UpVector)
	{
		SetActorRotation(FRotator(0, 270, 0));
	}
	else if(Direction == FVector::DownVector)
	{
		SetActorRotation(FRotator(0, 90, 0));
	}
	else if(Direction == FVector::RightVector)
	{
		SetActorRotation(FRotator(0, 0, 0));
	}
	else if(Direction == FVector::LeftVector)
	{
		SetActorRotation(FRotator(0, 180, 180));
	}
}

void APacmanPawn::PowerUp()
{
	FloatingPawnMovement->Acceleration = PowerUpAcceleration;
	FloatingPawnMovement->MaxSpeed = PowerUpSpeed;
	
	GetWorldTimerManager().SetTimer(PowerUpTimerHandle, this, &APacmanPawn::ToNormalSpeedAndAcceleration, PowerUpDuration, false);
}

void APacmanPawn::OnOverlapBegin(AActor* PlayerActor, AActor* OtherActor)
{
	const auto Foodie = Cast<AFoodie>(OtherActor);
	 
	if(Foodie)
	{
		Foodie->Consume();
	}
}

void APacmanPawn::ToNormalSpeedAndAcceleration() const
{
	FloatingPawnMovement->Acceleration = NormalAcceleration;
	FloatingPawnMovement->MaxSpeed = NormalSpeed;
}

