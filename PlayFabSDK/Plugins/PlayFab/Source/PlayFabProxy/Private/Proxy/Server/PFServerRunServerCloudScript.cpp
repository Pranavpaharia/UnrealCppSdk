// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFServerRunServerCloudScript.h"

UPFServerRunServerCloudScript::UPFServerRunServerCloudScript(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabServerAPI::FRunServerCloudScriptDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFServerRunServerCloudScript* UPFServerRunServerCloudScript::RunServerCloudScript(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InPlayFabId, const FString& InActionId, const FString& InParamsEncoded)
{
	UPFServerRunServerCloudScript* Proxy = NewObject<UPFServerRunServerCloudScript>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.PlayFabId = InPlayFabId;
	Proxy->Request.ActionId = InActionId;
	
	Proxy->Request.ParamsEncoded = InParamsEncoded;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFServerRunServerCloudScript::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

	bool CallResult = false;

	if(ServerAPI.IsValid())
	{	
		CallResult = ServerAPI->RunServerCloudScript(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPServerRunCloudScriptResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFServerRunServerCloudScript::OnSuccessCallback(const PlayFab::ServerModels::FRunCloudScriptResult& Result)
{
	FBPServerRunCloudScriptResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFServerRunServerCloudScript::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPServerRunCloudScriptResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
