#pragma once

#include <glm/glm.hpp>
#include <glm/ext/scalar_constants.hpp> // glm::pi

#include "cameras_gl/orthogonal_projection.h"

namespace cameras_gl {

    class SymmetricOrthogonalProjection : public OrthogonalProjection
    {
    public:
        // SymmetricOrthogonalProjection() = default;
        SymmetricOrthogonalProjection(const SymmetricOrthogonalProjection& other) = default;
        SymmetricOrthogonalProjection(
            glm::vec2 offset  = glm::vec2(0,0),
            float width       = 100.0f,
            float nearPlane   = 0.8f,
            float farPlane    = 5000.0f,
            glm::ivec2 viewportSize = glm::ivec2(2,2)
        );
        virtual ~SymmetricOrthogonalProjection();

        glm::vec2 offset()   const { return m_offset;           }
        float width()        const { return m_width;            }
        void setWidth(float width) { m_width = width; update(); }
        void set(
            glm::vec2 offset,
            float width,
            float nearPlane,
            float farPlane
        );
        void set(
            glm::vec2 offset,
            float width,
            float nearPlane,
            float farPlane,
            glm::ivec2 viewportSize
        );

        glm::vec2& accessOffset() { return m_offset; }
        float& accessWidth() { return m_width; }

        virtual void update() override;

    protected:

        glm::vec2 m_offset;
        float m_width;
        float m_nearPlane;
        float m_farPlane;
    };

} // namespace cameras_gl
