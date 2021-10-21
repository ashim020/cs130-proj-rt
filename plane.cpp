#include "plane.h"
#include "hit.h"
#include "ray.h"
#include <cfloat>
#include <limits>

// Intersect with the half space defined by the plane.  The plane's normal
// points outside.  If the ray starts on the "inside" side of the plane, be sure
// to record a hit with t=0 as the first entry in hits.
Hit Plane::Intersection(const Ray& ray, int part) const
{
    Hit hit = {0,0,0};
    double dot_ex_n = dot(ray.endpoint - this->x1, this->normal);
    if(dot_ex_n < DBL_EPSILON) {
        hit.object = this;
    } else {
        double dot_v_n = dot(ray.direction, this->normal);
        if(!(fabs(dot_v_n) < DBL_EPSILON)) {
            hit.dist = -dot_ex_n / dot_v_n;
            if(hit.dist > 0) {
                hit.object = this;
            } else {
                hit.dist = 0;
            }
        }
    }
    return hit;
}

vec3 Plane::Normal(const vec3& point, int part) const
{
    return normal;
}

// There is not a good answer for the bounding box of an infinite object.
// The safe thing to do is to return a box that contains everything.
Box Plane::Bounding_Box(int part) const
{
    Box b;
    b.hi.fill(std::numeric_limits<double>::max());
    b.lo=-b.hi;
    return b;
}

