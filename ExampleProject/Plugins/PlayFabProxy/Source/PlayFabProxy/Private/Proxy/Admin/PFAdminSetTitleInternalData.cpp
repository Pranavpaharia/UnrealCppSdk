// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFAdminSetTitleInternalData.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFAdminSetTitleInternalData::UPFAdminSetTitleInternalData(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabAdminAPI::FSetTitleInternalDataDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFAdminSetTitleInternalData* UPFAdminSetTitleInternalData::SetTitleInternalData(class APlayerController* PlayerController, const FBPAdminSetTitleDataRequest& InSetTitleDataRequest)
{
    UPFAdminSetTitleInternalData* Proxy = NewObject<UPFAdminSetTitleInternalData>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InSetTitleDataRequest;
    
    return Proxy;
}

void UPFAdminSetTitleInternalData::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

    bool CallResult = false;

    if (AdminAPI.IsValid())
    {
        CallResult = AdminAPI->SetTitleInternalData(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFAdminSetTitleInternalData::OnSuccessCallback(const PlayFab::AdminModels::FSetTitleDataResult& Result)
{
    OnSuccess.Broadcast();
}
