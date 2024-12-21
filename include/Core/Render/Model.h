#pragma once
#include "Core/Core.h"
#include "Core/Render/VertexArray.h"
#include "Core/Render/Buffer.h"
#include <string>
#include <vector>

class Model
{
public:
    Model(const std::string &filepath);
    ~Model();

    const std::vector<float>& GetVertices() const { return vertices; }
    void Init();
    void Render();

private:
    void RegisterMesh(const std::string &filepath);
    float GetFloat(std::string input);
    int GetInt(std::string input);

private:
    std::vector<float> vertices;
    Ref<VertexArray> VA; 
    Ref<VertexBuffer> VB;
};