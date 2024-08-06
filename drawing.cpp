#include "includes.h"

using namespace SDK;

void drawMenu()
{
	if (ShowMenu) {
		ImGui::SetNextWindowSize(ImVec2(850, 470));
		ImGui::Begin(appendFeature, nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);
		ImGui::BeginChild("child", ImVec2(218, 428), true);
		if (ImGui::Button("PLAYERS", ImVec2(200, 100))) {
			currTab = 0;
		}
		if (ImGui::Button("ITEMS", ImVec2(200, 100))) {
			currTab = 1;
		}
		if (ImGui::Button("AIM", ImVec2(200, 100))) {
			currTab = 2;
		}
		if (ImGui::Button("MISC", ImVec2(200, 100))) {
			currTab = 3;
		}
		ImGui::EndChild();

		ImGui::SameLine();
		ImGui::BeginChild("child1");

		if (currTab == 0)
		{
			ImGui::Checkbox("Enable ESP", &playersESP);
			if (playersESP)
			{
				ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 20.f);
				ImGui::Checkbox("Family ESP", &familyESP);

				ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 20.f);
				ImGui::Checkbox("Victim ESP", &victimESP);

				if (familyESP || victimESP) 
				{
					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 40.f);
					ImGui::Checkbox("Box", &boxESP);

					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 40.f);
					ImGui::Checkbox("Player Name", &nicknameESP);

					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 40.f);
					ImGui::Checkbox("Skeleton", &skeletonESP);

					if (skeletonESP)
					{
						ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 60.f);
						ImGui::ColorEdit3("Skeleton Color", (float*)&skeletonColor);
					}

					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 40.f);
					ImGui::Checkbox("Health", &healthESP);

					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 40.f);
					ImGui::Checkbox("Stamina", &staminaESP);

					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 40.f);
					ImGui::Checkbox("Distance", &distESP);

					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 40.f);
					ImGui::Checkbox("Line", &lineESP);

					if (lineESP)
					{
						ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 60.f);
						ImGui::ColorEdit3("Line Color", (float*)&lineColor);
					}

					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 40.f);
					ImGui::Checkbox("Max Range", &maxRange);
					if (!maxRange)
					{
						ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 40.f);
						ImGui::SliderFloat("ESP Range", &ESPRange, 0.f, 2000.f, "%.1f", ImGuiSliderFlags_NoInput);
					}

					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 40.f);
					ImGui::ColorEdit3("Family Color", (float*)&familyColor);

					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 40.f);
					ImGui::ColorEdit3("Victim Color", (float*)&victimColor);
				}
			}
		}
		if (currTab == 1)
		{
			ImGui::Checkbox("Enable ESP", &itemsESP);
			if (itemsESP)
			{
				ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 20.f);
				ImGui::Checkbox("Pickups", &pickupsESP);

				ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 20.f);
				ImGui::Checkbox("Usables", &usablesESP);

				ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 20.f);
				ImGui::Checkbox("Doors", &doorsESP);

				ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 20.f);
				ImGui::Checkbox("Obstacle", &obstacleESP);

				ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 20.f);
				ImGui::Checkbox("Noise Makers", &noisemakerESP);

				ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 20.f);
				ImGui::Checkbox("Exits", &exitESP);

				ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 20.f);
				ImGui::Checkbox("Grandpa", &grandpaESP);

				ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 20.f);
				ImGui::Checkbox("Lines", &itemsLineESP);

				if (itemsLineESP)
				{
					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 40.f);
					ImGui::ColorEdit3("Line Color", (float*)&itemLineColor);
				}

				ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 20.f);
				ImGui::Checkbox("Distance", &itemsDistESP);

				ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 20.f);
				ImGui::Checkbox("Max Range", &itemsMaxRange);
				if (!itemsMaxRange)
				{
					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 20.f);
					ImGui::SliderFloat("ESP Range", &itemsESPRange, 0.f, 2000.f, "%.1f", ImGuiSliderFlags_NoInput);
				}
			}
		}
		if (currTab == 2)
		{
			ImGui::Checkbox("Enable Aim", &aim);
			if (aim) 
			{
				ImGui::SliderFloat("Aim Radius", &aimRadius, 50, 500, "%.1f", ImGuiSliderFlags_NoInput);
				ImGui::ColorEdit3("Circle Color", (float*)&aimColor);
				ImGui::Text("Aim Key: X");
			}

		}
		if (currTab == 3)
		{
			ImGui::SliderFloat("Field of View", &fov, 0.f, 120.f, "%.1f", ImGuiSliderFlags_NoInput);
			ImGui::Checkbox("Custom Speed", &customSpeed);
			if (customSpeed)
			{
				ImGui::SliderFloat("Time Dilation", &timedilation, 0.f, 100.f, "%.1f", ImGuiSliderFlags_NoInput);
			}
			ImGui::Checkbox("Attack Speed", &customAttackSpeed);
			if (customAttackSpeed) 
			{
				ImGui::SliderFloat("Speed", &attackSpeed, defTimeDilation, 2.5f, "%.2f", ImGuiSliderFlags_NoInput);
			}
		}
		ImGui::EndChild();

		ImGui::End();
	}
}

