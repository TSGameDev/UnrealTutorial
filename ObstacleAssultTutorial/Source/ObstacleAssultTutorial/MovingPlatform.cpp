// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartingLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	FVector _CurrentLocation = GetActorLocation();
	_CurrentLocation += MovementIncriment * DeltaTime;
	SetActorLocation(_CurrentLocation);

	ReversePlatform(_CurrentLocation);
}

void AMovingPlatform::ReversePlatform(FVector CurrentPos)
{
	float DistanceTravelled = FVector::Dist(StartingLocation, CurrentPos);
	if (DistanceTravelled >= MoveMaxDistance)
	{
		FVector _MovDir = MovementIncriment.GetSafeNormal();
		StartingLocation = StartingLocation + _MovDir * MoveMaxDistance;
		SetActorLocation(StartingLocation);
		MovementIncriment = -MovementIncriment;
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{

}