

TraceRay(O, D, t_min, t_max, depth)
{
    closest_sphere, closest_t = ClosestIntersection(O, D, t_min, t_max)

    if closest_sphere == NULL
        return BACKGROUND_COLOR

    # Вычисление локального цвета
    P = O + closest_t*D  # Вычисление точки пересечения
    N = P - closest_sphere.center  # Вычисление нормали к сфере в точке пересечения
    N = N / length(N)

	
    local_color = closest_sphere.color*ComputeLighting(P, N, -D, sphere.specular)

    # Если мы достигли предела рекурсии или объект не отражающий, то мы закончили
    r = closest_sphere.reflective
    if depth <= 0 or r <= 0:
        return local_color

    # Вычисление отражённого цвета
    R = ReflectRay(-D, N)
    reflected_color = TraceRay(P, R, 0.001, inf, depth - 1)

    return local_color*(1 - r) + reflected_color*r
}