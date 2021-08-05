// Fill out your copyright notice in the Description page of Project Settings.


#include "Bulb.h"

// Sets default values
ABulb::ABulb()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	LightComponent = CreateDefaultSubobject<UPointLightComponent>("LightComponent");

	RootComponent = Mesh;
	LightComponent->SetupAttachment(Mesh);

	OnActorBeginOverlap.AddDynamic(this, &ABulb::OnOverlap);
}

// Called when the game starts or when spawned
void ABulb::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABulb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABulb::OnOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	UE_LOG(LogTemp, Warning, TEXT("Hello"));
	Destroy();
}