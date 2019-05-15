// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "PuzzleGameHUD.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "TextureResource.h"
#include "CanvasItem.h"
#include "UObject/ConstructorHelpers.h"

APuzzleGameHUD::APuzzleGameHUD()
{
	// Set the crosshair texture
	static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("/Game/FirstPerson/Textures/FirstPersonCrosshair"));
	CrosshairTex = CrosshairTexObj.Object;

	// Set font
	static ConstructorHelpers::FObjectFinder<UFont> FontObj(TEXT("/Engine/EngineFonts/RobotoDistanceField"));
	Font = FontObj.Object;
	num = 0;
	instructions[0] = "What";
	instructions[1] = " are";
	instructions[2] = " you";
	instructions[3] = " doing";
	instructions[4] = " in";
	instructions[5] = " bed";
	instructions[6] = " so";
	instructions[7] = " late?";
	instructions[8] = "\n";
	instructions[9] = "Find";
	instructions[10] = " the";
	instructions[11] = " key";
	instructions[12] = " to";
	instructions[13] = " the";
	instructions[14] = " door.";
	i = 0;
	TextInput = "";
	timer = 0;
	TimerOn = true;
	alphaa = 1.0f;
	Instruction = "What are you doing in bed so late?\n Find the key to the door.";
}

void APuzzleGameHUD::DrawHUD()
{
	Super::DrawHUD();

	// Draw very simple crosshair

	// find center of the Canvas
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

	// offset by half the texture's dimensions so that the center of the texture aligns with the center of the Canvas
	const FVector2D CrosshairDrawPosition( (Center.X - 8.0f),
										   (Center.Y - 8.0f));

	// draw the crosshair
	FCanvasTileItem TileItem( CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem( TileItem );


	for (TObjectIterator<AInstructionClass> Itr; Itr; ++Itr)
	{
		if (Itr->GetName() == "InstructionClass_1") {
			/*if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Green, FString::Printf(TEXT("%s"),*Itr->getInstructions()));
			}*/
			UGameViewportClient* Viewport = GetWorld()->GetGameViewport();
			FIntPoint ViewSize = Viewport->Viewport->GetSizeXY();
			const FVector2D ViewportSize = FVector2D(GEngine->GameViewport->Viewport->GetSizeXY());
			const FVector2D  ViewportCenter = FVector2D(ViewportSize.X / 2, ViewportSize.Y / 2);
			FText InstructionText = FText::FromString(Itr->getInstructions());
			FCanvasTextItem Text3(FVector2D(ViewSize.X / 2 - 200.0f, ViewSize.Y / 16), InstructionText, Font, FLinearColor::Yellow);

			Text3.Scale.Set(1.25f, 1.25f);

			Canvas->DrawItem(Text3);

			FText ControlText = FText::FromString(Itr->getControlText());
			//FLinearColor ControlFontColour = FLinearColor(1000.0f, 1000.0f, 1000.0f);
			FCanvasTextItem Text4(FVector2D(ViewSize.X / 2 - 150.0f, ViewSize.Y * 15 / 16), ControlText, Font, FLinearColor::Blue);

			Text4.Scale.Set(1.25f, 1.25f);

			Canvas->DrawItem(Text4);
		}
		else {
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Green, FString::Printf(TEXT("%s"), *Itr->GetName()));
			}
		}
	}

	for (TObjectIterator<AWorldClock> Itr; Itr; ++Itr)
	{
		if (Itr->GetName() == "WorldClock_1") {
			if (GetWorld())
			{
				UGameViewportClient* Viewport = GetWorld()->GetGameViewport();
				FIntPoint ViewSize = Viewport->Viewport->GetSizeXY();
				const FVector2D ViewportSize = FVector2D(GEngine->GameViewport->Viewport->GetSizeXY());
				const FVector2D  ViewportCenter = FVector2D(ViewportSize.X / 2, ViewportSize.Y / 2);
				/*if (GEngine)
				 {
					GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Green, FString::Printf(TEXT("Object Found!, %s"), *Itr->GetTimerText()));
				 }*/
				FText TimerText = FText::FromString(Itr->GetTimerText());
				//FLinearColor TimerFontColour = FLinearColor(1.0f, 1.0f, 1.0f);
				FCanvasTextItem Text1(FVector2D(ViewSize.X / 16, ViewSize.Y / 16), TimerText, Font, FLinearColor::Green);

				FText GameOverText = FText::FromString("Game Over!");
				//FLinearColor GameOverFontColour = FLinearColor(10.0f, 10.0f, 10.0f);
				FCanvasTextItem Text2(FVector2D(ViewSize.X / 2 - 300.0f, ViewSize.Y / 2), GameOverText, Font, FLinearColor::Red);

				Text1.Scale.Set(2.5f, 2.5f);
				//Text1.Scale.Set(ViewSize.X/16, ViewSize.Y/16);

				Text2.Scale.Set(5.0f, 5.0f);

				//draw text
				if (Itr->EndOfTimer()) {
					Canvas->DrawItem(Text2);
				}
				else {
					Canvas->DrawItem(Text1);
				}

				// draw instructions
				if (i < 15 && timer % 4 == 0) {
					TextInput += instructions[i];
					i++;
					if (i >= 15) {
						TimerOn = false;
					}
				}
				if (TimerOn) {
					timer++;
				}

				/*FText InstructionText = FText::FromString(TextInput);
				//FLinearColor InstructionFontColour = FLinearColor(100.0f, 100.0f, 100.0f);
				FCanvasTextItem Text3(FVector2D(ViewSize.X / 2 - 200.0f, ViewSize.Y / 16), InstructionText, Font, FLinearColor::Yellow);

				Text3.Scale.Set(1.25f, 1.25f);

				Canvas->DrawItem(Text3);*/

				/*FText ControlText = FText::FromString("Press E to interact with objects.");
				//FLinearColor ControlFontColour = FLinearColor(1000.0f, 1000.0f, 1000.0f);
				FCanvasTextItem Text4(FVector2D(ViewSize.X / 2 - 150.0f, ViewSize.Y * 15 / 16), ControlText, Font, FLinearColor::Blue);

				Text4.Scale.Set(1.25f, 1.25f);

				Canvas->DrawItem(Text4);*/
			}
		}
	}




