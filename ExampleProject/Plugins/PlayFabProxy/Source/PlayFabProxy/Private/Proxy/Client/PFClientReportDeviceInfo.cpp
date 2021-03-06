// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientReportDeviceInfo.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientReportDeviceInfo::UPFClientReportDeviceInfo(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FReportDeviceInfoDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientReportDeviceInfo* UPFClientReportDeviceInfo::ReportDeviceInfo(class APlayerController* PlayerController, const FBPClientDeviceInfoRequest& InDeviceInfoRequest)
{
    UPFClientReportDeviceInfo* Proxy = NewObject<UPFClientReportDeviceInfo>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InDeviceInfoRequest;
    
    return Proxy;
}

void UPFClientReportDeviceInfo::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if (ClientAPI.IsValid())
    {
        CallResult = ClientAPI->ReportDeviceInfo(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFClientReportDeviceInfo::OnSuccessCallback(const PlayFab::ClientModels::FEmptyResult& Result)
{
    OnSuccess.Broadcast();
}
