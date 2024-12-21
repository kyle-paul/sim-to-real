#pragma once
#include "Core/Core.h"
#include "Core/Render/VertexArray.h"

class Renderer
{
public:
    static void Init();
    static void Shutdown();
    static void DrawIndexed(const Ref<VertexArray> &VA);
    static void Draw(const Ref<VertexArray> &VA, const bool &isQuad, const uint32_t &count);
};