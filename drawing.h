#pragma once

void drawMenu();

void drawLine(SDK::FVector2D W2S, ImColor color, float thickness);

void drawBox(SDK::FVector2D W2S, ImColor color, float thickness);

void drawText(SDK::FVector2D World2Screen, float yOffset, const char* text, float size, ImColor color);

void drawHealth(SDK::FVector2D World2Screen, SDK::ABBQBaseCharacter* pawn);

void drawStamina(SDK::FVector2D World2Screen, SDK::ABBQBaseCharacter* pawn);

void drawSkeleton(SDK::USkeletalMeshComponent* mesh, ImColor color);