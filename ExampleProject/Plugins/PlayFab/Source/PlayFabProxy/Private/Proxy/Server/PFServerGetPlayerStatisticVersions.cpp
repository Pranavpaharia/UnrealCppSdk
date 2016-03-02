// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFServerGetPlayerStatisticVersions.h"

UPFServerGetPlayerStatisticVersions::UPFServerGetPlayerStatisticVersions(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabServerAPI::FGetPlayerStatisticVersionsDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFServerGetPlayerStatisticVersions* UPFServerGetPlayerStatisticVersions::GetPlayerStatisticVersions(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InStatisticName)
{
	UPFServerGetPlayerStatisticVersions* Proxy = NewObject<UPFServerGetPlayerStatisticVersions>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.StatisticName = InStatisticName;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFServerGetPlayerStatisticVersions::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

	bool CallResult = false;

	if(ServerAPI.IsValid())
	{	
		CallResult = ServerAPI->GetPlayerStatisticVersions(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPServerGetPlayerStatisticVersionsResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFServerGetPlayerStatisticVersions::OnSuccessCallback(const PlayFab::ServerModels::FGetPlayerStatisticVersionsResult& Result)
{
	FBPServerGetPlayerStatisticVersionsResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFServerGetPlayerStatisticVersions::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPServerGetPlayerStatisticVersionsResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
