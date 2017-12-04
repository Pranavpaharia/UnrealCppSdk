// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientRemoveContactEmail.generated.h"

UCLASS(MinimalAPI)
class UPFClientRemoveContactEmail : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FEmptyPlayFabDelegate OnSuccess; 

    // Removes a contact email from the player's profile.
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Client|Account Management")
        static UPFClientRemoveContactEmail* RemoveContactEmail(class APlayerController* PlayerController);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    
    PlayFab::UPlayFabClientAPI::FRemoveContactEmailDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ClientModels::FRemoveContactEmailResult& Result);
};
