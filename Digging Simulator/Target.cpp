// Fill out your copyright notice in the Description page of Project Settings.


#include "Target.h"

// Sets default values
ATarget::ATarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Health = 100.f; // Sets The target to have 100 health

	TargetMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pickup Mesh"));

}

// Called when the game starts or when spawned
void ATarget::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Checks to see if the target is at 0 health and if it is at 0 or less destroy it
void ATarget::DamageTarget(float Damage)
{
	Health -= Damage;

	if (Health <= 0.0f)
	{
		DestroyTarget();
	}
}

void ATarget::DestroyTarget()
{
	Destroy();
}
