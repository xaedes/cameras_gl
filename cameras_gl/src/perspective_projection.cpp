#include "cameras_gl/perspective_projection.h"

#include <glm/ext/matrix_clip_space.hpp> // glm::perspective

namespace cameras_gl {

    glm::mat4 PerspectiveProjection::perspective_inverse(
        const glm::mat4& m
    )
    {
        // https://github.com/xaedes/glm_inverse_perspective/blob/main/inverse_perspective.h
        
        // Based on compute_inverse<4, 4, T, Q, Aligned> from extern/glm/glm/detail/func_matrix.inl
        // a lot of values in perspective matrices (see extern/glm/glm/ext/matrix_clip_space.inl) are zero,
        // simplify compute_inverse<4, 4, T, Q, Aligned> using all known zeros:
        auto Coef00 = 0 - m[3][2] * m[2][3];
        auto Coef07 = m[1][1] * m[2][3];

        auto Coef10 = m[1][1] * m[3][2];
        auto Coef11 = m[1][1] * m[2][2];

        glm::mat4 Inverse(
            +Coef00*m[1][1],0,0,0,
            0,+m[0][0]*Coef00,0,0,
            0,0,0,-m[0][0]*Coef07,
            0,0,-m[0][0]*Coef10,m[0][0]*Coef11
        );
        auto Determinant = (m[0][0] * Inverse[0][0]);
        auto OneOverDeterminant = static_cast<float>(1) / Determinant;
        return Inverse * OneOverDeterminant;
    }

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
    glm::mat4 PerspectiveProjection::matInverse() const
    {
        return m_camera_from_image;
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
        m_camera_from_image = PerspectiveProjection::perspective_inverse(
            m_image_from_camera
        );
    }




} // namespace cameras_gl
