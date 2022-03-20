// Fill out your copyright notice in the Description page of Project Settings.


#include "PacmanController.h"

#include "Pacman/PacmanPawn.h"

void APacmanController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("MoveUp", IE_Pressed, this, &APacmanController::MoveUp);
	InputComponent->BindAction("MoveDown", IE_Pressed, this, &APacmanController::MoveDown);
	InputComponent->BindAction("MoveRight", IE_Pressed, this, &APacmanController::MoveRight);
	InputComponent->BindAction("MoveLeft", IE_Pressed, this, &APacmanController::MoveLeft);
	
}

APacmanPawn* APacmanController::GetPacmanPawn() const
{
	return Cast<APacmanPawn>(GetPawn()); 
}

void APacmanController::MoveUp()
{
	if(GetPacmanPawn())
	{
		GetPacmanPawn()->SetDirection(FVector::UpVector);
	}
}

void APacmanController::MoveDown()
{
	if(GetPacmanPawn())
	{
		GetPacmanPawn()->SetDirection(FVector::DownVector);
	}
}

void APacmanController::MoveLeft()
{
	if(GetPacmanPawn())
	{
		GetPacmanPawn()->SetDirection(FVector::LeftVector);
	}
}

void APacmanController::MoveRight()
{
	if(GetPacmanPawn())
	{
		GetPacmanPawn()->SetDirection(FVector::RightVector);
	}
}
