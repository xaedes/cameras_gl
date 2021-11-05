#pragma once

#include <glm/glm.hpp>

namespace cameras_gl {

    /**
     * @brief      This class describes a camera projection interface.
     */
    class CameraProjectionInterface
    {
    public:
        CameraProjectionInterface();
        virtual ~CameraProjectionInterface();

        inline operator glm::mat4() { return mat(); }

        virtual glm::mat4 mat() const = 0;
        virtual bool hasInverse() const = 0; // ortho has inverse, perspective not
        virtual glm::mat4 matInverse() const = 0;
        virtual glm::ivec2 viewportSize() const = 0;
        virtual glm::vec2 viewportSize_vec2() const = 0;
        
        virtual void setViewportSize(glm::ivec2 size) = 0;

        virtual float aspectRatio() const;
        
    };

} // namespace cameras_gl
