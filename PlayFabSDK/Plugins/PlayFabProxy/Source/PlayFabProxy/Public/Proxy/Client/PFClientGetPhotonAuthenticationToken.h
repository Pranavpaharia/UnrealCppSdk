// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientGetPhotonAuthenticationToken.generated.h"

UCLASS(MinimalAPI)
class UPFClientGetPhotonAuthenticationToken : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPClientGetPhotonAuthenticationTokenResultDelegate OnSuccess;

    // Gets a Photon custom authentication token that can be used to securely join the player into a Photon room. See https://api.playfab.com/docs/using-photon-with-playfab/ for more details.
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Client|Authentication")
        static UPFClientGetPhotonAuthenticationToken* GetPhotonAuthenticationToken(class APlayerController* PlayerController, const FBPClientGetPhotonAuthenticationTokenRequest& InGetPhotonAuthenticationTokenRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPClientGetPhotonAuthenticationTokenRequest Request;
    PlayFab::UPlayFabClientAPI::FGetPhotonAuthenticationTokenDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ClientModels::FGetPhotonAuthenticationTokenResult& Result);
};
