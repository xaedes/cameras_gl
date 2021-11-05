#pragma once

#include <glm/glm.hpp>
#include "cameras_gl/camera_view_interface.h"

#include <glm/ext/scalar_constants.hpp> // glm::pi

namespace cameras_gl {

    class LookAtView : public CameraViewInterface
    {
    public:

        // LookAtView() = default;
        LookAtView(const LookAtView& other) = default;
        LookAtView(
            glm::vec3 position = glm::vec3(0,0,0), 
            glm::vec3 target = glm::vec3(0,0,1), 
            glm::vec3 up = glm::vec3(0,1,0)
        );
        virtual ~LookAtView();

        glm::mat4 mat() const override;
        glm::mat4 matInverse() const override;
        glm::vec3 position() const override;
        inline const glm::vec3& target() const { return m_target; }
        inline const glm::vec3& up() const     { return m_up;     }

        void setPosition(const glm::vec3& position);
        void setTarget(const glm::vec3& target);
        void setUp(const glm::vec3& up);
        void set(
            const glm::vec3& position, 
            const glm::vec3& target,
            const glm::vec3& up
        );

        inline glm::vec3& accessPosition() { return m_position; }
        inline glm::vec3& accessTarget()   { return m_target;   }
        inline glm::vec3& accessUp()       { return m_up;       }

        void update();

    protected:
        glm::vec3 m_position{};
        glm::vec3 m_target{};
        glm::vec3 m_up{};

        glm::mat4 m_world_from_camera = glm::mat4(1);
        glm::mat4 m_camera_from_world = glm::mat4(1);
    };

} // namespace cameras_gl
