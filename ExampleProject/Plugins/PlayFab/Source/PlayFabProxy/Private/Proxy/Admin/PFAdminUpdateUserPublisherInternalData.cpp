// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFAdminUpdateUserPublisherInternalData.h"

UPFAdminUpdateUserPublisherInternalData::UPFAdminUpdateUserPublisherInternalData(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FUpdateUserPublisherInternalDataDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminUpdateUserPublisherInternalData* UPFAdminUpdateUserPublisherInternalData::UpdateUserPublisherInternalData(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InPlayFabId, const FString& InData)
{
	UPFAdminUpdateUserPublisherInternalData* Proxy = NewObject<UPFAdminUpdateUserPublisherInternalData>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.PlayFabId = InPlayFabId;
	
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminUpdateUserPublisherInternalData::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->UpdateUserPublisherInternalData(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPAdminUpdateUserDataResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminUpdateUserPublisherInternalData::OnSuccessCallback(const PlayFab::AdminModels::FUpdateUserDataResult& Result)
{
	FBPAdminUpdateUserDataResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFAdminUpdateUserPublisherInternalData::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPAdminUpdateUserDataResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
