#pragma once

#include "CoreMinimal.h"
#include "Event/Abstract/ChatEvent.h"
#include "OwnUserDto.h"

#include "HealthCheckEvent.generated.h"

/**
 * Represents an event that happened in Stream Chat
 */
USTRUCT()
struct FHealthCheckEvent : public FChatEvent
{
    GENERATED_BODY()

    inline static FName StaticType = TEXT("health.check");

    UPROPERTY()
    FString ConnectionId;

    UPROPERTY()
    FOwnUserDto Me;

    // TODO everything else
};
