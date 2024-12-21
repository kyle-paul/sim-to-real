#pragma once
#include "Core/Render/VertexArray.h"

class OpenGLVertexArray : public VertexArray
{
public:
    OpenGLVertexArray();
    virtual ~OpenGLVertexArray();

    virtual void Bind() const override;
    virtual void UnBind() const override;

    virtual void AddVertexBuffer(const Ref<VertexBuffer> &vertex_buffer) override;
    virtual void SetIndexBuffer(const Ref<IndexBuffer> &index_buffer) override;

    virtual const Ref<VertexBuffer> GetVertexBuffer() const override { return m_VertexBuffer; }
    virtual const Ref<IndexBuffer> GetIndexBuffer() const override { return m_IndexBuffer; }
    virtual const uint32_t GetVertexArrayID() const override { return VAO; }

private:
    uint32_t VAO;
    Ref<VertexBuffer> m_VertexBuffer;
    Ref<IndexBuffer> m_IndexBuffer;
};