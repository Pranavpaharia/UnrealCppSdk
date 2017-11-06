// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientLoginWithCustomID.generated.h"

UCLASS(MinimalAPI)
class UPFClientLoginWithCustomID : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPClientLoginResultDelegate OnSuccess;

    // Signs the user in using a custom unique identifier generated by the title, returning a session identifier that can subsequently be used for API calls which require an authenticated user
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Client|Authentication")
        static UPFClientLoginWithCustomID* LoginWithCustomID(class APlayerController* PlayerController, const FBPClientLoginWithCustomIDRequest& InLoginWithCustomIDRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPClientLoginWithCustomIDRequest Request;
    PlayFab::UPlayFabClientAPI::FLoginWithCustomIDDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ClientModels::FLoginResult& Result);
};