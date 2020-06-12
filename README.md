School 21 Project

Ray-tracer engine for rendering 4 shapes: sphere, plane, cylinder, cone. It includes multiple light spots: ambient, directional, point.

Shapes is readed from configuration files, which exists on "scenes" folder. Scenes have a same structure, so if you want to create own scene, you should follow simple rules: firstly, you need to put light spots, secondly, you need to put any objects and information about it.

Principles of work

Camera is origin of the ray. We find a ray's intersection with one of shapes for each pixel. If it happens, we create a ray from intersection point of the shape to a light spot. If any shape locates on the ray's way, we render a shadow on this pixel. If ray hasn't obstacles on his way, we render a light on this pixel. If ray hasn't intersection with any shape, we render background color.

Camera has opportunity to move and rotate. Try it typing on arrows and AWSDQE keys.

Launching

Enter "make" on the command line. Put ./RTv1 scenes/%scene_name% to the terminal. Enjoy (≧◡≦)

Creators:

	f0rsunka aka cvernius: raytracer engine
	berriestime aka dmorrige: parsing scenes

![](https://github.com/f0rsunka/rtv1/raw/master/screenshots/1.png)

![](https://github.com/f0rsunka/rtv1/raw/master/screenshots/2.png)

![](https://github.com/f0rsunka/rtv1/raw/master/screenshots/3.png)

![](https://github.com/f0rsunka/rtv1/raw/master/screenshots/5.png)

![](https://github.com/f0rsunka/rtv1/raw/master/screenshots/4.png)