void drawLine(FVector2D W2S, ImColor color, float thickness)
{
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(screenWidth / 2.f, screenHeight / 2.f), ImVec2(W2S.X, W2S.Y), color, thickness);
}

void drawBox(SDK::FVector2D W2S, ImColor color, float thickness) 
{
	ImGui::GetBackgroundDrawList()->AddRect({ W2S.X - boxWidth, W2S.Y - boxHeight }, { W2S.X + boxWidth, W2S.Y + boxHeight }, color, 0.f, 0.f, thickness);
}

void drawText(FVector2D World2Screen, float yOffset, const char* text, float size, ImColor color)
{
	ImFont* Font = ImGui::GetFont();

	ImVec2 textSize = ImGui::CalcTextSize(text);

	Font->Scale = size;

	ImGui::PushFont(Font);

	ImGui::GetBackgroundDrawList()->AddText({ (World2Screen.X - (textSize.x / 2) * (Font->Scale)) - 1.f, World2Screen.Y + yOffset - textSize.y }, ImColor{ 0.f, 0.f, 0.f, 1.f }, text);
	ImGui::GetBackgroundDrawList()->AddText({ (World2Screen.X - (textSize.x / 2) * (Font->Scale)) + 1.f, World2Screen.Y + yOffset - textSize.y }, ImColor{ 0.f, 0.f, 0.f, 1.f }, text);
	ImGui::GetBackgroundDrawList()->AddText({ (World2Screen.X - (textSize.x / 2) * (Font->Scale)) - 1.f, (World2Screen.Y + yOffset - textSize.y) - 1.f }, ImColor{ 0.f, 0.f, 0.f, 1.f }, text);
	ImGui::GetBackgroundDrawList()->AddText({ (World2Screen.X - (textSize.x / 2) * (Font->Scale)) + 1.f, (World2Screen.Y + yOffset - textSize.y) + 1.f }, ImColor{ 0.f, 0.f, 0.f, 1.f }, text);
	ImGui::GetBackgroundDrawList()->AddText({ World2Screen.X - (textSize.x / 2) * (Font->Scale) , World2Screen.Y + yOffset - textSize.y }, color, text);

	Font->Scale = 1.f;

	ImGui::PopFont();
}

void drawHealth(FVector2D World2Screen, ABBQBaseCharacter* pawn)
{
	float curMaxHealth = pawn->AttributeSet->MaxHealth.CurrentValue / (pawn->AttributeSet->MaxHealth.CurrentValue / 100);
	float curHealth = pawn->AttributeSet->Health.CurrentValue / (pawn->AttributeSet->MaxHealth.CurrentValue / 100);

	ImColor color;

	if (curHealth >= 95.f) {

		color = ImColor(0.f, 1.f, 0.f, 1.f);

	}
	else if (curHealth >= 75.f) {

		color = ImColor(1.f, 1.f, 0.f, 1.f);

	}
	else if (curHealth >= 50.f) {

		color = ImColor(1.f, 0.5f, 0.f, 1.f);

	}
	else if (curHealth >= 25.f) {

		color = ImColor(1.f, 0.f, 0.f, 1.f);

	}
	else if (curHealth > 0.f) {

		color = ImColor(0.5f, 0.2f, 0.f, 1.f);

	}
	if (curHealth > 0.f && curHealth <= curMaxHealth)
	{

		ImGui::GetBackgroundDrawList()->AddLine({ World2Screen.X - boxWidth - 10.f, (World2Screen.Y + boxHeight) - (2 * boxWidth * (curHealth / 100.f)) }, { World2Screen.X - boxWidth - 10.f, World2Screen.Y + boxHeight }, ImColor(0.f, 0.f, 0.f, 1.f), 5.f);

		ImGui::GetBackgroundDrawList()->AddLine({ World2Screen.X - boxWidth - 10.f, (World2Screen.Y + boxHeight) - (2 * boxWidth * (curHealth / 100.f)) + 1.f }, { World2Screen.X - boxWidth - 10.f, World2Screen.Y + boxHeight - 1.f }, color, 3.f);

	}
}

