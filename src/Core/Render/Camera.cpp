#include "Core/Render/Camera.h"
#include <glm/gtc/matrix_transform.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/compatibility.hpp>

Camera::Camera()
{

}

Camera::~Camera()
{

}

const glm::mat4 Camera::GetProjectionMatrix() const
{
    return glm::perspective(glm::radians(CamSpec.FOV), CamSpec.Aspect, 
                            CamSpec.NearClip, CamSpec.FarClip);
}

const glm::mat4 Camera::GetViewMatrix() const
{
    return glm::mat4(
        CamSpec.OX.x, CamSpec.OY.x, CamSpec.OZ.x, 0.0f,
        CamSpec.OX.y, CamSpec.OY.y, CamSpec.OZ.y, 0.0f,
        CamSpec.OX.z, CamSpec.OY.z, CamSpec.OZ.z, 0.0f,
        -CamSpec.position.x, -CamSpec.position.y, -CamSpec.position.z, 1.0f
    ) * glm::toMat4(glm::quat(CamSpec.rotation));
}

const glm::mat4 Camera::GetProjectionViewMatrix() const
{
    return GetProjectionMatrix() * GetViewMatrix();
}