// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFAdminGetUserInternalData.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFAdminGetUserInternalData::UPFAdminGetUserInternalData(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabAdminAPI::FGetUserInternalDataDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFAdminGetUserInternalData* UPFAdminGetUserInternalData::GetUserInternalData(class APlayerController* PlayerController, const FBPAdminGetUserDataRequest& InGetUserDataRequest)
{
    UPFAdminGetUserInternalData* Proxy = NewObject<UPFAdminGetUserInternalData>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetUserDataRequest;
    
    return Proxy;
}

void UPFAdminGetUserInternalData::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

    bool CallResult = false;

    if(AdminAPI.IsValid())
    {
        CallResult = AdminAPI->GetUserInternalData(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFAdminGetUserInternalData::OnSuccessCallback(const PlayFab::AdminModels::FGetUserDataResult& Result)
{
    FBPAdminGetUserDataResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}