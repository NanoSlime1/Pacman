// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TeleporterActor.generated.h"

class UBoxComponent;
class USoundCue;
UCLASS()
class PACMAN_API ATeleporterActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATeleporterActor();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UBoxComponent* BoxComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USceneComponent* SceneComponent;

public:	
	virtual void Tick(float DeltaTime) override;
	
	void TeleportToTarget(AActor* Actor);
	
	UPROPERTY(EditAnyWhere)
	ATeleporterActor* Target = nullptr;
	
	UPROPERTY(EditAnyWhere)
	USoundCue* TeleporterSound;

	UFUNCTION()
	void OnOverlapBegin(AActor* TeleporterActor, AActor* OtherActor);
	
};
