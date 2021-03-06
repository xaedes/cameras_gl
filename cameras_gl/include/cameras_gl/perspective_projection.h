#pragma once

#include <glm/glm.hpp>
#include <glm/ext/scalar_constants.hpp> // glm::pi

#include "cameras_gl/camera_projection_interface.h"

namespace cameras_gl {

    class PerspectiveProjection : public CameraProjectionInterface
    {
    public:
        // PerspectiveProjection() = default;
        PerspectiveProjection(const PerspectiveProjection& other) = default;
        PerspectiveProjection(
            float fov_radians = 45 * glm::pi<float>() / 180, 
            float nearPlane = 0.8f, 
            float farPlane = 5000.0f, 
            glm::ivec2 viewportSize = glm::ivec2(2,2)
        );
        virtual ~PerspectiveProjection();

        virtual glm::mat4 mat() const override;
        virtual bool hasInverse() const override;
        virtual glm::mat4 matInverse() const override;

        float fov() const;
        float nearPlane() const;
        float farPlane() const;
        virtual glm::ivec2 viewportSize() const override;
        virtual glm::vec2 viewportSize_vec2() const override;

        void setFov(float fov);
        void setNearPlane(float nearPlane);
        void setFarPlane(float farPlane);
        virtual void setViewportSize(glm::ivec2 size);
        void set(
            float fov,
            float nearPlane,
            float farPlane
        );
        void set(
            float fov,
            float nearPlane,
            float farPlane,
            glm::ivec2 viewportSize
        );

        inline float& accessFov()       { return m_fov; }
        inline float& accessNearPlane() { return m_nearPlane; }
        inline float& accessFarPlane()  { return m_farPlane; }
        inline glm::ivec2& accessViewportSize()  { return m_viewportSize; }

        virtual void update();

    protected:

        float m_fov;
        float m_nearPlane;
        float m_farPlane;
        glm::ivec2 m_viewportSize; 

        glm::mat4 m_image_from_camera;
    };

} // namespace cameras_gl