/*
	// draw a text on canvas
	if (num < 1) {
		Clock = GetWorld()->SpawnActor<AWorldClock>(GetActorLocation(), GetActorRotation());
		num++;
	}
	FText TimerText = FText::FromString(Clock->GetTimerText());
	FLinearColor TimerFontColour = FLinearColor(1.0f, 1.0f, 1.0f);
	FCanvasTextItem Text1(FVector2D(25.0f, 25.0f), TimerText, Font, TimerFontColour);

	FText GameOverText = FText::FromString("Game Over!");
	FLinearColor GameOverFontColour = FLinearColor(10.0f, 10.0f, 10.0f);
	FCanvasTextItem Text2(FVector2D(375.0f, 250.0f), GameOverText, Font, GameOverFontColour);

	//Text Scale
	Text1.Scale.Set(2.5f, 2.5f);

	//Text Scale
	Text2.Scale.Set(5.0f, 5.0f);

	//draw text
	if (Clock->EndOfTimer()) {
		Canvas->DrawItem(Text2);
	}
	else {
		Canvas->DrawItem(Text1);
	}

	// draw instructions
	if (i < 15 && timer % 4 == 0) {
		TextInput += instructions[i];
		i++;
		if (i >= 15) {
			TimerOn = false;
		}
	}
	else if (i >= 15) {
		++i;
		alphaa = FMath::Clamp<float>(alphaa - .01f, 0, 100);
	}
	if (TimerOn) {
		timer++;
	}

	FText InstructionText = FText::FromString(TextInput);
	FLinearColor InstructionFontColour = FLinearColor(100.0f, 100.0f, 100.0f, alphaa);
	FCanvasTextItem Text3(FVector2D(500.0f, 50.0f), InstructionText, Font, InstructionFontColour);

	//Text Scale
	Text3.Scale.Set(1.25f, 1.25f);

	//draw text

	Canvas->DrawItem(Text3);

	// draw control instructions
	FText ControlText = FText::FromString("Press E to interact with objects.");
	FLinearColor ControlFontColour = FLinearColor(1000.0f, 1000.0f, 1000.0f);
	FCanvasTextItem Text4(FVector2D(437.5f, 625.0f), ControlText, Font, ControlFontColour);

	//Text Scale
	Text4.Scale.Set(1.25f, 1.25f);

	//draw text
	Canvas->DrawItem(Text4);


*/
}
