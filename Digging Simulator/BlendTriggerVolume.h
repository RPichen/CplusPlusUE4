// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlendTriggerVolume.generated.h"

UCLASS()
class FINALPROJECTGAM31_API ABlendTriggerVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlendTriggerVolume();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UBoxComponent* OverlapVolume;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ACameraActor* CameraToFind;

	UPROPERTY(EditDefaultsOnly, meta = (ClampMin = 0.0f))
		float CameraBlendTime;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor);

	virtual void NotifyActorEndOverlap(AActor* OtherActor);



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
