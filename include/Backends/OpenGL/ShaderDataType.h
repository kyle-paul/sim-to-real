#pragma once
#include <glad/glad.h>
#include "Core/Debug/Assert.h"

enum class ShaderDataType
{
    None=0, Float, Float2, Float3, Float4, 
    Mat3, Mat4, Int, Int2, Int3, Int4, Bool
};

static uint32_t ShaderDataTypeSize(ShaderDataType type) {
    switch(type) {
        case ShaderDataType::Float:     return 4;           // 4 bytes
        case ShaderDataType::Float2:    return 4 * 2;       // 8 bytes
        case ShaderDataType::Float3:    return 4 * 3;       // 12 bytes
        case ShaderDataType::Float4:    return 4 * 4;       // 16 bytes
        case ShaderDataType::Mat3:      return 4 * 3 * 3;   // 36 bytes
        case ShaderDataType::Mat4:      return 4 * 4 * 4;   // 64 bytes
        case ShaderDataType::Int:       return 4;           // 4 bytes
        case ShaderDataType::Int2:      return 4 * 2;       // 8 bytes
        case ShaderDataType::Int3:      return 4 * 3;       // 12 bytes
        case ShaderDataType::Int4:      return 4 * 4;       // 16 bytes
        case ShaderDataType::Bool:      return 1;           // 1 byte
    }

    ASSERT(false, "Unknowned or Undefined ShaderDataType!");
    return 0;
};

static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
{
    switch(type)
    {
        case ShaderDataType::Float  : return GL_FLOAT;
        case ShaderDataType::Float2 : return GL_FLOAT;
        case ShaderDataType::Float3 : return GL_FLOAT;
        case ShaderDataType::Float4 : return GL_FLOAT;
    }
    ASSERT(false, "Unknowned or Undefined type in ShaderDataTypeToOpenGLBaseType!");
    return 0;
}