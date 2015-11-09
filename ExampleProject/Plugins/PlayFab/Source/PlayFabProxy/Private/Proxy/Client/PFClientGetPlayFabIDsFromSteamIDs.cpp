// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFClientGetPlayFabIDsFromSteamIDs.h"

UPFClientGetPlayFabIDsFromSteamIDs::UPFClientGetPlayFabIDsFromSteamIDs(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FGetPlayFabIDsFromSteamIDsDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientGetPlayFabIDsFromSteamIDs* UPFClientGetPlayFabIDsFromSteamIDs::GetPlayFabIDsFromSteamIDs(UObject* WorldContextObject, class APlayerController* PlayerController , const TArray<int32>& InSteamIDs)
{
	UPFClientGetPlayFabIDsFromSteamIDs* Proxy = NewObject<UPFClientGetPlayFabIDsFromSteamIDs>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	for (const int32& elem : InSteamIDs)
    {
        Proxy->Request.SteamIDs.Add(static_cast<uint64>(elem));
    }

	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientGetPlayFabIDsFromSteamIDs::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->GetPlayFabIDsFromSteamIDs(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPClientGetPlayFabIDsFromSteamIDsResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientGetPlayFabIDsFromSteamIDs::OnSuccessCallback(const PlayFab::ClientModels::FGetPlayFabIDsFromSteamIDsResult& Result)
{
	FBPClientGetPlayFabIDsFromSteamIDsResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFClientGetPlayFabIDsFromSteamIDs::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPClientGetPlayFabIDsFromSteamIDsResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
