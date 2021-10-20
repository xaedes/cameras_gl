#include "cameras_gl/orbital_view.h"

#include <glm/gtx/extend.hpp>
#include <glm/gtx/transform.hpp> 
#include <glm/gtx/norm.hpp>
#include <glm/gtx/rotate_vector.hpp> // glm::rotateX

#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::lookAt
#include <glm/gtc/matrix_inverse.hpp>   // glm::affineInverse
#include <glm/gtx/euler_angles.hpp>   // glm::eulerAngleX, glm::eulerAngleY, glm::eulerAngleZ
#include <glm/gtx/transform.hpp>   // glm::translate, glm::rotate, 


namespace cameras_gl {


    OrbitalView::OrbitalView(
        glm::vec3 target,
        glm::vec3 angles,
        float distance
    )
        : m_target(target)
        , m_angles(angles)
        , m_distance(distance)
        , m_swapYZ(false)
    {}

    OrbitalView::~OrbitalView()
    {}

    glm::mat4 OrbitalView::mat() const 
    {
        return m_camera_from_world;
    }

    glm::mat4 OrbitalView::matInverse() const 
    {
        return m_world_from_camera;
    }

    glm::vec3 OrbitalView::position() const 
    {
        return m_position;
    }    

    void OrbitalView::setTarget(const glm::vec3& target)
    {
        m_target = target;
        update();
    }

    void OrbitalView::setAngles(const glm::vec3& angles)
    {
        m_angles = angles;
        update();
    }

    void OrbitalView::setDistance(float distance)
    {
        m_distance = distance;
        update();
    }
    
    void OrbitalView::setSwapYZ(bool swapYZ)
    {
        m_swapYZ = swapYZ;
        update();
    }

    void OrbitalView::set(
        const glm::vec3& target, 
        const glm::vec3& angles, 
        float distance
    )
    {
        m_target = target;
        m_angles = angles;
        m_distance = distance;
        update();
    }

    void OrbitalView::update()
    {
        m_world_from_camera = (
            glm::translate(m_target)
            * (glm::eulerAngleY(m_angles.z))
            * (glm::eulerAngleX(-m_angles.y))
            * (glm::eulerAngleZ(m_angles.x))
            * glm::translate(glm::vec3(0, 0, m_distance))
        );
        if (m_swapYZ)
        {
            m_world_from_camera = glm::mat4(
                1, 0, 0, 0,
                0, 0, 1, 0,
                0, 1, 0, 0,
                0, 0, 0, 1
            ) * m_world_from_camera;
        }
        m_camera_from_world = glm::affineInverse(m_world_from_camera);
        m_position = m_world_from_camera * glm::vec4(0, 0, 0, 1);
    }

} // namespace cameras_gl
