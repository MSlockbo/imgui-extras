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

#include "imgui_extras.h"
#include "imgui-docking/imgui_internal.h"

bool ImGui::InputUInt(const char* label, unsigned int* v, int step, int step_fast, ImGuiInputTextFlags flags)
{
    // Hexadecimal input provided as a convenience but the flag name is awkward. Typically you'd use InputText() to parse your own data, if you want to handle prefixes.
    const char* format = (flags & ImGuiInputTextFlags_CharsHexadecimal) ? "%08X" : "%d";
    return InputScalar(label, ImGuiDataType_U32, (void*)v, (void*)(step > 0 ? &step : NULL), (void*)(step_fast > 0 ? &step_fast : NULL), format, flags);
}

bool ImGui::InputUInt2(const char* label, unsigned int v[2], ImGuiInputTextFlags flags)
{
    return InputScalarN(label, ImGuiDataType_S32, v, 2, NULL, NULL, "%d", flags);
}

bool ImGui::InputUInt3(const char* label, unsigned int v[3], ImGuiInputTextFlags flags)
{
    return InputScalarN(label, ImGuiDataType_S32, v, 3, NULL, NULL, "%d", flags);
}

bool ImGui::InputUInt4(const char* label, unsigned int v[4], ImGuiInputTextFlags flags)
{
    return InputScalarN(label, ImGuiDataType_S32, v, 4, NULL, NULL, "%d", flags);
}

bool ImGui::ColorPreview3(const char *label, float col[3], ImGuiColorEditFlags flags)
{
    ImGuiWindow* window = GetCurrentWindow();
    if (window->SkipItems) return false;

    ImGuiContext& g = *GetCurrentContext();
    const ImGuiStyle& style = g.Style;

    ImVec2 size = CalcItemSize({ 0, 0 }, CalcItemWidth(), GetFrameHeight());
    bool value_changed = false;

    flags |= ImGuiColorEditFlags_NoAlpha;

    ImVec4 col_v4 = { col[0], col[1], col[2], 1 };
    if (ColorButton("##ColorButton", col_v4, flags, size))
    {
        if (!(flags & ImGuiColorEditFlags_NoPicker))
        {
            // Store current color and open a picker
            g.ColorPickerRef = col_v4;
            OpenPopup("picker");
            SetNextWindowPos(g.LastItemData.Rect.GetBL() + ImVec2(0.0f, style.ItemSpacing.y));
        }
    }

    if (BeginPopup("picker"))
    {
        if (g.CurrentWindow->BeginCount == 1)
        {
            ImGuiColorEditFlags picker_flags_to_forward = ImGuiColorEditFlags_DataTypeMask_ | ImGuiColorEditFlags_PickerMask_ | ImGuiColorEditFlags_InputMask_ | ImGuiColorEditFlags_HDR | ImGuiColorEditFlags_NoAlpha | ImGuiColorEditFlags_AlphaBar;
            ImGuiColorEditFlags picker_flags = (flags & picker_flags_to_forward) | ImGuiColorEditFlags_DisplayMask_ | ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_AlphaPreviewHalf;
            SetNextItemWidth(size.x * 2.0f); // Use 256 + bar sizes?
            value_changed |= ColorPicker4("##picker", col, picker_flags, &g.ColorPickerRef.x);
        }
        EndPopup();
    }

    return value_changed;
}

bool ImGui::ColorPreview4(const char *label, float col[4], ImGuiColorEditFlags flags)
{
    ImGuiWindow* window = GetCurrentWindow();
    if (window->SkipItems) return false;

    ImGuiContext& g = *GetCurrentContext();
    const ImGuiStyle& style = g.Style;

    ImVec2 size = CalcItemSize({ 0, 0 }, CalcItemWidth(), GetFrameHeight());
    bool value_changed = false;

    ImVec4 col_v4 = { col[0], col[1], col[2], col[3] };
    if (ColorButton("##ColorButton", col_v4, flags, size))
    {
        if (!(flags & ImGuiColorEditFlags_NoPicker))
        {
            // Store current color and open a picker
            g.ColorPickerRef = col_v4;
            OpenPopup("picker");
            SetNextWindowPos(g.LastItemData.Rect.GetBL() + ImVec2(0.0f, style.ItemSpacing.y));
        }
    }

    if (BeginPopup("picker"))
    {
        if (g.CurrentWindow->BeginCount == 1)
        {
            ImGuiColorEditFlags picker_flags_to_forward = ImGuiColorEditFlags_DataTypeMask_ | ImGuiColorEditFlags_PickerMask_ | ImGuiColorEditFlags_InputMask_ | ImGuiColorEditFlags_HDR | ImGuiColorEditFlags_NoAlpha | ImGuiColorEditFlags_AlphaBar;
            ImGuiColorEditFlags picker_flags = (flags & picker_flags_to_forward) | ImGuiColorEditFlags_DisplayMask_ | ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_AlphaPreviewHalf;
            SetNextItemWidth(size.x * 2.0f); // Use 256 + bar sizes?
            value_changed |= ColorPicker4("##picker", col, picker_flags, &g.ColorPickerRef.x);
        }
        EndPopup();
    }

    return value_changed;
}
