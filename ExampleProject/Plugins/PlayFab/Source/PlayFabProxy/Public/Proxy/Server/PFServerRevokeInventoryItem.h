// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabServerAPI.h"
#include "Core/PlayFabServerDataModels.h"
#include "Proxy/PlayFabServerBPDataModels.h"
#include "PFServerRevokeInventoryItem.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFServerRevokeInventoryItem : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnSuccess; 

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnFailure; 
	
	// Revokes access to an item in a user's inventory
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Server|Player Item Management")
	static UPFServerRevokeInventoryItem* RevokeInventoryItem(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InPlayFabId, const FString& InCharacterId, const FString& InItemInstanceId);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ServerModels::FRevokeInventoryItemRequest Request;

	PlayFab::UPlayFabServerAPI::FRevokeInventoryItemDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ServerModels::FRevokeInventoryResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
