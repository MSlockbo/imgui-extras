// =====================================================================================================================
//	imgui-extras, an extension for Dear ImGui that adds extra functionality.
//	Copyright (C) 2024  Medusa Slockbower
//
//	This program is free software: you can redistribute it and/or modify
//	it under the terms of the GNU General Public License as published by
//	the Free Software Foundation, either version 3 of the License, or
//	(at your option) any later version.
//
//	This program is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//	GNU General Public License for more details.
//
//	You should have received a copy of the GNU General Public License
//	along with this program.  If not, see <https://www.gnu.org/licenses/>.
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

	bool ColorPreview3(const char* label, float v[3], ImGuiColorEditFlags flags = 0);
	inline bool ColorPreview3(const char* label, ImVec4 color, ImGuiColorEditFlags flags = 0) { ColorPreview3(label, &color.x, flags); }
	inline bool ColorPreview3(const char* label, ImColor color, ImGuiColorEditFlags flags = 0) { ColorPreview3(label, &color.Value.x, flags); }

	bool ColorPreview4(const char* label, float v[4], ImGuiColorEditFlags flags = 0);
	inline bool ColorPreview4(const char* label, ImVec4 color, ImGuiColorEditFlags flags = 0) { ColorPreview4(label, &color.x, flags); }
	inline bool ColorPreview4(const char* label, ImColor color, ImGuiColorEditFlags flags = 0) { ColorPreview4(label, &color.Value.x, flags); }
}

#endif //IMGUI_EXTRAS_H
