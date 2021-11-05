#include "cameras_gl/perspective_projection.h"

#include <glm/ext/matrix_clip_space.hpp> // glm::perspective

namespace cameras_gl {

    PerspectiveProjection::PerspectiveProjection(
        float fov_radians, 
        float nearPlane, 
        float farPlane, 
        glm::ivec2 viewportSize
    )
        : m_fov(fov_radians)
        , m_nearPlane(nearPlane)
        , m_farPlane(farPlane)
        , m_viewportSize(viewportSize)
    {
        update();
    }
    PerspectiveProjection::~PerspectiveProjection()
    {}

    glm::mat4 PerspectiveProjection::mat() const
    {
        return m_image_from_camera;
    }
    bool PerspectiveProjection::hasInverse() const
    {
        return false;
    }
    glm::mat4 PerspectiveProjection::matInverse() const
    {
        return glm::mat4(1);
    }

    float PerspectiveProjection::fov() const
    {
        return m_fov;
    }

    float PerspectiveProjection::nearPlane() const
    {
        return m_nearPlane;
    }

    float PerspectiveProjection::farPlane() const
    {
        return m_farPlane;
    }

    glm::ivec2 PerspectiveProjection::viewportSize() const
    {
        return m_viewportSize;
    }

    glm::vec2 PerspectiveProjection::viewportSize_vec2() const
    {
        return glm::vec2(m_viewportSize.x, m_viewportSize.y);
    }


    void PerspectiveProjection::setFov(float fov)
    {
        m_fov = fov;
        update();
    }

    void PerspectiveProjection::setNearPlane(float nearPlane)
    {
        m_nearPlane = nearPlane;
        update();
    }

    void PerspectiveProjection::setFarPlane(float farPlane)
    {
        m_farPlane = farPlane;
        update();
    }

    void PerspectiveProjection::setViewportSize(glm::ivec2 viewportSize)
    {
        m_viewportSize = viewportSize;
        update();
    }

    void PerspectiveProjection::set(
        float fov,
        float nearPlane,
        float farPlane
    )
    {
        m_fov = fov;
        m_nearPlane = nearPlane;
        m_farPlane = farPlane;
        update();
    }

    void PerspectiveProjection::set(
        float fov,
        float nearPlane,
        float farPlane,
        glm::ivec2 viewportSize
    )
    {
        m_fov = fov;
        m_nearPlane = nearPlane;
        m_farPlane = farPlane;
        m_viewportSize = viewportSize;
        update();
    }


    void PerspectiveProjection::update()
    {
        m_image_from_camera = glm::perspective(
            m_fov, 
            aspectRatio(), 
            m_nearPlane, 
            m_farPlane
        );
    }




} // namespace cameras_gl
