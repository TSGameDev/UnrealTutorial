// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSULTTUTORIAL_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void MovePlatform(float DeltaTime);
	void ReversePlatform(FVector CurrentPos);
	void RotatePlatform(float DeltaTime);

	//Non-blueprint accessable variables
	FVector StartingLocation;

	//blueprint or inspector accessable variables
	UPROPERTY(EditAnywhere, Category="Moving Platform")
	FVector MovementIncriment;

	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	float MoveMaxDistance;
};
