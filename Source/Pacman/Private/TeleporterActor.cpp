// Fill out your copyright notice in the Description page of Project Settings.


#include "TeleporterActor.h"

#include "PacmanPawn.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"

// Sets default values
ATeleporterActor::ATeleporterActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>("BoxComponent");
	
	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
}

// Called when the game starts or when spawned
void ATeleporterActor::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &ATeleporterActor::OnOverlapBegin);
}

// Called every frame
void ATeleporterActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATeleporterActor::TeleportToTarget(AActor* Actor)
{
	UGameplayStatics::PlaySound2D(this, TeleporterSound);

	Actor->SetActorLocation(Target->SceneComponent->GetComponentLocation());
}

void ATeleporterActor::OnOverlapBegin(AActor* TeleporterActor, AActor* OtherActor)
{
	if(OtherActor->IsA(APacmanPawn::StaticClass()))
	{
		GetWorldTimerManager().SetTimerForNextTick([OtherActor, this]()//
		{
			TeleportToTarget(OtherActor);
		});
	}
}

