// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerGetAllSegments.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerGetAllSegments::UPFServerGetAllSegments(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FGetAllSegmentsDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerGetAllSegments* UPFServerGetAllSegments::GetAllSegments(class APlayerController* PlayerController)
{
    UPFServerGetAllSegments* Proxy = NewObject<UPFServerGetAllSegments>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    
    return Proxy;
}

void UPFServerGetAllSegments::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if (ServerAPI.IsValid())
    {
        CallResult = ServerAPI->GetAllSegments(SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFServerGetAllSegments::OnSuccessCallback(const PlayFab::ServerModels::FGetAllSegmentsResult& Result)
{
    FBPServerGetAllSegmentsResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
