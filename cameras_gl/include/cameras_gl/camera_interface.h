#pragma once

#include <type_traits>
#include <glm/glm.hpp>
#include "cameras_gl/camera_view_interface.h"
#include "cameras_gl/camera_projection_interface.h"
//#include "geometry/cast_ray_world.h"
//#include "geometry/reproject_to_plane.h"

namespace cameras_gl {

    /**
     * @brief      This class describes a camera interface with access to
     *             CameraProjectionInterface and CameraViewInterface.
     */
    class CameraInterface
    {
    public:
        CameraInterface(){}
        virtual ~CameraInterface(){}

        virtual CameraProjectionInterface& projection() = 0;
        virtual CameraViewInterface& view() = 0;
        virtual const CameraProjectionInterface& projection() const = 0;
        virtual const CameraViewInterface& view() const = 0;

        inline void setViewportSize(glm::ivec2 size)
        {
            projection().setViewportSize(size);
        }

    };

} // namespace cameras_gl
