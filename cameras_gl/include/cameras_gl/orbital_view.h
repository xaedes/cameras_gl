#pragma once

#include <glm/glm.hpp>
#include "cameras_gl/camera_view_interface.h"

#include <glm/ext/scalar_constants.hpp> // glm::pi

namespace cameras_gl {

    class OrbitalView : public CameraViewInterface
    {
    public:

        OrbitalView(
            glm::vec3 target = glm::vec3(0,0,0), 
            glm::vec3 angles = glm::vec3(0,0,0), 
            float distance = 10
        );
        virtual ~OrbitalView();
        
        glm::mat4 mat() const override;
        glm::mat4 matInverse() const override;
        
        glm::vec3 position() const override;
        inline const glm::vec3& target() const { return m_target; }
        inline const glm::vec3& angles() const { return m_angles; }
        inline float distance() const { return m_distance; }
        inline bool swapYZ() const { return m_swapYZ; }

        void setTarget(const glm::vec3& target);
        void setAngles(const glm::vec3& angles);
        void setDistance(float distance);
        void setSwapYZ(bool swapYZ);
        void set(
            const glm::vec3& target, 
            const glm::vec3& angles, 
            float distance
        );

        inline glm::vec3& accessTarget()   { return m_target;   }
        inline glm::vec3& accessAngles()   { return m_angles;   }
        inline float& accessDistance()     { return m_distance; }
        inline bool& accessSwapYZ()        { return m_swapYZ;   }

        void update();

    protected:
        glm::vec3 m_target;
        glm::vec3 m_angles;
        float m_distance;

        glm::vec3 m_position;

        bool m_swapYZ;

        glm::mat4 m_world_from_camera = glm::mat4(1);
        glm::mat4 m_camera_from_world = glm::mat4(1);
        
    };

} // namespace cameras_gl
