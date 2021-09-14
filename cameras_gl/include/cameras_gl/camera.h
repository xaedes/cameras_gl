#pragma once

#include <type_traits>
#include <glm/glm.hpp>
#include "cameras_gl/camera_interface.h"
#include "cameras_gl/camera_view_interface.h"
#include "cameras_gl/camera_projection_interface.h"

namespace cameras_gl {

    /**
     * @brief      This class describes a camera with specified camera
     *             projection and view types. 
     *
     * @tparam     projection_type  type implementing CameraProjectionInterface
     * @tparam     view_type        type implementing CameraViewInterface
     */
    template<
        typename projection_type,
        typename view_type,
        // https://stackoverflow.com/a/30687399/798588
        typename std::enable_if_t<std::is_base_of<CameraProjectionInterface, projection_type>::value, bool> = true,
        typename std::enable_if_t<std::is_base_of<CameraViewInterface, view_type>::value, bool> = true
    >
    class Camera : public CameraInterface
    {
    public:
        Camera(){}
        virtual ~Camera(){}

        CameraProjectionInterface& projection() override
        {
            return static_cast<CameraProjectionInterface&>(m_projection);
        }
        CameraViewInterface& view() override
        {
            return static_cast<CameraViewInterface&>(m_view);
        }

        const CameraProjectionInterface& projection() const override
        {
            return static_cast<const CameraProjectionInterface&>(m_projection);
        }
        const CameraViewInterface& view() const override
        {
            return static_cast<const CameraViewInterface&>(m_view);
        }
        
        inline projection_type& accessProjection() { return m_projection; }
        inline view_type& accessView() { return m_view; }
        
        inline const projection_type& accessProjection() const { return m_projection; }
        inline const view_type& accessView() const { return m_view; }
        
    protected:
        projection_type m_projection;
        view_type       m_view;
    };

} // namespace cameras_gl
