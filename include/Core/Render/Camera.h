#pragma once
#include "Core/Render/CameraConfig.h"
#include <glm/glm.hpp>

class Camera
{
public:
    Camera();
    ~Camera();

    const glm::mat4 GetProjectionMatrix() const;
    const glm::mat4 GetViewMatrix() const;
    const glm::mat4 GetProjectionViewMatrix() const;

public:
    CameraSpec CamSpec;
      
private:
};