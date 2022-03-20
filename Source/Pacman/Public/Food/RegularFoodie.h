// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Food/Foodie.h"
#include "RegularFoodie.generated.h"

/**
 * 
 */
UCLASS()
class PACMAN_API ARegularFoodie : public AFoodie
{
	GENERATED_BODY()
	
	virtual void Consume() override;
};
