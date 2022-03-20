// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Food/Foodie.h"
#include "PowerUpFoodie.generated.h"

/**
 * 
 */
UCLASS()
class PACMAN_API APowerUpFoodie : public AFoodie
{
	GENERATED_BODY()
	
	virtual void Consume() override;
};
