#pragma once

#include <glm/glm.hpp>

namespace cameras_gl {

    class CameraViewInterface
    {
    public:
        CameraViewInterface();
        virtual ~CameraViewInterface();

        inline operator glm::mat4() { return mat(); }
        virtual glm::vec3 position() const = 0;

        /**
         * @brief      Transformation matrix that transforms from world space to camera space. 
         *
         * @return     { description_of_the_return_value }
         */
        virtual glm::mat4 mat() const = 0;

        /**
         * @brief      Transformation matrix that transforms from camera space to world space.
         *
         * @return     { description_of_the_return_value }
         */
        virtual glm::mat4 matInverse() const; 
    };

} // namespace cameras_gl
