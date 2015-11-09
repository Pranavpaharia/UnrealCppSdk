// Fill out your copyright notice in the Description page of Project Settings.

#include "ExampleProject.h"
#include "MyCharacter.h"

#include "PlayFab.h"
#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
    Super::SetupPlayerInputComponent(InputComponent);

}







/**
* PlayFab Latent commands
*/

class PlayFabApiTest_RegisterPlayFabUser;
class PlayFabApiTest_LoginWithEmail;



class PlayFabApiTest_LoginWithEmail : public IAutomationLatentCommand
{
public:
    PlayFabApiTest_LoginWithEmail(bool successMandatory, const FString& username, const FString& email, const FString& password)
    {
        this->successMandatory = successMandatory;
        this->username = username;
        this->email = email;
        this->password = password;
    }

    bool Update()
    {
        // Initialize, setup the call, and wait for the result
        if (!clientAPI.IsValid())
        {
            clientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

            PlayFab::ClientModels::FLoginWithEmailAddressRequest request;
            request.Email = email;
            request.Password = password;

            clientAPI->LoginWithEmailAddress(request
                , PlayFab::UPlayFabClientAPI::FLoginWithEmailAddressDelegate::CreateRaw(this, &PlayFabApiTest_LoginWithEmail::OnSuccess)
                , PlayFab::FPlayFabErrorDelegate::CreateRaw(this, &PlayFabApiTest_LoginWithEmail::OnError)
                );
        }

        // Return when the api call is resolved
        return clientAPI->GetPendingCalls() == 0;
    }
private:
    void OnSuccess(const PlayFab::ClientModels::FLoginResult& Result)
    {
        UE_LOG(LogTemp, Log, TEXT("LoginWithEmailAddress Success"));
    }

    void OnError(const PlayFab::FPlayFabError& Error)
    {
        if (successMandatory)
        {
            UE_LOG(LogTemp, Error, TEXT("LoginWithEmailAddress Failed"));
        }
        else
        {
            // ADD_LATENT_AUTOMATION_COMMAND(PlayFabApiTest_RegisterPlayFabUser(username, email, password));
        }
    }

    FString username;
    FString email;
    FString password;
    bool successMandatory = false;
    PlayFabClientPtr clientAPI = nullptr;
};

class PlayFabApiTest_RegisterPlayFabUser : public IAutomationLatentCommand
{
public:
    PlayFabApiTest_RegisterPlayFabUser(const FString& username, const FString& email, const FString& password)
    {
        this->username = username;
        this->email = email;
        this->password = password;
    }

    bool Update()
    {
        // Initialize, setup the call, and wait for the result
        if (!clientAPI.IsValid())
        {
            clientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

            PlayFab::ClientModels::FRegisterPlayFabUserRequest request;
            request.Email = email;
            request.Password = password;
            request.Username = username;

            clientAPI->RegisterPlayFabUser(request
                , PlayFab::UPlayFabClientAPI::FRegisterPlayFabUserDelegate::CreateRaw(this, &PlayFabApiTest_RegisterPlayFabUser::OnSuccess)
                , PlayFab::FPlayFabErrorDelegate::CreateRaw(this, &PlayFabApiTest_RegisterPlayFabUser::OnError)
                );
        }

        // Return when the api call is resolved
        return clientAPI->GetPendingCalls() == 0;
    }
private:
    void OnSuccess(const PlayFab::ClientModels::FRegisterPlayFabUserResult& Result)
    {
        UE_LOG(LogTemp, Log, TEXT("RegisterPlayFabUser Success"));
        ADD_LATENT_AUTOMATION_COMMAND(PlayFabApiTest_LoginWithEmail(true, username, email, password));
    }

    void OnError(const PlayFab::FPlayFabError& Error)
    {
        UE_LOG(LogTemp, Error, TEXT("RegisterPlayFabUser Failed"));
    }

    FString username;
    FString email;
    FString password;
    PlayFabClientPtr clientAPI = nullptr;
};


#define ADD_TEST(Name) TestFunctions.Add(&PlayFabApiTestSuite::Name); TestFunctionNames.Add(TEXT(#Name));
class PlayFabApiTestSuite : public FAutomationTestBase
{
    typedef bool (PlayFabApiTestSuite::*TestFunc)();

public:
    PlayFabApiTestSuite(const FString& InName)
        : FAutomationTestBase(InName, false)
    {
        ADD_TEST(Test_LoginOrRegister);
    }

    virtual uint32 GetTestFlags() const override { return EAutomationTestFlags::ATF_Editor; }
    virtual bool IsStressTest() const { return false; }
    virtual uint32 GetRequiredDeviceNum() const override { return 1; }

protected:
    virtual FString GetBeautifiedTestName() const override { return "PlayFabApiTests"; }
    virtual void GetTests(TArray<FString>& OutBeautifiedNames, TArray <FString>& OutTestCommands) const override
    {
        for (const FString& TestName : TestFunctionNames)
        {
            OutBeautifiedNames.Add(TestName);
            OutTestCommands.Add(TestName);
        }
    }

    bool RunTest(const FString& Parameters) override
    {
        clientAPI = IPlayFabModuleInterface::Get().GetClientAPI();
        TestTrue(TEXT("The ClientAPI reports itself as invalid."), clientAPI.IsValid());
        if (clientAPI.IsValid())
        {
            // find the matching test
            TestFunc TestFunction = nullptr;
            for (int32 i = 0; i < TestFunctionNames.Num(); ++i)
            {
                if (TestFunctionNames[i] == Parameters)
                {
                    TestFunction = TestFunctions[i];
                    return (this->*TestFunction)();
                }
            }
        }
        return false;
    }

    bool Test_LoginOrRegister()
    {
        ADD_LATENT_AUTOMATION_COMMAND(PlayFabApiTest_LoginWithEmail(false, TEXT("paul"), TEXT("paul@playfab.com"), TEXT("testPassword")));

        return true;
    };

    PlayFabClientPtr clientAPI;
    TArray<TestFunc> TestFunctions;
    TArray<FString> TestFunctionNames;
};

namespace
{
    PlayFabApiTestSuite FPlayFabApiTestsAutomationTestInstance(TEXT("FPlayFabApiTests"));
}
