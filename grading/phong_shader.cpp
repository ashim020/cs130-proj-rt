#include "light.h"
#include "object.h"
#include "phong_shader.h"
#include "ray.h"
#include "render_world.h"

vec3 Phong_Shader::
Shade_Surface(const Ray& ray,const vec3& intersection_point,
    const vec3& normal,int recursion_depth) const
{
    vec3 color;
    vec3 diffuse;
    //determine the color
    for(unsigned i = 0; i < world.lights.size(); i++) {
        vec3 l = world.lights[i]->position - intersection_point;
        vec3 light_color = world.lights[i]->Emitted_Light(l);
        double nl_dot = std::max(0.0, dot(normal, l.normalized()));
        diffuse = color_diffuse * light_color * nl_dot;
    }
    color += diffuse;
    return color;
}
