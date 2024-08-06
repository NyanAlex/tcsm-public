#pragma once
#include <Windows.h>
#include <d3d11.h>
#include <dxgi.h>
#include <iostream>
#include <vector>
#include <thread>
#include "imgui/imgui.h"
#include "ImGui/imgui_internal.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx12.h"
#include "SDK.hpp"
#include "engine.h"
#include "drawing.h"
#include "globals.h"

#define screenWidth ImGui::GetIO().DisplaySize.x
#define screenHeight ImGui::GetIO().DisplaySize.y