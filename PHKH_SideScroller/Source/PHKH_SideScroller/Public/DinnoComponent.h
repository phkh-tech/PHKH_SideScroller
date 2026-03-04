#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DinnoComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PHKH_SIDESCROLLER_API UDinnoComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UDinnoComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(
		float DeltaTime,
		ELevelTick TickType,
		FActorComponentTickFunction* ThisTickFunction
	) override;

	// Reference to the owner's torch light component
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Torch")
	ULightComponent* OwnerTorchLightComponent;

	// Tweaks torch settings dynamically from Blueprint
	UFUNCTION(BlueprintCallable, Category = "Torch")
	void TweakTorchSettings(float NewIntensity, FLinearColor NewColor);
};