#include "Core/Render/Buffer.h"
#include "Core/Render/RendererAPI.h"
#include "Backends/OpenGL/OpenGLBuffer.h"

Ref<VertexBuffer> VertexBuffer::Create(float *vertices, uint32_t size)
{
    switch(RendererAPI::GetCurrentAPI()) 
    {
        case RendererAPI::API::None: 
        {
            ASSERT(false, "[Vertex Buffer] None API backend is not supported.");
            return nullptr;
        }
        case RendererAPI::API::OpenGL: 
        {
            return CreateRef<OpenGLVertexBuffer>(vertices, size);
        }
    }
    ASSERT(false, "[Vertex Buffer] Please select an API backend for rendering. Options are [OpenGL, Vulcan]");
    return  nullptr;
}

VertexBuffer::~VertexBuffer()
{

}

Ref<IndexBuffer> IndexBuffer::Create(uint32_t *indices, uint32_t count) 
{
    switch(RendererAPI::GetCurrentAPI()) 
    {
        case RendererAPI::API::None: 
        {
            ASSERT(false, "[Index Buffer] None API backend is not supported.");
            return nullptr;
        }
        case RendererAPI::API::OpenGL: 
        {
            return CreateRef<OpenGLIndexBuffer>(indices, count);
        }
    }
    ASSERT(false, "[Index Buffer] Please select an API backend for rendering. Options are [OpenGL, Vulcan]");
    return  nullptr;
}

IndexBuffer::~IndexBuffer()
{
    
}