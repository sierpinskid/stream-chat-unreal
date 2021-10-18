﻿// Copyright Stream.IO, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "User.h"

#include "Message.generated.h"

struct FMessageDto;
struct FMessageRequestDto;

UENUM(BlueprintType)
enum class EMessageSendState : uint8
{
    Sending,
    Sent,
    Updating,
    Deleting,
    Failed
};

UENUM(BlueprintType)
enum class EMessageType : uint8
{
    Regular,
    Ephemeral,
    Error,
    Reply,
    System,
    Deleted
};

/**
 * A Stream Chat message
 */
USTRUCT(BlueprintType)
struct FMessage
{
    GENERATED_BODY()

    FMessage() = default;
    // From server responses
    explicit FMessage(const FMessageDto&);
    // Updating
    explicit operator FMessageRequestDto() const;
    // Sending
    explicit FMessage(const FMessageRequestDto&, const FUser& SendingUser);

    /// The message ID. This is either created by Stream or set client side when
    /// the message is added.
    UPROPERTY()
    FString Id;

    /// The text of this message
    // TODO Optional
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stream Chat Message")
    FString Text;

    /// Sending state of the message
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stream Chat Message")
    EMessageSendState State;

    /// User who sent the message
    // TODO Optional
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stream Chat Message")
    FUser User;

    /// The message type
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stream Chat Message")
    EMessageType Type;

    /// The list of user mentioned in the message
    UPROPERTY()
    TArray<FUser> MentionedUsers;

    /// Reserved field indicating when the message was updated last time.
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stream Chat Message")
    FDateTime UpdatedAt;

    /// Reserved field indicating when the message was deleted.
    TOptional<FDateTime> DeletedAt;

    // TODO rest of fields
};
