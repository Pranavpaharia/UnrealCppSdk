// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientUnlinkFacebookAccount.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientUnlinkFacebookAccount::UPFClientUnlinkFacebookAccount(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FUnlinkFacebookAccountDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientUnlinkFacebookAccount* UPFClientUnlinkFacebookAccount::UnlinkFacebookAccount(class APlayerController* PlayerController)
{
    UPFClientUnlinkFacebookAccount* Proxy = NewObject<UPFClientUnlinkFacebookAccount>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    
    return Proxy;
}

void UPFClientUnlinkFacebookAccount::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if (ClientAPI.IsValid())
    {
        CallResult = ClientAPI->UnlinkFacebookAccount(SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFClientUnlinkFacebookAccount::OnSuccessCallback(const PlayFab::ClientModels::FUnlinkFacebookAccountResult& Result)
{
    OnSuccess.Broadcast();
}
