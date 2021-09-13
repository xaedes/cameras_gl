#include "cameras_gl/look_at_view.h"

#include <glm/gtc/matrix_inverse.hpp>   // glm::affineInverse
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::lookAt

namespace cameras_gl {

    LookAtView::LookAtView(glm::vec3 position, glm::vec3 target, glm::vec3 up)
        : m_position(position)
        , m_target(target)
        , m_up(up)
    {}
    LookAtView::~LookAtView()
    {}

    glm::mat4 LookAtView::mat() const 
    {
        return m_camera_from_world;
    }

    glm::mat4 LookAtView::matInverse() const 
    {
        return m_world_from_camera;
    }

    glm::vec3 LookAtView::position() const 
    {
        return m_position;
    }

    void LookAtView::setPosition(const glm::vec3& position)
    {
        m_position = position;
        update();
    }

    void LookAtView::setTarget(const glm::vec3& target)
    {
        m_target = target;
        update();
    }

    void LookAtView::setUp(const glm::vec3& up)
    {
        m_up = up;
        update();
    }

    void LookAtView::set(
        const glm::vec3& position, 
        const glm::vec3& target,
        const glm::vec3& up
    )
    {
        m_position = position;
        m_target = target;
        m_up = up;
        update();
    }


    void LookAtView::update()
    {
        m_camera_from_world = glm::lookAt(m_position, m_target, m_up);
        m_world_from_camera = glm::affineInverse(m_camera_from_world);
    }


} // namespace cameras_gl
