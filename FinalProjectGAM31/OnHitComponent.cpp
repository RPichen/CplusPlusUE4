// Fill out your copyright notice in the Description page of Project Settings.


#include "OnHitComponent.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AOnHitComponent::AOnHitComponent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	// Use a cube as a simple collision representation
	MyComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	MyComp->SetSimulatePhysics(true);
	MyComp->SetNotifyRigidBodyCollision(true);
	MyComp->BodyInstance.SetCollisionProfileName("BlockAllDynamic");
	MyComp->OnComponentHit.AddDynamic(this, &AOnHitComponent::OnCompHit);

	// Set as root component
	RootComponent = MyComp;
}

// Called when the game starts or when spawned
void AOnHitComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOnHitComponent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// On overlap of the components collison box actor is destroyed
void AOnHitComponent::OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse,
	const FHitResult& Hit)
{
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL))
	{
		Destroy();
		/*
		AFinalProjectGAM312Character* TestPlayer = Cast<AFinalProjectGAM312Character>(Hitresult->Actor.Get()); // Checks to see if the player is hitting the OnHitComponent

		if (TestPlayer != NULL && !TestPlayer->IsPendingKill()) // If Player is hit deal 50 damage to Player
		{
			TestPlayer->DamagePlayer(50.f);
		}
		*/
	}
}