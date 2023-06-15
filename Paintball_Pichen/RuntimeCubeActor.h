// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RuntimeMeshComponent.h"
#include "RuntimeCubeActor.generated.h"

UCLASS()
class PAINTBALL_PICHEN_API ARuntimeCubeActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARuntimeCubeActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	virtual void GenerateBoxMesh();
	virtual void CreateBoxMesh(FVector BoxRadius, TArray < FVector > & Vertices, TArray < int32 > &
		Triangles, TArray < FVector > & Normals, TArray < FVector2D > & UVs, TArray <
		FRuntimeMeshTangent > & Tangents, TArray < FColor > & Colors);
private:
	UPROPERTY(VisibleAnywhere) URuntimeMeshComponent * mesh;
	
};
