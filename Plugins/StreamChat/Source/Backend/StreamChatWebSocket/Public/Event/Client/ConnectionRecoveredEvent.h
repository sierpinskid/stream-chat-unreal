// Copyright Stream.IO, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Event/Abstract/LocalEvent.h"

#include "ConnectionRecoveredEvent.generated.h"

/**
 * When the state of the connection changed
 */
USTRUCT()
struct FConnectionRecoveredEvent : public FLocalEvent
{
    GENERATED_BODY()

    inline static FName StaticType = TEXT("connection.recovered");
};
