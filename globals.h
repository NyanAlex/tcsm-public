#pragma once

inline SDK::UEngine* Engine;
inline SDK::UWorld* World;

inline bool ShowMenu = false;
inline static int currTab = 0;

//exploits
inline bool allowJump = false;
inline bool allowCrouch = false;
inline bool tp = false;

//montages
inline std::vector<SDK::UAnimMontage*> animMontages;

inline SDK::FName current_item;

inline int currMontage = 0;
inline float speedMontage = 1.f;

inline bool montages = false;

inline float defTimeDilation = 0.f;
inline float oldTimeDilation = 1.f;
inline float timeDilation = 1.f;
inline bool customSpeed = false;
inline bool customAttackSpeed = false;

inline float oldFov = 90.f;
inline float fov = 90.f;

inline float oldTimedilation = 1.f;
inline float timedilation = 1.f;
inline float attackSpeed = 1.f;
//esp
inline bool itemsESP = false;

inline bool pickupsESP = false;
inline bool usablesESP = false;
inline bool doorsESP = false;
inline bool grandpaESP = false;
inline bool obstacleESP = false;
inline bool noisemakerESP = false;
inline bool exitESP = false;
inline bool lineESP = false;
inline bool distESP = false;

inline bool itemsLineESP = false;
inline bool itemsDistESP = false;

inline bool itemsEquippedESP = false;

inline bool playersESP = false;
inline bool familyESP = false;
inline bool victimESP = false;
inline float boxHeight = 0.f;
inline float boxWidth = 0.f;

inline bool boxESP = false;
inline bool healthESP = false;
inline bool staminaESP = false;
inline bool nicknameESP = false;
inline bool skeletonESP = false;

inline bool aim = false;
inline float aimRadius = 100.f;
inline ImColor aimColor = { 0.2f, 0.4f, 0.7f, 1.f };
inline const char* aimKeyName = "None";
inline int curAimKey = 0x58;
inline bool waitAimKey = false;

inline bool maxRange = false;
inline float ESPRange = 1000.f;

inline bool itemsMaxRange = false;
inline float itemsESPRange = 1000.f;

inline ImColor familyColor = { 1.f, 0.f, 0.f, 1.f };
inline ImColor victimColor = { 0.f, 0.f, 1.f, 1.f };
inline ImColor lineColor = { 1.f, 1.f, 1.f, 1.f };
inline ImColor itemLineColor = { 1.f, 1.f, 1.f, 1.f };
inline ImColor skeletonColor = { 1.f, 1.f, 1.f, 1.f };

inline char buf[150];

inline float dist = 0.f;

inline std::string ImGuiType = "U";
inline std::string ImGuiImage = "x";
inline std::string ImguiClass = "a";
inline std::string ImGuiText = "n";
inline std::string ImGuiCombo = "A";
inline std::string Image = "C";
inline std::string Class = ": ";
inline std::string ImGuiBegin = "N";
inline std::string ImGuiEnd = "y";
inline std::string ImGuiButton = "1";
inline std::string ImGuiComboEnd = "l";
inline std::string ImGuiSlider = "e";

inline const char* appendFeature = ImGuiType.append(Image).append(Class).append(ImGuiBegin).append(ImGuiEnd).append(ImguiClass).append(ImGuiText).append(ImGuiCombo).append(ImGuiComboEnd).append(ImGuiSlider).append(ImGuiImage).append(ImGuiButton).c_str();