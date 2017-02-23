// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientUnlinkWindowsHello.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFClientUnlinkWindowsHello : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnSuccess; 

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnFailure; 
	
	// Unlink Windows Hello from the current PlayFab Account
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Client|Authentication")
	static UPFClientUnlinkWindowsHello* UnlinkWindowsHello(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InPublicKeyHint);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ClientModels::FUnlinkWindowsHelloAccountRequest Request;

	PlayFab::UPlayFabClientAPI::FUnlinkWindowsHelloDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ClientModels::FUnlinkWindowsHelloAccountResponse& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
