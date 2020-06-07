
#include "rtv1.h"

void        init_scene(char *filename, t_rtv *r)
{
    int     fd;
    int     all_count;
    int     light_count;
    char    *line;

    all_count = 0;
    if (!(fd = open(filename, O_RDONLY)))
    {
        write(1, "Invalid file! Expected *.rtv1 text scene file.\n", 47);
        exit(1);
    }
    while (get_next_line(fd, &line) == 1)
    {
        all_count += get_objects_by_name(line, "plane");
        all_count += get_objects_by_name(line, "sphere");
        all_count += get_objects_by_name(line, "cone");
        all_count += get_objects_by_name(line, "cylinder");
        free(line);
    }
    close(fd);
    init_primitive(r, all_count);
}

int			get_objects_by_name(const char *line, const char *needed)
{
    char    *tmp;

    tmp = strstr(line, needed);
    if (tmp != 0)
        return (1);
    return (0);
}

void	init_plane(t_scene *scene, t_vec3 center, t_vec3 normal, t_color color)
{
    scene->object = (t_object *)malloc(sizeof(t_object));
    scene->object == NULL ? exit(88) : 0;
    ((t_object *)scene->object)->center = (t_vec3){center.x, center.y, center.z};
    ((t_object *)scene->object)->normal = (t_vec3){normal.x, normal.y, normal.z};
    ((t_object *)scene->object)->material.color = float_to_byte((t_color){color.r, color.g, color.b});
    ((t_object *)scene->object)->material.specular = 50.0f;
    scene->type = PLANE;
}

void	init_primitive(t_rtv *r, int n)
{
    int		i;
    t_scene	*tmp;

    i = 0;
    while (i < n)
    {
        r->scene = (t_scene*)malloc(sizeof(t_scene));
        (r->scene == NULL ? exit(8) : 1);
        if (i == 0)
            init_sphere(i, r->scene);
        if (i == 1)
            init_plane(r->scene, (t_vec3){0,-1.5,0}, (t_vec3){0,1,0}, (t_color){255, 0, 0});
        if (i == 2)
            init_plane(r->scene, (t_vec3){1.5,0,0}, (t_vec3){-1,0,0}, (t_color){0, 255, 0});
        if (i == 3)
            init_plane(r->scene, (t_vec3){-1.5,0,0}, (t_vec3){1,0,0}, (t_color){0, 0, 255});
//		if (i >= 1 && i <= 2)
//			init_sphere(i, scene);
//		if (i == 3)
//			init_plane(scene);
//		// if (i == 4)
//		// 	init_cone(scene);
//		if (i == 0)
//			init_cylinder(scene);

        if (i == 0)
            r->scene->next = NULL;
        else
            r->scene->next = tmp;
        i++;
        tmp = r->scene;
    }
    r->scene = r->scene;
}