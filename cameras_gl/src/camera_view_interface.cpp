#include "cameras_gl/camera_view_interface.h"

#include <glm/gtc/matrix_inverse.hpp> // glm::affineInverse

namespace cameras_gl {

    CameraViewInterface::CameraViewInterface() 
    {}

    CameraViewInterface::~CameraViewInterface() 
    {}
    
    glm::mat4 CameraViewInterface::matInverse() const
    { 
        return glm::affineInverse(mat()); 
    }


} // namespace cameras_gl
