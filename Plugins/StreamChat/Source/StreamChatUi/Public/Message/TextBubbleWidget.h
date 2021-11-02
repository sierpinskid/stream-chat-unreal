﻿// Copyright Stream.IO, Inc. All Rights Reserved.

#pragma once

#include "BubbleStackPosition.h"
#include "BubbleStackSide.h"
#include "Channel/Message.h"
#include "Components/Border.h"
#include "Components/TextBlock.h"
#include "CoreMinimal.h"
#include "StreamUserWidget.h"

#include "TextBubbleWidget.generated.h"

/**
 *
 */
UCLASS()
class STREAMCHATUI_API UTextBubbleWidget final : public UStreamUserWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Stream Chat")
    void Setup(const FMessage& InMessage, EBubbleStackSide InSide, EBubbleStackPosition InPosition);

protected:
    UPROPERTY(meta = (BindWidget))
    UTextBlock* TextBlock;
    UPROPERTY(meta = (BindWidget))
    UBorder* Border;

    UPROPERTY(EditAnywhere, Category = Bubble)
    UTexture2D* MaskOpeningTexture;
    UPROPERTY(EditAnywhere, Category = Bubble)
    UTexture2D* MaskEndTexture;
    UPROPERTY(EditAnywhere, Category = Bubble)
    UTexture2D* YouOpeningTexture;
    UPROPERTY(EditAnywhere, Category = Bubble)
    UTexture2D* YouEndTexture;
    UPROPERTY(EditAnywhere, Category = Bubble)
    FLinearColor MeBubbleColor;
    UPROPERTY(EditAnywhere, Category = Bubble)
    FLinearColor DeletedBubbleColor;
    UPROPERTY(EditAnywhere, Category = Text)
    FLinearColor NormalTextColor;
    UPROPERTY(EditAnywhere, Category = Text)
    FLinearColor DeletedTextColor;

private:
    virtual void OnSetup() override;

    UTexture2D* GetBubbleTexture() const;
    const FLinearColor& GetBubbleColor() const;
    const FLinearColor& GetTextColor() const;
    FText GetText() const;

    UPROPERTY(EditAnywhere, Category = Setup)
    FMessage Message;
    UPROPERTY(EditAnywhere, Category = Setup)
    EBubbleStackPosition Position;
    UPROPERTY(EditAnywhere, Category = Setup)
    EBubbleStackSide Side;
};
