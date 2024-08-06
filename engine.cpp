#include "includes.h"

using namespace SDK;

void mainLoop()
{
	World = UWorld::GetWorld();

	if (World != nullptr) 
	{
		if (defTimeDilation == 0.f)
		{
			auto settings = World->K2_GetWorldSettings();
			if (settings != nullptr)
			{
				defTimeDilation = settings->MatineeTimeDilation;
			}
		}

		if (oldFov != fov) {
			auto controller = World->OwningGameInstance->LocalPlayers[0]->PlayerController;
			controller->FOV(fov);
			oldFov = fov;
		}

		if (customSpeed)
		{
			if (oldTimeDilation != timedilation)
			{
				auto settings = World->K2_GetWorldSettings();
				if (settings != nullptr)
				{
					settings->MaxGlobalTimeDilation = 100.f;
					settings->MatineeTimeDilation = timedilation;
					oldTimeDilation = timedilation;
				}
			}
			else if (timedilation != defTimeDilation)
			{
				auto settings = World->K2_GetWorldSettings();
				if (settings != nullptr)
				{
					settings->MaxGlobalTimeDilation = 100.f;
					settings->MatineeTimeDilation = timedilation;
					oldTimeDilation = timedilation;
				}
			}
		}
		else
		{
			auto settings = World->K2_GetWorldSettings();
			if (settings != nullptr)
			{
				if (settings->MatineeTimeDilation != defTimeDilation)
					settings->MatineeTimeDilation = defTimeDilation;
			}
		}
		if (customAttackSpeed)
		{
			auto settings = World->K2_GetWorldSettings();
			if (settings != nullptr)
			{
				if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
				{
					settings->MatineeTimeDilation = attackSpeed;
				}
				else {
					if (customSpeed)
					{
						settings->MatineeTimeDilation = timedilation;
					}
					else {
						settings->MatineeTimeDilation = defTimeDilation;
					}
				}

			}
		}


		if (allowCrouch) {
			if (GetAsyncKeyState(0xA2) & 0x8000)
			{
				auto controller = World->OwningGameInstance->LocalPlayers[0]->PlayerController;
				auto bbq = static_cast<ABBQGameSessionCharacter*>(controller->Character);
				bbq->Crouch(false);
			}
			else {
				auto controller = World->OwningGameInstance->LocalPlayers[0]->PlayerController;
				auto bbq = static_cast<ABBQGameSessionCharacter*>(controller->Character);
				bbq->UnCrouch(false);
			}
		}

		if (itemsESP)
		{
			auto level = World->PersistentLevel;

			if (level != nullptr) {

				auto actorsArray = level->Actors;

				for (int i = 0; i < actorsArray.Num(); i++) {

					if (!actorsArray.IsValidIndex(i)) continue;

					if (actorsArray[i] == nullptr) continue;

					auto gi = World->OwningGameInstance;

					if (gi == nullptr) continue;

					auto lp = gi->LocalPlayers;

					if (!lp.IsValidIndex(0)) continue;

					if (lp[0] == nullptr) continue;

					auto myCtrl = lp[0]->PlayerController;

					if (myCtrl == nullptr) continue;

					auto myPawn = myCtrl->Character;

					if (myPawn == nullptr) continue;

					auto currLoc = actorsArray[i]->K2_GetActorLocation();

					auto myLoc = myPawn->K2_GetActorLocation();

					int distance = (int)(UKismetMathLibrary::Vector_Distance(myLoc, currLoc) / 100);

					FVector2D W2S;

					myCtrl->ProjectWorldLocationToScreen(currLoc, &W2S, true);

					auto name = actorsArray[i]->GetName();

					char buf[50];

					sprintf_s(buf, ("[ %i m ]\n"), distance);

					auto nameDist = buf;

					if (itemsMaxRange || distance <= itemsESPRange)
					{
						if (W2S.X || W2S.Y)
						{
							if (pickupsESP)
							{
								if (name.contains("Fuse") && name.contains("Pickup"))
								{
									drawText(W2S, 0.f, "Fuse", 0.95f, ImColor(0.5f, 0.f, 1.f, 1.f));
									if (itemsDistESP)
									{
										drawText(W2S, 20.f, nameDist, 0.8f, ImColor(0.5f, 0.f, 1.f, 1.f));
									}
									if (itemsLineESP)
									{
										drawLine(W2S, itemLineColor, 1.f);
									}
								}
								if (name.contains("BP_LargeHealthPickup") && !name.contains("Dressed"))
								{
									drawText(W2S, 0.f, "Large Health", 0.95f, ImColor(0.f, 1.f, 1.f, 1.f));
									if (itemsDistESP)
									{
										drawText(W2S, 20.f, nameDist, 0.8f, ImColor(0.f, 1.f, 1.f, 1.f));
									}
									if (itemsLineESP)
									{
										drawLine(W2S, itemLineColor, 1.f);
									}
								}
								if (name.contains("BP_SmallHealthPickup") && !name.contains("Dressed"))
								{
									drawText(W2S, 0.f, "Small Health", 0.95f, ImColor(0.f, 1.f, 1.f, 1.f));
									if (itemsDistESP)
									{
										drawText(W2S, 20.f, nameDist, 0.8f, ImColor(0.f, 1.f, 1.f, 1.f));
									}
									if (itemsLineESP)
									{
										drawLine(W2S, itemLineColor, 1.f);
									}
								}
								if (name.contains("BP_LockPickup"))
								{
									drawText(W2S, 0.f, "Lock", 0.95f, ImColor(0.f, 0.f, 0.8f, 1.f));
									if (itemsDistESP)
									{
										drawText(W2S, 20.f, nameDist, 0.8f, ImColor(0.f, 0.f, 0.8f, 1.f));
									}
									if (itemsLineESP)
									{
										drawLine(W2S, itemLineColor, 1.f);
									}
								}
								if (name.contains("BP_SissyPowderPickup"))
								{
									drawText(W2S, 0.f, "Powder", 0.95f, ImColor(0.5f, 1.f, 0.f, 1.f));
									if (itemsDistESP)
									{
										drawText(W2S, 20.f, nameDist, 0.8f, ImColor(0.5f, 1.f, 0.f, 1.f));
									}
									if (itemsLineESP)
									{
										drawLine(W2S, itemLineColor, 1.f);
									}
								}
								if (name.contains("BP_ShardPickup"))
								{
									drawText(W2S, 0.f, "Bone Shard", 0.95f, ImColor(0.9f, 0.9f, 0.9f, 1.f));
									if (itemsDistESP)
									{
										drawText(W2S, 20.f, nameDist, 0.8f, ImColor(0.9f, 0.9f, 0.9f, 1.f));
									}
									if (itemsLineESP)
									{
										drawLine(W2S, itemLineColor, 1.f);
									}
								}
								if (name.contains("BP_UnlockToolPickup"))
								{
									drawText(W2S, 0.f, "Unlock Tool", 0.95f, ImColor(0.f, 0.f, 1.f, 1.f));
									if (itemsDistESP)
									{
										drawText(W2S, 20.f, nameDist, 0.8f, ImColor(0.f, 0.f, 1.f, 1.f));
									}
									if (itemsLineESP)
									{
										drawLine(W2S, itemLineColor, 1.f);
									}
								}
								if (name.contains("BP_WaterValve"))
								{
									drawText(W2S, 0.f, "Water Valve", 0.95f, ImColor(1.f, 0.f, 0.5f, 1.f));
									if (itemsDistESP)
									{
										drawText(W2S, 20.f, nameDist, 0.8f, ImColor(1.f, 0.f, 0.5f, 1.f));
									}
									if (itemsLineESP)
									{
										drawLine(W2S, itemLineColor, 1.f);
									}
								}
							}
							if (usablesESP) {
								if (name.contains("BP_BloodBucket_Dressed"))
								{
									drawText(W2S, 0.f, "Blood Bucket", 0.95f, ImColor(1.f, 0.f, 0.f, 1.f));
									if (itemsDistESP)
									{
										drawText(W2S, 20.f, nameDist, 0.8f, ImColor(1.f, 0.f, 0.f, 1.f));
									}
									if (itemsLineESP)
									{
										drawLine(W2S, itemLineColor, 1.f);
									}
								}
								if (name.contains("BP_Fusebox")) {
									drawText(W2S, 0.f, "Fuse Box", 0.95f, ImColor(0.f, 0.f, 0.8f, 1.f));
									if (itemsDistESP)
									{
										drawText(W2S, 20.f, nameDist, 0.8f, ImColor(0.f, 0.f, 0.8f, 1.f));
									}
									if (itemsLineESP)
									{
										drawLine(W2S, itemLineColor, 1.f);
									}
								}
								if (name.contains("BP_BoneShardDispenser"))
								{
									drawText(W2S, 0.f, "Pile of Bones", 0.95f, ImColor(0.8f, 0.8f, 0.8f, 1.f));
									if (itemsDistESP)
									{
										drawText(W2S, 20.f, nameDist, 0.8f, ImColor(0.8f, 0.8f, 0.8f, 1.f));
									}
									if (itemsLineESP)
									{
										drawLine(W2S, itemLineColor, 1.f);
									}
								}
								if (name.contains("BP_ToolBoxDispenser"))
								{
									drawText(W2S, 0.f, "Tool Box", 0.95f, ImColor(0.f, 0.f, 0.8f, 1.f));
									if (itemsDistESP)
									{
										drawText(W2S, 20.f, nameDist, 0.8f, ImColor(0.f, 0.f, 0.8f, 1.f));
									}
									if (itemsLineESP)
									{
										drawLine(W2S, itemLineColor, 1.f);
									}
								}
								if (name.contains("Hiding"))
								{
									drawText(W2S, 0.f, "Hiding Spot", 0.95f, ImColor(0.2f, 1.f, 0.5f, 1.f));
									if (itemsDistESP)
									{
										drawText(W2S, 20.f, nameDist, 0.8f, ImColor(0.2f, 1.f, 0.5f, 1.f));
									}
									if (itemsLineESP)
									{
										drawLine(W2S, itemLineColor, 1.f);
									}
								}
							}
							if (doorsESP) {
								if (name.contains("SlidingDoor"))
								{
									drawText(W2S, 0.f, "Door", 0.95f, ImColor(0.7f, 0.5f, 0.8f, 1.f));
									if (itemsDistESP)
									{
										drawText(W2S, 20.f, nameDist, 0.8f, ImColor(0.7f, 0.5f, 0.8f, 1.f));
									}
									if (itemsLineESP)
									{
										drawLine(W2S, itemLineColor, 1.f);
									}
								}
							}
							if (grandpaESP) {
								if (name.contains("BP_BBQGrandpa"))
								{
									drawText(W2S, 0.f, "Grandpa", 0.95f, ImColor(1.f, 1.f, 0.f, 1.f));
									if (itemsDistESP)
									{
										drawText(W2S, 20.f, nameDist, 0.8f, ImColor(1.f, 1.f, 0.f, 1.f));
									}
									if (itemsLineESP)
									{
										drawLine(W2S, itemLineColor, 1.f);
									}
								}
							}
							if (noisemakerESP) {
								if (name.contains("BP_NoiseMaker_Chicken"))
								{
									drawText(W2S, 0.f, "Chicken", 0.95f, ImColor(1.f, 1.f, 1.f, 1.f));
									if (itemsDistESP)
									{
										drawText(W2S, 20.f, nameDist, 0.8f, ImColor(1.f, 1.f, 1.f, 1.f));
									}
									if (itemsLineESP)
									{
										drawLine(W2S, itemLineColor, 1.f);
									}
								}
								if (name.contains("BP_NoiseMaker_BoneChime"))
								{
									drawText(W2S, 0.f, "Bone Chime", 0.95f, ImColor(1.f, 1.f, 1.f, 1.f));
									if (itemsDistESP)
									{
										drawText(W2S, 20.f, nameDist, 0.8f, ImColor(1.f, 1.f, 1.f, 1.f));
									}
									if (itemsLineESP)
									{
										drawLine(W2S, itemLineColor, 1.f);
									}
								}
							}
							if (obstacleESP) {
								if (name.contains("BP_Clambering_GenericObstacle"))
								{
									drawText(W2S, 0.f, "Obstacle", 0.95f, ImColor(0.5f, 0.5f, 0.5f, 1.f));
									if (itemsDistESP)
									{
										drawText(W2S, 20.f, nameDist, 0.8f, ImColor(0.5f, 0.5f, 0.5f, 1.f));
									}
									if (itemsLineESP)
									{
										drawLine(W2S, itemLineColor, 1.f);
									}
								}
							}
							if (exitESP)
							{
								if (name.contains("Escape"))
								{
									drawText(W2S, 0.f, "Exit", 0.95f, ImColor(1.f, 0.f, 1.f, 1.f));
									if (itemsDistESP)
									{
										drawText(W2S, 20.f, nameDist, 0.8f, ImColor(1.f, 0.f, 1.f, 1.f));
									}
									if (itemsLineESP)
									{
										drawLine(W2S, itemLineColor, 1.f);
									}
								}
							}
						}
					}
				}
			}
		}
		if (playersESP)
		{
			auto gameState = World->GameState;

			if (gameState != nullptr)
			{
				auto playerArray = gameState->PlayerArray;

				for (int x = 0; x < playerArray.Num(); x++)
				{
					if (!playerArray.IsValidIndex(x)) continue;

					if (playerArray[x] == nullptr) continue;

					auto ogi = World->OwningGameInstance;

					if (ogi == nullptr) continue;

					auto lp = ogi->LocalPlayers[0];

					if (lp == nullptr) continue;

					auto myCtrl = lp->PlayerController;

					if (myCtrl == nullptr) continue;

					auto myPawn = myCtrl->Character;

					if (myPawn == nullptr) continue;

					auto pawn = playerArray[x]->PawnPrivate;

					if (pawn == nullptr) continue;

					auto myBBQ = static_cast<ABP_BBQPlayer_C*>(myPawn);

					if (myBBQ == nullptr) continue;

					auto bbq = static_cast<ABP_BBQPlayer_C*>(pawn);

					if (bbq == nullptr) continue;

					auto bbqMesh = bbq->Mesh;

					if (bbqMesh == nullptr) continue;

					auto playerState = pawn->PlayerState;

					if (playerState == nullptr) continue;

					auto playerName = playerState->PlayerNamePrivate;

					if (playerName == nullptr) continue;

					auto myTeam = myBBQ->DefaultTeamID;

					auto team = bbq->DefaultTeamID;

					FBBQInventoryItem eqquipedItem;

					auto myLoc = myPawn->K2_GetActorLocation();

					auto currLoc = pawn->K2_GetActorLocation();

					float vecDist = UKismetMathLibrary::Vector_Distance(myLoc, currLoc);

					int distance = vecDist / 100.f;

					if (pawn != myPawn)
					{
						if (!bbq->IsDead())
						{
							char buf[50];

							sprintf_s(buf, "[ %i m ] \n", distance);

							auto nameDist = buf;

							auto name = bbq->PlayerState->PlayerNamePrivate;

							FVector2D W2S;

							//bbq->AttachPOILocator();
							//bbq->Server_SetDebugNameVisibility(true);

							myCtrl->ProjectWorldLocationToScreen(currLoc, &W2S, true);

							auto headLocation = bbqMesh->GetSocketLocation(UKismetStringLibrary::Conv_StringToName(L"head"));
							FVector2D head;

							auto footLocation = bbqMesh->GetSocketLocation(UKismetStringLibrary::Conv_StringToName(L"ik_foot_root"));
							FVector2D foot;

							myCtrl->ProjectWorldLocationToScreen(headLocation, &head, true);

							myCtrl->ProjectWorldLocationToScreen(footLocation, &foot, true);

							boxHeight = head.Y - foot.Y;

							boxWidth = boxHeight / 2.5f;

							if (maxRange || distance <= ESPRange)
							{
								if (W2S.X || W2S.Y)
								{
									if (familyESP && team == ETeamID::TI_FamilyTeam)
									{
										if (boxESP)
										{
											drawBox(W2S, familyColor, 2);
										}
										if (lineESP)
										{
											drawLine(W2S, lineColor, 1.f);
										}
										if (nicknameESP) {
											if (distESP)
											{
												std::string forthis = nameDist;
												drawText(W2S, boxHeight + 30.f, forthis.append(name.ToString()).c_str(), 1.f, ImColor(1.f, 1.f, 1.f, 1.f));
											}
											else {
												drawText(W2S, boxHeight + 30.f, name.ToString().c_str(), 1.f, ImColor(1.f, 1.f, 1.f, 1.f));
											}
										}
										if (distESP)
										{
											if (!nicknameESP) drawText(W2S, boxHeight + 30.f, nameDist, 1.f, ImColor(1.f, 1.f, 1.f, 1.f));
										}
										if (skeletonESP) {
											drawSkeleton(bbqMesh, skeletonColor);
										}
										if (healthESP) {
											drawHealth(W2S, bbq);
										}
										if (staminaESP) {
											drawStamina(W2S, bbq);
										}
									}
									if (victimESP && team == ETeamID::TI_VictimTeam)
									{
										if (boxESP)
										{
											drawBox(W2S, victimColor, 2);
										}
										if (lineESP)
										{
											drawLine(W2S, lineColor, 1.f);
										}
										if (nicknameESP) {
											if (distESP)
											{
												std::string forthis = nameDist;
												drawText(W2S, boxHeight + 30.f, forthis.append(name.ToString()).c_str(), 1.f, ImColor(1.f, 1.f, 1.f, 1.f));
											}
											else {
												drawText(W2S, boxHeight + 30.f, name.ToString().c_str(), 1.f, ImColor(1.f, 1.f, 1.f, 1.f));
											}
										}
										if (distESP)
										{
											if (!nicknameESP) drawText(W2S, boxHeight + 30.f, nameDist, 1.f, ImColor(1.f, 1.f, 1.f, 1.f));
										}

										if (skeletonESP) {
											drawSkeleton(bbqMesh, skeletonColor);
										}
										if (healthESP) {
											drawHealth(W2S, bbq);
										}
										if (staminaESP) {
											drawStamina(W2S, bbq);
										}
									}
								}
							}
						}
					}
				}
			}
		}

		if (aim)
		{
			ImGui::GetBackgroundDrawList()->AddCircle({ screenWidth / 2.f, screenHeight / 2.f }, aimRadius, aimColor, 150, 4.f);

			auto gameState = World->GameState;

			if (gameState != nullptr)
			{
				auto playerArray = gameState->PlayerArray;

				for (int x = 0; x < playerArray.Num(); x++)
				{
					if (!playerArray.IsValidIndex(x)) continue;

					if (playerArray[x] == nullptr) continue;

					auto ogi = World->OwningGameInstance;

					if (ogi == nullptr) continue;

					auto lp = ogi->LocalPlayers[0];

					if (lp == nullptr) continue;

					auto myCtrl = lp->PlayerController;

					if (myCtrl == nullptr) continue;

					auto myPawn = myCtrl->Pawn;

					if (myPawn == nullptr) continue;

					auto pawn = playerArray[x]->PawnPrivate;

					if (pawn == nullptr) continue;

					if (myPawn == pawn) continue;

					auto myBBQ = static_cast<ABP_BBQPlayer_C*>(myPawn);

					if (myBBQ == nullptr) continue;

					auto bbq = static_cast<ABP_BBQPlayer_C*>(pawn);

					if (bbq == nullptr) continue;

					auto myTeam = myBBQ->DefaultTeamID;

					auto team = bbq->DefaultTeamID;

					auto myLoc = myPawn->K2_GetActorLocation();

					auto currLoc = pawn->K2_GetActorLocation();

					float vecDist = UKismetMathLibrary::Vector_Distance(myLoc, currLoc);

					int distance = vecDist / 100.f;

					FVector2D W2S;

					myCtrl->ProjectWorldLocationToScreen(currLoc, &W2S, true);

					if (GetAsyncKeyState(curAimKey) & 0x8000)
					{
						if (myTeam != team)
						{
							if (W2S.X < (screenWidth / 2) + aimRadius && W2S.X >(screenWidth / 2) - aimRadius && W2S.Y < (screenHeight / 2) + aimRadius && W2S.Y >(screenHeight / 2) - aimRadius)
							{
								auto rot = UKismetMathLibrary::FindLookAtRotation(myLoc, currLoc);
								myCtrl->ControlRotation = rot;
							}
						}
					}
				}
			}
		}
	}
}