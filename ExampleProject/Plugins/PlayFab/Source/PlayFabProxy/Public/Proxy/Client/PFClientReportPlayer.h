// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientReportPlayer.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFClientReportPlayer : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPClientReportPlayerClientResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPClientReportPlayerClientResultDelegate OnFailure;
	
	// Submit a report for another player (due to bad bahavior, etc.), so that customer service representatives for the title can take action concerning potentially toxic players.
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Client|Account Management")
	static UPFClientReportPlayer* ReportPlayer(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InReporteeId, const FString& InComment);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ClientModels::FReportPlayerClientRequest Request;

	PlayFab::UPlayFabClientAPI::FReportPlayerDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ClientModels::FReportPlayerClientResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
