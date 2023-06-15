// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "TriangleActor.generated.h"

UCLASS()
class PAINTBALL_PICHEN_API ATriangleActor : public AActor
{
	GENERATED_BODY()
	

		UPROPERTY(VisibleAnywhere, Category = "TriangleActor")
		UProceduralMeshComponent* pm;

public:
	ATriangleActor();
	// Create the arrays for the shape
	UPROPERTY()
		TArray<FVector> vertices;
	UPROPERTY()
		TArray<FVector> normals;
	UPROPERTY()
		TArray<int32> triangles;
	UPROPERTY()
		TArray<FVector2D> uvs;
	UPROPERTY()
		TArray<FLinearColor> vertexColors;
	UPROPERTY()
		TArray<FProcMeshTangent> tangents;

	// Function for creating the mesh
	virtual void OnConstruction(const FTransform& Transform) override;

	// Function for clearing the arrays
	void ClearMeshData();
};