#pragma once
#include "Backends/OpenGL/ShaderDataType.h"

struct BufferElement
{
    std::string Name;
    uint32_t Size;
    uint32_t Offset;

    ShaderDataType Type;
    bool Normalized;

    BufferElement(ShaderDataType type, const std::string &Name, bool Normalized=false)
        :Name(Name), Type(type), Size(ShaderDataTypeSize(type)), Offset(0), Normalized(Normalized)
    {
        
    }

    uint32_t GetDimCount() const 
    {
        switch (Type) 
        {
            case ShaderDataType::Float:  return 1;
            case ShaderDataType::Float2: return 2;
            case ShaderDataType::Float3: return 3;
            case ShaderDataType::Float4: return 4;
            case ShaderDataType::Mat3:   return 3;
            case ShaderDataType::Mat4:   return 4;
            case ShaderDataType::Int:    return 1;
            case ShaderDataType::Int2:   return 2;
            case ShaderDataType::Int3:   return 3;
            case ShaderDataType::Int4:   return 4;
            case ShaderDataType::Bool:   return 1;
        }
        ASSERT(false, "Unknowned or Undefined Dimension of Data!");
        return 0;
    }
};

class BufferLayout
{
public:
    BufferLayout() {}
    BufferLayout(const std::initializer_list<BufferElement> &layoutArray) : m_Elements(layoutArray) 
    { 
        CalculateOffsetAndStride();
    }

    inline const std::vector<BufferElement> &GetElements() const { return m_Elements; }
    uint32_t GetStride() const { return m_Stride; }

    std::vector<BufferElement>::iterator begin() { return m_Elements.begin(); }
    std::vector<BufferElement>::iterator end() { return m_Elements.end(); }
    std::vector<BufferElement>::const_iterator begin() const { return m_Elements.begin(); }
    std::vector<BufferElement>::const_iterator end() const { return m_Elements.end(); }

private:
    void CalculateOffsetAndStride() 
    {
        uint32_t offset = 0;
        m_Stride = 0;
        for (auto &element : m_Elements) 
        {
            element.Offset = offset;
            offset += element.Size;
            m_Stride += element.Size;
        }
    }
private:
    std::vector<BufferElement> m_Elements;
    uint32_t m_Stride;
};


class VertexBuffer 
{
public:
    virtual ~VertexBuffer();

    virtual void Bind() const = 0;
    virtual void Unbind() const = 0;

    virtual void SetData(const void* data, uint32_t size) = 0;
    virtual void SetLayout(const BufferLayout &layout) = 0;
    virtual const BufferLayout& GetLayout() const = 0;
    virtual const uint32_t GetSize() const = 0;

    static std::shared_ptr<VertexBuffer> Create(float *vertices, uint32_t size);
};

class IndexBuffer
{
public:
    virtual ~IndexBuffer();

    virtual void Bind() const = 0;
    virtual void Unbind() const = 0;

    virtual uint32_t GetCount() const = 0;
    
    static std::shared_ptr<IndexBuffer> Create(uint32_t *indices, uint32_t count);
};