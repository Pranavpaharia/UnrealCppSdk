// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFAdminIncrementPlayerStatisticVersion.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFAdminIncrementPlayerStatisticVersion::UPFAdminIncrementPlayerStatisticVersion(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabAdminAPI::FIncrementPlayerStatisticVersionDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFAdminIncrementPlayerStatisticVersion* UPFAdminIncrementPlayerStatisticVersion::IncrementPlayerStatisticVersion(class APlayerController* PlayerController, const FBPAdminIncrementPlayerStatisticVersionRequest& InIncrementPlayerStatisticVersionRequest)
{
    UPFAdminIncrementPlayerStatisticVersion* Proxy = NewObject<UPFAdminIncrementPlayerStatisticVersion>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InIncrementPlayerStatisticVersionRequest;
    
    return Proxy;
}

void UPFAdminIncrementPlayerStatisticVersion::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

    bool CallResult = false;

    if(AdminAPI.IsValid())
    {
        CallResult = AdminAPI->IncrementPlayerStatisticVersion(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFAdminIncrementPlayerStatisticVersion::OnSuccessCallback(const PlayFab::AdminModels::FIncrementPlayerStatisticVersionResult& Result)
{
    FBPAdminIncrementPlayerStatisticVersionResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}