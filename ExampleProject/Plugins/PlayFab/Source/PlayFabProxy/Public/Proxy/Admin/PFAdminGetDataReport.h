// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminGetDataReport.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFAdminGetDataReport : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPAdminGetDataReportResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPAdminGetDataReportResultDelegate OnFailure;
	
	// Retrieves a download URL for the requested report. Currently available reports: Daily / Monthly API Usage, Daily / Monthly Overview, Monthly Real Money Purchase History, Monthly Top Items, Monthly Top Spenders, Monthly VC Purcahse History, Sevan Day Retention
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Admin|Player Data Management")
	static UPFAdminGetDataReport* GetDataReport(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InReportName, const int32& InYear, const int32& InMonth, const int32& InDay);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::AdminModels::FGetDataReportRequest Request;

	PlayFab::UPlayFabAdminAPI::FGetDataReportDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::AdminModels::FGetDataReportResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
