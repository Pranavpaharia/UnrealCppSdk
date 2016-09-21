// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFAdminRefundPurchase.h"

UPFAdminRefundPurchase::UPFAdminRefundPurchase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FRefundPurchaseDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminRefundPurchase* UPFAdminRefundPurchase::RefundPurchase(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InPlayFabId, const FString& InOrderId, const FString& InReason)
{
	UPFAdminRefundPurchase* Proxy = NewObject<UPFAdminRefundPurchase>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.PlayFabId = InPlayFabId;
	Proxy->Request.OrderId = InOrderId;
	Proxy->Request.Reason = InReason;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminRefundPurchase::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->RefundPurchase(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPAdminRefundPurchaseResponse BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminRefundPurchase::OnSuccessCallback(const PlayFab::AdminModels::FRefundPurchaseResponse& Result)
{
	FBPAdminRefundPurchaseResponse BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFAdminRefundPurchase::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPAdminRefundPurchaseResponse BPResult;
 	OnFailure.Broadcast(BPResult);	
}