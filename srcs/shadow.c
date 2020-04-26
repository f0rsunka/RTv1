/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 20:19:10 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/13 20:37:30 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

hit = orig + dir*dist_i;
            N = (hit - spheres[i].center).normalize();

Vec3f reflect(const Vec3f &I, const Vec3f &N) {
    return I - N*2.f*(I*N);
}

struct Material
{
	Material(const Vec2f &a, const Vec3f &color, const float &spec) : albedo(a), diffuse_color(color), specular_exponent(spec) {}
	Material() : albedo(1,0), diffuse_color(), specular_exponent() {}
	Vec2f albedo;
	Vec3f diffuse_color;
	float specular_exponent;
};

return (intensity = material.diffuse_color * diffuse_light_intensity * material.albedo[0])


	Material      ivory(Vec2f(0.6,  0.3), Vec3f(0.4, 0.4, 0.3),   50.);
    Material red_rubber(Vec2f(0.9,  0.1), Vec3f(0.3, 0.1, 0.1),   10.);

	spheres.push_back(Sphere(Vec3f(-3,    0,   -16), 2,      ivory));
    spheres.push_back(Sphere(Vec3f(-1.0, -1.5, -12), 2, red_rubber));













bool scene_intersect(const Vec3f &orig, const Vec3f &dir, const std::vector<Sphere> &spheres, Vec3f &hit, Vec3f &N, Material &material) {
    float spheres_dist = std::numeric_limits<float>::max();
    for (size_t i=0; i < spheres.size(); i++) {
        float closest.dist;
        if (spheres[i].ray_intersect(orig, dir, closest.dist) && closest.dist < spheres_dist) {
            spheres_dist = closest.dist;
            hit = orig + dir*closest.dist;
            N = (hit - spheres[i].center).normalize();
            material = spheres[i].material;
        }
    }
    return spheres_dist<1000;
}


bool ray_intersect(const Vec3f &orig, const Vec3f &dir, float &t0) const {
        Vec3f L = center - orig;
        float tca = L*dir;
        float d2 = L*L - tca*tca;
        if (d2 > radius*radius) return false;
        float thc = sqrtf(radius*radius - d2);
        t0       = tca - thc;
        float t1 = tca + thc;
        if (t0 < 0) t0 = t1;
        if (t0 < 0) return false;
        return true;
    }

Vec3f cast_ray(const Vec3f &orig, const Vec3f &dir, const std::vector<Sphere> &spheres, const std::vector<Light> &lights) {
    Vec3f point, N;
    Material material;

    if (!scene_intersect(orig, dir, spheres, point, N, material)) {
        return Vec3f(0.2, 0.7, 0.8); // background color
    }

    float diffuse_light_intensity = 0, specular_light_intensity = 0;
    for (size_t i=0; i<lights.size(); i++) {
        Vec3f light_dir      = (lights[i].position - point).normalize();

        diffuse_light_intensity  += lights[i].intensity * std::max(0.f, light_dir*N);
        specular_light_intensity += powf(std::max(0.f, -reflect(-light_dir, N)*dir), material.specular_exponent)*lights[i].intensity;
    }
    return material.diffuse_color * diffuse_light_intensity * material.albedo[0] + Vec3f(1., 1., 1.)*specular_light_intensity * material.albedo[1];
}




t_color		trace_ray(t_vec3 camera, t_vec3 dir, t_rtv *r)
{
	t_color				color;
	t_closest_sphere	closest;
	t_scene				*start_list;
	t_scene				*tmp;
	float				*tmp_dist;

	closest.dist = FLT_MAX - 1;
	tmp_dist = FLT_MAX;
	closest.sphere = NULL;
	start_list = r->scene;
	while (tmp != NULL)
	{
		if (r->scene->type == SPHERE)
		{
			if (intersect_ray_sphere(camera, dir, *(t_sphere *)r->scene->object, &closest.dist) && closest.dist < tmp_dist)
			{
				tmp_dist = closest.dist;
				closest.sphere = (t_sphere *)r->scene->object;
				r->scene = start_list;
				color = add_light(closest.sphere->material.color, closest, dir, r);
				return (color);
			}
		}
		tmp = r->scene->next;
		r->scene = tmp;
	}
	r->scene = start_list;
	if (closest.sphere == NULL)
		return (transform_color(BACKGROUND_COLOR));
	// color = add_light(closest.sphere->material.color, closest, dir, r);
	// return (color);
}




	dist = MAX_DIST + 1.f;
	i = 0;
	while (i < count)
	{
		if ((*(obj + i)).e_type == o_sphere)
		{
			dist_i = 0.f;
			j = sphere_intersect(orig, dir, (obj + i), &dist_i);
			if (j && dist_i < dist)
			{
				dist = dist_i;
				lighting->hit = orig + dir * dist_i;
				lighting->n = fast_normalize(lighting->hit - ((*(obj + i)).center));
				if (j == 2)
					lighting->n *= -1.f;
				lighting->mat = (*(obj + i)).mat;
				if ((*(obj + i)).mat.texture_id != -1)
				{
					uv = uv_mapping_for_sphere(lighting);
					normalize_coord_for_texture((obj + i), uv, &(lighting->mat.diffuse_color), texture, texture_w, texture_h, prev_texture_size);
				}
			}
		}