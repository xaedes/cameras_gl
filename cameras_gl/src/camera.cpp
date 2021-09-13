#include "cameras_gl/camera.h"

namespace cameras_gl { 

    Camera::Camera()
    {}

    Camera::~Camera()
    {}

    CameraProjectionInterface& Camera::projection()
    {
        return static_cast<CameraProjectionInterface&>(m_projection);
    };
    CameraViewInterface& Camera::view()
    {
        return static_cast<CameraViewInterface&>(m_view);
    };
    
    const CameraProjectionInterface& Camera::projection() const
    {
        return static_cast<const CameraProjectionInterface&>(m_projection);
    };
    const CameraViewInterface& Camera::view() const
    {
        return static_cast<const CameraViewInterface&>(m_view);
    };

} // namespace cameras_gl
