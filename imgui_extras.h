// =====================================================================================================================
// Copyright 2024 Medusa Slockbower
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// 	http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// =====================================================================================================================

#ifndef IMGUI_EXTRAS_H
#define IMGUI_EXTRAS_H

#include <imgui-docking/imgui.h>

namespace ImGui
{
    bool InputUInt(const char* label,  unsigned int* v, int step = 1, int step_fast = 100, ImGuiInputTextFlags flags = 0);
    bool InputUInt2(const char* label, unsigned int v[2], ImGuiInputTextFlags flags = 0);
    bool InputUInt3(const char* label, unsigned int v[3], ImGuiInputTextFlags flags = 0);
    bool InputUInt4(const char* label, unsigned int v[4], ImGuiInputTextFlags flags = 0);

    bool ColorPreview(const char* label, float  v[4], ImGuiColorEditFlags flags = 0);
    inline bool ColorPreview(const char* label, ImVec4 color, ImGuiColorEditFlags flags = 0) { ColorPreview(label, &color.x, flags); }
    inline bool ColorPreview(const char* label, ImColor color, ImGuiColorEditFlags flags = 0) { ColorPreview(label, &color.Value.x, flags); }
}

#endif //IMGUI_EXTRAS_H
