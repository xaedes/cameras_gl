#include "cameras_gl/orthogonal_projection.h"

#include <glm/ext/matrix_clip_space.hpp> // glm::ortho

namespace cameras_gl {

    glm::mat4 OrthogonalProjection::orthogonal_inverse(
        const glm::mat4& m
    )
    {
        // glm/glm/ext/matrix_clip_space.inl
        // GLM_FUNC_QUALIFIER ::glm::mat<4, 4, T, defaultp> orthoLH_ZO(T left, T right, T bottom, T top, T zNear, T zFar)
        // ::glm::mat<4, 4, T, defaultp> Result(1);
        // Result[0][0] = static_cast<T>(2) / (right - left);
        // Result[1][1] = static_cast<T>(2) / (top - bottom);
        // Result[2][2] = static_cast<T>(1) / (zFar - zNear);
        // Result[3][0] = - (right + left) / (right - left);
        // Result[3][1] = - (top + bottom) / (top - bottom);
        // Result[3][2] = - zNear / (zFar - zNear);
        auto Coef08 = -m[3][1] * m[2][2];
        auto Coef10 = m[1][1] * m[3][2];
        auto Coef11 = m[1][1] * m[2][2];
        auto Coef16 = -m[3][0] * m[2][2];

        glm::mat4 Inverse(
            m[1][1]*m[2][2], 0, 0, 0,
            0, m[0][0]*m[2][2], 0, 0,
            0, 0, m[0][0]*m[1][1],0,
            m[1][1]*Coef16, m[0][0]*Coef08, -m[0][0]*Coef10, m[0][0]*Coef11
        );

        auto Determinant = (m[0][0] * Inverse[0][0]);
        auto OneOverDeterminant = static_cast<decltype(Determinant)>(1) / Determinant;

        return Inverse * OneOverDeterminant;
    }

    OrthogonalProjection::OrthogonalProjection(
        float leftPlane, 
        float rightPlane, 
        float bottomPlane, 
        float topPlane, 
        float nearPlane, 
        float farPlane, 
        glm::ivec2 viewportSize
    )
        : m_leftPlane(leftPlane)
        , m_rightPlane(rightPlane)
        , m_bottomPlane(bottomPlane)
        , m_topPlane(topPlane)
        , m_nearPlane(nearPlane)
        , m_farPlane(farPlane)
        , m_viewportSize(viewportSize)
    {
        update();
    }
    OrthogonalProjection::~OrthogonalProjection()
    {}

    glm::mat4 OrthogonalProjection::mat() const
    {
        return m_image_from_camera;
    }
    bool OrthogonalProjection::hasInverse() const
    {
        return true;
    }
    glm::mat4 OrthogonalProjection::matInverse() const
    {
        return m_camera_from_image;
    }

    glm::ivec2 OrthogonalProjection::viewportSize() const
    {
        return m_viewportSize;
    }

    glm::vec2 OrthogonalProjection::viewportSize_vec2() const
    {
        return glm::vec2(m_viewportSize.x, m_viewportSize.y);
    }

    void OrthogonalProjection::setViewportSize(glm::ivec2 viewportSize)
    {
        m_viewportSize = viewportSize;
        update();
    }

    void OrthogonalProjection::set(
        float leftPlane,
        float rightPlane,
        float bottomPlane,
        float topPlane,
        float nearPlane,
        float farPlane
    )
    {
        m_leftPlane   = leftPlane;
        m_rightPlane  = rightPlane;
        m_bottomPlane = bottomPlane;
        m_topPlane    = topPlane;
        m_nearPlane   = nearPlane;
        m_farPlane    = farPlane;
        update();
    }

    void OrthogonalProjection::set(
        float leftPlane,
        float rightPlane,
        float bottomPlane,
        float topPlane,
        float nearPlane,
        float farPlane,
        glm::ivec2 viewportSize
    )
    {
        m_leftPlane    = leftPlane;
        m_rightPlane   = rightPlane;
        m_bottomPlane  = bottomPlane;
        m_topPlane     = topPlane;
        m_nearPlane    = nearPlane;
        m_farPlane     = farPlane;
        m_viewportSize = viewportSize;
        update();
    }


    void OrthogonalProjection::update()
    {
        m_image_from_camera = glm::ortho(
            m_leftPlane,
            m_rightPlane,
            m_bottomPlane,
            m_topPlane,
            m_nearPlane,
            m_farPlane
        );
        m_camera_from_image = OrthogonalProjection::orthogonal_inverse(
            m_image_from_camera
        );
    }




} // namespace cameras_gl
