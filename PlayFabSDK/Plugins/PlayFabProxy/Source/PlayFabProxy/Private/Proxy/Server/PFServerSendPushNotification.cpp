// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerSendPushNotification.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerSendPushNotification::UPFServerSendPushNotification(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FSendPushNotificationDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerSendPushNotification* UPFServerSendPushNotification::SendPushNotification(class APlayerController* PlayerController, const FBPServerSendPushNotificationRequest& InSendPushNotificationRequest)
{
    UPFServerSendPushNotification* Proxy = NewObject<UPFServerSendPushNotification>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InSendPushNotificationRequest;
    
    return Proxy;
}

void UPFServerSendPushNotification::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if(ServerAPI.IsValid())
    {
        CallResult = ServerAPI->SendPushNotification(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFServerSendPushNotification::OnSuccessCallback(const PlayFab::ServerModels::FSendPushNotificationResult& Result)
{
    OnSuccess.Broadcast();
}