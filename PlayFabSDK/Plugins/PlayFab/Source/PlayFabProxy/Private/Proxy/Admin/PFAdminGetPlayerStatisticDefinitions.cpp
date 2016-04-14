// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFAdminGetPlayerStatisticDefinitions.h"

UPFAdminGetPlayerStatisticDefinitions::UPFAdminGetPlayerStatisticDefinitions(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FGetPlayerStatisticDefinitionsDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminGetPlayerStatisticDefinitions* UPFAdminGetPlayerStatisticDefinitions::GetPlayerStatisticDefinitions(UObject* WorldContextObject, class APlayerController* PlayerController )
{
	UPFAdminGetPlayerStatisticDefinitions* Proxy = NewObject<UPFAdminGetPlayerStatisticDefinitions>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminGetPlayerStatisticDefinitions::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->GetPlayerStatisticDefinitions(SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPAdminGetPlayerStatisticDefinitionsResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminGetPlayerStatisticDefinitions::OnSuccessCallback(const PlayFab::AdminModels::FGetPlayerStatisticDefinitionsResult& Result)
{
	FBPAdminGetPlayerStatisticDefinitionsResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFAdminGetPlayerStatisticDefinitions::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPAdminGetPlayerStatisticDefinitionsResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}