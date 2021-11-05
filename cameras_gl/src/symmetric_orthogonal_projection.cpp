#pragma once

#include "cameras_gl/symmetric_orthogonal_projection.h"

namespace cameras_gl {
    SymmetricOrthogonalProjection::SymmetricOrthogonalProjection(
        glm::vec2 offset,
        float width,
        float nearPlane,
        float farPlane,
        glm::ivec2 viewportSize
    )   
        : m_offset(offset)
        , m_width(width)
        , m_nearPlane(nearPlane)
        , m_farPlane(farPlane)
    {
        m_viewportSize = viewportSize;
        update();
    }

    SymmetricOrthogonalProjection::~SymmetricOrthogonalProjection()
    {}

    void SymmetricOrthogonalProjection::set(
        glm::vec2 offset,
        float width,
        float nearPlane,
        float farPlane
    )
    {
        m_offset     = offset;
        m_width     = width;
        m_nearPlane = nearPlane;
        m_farPlane  = farPlane;
        update();
    }

    void SymmetricOrthogonalProjection::set(
        glm::vec2 offset,
        float width,
        float nearPlane,
        float farPlane,
        glm::ivec2 viewportSize
    )
    {
        m_offset     = offset;
        m_width     = width;
        m_nearPlane = nearPlane;
        m_farPlane  = farPlane;
        m_viewportSize  = viewportSize;
        update();
    }

    void SymmetricOrthogonalProjection::update()
    {
        auto aspectRatio = this->aspectRatio();
        m_leftPlane   = m_offset.x + -0.5f * m_width;
        m_rightPlane  = m_offset.x + +0.5f * m_width;
        m_bottomPlane = m_offset.y + -0.5f * m_width / aspectRatio;
        m_topPlane    = m_offset.y + +0.5f * m_width / aspectRatio;
        OrthogonalProjection::update();
    }


} // namespace cameras_gl
