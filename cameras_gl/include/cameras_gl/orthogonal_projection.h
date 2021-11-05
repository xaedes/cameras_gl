#pragma once

#include <glm/glm.hpp>
#include <glm/ext/scalar_constants.hpp> // glm::pi

#include "cameras_gl/camera_projection_interface.h"

namespace cameras_gl {

    class OrthogonalProjection : public CameraProjectionInterface
    {
    public:
        static glm::mat4 orthogonal_inverse(
            const glm::mat4& image_from_camera
        );
        
        // OrthogonalProjection() = default;
        OrthogonalProjection(const OrthogonalProjection& other) = default;
        OrthogonalProjection(
            float leftPlane   = -100.0f,
            float rightPlane  = +100.0f,
            float bottomPlane = -100.0f,
            float topPlane    = +100.0f,
            float nearPlane   = 0.8f,
            float farPlane    = 5000.0f,
            glm::ivec2 viewportSize = glm::ivec2(2,2)
        );
        virtual ~OrthogonalProjection();

        virtual glm::mat4 mat() const override;
        virtual bool hasInverse() const override;
        virtual glm::mat4 matInverse() const override;

        virtual glm::ivec2 viewportSize() const override;
        virtual glm::vec2 viewportSize_vec2() const override;
        virtual void setViewportSize(glm::ivec2 size) override;
        glm::ivec2& accessViewportSize()  { return m_viewportSize; }

        float leftPlane()   const { return m_leftPlane;   }
        float rightPlane()  const { return m_rightPlane;  }
        float bottomPlane() const { return m_bottomPlane; }
        float topPlane()    const { return m_topPlane;    }
        float nearPlane()   const { return m_nearPlane;   }
        float farPlane()    const { return m_farPlane;    }


        void setLeftPlane   (float leftPlane   ) { m_leftPlane = leftPlane;     update(); }
        void setRightPlane  (float rightPlane  ) { m_rightPlane = rightPlane;   update(); }
        void setBottomPlane (float bottomPlane ) { m_bottomPlane = bottomPlane; update(); }
        void setTopPlane    (float topPlane    ) { m_topPlane = topPlane;       update(); }
        void setNearPlane   (float nearPlane   ) { m_nearPlane = nearPlane;     update(); }
        void setFarPlane    (float farPlane    ) { m_farPlane = farPlane;       update(); }
        void set(
            float leftPlane,
            float rightPlane,
            float bottomPlane,
            float topPlane,
            float nearPlane,
            float farPlane
        );
        void set(
            float leftPlane,
            float rightPlane,
            float bottomPlane,
            float topPlane,
            float nearPlane,
            float farPlane,
            glm::ivec2 viewportSize
        );

        float& accessLeftPlane()   { return m_leftPlane;   }
        float& accessRightPlane()  { return m_rightPlane;  }
        float& accessBottomPlane() { return m_bottomPlane; }
        float& accessTopPlane()    { return m_topPlane;    }
        float& accessNearPlane()   { return m_nearPlane;   }
        float& accessFarPlane()    { return m_farPlane;    }

        virtual void update();

    protected:

        float m_leftPlane;
        float m_rightPlane;
        float m_bottomPlane;
        float m_topPlane;
        float m_nearPlane;
        float m_farPlane;
        glm::ivec2 m_viewportSize; 

        glm::mat4 m_image_from_camera;
        glm::mat4 m_camera_from_image;
    };

} // namespace cameras_gl
