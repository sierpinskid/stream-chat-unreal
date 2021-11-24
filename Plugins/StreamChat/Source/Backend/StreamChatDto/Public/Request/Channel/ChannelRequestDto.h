﻿// Copyright Stream.IO, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "ChannelRequestDto.generated.h"

/**
 * @brief #/components/schemas/ChannelRequest
 * @ingroup StreamChatDto
 */
USTRUCT()
struct FChannelRequestDto
{
    GENERATED_BODY()

    // TODO Auto translation
    // TODO ConfigOverrides
    // TODO Disabled, Frozen.

    // TODO it seems this should really be a ChannelMemberRequest
    UPROPERTY()
    TArray<FString> Members;

    // TODO OwnCapabilities

    // TODO Team
};
