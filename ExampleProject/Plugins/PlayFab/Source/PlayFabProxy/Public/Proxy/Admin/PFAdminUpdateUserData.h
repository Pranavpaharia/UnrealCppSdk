// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminUpdateUserData.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFAdminUpdateUserData : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPAdminUpdateUserDataResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPAdminUpdateUserDataResultDelegate OnFailure;
	
	// Updates the title-specific custom data for the user which is readable and writable by the client
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Admin|Player Data Management")
	static UPFAdminUpdateUserData* UpdateUserData(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InPlayFabId, const FString& InData);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::AdminModels::FUpdateUserDataRequest Request;

	PlayFab::UPlayFabAdminAPI::FUpdateUserDataDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::AdminModels::FUpdateUserDataResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
