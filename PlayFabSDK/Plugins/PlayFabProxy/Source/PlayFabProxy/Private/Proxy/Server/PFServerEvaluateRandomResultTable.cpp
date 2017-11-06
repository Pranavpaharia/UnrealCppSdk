// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerEvaluateRandomResultTable.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerEvaluateRandomResultTable::UPFServerEvaluateRandomResultTable(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FEvaluateRandomResultTableDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerEvaluateRandomResultTable* UPFServerEvaluateRandomResultTable::EvaluateRandomResultTable(class APlayerController* PlayerController, const FBPServerEvaluateRandomResultTableRequest& InEvaluateRandomResultTableRequest)
{
    UPFServerEvaluateRandomResultTable* Proxy = NewObject<UPFServerEvaluateRandomResultTable>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InEvaluateRandomResultTableRequest;
    
    return Proxy;
}

void UPFServerEvaluateRandomResultTable::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if(ServerAPI.IsValid())
    {
        CallResult = ServerAPI->EvaluateRandomResultTable(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFServerEvaluateRandomResultTable::OnSuccessCallback(const PlayFab::ServerModels::FEvaluateRandomResultTableResult& Result)
{
    FBPServerEvaluateRandomResultTableResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}