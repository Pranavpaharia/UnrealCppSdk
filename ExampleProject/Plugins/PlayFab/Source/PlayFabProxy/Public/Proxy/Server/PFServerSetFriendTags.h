// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabServerAPI.h"
#include "Core/PlayFabServerDataModels.h"
#include "Proxy/PlayFabServerBPDataModels.h"
#include "PFServerSetFriendTags.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFServerSetFriendTags : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnSuccess; 

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnFailure; 
	
	// Updates the tag list for a specified user in the friend list of another user
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Server|Friend List Management")
	static UPFServerSetFriendTags* SetFriendTags(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InPlayFabId, const FString& InFriendPlayFabId, const TArray<FString>& InTags);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ServerModels::FSetFriendTagsRequest Request;

	PlayFab::UPlayFabServerAPI::FSetFriendTagsDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ServerModels::FEmptyResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
