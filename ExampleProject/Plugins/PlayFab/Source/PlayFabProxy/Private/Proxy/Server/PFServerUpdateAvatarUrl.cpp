// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFServerUpdateAvatarUrl.h"

UPFServerUpdateAvatarUrl::UPFServerUpdateAvatarUrl(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabServerAPI::FUpdateAvatarUrlDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFServerUpdateAvatarUrl* UPFServerUpdateAvatarUrl::UpdateAvatarUrl(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InPlayFabId, const FString& InImageUrl)
{
	UPFServerUpdateAvatarUrl* Proxy = NewObject<UPFServerUpdateAvatarUrl>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.PlayFabId = InPlayFabId;
	Proxy->Request.ImageUrl = InImageUrl;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFServerUpdateAvatarUrl::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

	bool CallResult = false;

	if(ServerAPI.IsValid())
	{	
		CallResult = ServerAPI->UpdateAvatarUrl(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		OnFailure.Broadcast();
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFServerUpdateAvatarUrl::OnSuccessCallback(const PlayFab::ServerModels::FEmptyResult& Result)
{
	OnSuccess.Broadcast();
}

void UPFServerUpdateAvatarUrl::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	OnFailure.Broadcast();	
}