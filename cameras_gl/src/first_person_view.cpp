#include "cameras_gl/first_person_view.h"

#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/gtc/matrix_inverse.hpp>   // glm::affineInverse
#include <glm/gtx/euler_angles.hpp>   // glm::eulerAngleX, glm::eulerAngleY, glm::eulerAngleZ
#include <glm/gtx/transform.hpp>   // glm::translate, glm::rotate, 

namespace cameras_gl {

    FirstPersonView::FirstPersonView(
        const glm::vec3& position, 
        const glm::vec3& rollPitchYaw
    )
        : m_position(position)
        , m_rollPitchYaw(rollPitchYaw)
    {
        update();
    }

    FirstPersonView::~FirstPersonView()
    {}

    glm::vec3 FirstPersonView::position() const
    {
        return m_position;
    }

    glm::mat4 FirstPersonView::mat() const
    {
        return m_camera_from_world;
    }
    
    glm::mat4 FirstPersonView::matInverse() const
    { 
        return m_world_from_camera;
    }

    void FirstPersonView::setPosition(const glm::vec3& pos)
    {
        m_position = pos;
        update();
    }
    
    void FirstPersonView::setRollPitchYaw(const glm::vec3& rollPitchYaw)
    {
        m_rollPitchYaw = rollPitchYaw;
        update();
    }

    void FirstPersonView::set(
        const glm::vec3& position, 
        const glm::vec3& rollPitchYaw
    )
    {
        m_position = position;
        m_rollPitchYaw = rollPitchYaw;
        update();
    }

    void FirstPersonView::update()
    {
        m_world_from_camera = (
            glm::translate(m_position)
            * (glm::eulerAngleY(m_rollPitchYaw.z)) // yaw
            * (glm::eulerAngleZ(m_rollPitchYaw.x)) // roll
            * (glm::eulerAngleX(m_rollPitchYaw.y)) // pitch
        );
        m_camera_from_world = glm::affineInverse(m_world_from_camera);
    }



} // namespace cameras_gl
