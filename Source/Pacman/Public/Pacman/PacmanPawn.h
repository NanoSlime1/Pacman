// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PacmanPawn.generated.h"

class UFloatingPawnMovement;
UCLASS()
class PACMAN_API APacmanPawn : public APawn
{
	GENERATED_BODY()

public:
	APacmanPawn();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UFloatingPawnMovement* FloatingPawnMovement;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(BlueprintReadOnly)
	bool Frozen = false;

public:
	void SetDirection(const FVector Direction);
	bool IsFrozen() { return Frozen; }
	void PowerUp();

	UFUNCTION(BlueprintCallable)
	void SetFrozen(bool Value) { Frozen = Value; }

	UPROPERTY(EditDefaultsOnly, Category = "Speed")
	float NormalSpeed;

	UPROPERTY(EditDefaultsOnly, Category = "Speed")
	float NormalAcceleration;

	UPROPERTY(EditDefaultsOnly, Category = "Speed")
	float PowerUpSpeed;

	UPROPERTY(EditDefaultsOnly, Category = "Speed")
	float PowerUpAcceleration;

	UPROPERTY(EditDefaultsOnly, Category = "Speed")
	float PowerUpDuration;

private:
	FTimerHandle PowerUpTimerHandle;
	
	UFUNCTION()
	void OnOverlapBegin(AActor* PlayerActor, AActor* OtherActor);

	void ToNormalSpeedAndAcceleration() const;
};
