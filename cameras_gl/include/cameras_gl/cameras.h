#pragma once

#include "cameras_gl/camera.h"
#include "cameras_gl/first_person_view.h"
#include "cameras_gl/look_at_view.h"
#include "cameras_gl/orbital_view.h"
#include "cameras_gl/perspective_projection.h"

namespace cameras_gl {

    using FirstPersonPerspectiveCamera = Camera<PerspectiveProjection, FirstPersonView>;
    using LookAtPerspectiveCamera = Camera<PerspectiveProjection, LookAtView>;
    using OrbitalPerspectiveCamera = Camera<PerspectiveProjection, OrbitalView>;

} // namespace cameras_gl
