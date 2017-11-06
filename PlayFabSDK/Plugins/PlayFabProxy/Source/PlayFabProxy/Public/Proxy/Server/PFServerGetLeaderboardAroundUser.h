// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabServerAPI.h"
#include "Core/PlayFabServerDataModels.h"
#include "Proxy/PlayFabServerBPDataModels.h"
#include "PFServerGetLeaderboardAroundUser.generated.h"

UCLASS(MinimalAPI)
class UPFServerGetLeaderboardAroundUser : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPServerGetLeaderboardAroundUserResultDelegate OnSuccess;

    // Retrieves a list of ranked users for the given statistic, centered on the currently signed-in user
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Server|Player Data Management")
        static UPFServerGetLeaderboardAroundUser* GetLeaderboardAroundUser(class APlayerController* PlayerController, const FBPServerGetLeaderboardAroundUserRequest& InGetLeaderboardAroundUserRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPServerGetLeaderboardAroundUserRequest Request;
    PlayFab::UPlayFabServerAPI::FGetLeaderboardAroundUserDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ServerModels::FGetLeaderboardAroundUserResult& Result);
};