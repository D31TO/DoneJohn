// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

//Keep this at the bottom
#include "PickupItem.generated.h"

UCLASS()
class DONEJOHN_API APickupItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	USphereComponent* SphereCollider;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UStaticMeshComponent* StaticMesh;




public:
	UFUNCTION()
	void OnPickup(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);

};
