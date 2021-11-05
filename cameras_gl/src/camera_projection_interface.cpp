#include "cameras_gl/camera_projection_interface.h"

#include <glm/matrix.hpp> // glm::inverse for generic 4x4 matrices

namespace cameras_gl {

    CameraProjectionInterface::CameraProjectionInterface() 
    {}

    CameraProjectionInterface::~CameraProjectionInterface() 
    {}
    
    float CameraProjectionInterface::aspectRatio() const
    {
        glm::ivec2 vpsize = viewportSize();
        if (vpsize[1] == 0) 
        {
            return 1.0f;
        }
        else 
        {
            return (vpsize[0] / static_cast<float>(vpsize[1]));
        }
    }
} // namespace cameras_gl
