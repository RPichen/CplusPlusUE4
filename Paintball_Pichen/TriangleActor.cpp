// Fill out your copyright notice in the Description page of Project Settings.

#include "TriangleActor.h"


// Sets default values
ATriangleActor::ATriangleActor()
{
	PrimaryActorTick.bCanEverTick = true;

	// Create the ProceduralMeshComponent
	pm = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("ProceduralMesh"));
	pm->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
}

void ATriangleActor::OnConstruction(const FTransform& Transform)
{
	ClearMeshData();

	// Create the vertices of the shape
	vertices.Add(FVector(0.0f, 0.0f, 0.0f));
	vertices.Add(FVector(100.0f, 0.0f, 0.0f));
	vertices.Add(FVector(0.0f, 100.0f, 0.0f));

	// Create the triangles of the shape
	triangles.Add(0);
	triangles.Add(2);
	triangles.Add(1);


	// Create the UV's of the shape
	uvs.Add(FVector2D(0.0f, 0.0f));
	uvs.Add(FVector2D(1.0f, 0.0f));
	uvs.Add(FVector2D(0.0f, 1.0f));

	uvs.Init(FVector2D(0.0f, 0.0f), 3);
	normals.Init(FVector(0.0f, 0.0f, 1.0f), 3);
	vertexColors.Init(FLinearColor(0.0f, 0.0f, 0.0f, 1.0f), 3);
	tangents.Init(FProcMeshTangent(1.0f, 0.0f, 0.0f), 3);

	//Function that creates mesh section
	pm->CreateMeshSection_LinearColor(0, vertices, triangles, normals, uvs, vertexColors, tangents, false);
}

// Implement the ClearMeshData Function
void ATriangleActor::ClearMeshData()
{
	vertices.Empty();
	triangles.Empty();
	uvs.Empty();
	normals.Empty();
	vertexColors.Empty();
	tangents.Empty();
}