void drawStamina(FVector2D World2Screen, ABBQBaseCharacter* pawn)
{
	float curMaxStamina = pawn->AttributeSet->MaxStamina.CurrentValue / (pawn->AttributeSet->MaxStamina.CurrentValue / 100);
	float curStamina = pawn->AttributeSet->Stamina.CurrentValue / (pawn->AttributeSet->MaxStamina.CurrentValue / 100);

	ImColor color;
	color = ImColor(0.f, 0.f, 1.f, 1.f);

	if (curStamina > 0.f && curStamina <= curMaxStamina)
	{

		ImGui::GetBackgroundDrawList()->AddLine({ World2Screen.X - boxWidth - 15.f, (World2Screen.Y + boxHeight) - (2 * boxWidth * (curStamina / 100.f)) }, { World2Screen.X - boxWidth - 15.f, World2Screen.Y + boxHeight }, ImColor(0.f, 0.f, 0.f, 1.f), 5.f);

		ImGui::GetBackgroundDrawList()->AddLine({ World2Screen.X - boxWidth - 15.f, (World2Screen.Y + boxHeight) - (2 * boxWidth * (curStamina / 100.f)) + 1.f }, { World2Screen.X - boxWidth - 15.f, World2Screen.Y + boxHeight - 1.f }, color, 3.f);

	}
}

void drawSkeleton(SDK::USkeletalMeshComponent* mesh, ImColor color)
{
	auto names = mesh->GetAllSocketNames();

	for (int x = 0; x < names.Num(); x++)
	{
		//checks
		if (!names.IsValid()) continue;

		if (!names.IsValidIndex(x)) continue;

		//filters for tcsm
		if (names[x].ToString().contains("ik") ||
			names[x].ToString().contains("root") ||
			names[x].ToString().contains("attach") ||
			names[x].ToString().contains("breast") ||
			names[x].ToString().contains("socket") ||
			names[x].ToString().contains("hair") ||
			names[x].ToString().contains("eyeball") ||
			names[x].ToString().contains("butt")) continue;

		auto ogi = World->OwningGameInstance;

		if (ogi == nullptr) continue;

		auto lp = ogi->LocalPlayers[0];

		if (lp == nullptr) continue;

		auto myCtrl = lp->PlayerController;

		if (myCtrl == nullptr) continue;

		auto boneIndex = mesh->GetBoneIndex(names[x]);

		if (boneIndex <= 1) continue;

		auto boneName = mesh->GetBoneName(boneIndex);

		auto parentBoneName = mesh->GetParentBone(boneName);

		if (parentBoneName.ToString().contains("ik") ||
			parentBoneName.ToString().contains("root") ||
			parentBoneName.ToString().contains("attach") ||
			parentBoneName.ToString().contains("breast") ||
			parentBoneName.ToString().contains("socket") ||
			parentBoneName.ToString().contains("hair") ||
			parentBoneName.ToString().contains("eyeball") ||
			parentBoneName.ToString().contains("butt")) continue;

		auto boneLocation = mesh->GetSocketLocation(boneName);
		auto parentBoneLocation = mesh->GetSocketLocation(parentBoneName);

		FVector2D bone2D;
		FVector2D parentBone2D;

		myCtrl->ProjectWorldLocationToScreen(boneLocation, &bone2D, true);
		myCtrl->ProjectWorldLocationToScreen(parentBoneLocation, &parentBone2D, true);

		ImGui::GetBackgroundDrawList()->AddLine({ parentBone2D.X, parentBone2D.Y }, { bone2D.X, bone2D.Y }, color, 1.f);
	}
}