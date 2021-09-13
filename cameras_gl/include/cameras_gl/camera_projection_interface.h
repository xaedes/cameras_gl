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
        virtual glm::mat4 matInverse() const;
        virtual glm::ivec2 viewportSize() const = 0;
        virtual glm::vec2 viewportSize_vec2() const = 0;
        
        virtual void setViewportSize(glm::ivec2 size) = 0;

        float aspectRatio() const;
        
    };

} // namespace cameras_gl
