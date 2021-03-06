// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminGetUserBans.generated.h"

UCLASS(MinimalAPI)
class UPFAdminGetUserBans : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPAdminGetUserBansResultDelegate OnSuccess;

    // Gets all bans for a user.
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Admin|Account Management")
        static UPFAdminGetUserBans* GetUserBans(class APlayerController* PlayerController, const FBPAdminGetUserBansRequest& InGetUserBansRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPAdminGetUserBansRequest Request;
    PlayFab::UPlayFabAdminAPI::FGetUserBansDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::AdminModels::FGetUserBansResult& Result);
};
