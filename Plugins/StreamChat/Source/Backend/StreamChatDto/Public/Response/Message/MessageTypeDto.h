﻿#pragma once

#include "CoreMinimal.h"

#include "MessageTypeDto.generated.h"

/**
 * https://getstream.io/chat/docs/other-rest/message_format/#message-types
 */
UENUM()
enum class EMessageTypeDto : uint8
{
    Regular,
    Ephemeral,
    Error,
    Reply,
    System,
    Deleted
};
