// Fill out your copyright notice in the Description page of Project Settings.


#include "LightSwitchCodeOnly.h"
#include "Components/PointLightComponent.h"
#include "Components/SphereComponent.h"
#include "DrawDebugHelpers.h"

// Sets default values
ALightSwitchCodeOnly::ALightSwitchCodeOnly()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	LightIntensity = 3000.f;

	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("Point Light"));
	PointLight->Intensity = LightIntensity;
	RootComponent = PointLight;

	LightSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Light Shere Comp"));
	LightSphere->InitSphereRadius(300.0f);
	LightSphere->SetCollisionProfileName(TEXT("Trigger"));
	LightSphere->SetupAttachment(RootComponent);

	LightSphere->OnComponentBeginOverlap.AddDynamic(this, &ALightSwitchCodeOnly::OnOverlapBegin);
	LightSphere->OnComponentEndOverlap.AddDynamic(this, &ALightSwitchCodeOnly::OnOverlapEnd);
}

// Called when the game starts or when spawned
void ALightSwitchCodeOnly::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALightSwitchCodeOnly::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALightSwitchCodeOnly::ToggleLight()
{
	PointLight->ToggleVisibility();
}

void ALightSwitchCodeOnly::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32
	OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		ToggleLight();
	}
}

void ALightSwitchCodeOnly::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32
	OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		ToggleLight();
	}
}

