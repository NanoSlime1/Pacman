// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Foodie.generated.h"

class USoundCue;


UCLASS()
class PACMAN_API AFoodie : public AActor
{
	GENERATED_BODY()
	
public:	
	AFoodie();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void Consume();

private:
	UPROPERTY(EditAnywhere)
	USoundCue* ConsumeSound;

};
