// Copyright (c) 2022, arch1t3cht <arch1t3cht@gmail.com>
//
// Permission to use, copy, modify, and distribute this software for any
// purpose with or without fee is hereby granted, provided that the above
// copyright notice and this permission notice appear in all copies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
// ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
// ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
// OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
//
// Aegisub Project http://www.aegisub.org/

/// @file visual_tool_perspective.h
/// @see visual_tool_perspective.cpp
/// @ingroup visual_ts
///

#include "visual_feature.h"
#include "visual_tool.h"

class VisualToolPerspective final : public VisualTool<VisualDraggableFeature> {
	float angle_x = 0.f; /// Current x rotation
	float angle_y = 0.f; /// Current y rotation
	float angle_z = 0.f; /// Current z rotation

	float fax = 0.f;
	float fay = 0.f;

	int align = 0;
	float fax_shift_factor = 0.f;

	double textwidth = 0.f;
	double textheight = 0.f;

	Vector2D fsc;

	Vector2D org;
	Vector2D pos;

	Feature *orgf;
	Vector2D old_orgf;

	std::vector<Vector2D> old_positions;
	std::vector<Feature *> quad_corners;

	void Solve2x2Proper(float a11, float a12, float a21, float a22, float b1, float b2, float &x1, float &x2);
	void Solve2x2(float a11, float a12, float a21, float a22, float b1, float b2, float &x1, float &x2);

	void DoRefresh() override;
	void Draw() override;
	void UpdateDrag(Feature *feature) override;
	void SetFeaturePositions();
	void ResetFeaturePositions();
	void SaveFeaturePositions();
public:
	VisualToolPerspective(VideoDisplay *parent, agi::Context *context);
};
