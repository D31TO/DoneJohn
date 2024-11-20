// Fill out your copyright notice in the Description page of Project Settings.


#include "PickupItem.h"
#include "Components/SphereComponent.h"

// Sets default values
APickupItem::APickupItem()
{
	SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collider"));
	SphereCollider->SetupAttachment(RootComponent);

	SphereCollider->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SphereCollider->InitSphereRadius(64.f);
	SphereCollider->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);

	SphereCollider->OnComponentBeginOverlap.AddDynamic(this, &APickupItem::OnPickup);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));


	StaticMesh->AttachToComponent(SphereCollider, FAttachmentTransformRules::KeepWorldTransform);
}

// Called when the game starts or when spawned
void APickupItem::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, TEXT("I Exist"));
}

// Called every frame
void APickupItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APickupItem::OnPickup(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Pickup Success"));
	Destroy();
}

