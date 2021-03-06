// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabServerAPI.h"
#include "Core/PlayFabServerDataModels.h"
#include "Proxy/PlayFabServerBPDataModels.h"
#include "PFServerUpdateUserInternalData.generated.h"

UCLASS(MinimalAPI)
class UPFServerUpdateUserInternalData : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPServerUpdateUserDataResultDelegate OnSuccess;

    // Updates the title-specific custom data for the user which cannot be accessed by the client
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Server|Player Data Management")
        static UPFServerUpdateUserInternalData* UpdateUserInternalData(class APlayerController* PlayerController, const FBPServerUpdateUserInternalDataRequest& InUpdateUserInternalDataRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPServerUpdateUserInternalDataRequest Request;
    PlayFab::UPlayFabServerAPI::FUpdateUserInternalDataDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ServerModels::FUpdateUserDataResult& Result);
};
