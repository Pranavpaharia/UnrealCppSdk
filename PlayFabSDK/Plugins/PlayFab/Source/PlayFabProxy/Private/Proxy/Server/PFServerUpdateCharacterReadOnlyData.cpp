// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFServerUpdateCharacterReadOnlyData.h"

UPFServerUpdateCharacterReadOnlyData::UPFServerUpdateCharacterReadOnlyData(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabServerAPI::FUpdateCharacterReadOnlyDataDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFServerUpdateCharacterReadOnlyData* UPFServerUpdateCharacterReadOnlyData::UpdateCharacterReadOnlyData(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InPlayFabId, const FString& InCharacterId, const FString& InData)
{
	UPFServerUpdateCharacterReadOnlyData* Proxy = NewObject<UPFServerUpdateCharacterReadOnlyData>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.PlayFabId = InPlayFabId;
	Proxy->Request.CharacterId = InCharacterId;
	
	
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFServerUpdateCharacterReadOnlyData::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

	bool CallResult = false;

	if(ServerAPI.IsValid())
	{	
		CallResult = ServerAPI->UpdateCharacterReadOnlyData(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPServerUpdateCharacterDataResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFServerUpdateCharacterReadOnlyData::OnSuccessCallback(const PlayFab::ServerModels::FUpdateCharacterDataResult& Result)
{
	FBPServerUpdateCharacterDataResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFServerUpdateCharacterReadOnlyData::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPServerUpdateCharacterDataResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
