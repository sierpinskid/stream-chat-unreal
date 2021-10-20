﻿#pragma once

#include "CoreMinimal.h"
#include "JsonObjectWrapper.h"
#include "PaginationOptions.h"
#include "Request/Channel/SortOptionDto.h"
#include "Response/Reaction/ReactionResponseDto.h"

struct FReactionRequestDto;
class FHttpClient;
class FRequestBuilder;
class FTokenManager;
struct FChannelResponseDto;
struct FChannelStateResponseDto;
struct FChannelsResponseDto;
struct FHttpResponse;
struct FMessageRequestDto;
struct FMessageResponseDto;
struct FSortOption;

template <class T>
using TCallback = TFunction<void(const T&)>;

enum class EChannelFlags : uint8
{
    None = 0,

    // Refresh channel state
    State = 1 << 0,

    // Start watching the channel
    Watch = 1 << 1,

    // Fetch user presence info
    Presence = 1 << 2,
};
ENUM_CLASS_FLAGS(EChannelFlags);

class STREAMCHATAPI_API FChatApi
{
public:
    explicit FChatApi(const FString& InApiKey, const FString& InHost, const TSharedRef<FTokenManager>&);

    void GetOrCreateChannel(
        TCallback<FChannelStateResponseDto> Callback,
        const FString& ChannelType,
        const FString& ConnectionId,
        const FString& ChannelId = {},
        EChannelFlags Flags = EChannelFlags::Watch) const;

    void SendNewMessage(
        const FString& ChannelType,
        const FString& ChannelId,
        const FMessageRequestDto& MessageRequest,
        bool bSkipPush = false,
        TCallback<FMessageResponseDto> Callback = {}) const;

    void UpdateMessage(const FMessageRequestDto& MessageRequest, TCallback<FMessageResponseDto> Callback = {}) const;
    void DeleteMessage(const FString& Id, bool bHard = false, TCallback<FMessageResponseDto> Callback = {}) const;

    void SendReaction(
        const FString& MessageId,
        const FReactionRequestDto& ReactionRequest,
        bool bEnforceUnique = true,
        bool bSkipPush = false,
        TCallback<FReactionResponseDto> Callback = {});

    /**
     * Query channels with filter query
     * @param ConnectionId
     * @param Filter
     * @param SortOptions
     * @param MemberLimit
     * @param MessageLimit
     * @param Flags
     * @param PaginationOptions
     * @param Callback
     */
    void QueryChannels(
        TCallback<FChannelsResponseDto> Callback,
        const FString& ConnectionId,
        const TOptional<FJsonObjectWrapper>& Filter = {},
        const TArray<FSortOptionDto>& SortOptions = {},
        TOptional<uint32> MemberLimit = {},
        TOptional<uint32> MessageLimit = {},
        EChannelFlags Flags = EChannelFlags::State | EChannelFlags::Watch,
        FPaginationOptions PaginationOptions = {}) const;

private:
    FString BuildUrl(const FString& Path) const;

    void AddAuth(FRequestBuilder&) const;
    static void OnError(const FHttpResponse&);

    TSharedPtr<FTokenManager> TokenManager;
    FString ApiKey;

    TSharedPtr<FHttpClient> Client;
    FString Scheme;
    FString Host;
};
