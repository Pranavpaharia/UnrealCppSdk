// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientRedeemCoupon.generated.h"

UCLASS(MinimalAPI)
class UPFClientRedeemCoupon : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPClientRedeemCouponResultDelegate OnSuccess;

    // Adds the virtual goods associated with the coupon to the user's inventory. Coupons can be generated  via the Economy->Catalogs tab in the PlayFab Game Manager.
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Client|Player Item Management")
        static UPFClientRedeemCoupon* RedeemCoupon(class APlayerController* PlayerController, const FBPClientRedeemCouponRequest& InRedeemCouponRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPClientRedeemCouponRequest Request;
    PlayFab::UPlayFabClientAPI::FRedeemCouponDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ClientModels::FRedeemCouponResult& Result);
};