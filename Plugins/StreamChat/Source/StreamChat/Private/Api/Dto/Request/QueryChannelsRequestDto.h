﻿// Copyright Stream.IO, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FilterDto.h"
#include "SortOptionDto.h"

#include "QueryChannelsRequestDto.generated.h"

/**
 * #/components/schemas/QueryChannelsRequest
 * @see https://getstream.io/chat/docs/rest/#channels-querychannels-request
 */
USTRUCT()
struct FQueryChannelsRequestDto
{
    GENERATED_BODY()

    /// WebSocket connection ID to interact with
    UPROPERTY()
    FString ConnectionId;

    UPROPERTY()
    FFilterDto FilterConditions;

    /// Number of channels to limit
    UPROPERTY()
    uint32 Limit;

    /// Number of members to limit
    UPROPERTY()
    uint32 MemberLimit;

    /// Number of messages to limit
    UPROPERTY()
    uint32 MessageLimit;

    /// Channel pagination offset
    UPROPERTY()
    uint32 Offset;

    /// Fetch user presence info
    UPROPERTY()
    bool bPresence;

    /// List of sort parameters
    UPROPERTY()
    TArray<FSortOptionDto> Sort;

    /// Refresh channel state
    UPROPERTY()
    bool bState;

    /// Start watching the channel
    UPROPERTY()
    bool bWatch;
};
