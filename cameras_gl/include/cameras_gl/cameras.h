#pragma once

#include "cameras_gl/camera.h"
#include "cameras_gl/first_person_view.h"
#include "cameras_gl/look_at_view.h"
#include "cameras_gl/orbital_view.h"
#include "cameras_gl/perspective_projection.h"
#include "cameras_gl/orthogonal_projection.h"
#include "cameras_gl/symmetric_orthogonal_projection.h"

namespace cameras_gl {

    using FirstPersonPerspectiveCamera         = Camera<PerspectiveProjection,         FirstPersonView >;
    using LookAtPerspectiveCamera              = Camera<PerspectiveProjection,         LookAtView      >;
    using OrbitalPerspectiveCamera             = Camera<PerspectiveProjection,         OrbitalView     >;

    using FirstPersonOrthogonalCamera          = Camera<OrthogonalProjection,          FirstPersonView >;
    using LookAtOrthogonalCamera               = Camera<OrthogonalProjection,          LookAtView      >;
    using OrbitalOrthogonalCamera              = Camera<OrthogonalProjection,          OrbitalView     >;

    using FirstPersonSymmetricOrthogonalCamera = Camera<SymmetricOrthogonalProjection, FirstPersonView >;
    using LookAtSymmetricOrthogonalCamera      = Camera<SymmetricOrthogonalProjection, LookAtView      >;
    using OrbitalSymmetricOrthogonalCamera     = Camera<SymmetricOrthogonalProjection, OrbitalView     >;

} // namespace cameras_gl
