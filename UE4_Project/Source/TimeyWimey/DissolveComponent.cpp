// Fill out your copyright notice in the Description page of Project Settings.

#include "DissolveComponent.h"
#include "Classes/Engine/World.h"
#include "PlayerFPP_Character.h"
#include "TeleportComponent.h"

// Sets default values for this component's properties
UDissolveComponent::UDissolveComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDissolveComponent::BeginPlay()
{
	Super::BeginPlay();

	player = Cast<APlayerFPP_Character>(GetWorld()->GetFirstPlayerController()->GetPawn());
	teleport_component = player->GetTeleportComponent();
}


// Called every frame
void UDissolveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	dissolve = teleport_component->start_dissolve;
}
