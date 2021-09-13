#pragma once

#include <glm/glm.hpp>
#include "cameras_gl/camera_view_interface.h"

#include <glm/ext/scalar_constants.hpp> // glm::pi

namespace cameras_gl {

    class FirstPersonView : public CameraViewInterface
    {
    public:

        FirstPersonView() = default;
        FirstPersonView(const FirstPersonView& other) = default;
        FirstPersonView(
            const glm::vec3& position, 
            const glm::vec3& rollPitchYaw = glm::vec3(0)
        );

        virtual ~FirstPersonView();
        
        virtual glm::vec3 position() const override;
        inline const glm::vec3& rollPitchYaw() const { return m_rollPitchYaw; }

        virtual glm::mat4 mat() const override;
        virtual glm::mat4 matInverse() const override;

        void setPosition(const glm::vec3& position);
        void setRollPitchYaw(const glm::vec3& rollPitchYaw);
        void set(
            const glm::vec3& position, 
            const glm::vec3& rollPitchYaw
        );

        inline glm::vec3& accessPosition()     { return m_position; }
        inline glm::vec3& accessRollPitchYaw() { return m_rollPitchYaw; }

        void update();

    protected:

        glm::vec3 m_position = glm::vec3{};
        glm::vec3 m_rollPitchYaw = glm::vec3{};

        glm::mat4 m_world_from_camera = glm::mat4(1);
        glm::mat4 m_camera_from_world = glm::mat4(1);
    };

} // namespace cameras_gl
