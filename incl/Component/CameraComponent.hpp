// Copyright (c) Alexis Chân Gridel. All Rights Reserved.
// Copyright (c) Axolotl Engine contributors. All Rights Reserved.
// Licensed under the GNU General Public License v3.0.
// See the LICENSE file in the project root for more information.

#ifndef _CAMERA_COMPONENT_H
#define _CAMERA_COMPONENT_H

#include <glad/glad.h>
#include <glm/ext.hpp>
#include <glm/fwd.hpp>

namespace ax::component
{
    class CameraComponent
    {
        glm::mat4 view_matrix_;
        glm::mat4 projection_matrix_;
        glm::vec3 camera_position_;
        
    public:
        CameraComponent(GLfloat fov, GLfloat width, GLfloat height, GLfloat near, GLfloat far,
                        const glm::vec3& cameraPosition)
        :
            view_matrix_(lookAt(cameraPosition, glm::vec3(0.0F, 0.0F, 0.0F), glm::vec3(0.0F, 1.0F, 0.0F))),
            projection_matrix_(glm::perspective(fov, width / height, near, far)),
            camera_position_(cameraPosition)
        {
        }

        CameraComponent(const CameraComponent&) = default;
        CameraComponent(CameraComponent&&) = default;
        CameraComponent& operator=(const CameraComponent&) = default;
        CameraComponent& operator=(CameraComponent&&) = default;

        ~CameraComponent();

        [[nodiscard]] glm::mat4 GetViewMatrix() const noexcept { return view_matrix_; }
        [[nodiscard]] glm::mat4 GetProjectionMatrix() const noexcept { return projection_matrix_; }
        [[nodiscard]] glm::vec3 GetCameraPosition() const noexcept { return camera_position_; }

    };
} // namespace ax::component
#endif // _CAMERA_COMPONENT_H
