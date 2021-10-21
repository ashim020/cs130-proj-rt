#include "sphere.h"
#include "ray.h"

// Determine if the ray intersects with the sphere
Hit Sphere::Intersection(const Ray& ray, int part) const
{
    vec3 ec = ray.endpoint - this->center;
    Hit hit = {0, 0, 0};
    double a = dot(ray.direction, ray.direction);
    double b = 2 * dot(ray.direction, ec);
    double c = dot(ec, ec) - pow(this->radius, 2);
    double t1 = -1;
    double t2 = -1;
    double det = pow(b, 2) - 4 * a * c;
    if(det >= 0 && a > 0) {
        t1 = (-b + sqrt(det)) / (2 * a);
        t2 = (-b - sqrt(det)) / (2 * a);
    }
    if(t1 < small_t) {
        t1 = -1;
    }
    if(t2 < small_t) {
        t2 = -1;
    }
    if(t1 > 0 || t2 > 0) {
        hit.object = this;
        if(t1 > 0 && t2 > 0) {
            hit.dist = std::min(t1, t2);
        }
        else if(t1 > 0) {
            hit.dist = t1;
        }
        else {
            hit.dist = t2;
        }
    }
    return hit;
}

vec3 Sphere::Normal(const vec3& point, int part) const
{
    vec3 normal;
    // compute the normal direction
    normal = (point - center).normalized();
    return normal;
}

Box Sphere::Bounding_Box(int part) const
{
    Box box;
    TODO; // calculate bounding box
    return box;
}

