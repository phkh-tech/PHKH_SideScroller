#include "DinnoComponent.h"
#include "Components/LightComponent.h"
#include "Components/LocalLightComponent.h"

// Sets default values for this component's properties
UDinnoComponent::UDinnoComponent()
{
	// Enable ticking every frame
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UDinnoComponent::BeginPlay()
{
	Super::BeginPlay();

	// Try to find a light component in the owner actor
	if (const AActor* Owner = GetOwner())
	{
		OwnerTorchLightComponent = Owner->FindComponentByClass<ULightComponent>();
	}
}

// Called every frame
void UDinnoComponent::TickComponent(
	float DeltaTime,
	ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction
)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

// Dynamically adjust torch intensity and color
void UDinnoComponent::TweakTorchSettings(float NewIntensity, FLinearColor NewColor)
{
	if (OwnerTorchLightComponent)
	{
		OwnerTorchLightComponent->SetIntensity(NewIntensity);
		OwnerTorchLightComponent->SetLightColor(NewColor);
	}
}