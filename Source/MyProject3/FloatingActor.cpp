// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject3.h"
#include "FloatingActor.h"


// Sets default values
AFloatingActor::AFloatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloatingActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	//Causes FloatingActors to bob up and down smoothly.
	//RunningTime var keeps track of movement over time.
	FVector NewLocation = GetActorLocation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Z += DeltaHeight * BobScale; //Scale our height by a factor of 20
	float DeltaLength = (FMath::Cos(RunningTime + DeltaTime) - FMath::Cos(RunningTime));
	NewLocation.X += DeltaLength * SwayScale;
	RunningTime += DeltaTime;
	
	SetActorLocation(NewLocation);
}

