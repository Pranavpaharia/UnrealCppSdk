// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabEntityAPI.h"
#include "Core/PlayFabEntityDataModels.h"
#include "Proxy/PlayFabEntityBPDataModels.h"
#include "PFEntityRemoveGroupApplication.generated.h"

UCLASS(MinimalAPI)
class UPFEntityRemoveGroupApplication : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FEmptyPlayFabDelegate OnSuccess; 

    // Removes an application to join a group
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Entity|Groups")
        static UPFEntityRemoveGroupApplication* RemoveGroupApplication(class APlayerController* PlayerController, const FBPEntityRemoveGroupApplicationRequest& InRemoveGroupApplicationRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPEntityRemoveGroupApplicationRequest Request;
    PlayFab::UPlayFabEntityAPI::FRemoveGroupApplicationDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::EntityModels::FEmptyResult& Result);
};