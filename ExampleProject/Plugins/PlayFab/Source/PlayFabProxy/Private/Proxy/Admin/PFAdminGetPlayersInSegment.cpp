// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFAdminGetPlayersInSegment.h"

UPFAdminGetPlayersInSegment::UPFAdminGetPlayersInSegment(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FGetPlayersInSegmentDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminGetPlayersInSegment* UPFAdminGetPlayersInSegment::GetPlayersInSegment(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InSegmentId, const int32& InSecondsToLive, const int32& InMaxBatchSize, const FString& InContinuationToken)
{
	UPFAdminGetPlayersInSegment* Proxy = NewObject<UPFAdminGetPlayersInSegment>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.SegmentId = InSegmentId;
	Proxy->Request.SecondsToLive = InSecondsToLive;
	Proxy->Request.MaxBatchSize = InMaxBatchSize;
	Proxy->Request.ContinuationToken = InContinuationToken;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminGetPlayersInSegment::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->GetPlayersInSegment(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPAdminGetPlayersInSegmentResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminGetPlayersInSegment::OnSuccessCallback(const PlayFab::AdminModels::FGetPlayersInSegmentResult& Result)
{
	FBPAdminGetPlayersInSegmentResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFAdminGetPlayersInSegment::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPAdminGetPlayersInSegmentResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
