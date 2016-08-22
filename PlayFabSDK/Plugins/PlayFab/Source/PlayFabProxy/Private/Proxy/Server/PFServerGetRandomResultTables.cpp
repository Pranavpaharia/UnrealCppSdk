// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFServerGetRandomResultTables.h"

UPFServerGetRandomResultTables::UPFServerGetRandomResultTables(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabServerAPI::FGetRandomResultTablesDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFServerGetRandomResultTables* UPFServerGetRandomResultTables::GetRandomResultTables(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InCatalogVersion, const TArray<FString>& InTableIDs)
{
	UPFServerGetRandomResultTables* Proxy = NewObject<UPFServerGetRandomResultTables>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.CatalogVersion = InCatalogVersion;
	Proxy->Request.TableIDs = InTableIDs;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFServerGetRandomResultTables::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

	bool CallResult = false;

	if(ServerAPI.IsValid())
	{	
		CallResult = ServerAPI->GetRandomResultTables(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPServerGetRandomResultTablesResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFServerGetRandomResultTables::OnSuccessCallback(const PlayFab::ServerModels::FGetRandomResultTablesResult& Result)
{
	FBPServerGetRandomResultTablesResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFServerGetRandomResultTables::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPServerGetRandomResultTablesResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}