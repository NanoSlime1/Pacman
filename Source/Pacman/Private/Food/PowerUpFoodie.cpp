// Fill out your copyright notice in the Description page of Project Settings.


#include "Food/PowerUpFoodie.h"

#include "PacmanPawn.h"
#include "Kismet/GameplayStatics.h"

void APowerUpFoodie::Consume()
{
	const auto Pacman = Cast<APacmanPawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	
	if(Pacman)
	{
		Pacman->PowerUp();
	}
	
	Super::Consume();
}
