// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LightSwitchCodeOnly.generated.h"

UCLASS()
class FINALPROJECTGAM31_API ALightSwitchCodeOnly : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALightSwitchCodeOnly();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(VisibleAnywhere, Category = "Light Switch")
		class UPointLightComponent* PointLight;

	UPROPERTY(VisibleAnywhere, Category = "Light Switch")
		class USphereComponent* LightSphere;

	UPROPERTY(VisibleAnywhere, Category = "Light Switch")
		float LightIntensity;

	UFUNCTION()
		void ToggleLight();

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32
			OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32
			OtherBodyIndex);
};
