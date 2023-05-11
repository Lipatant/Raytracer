# The Raytracer Project 

The repository for the Raytracer project.

<img src="raytracer.gif" alt="demonstration Raytracer" width="680" height="400">


---


## Table of contents

1. The purpose of the project
2. How to use Raytracer
3. How to launch
4. People on the project


---


## 1. The purpose of the project

Raytracing is a 3D rendering technique used in computer graphics. This technique consists
of simulating the propagation of light in a virtual scene by tracing light rays from the
camera or a light source and calculating their interaction with the objects in the scene.
The result is a realistic image with very realistic light effects, reflections, refractions and shadows.
Your goal is to create a program able to generate an image from a file describing the scene.

<img src="CPP_logo.png" alt="Logo Cpp" width="173" height="173">
<img src="Raytracer_diagram.png" alt="Raytracer Diagram" width="263" height="173">
<img src="Epitech_logo.png" alt="Logo Epitech" width="173" height="173">


---


## 2. How to use Raytracer

To use Raytracer you need a configuration file like the following:

```cpp

/*example.cfg: An example configuration file that stores information about a store. */

// Basic store information:

// version
//shape x y z width height r g b

scene =
{
    shapes = (
        {
            shape = "sph"; // form
            x = 10;        // position x in the scene
            y = 11;        // position y in the scene
            z = 12;        // position z in the scene
            width = 10;    // width of the form
            height = 10;   // height of the form
            r = 155;       // rgb code
            g = 255;       // rgb code
            b = 255;       // rgb code
        },
        {
            shape = "tri";
            x = 10;
            y = 10;
            z = 10;
            width = 10;
            height = 10;
            r = 155;
            g = 255;
            b = 255;
        }
    );
};

```


---


## 3. How to launch

To run the project:

```sh

> make
> ./raytracer <SCENE_FILE>

```


---


## 4. People on the project

| [<img src="https://github.com/Cyprien-nguyen-van-vien.png?size=85" width=85><br><sub>Cyprien Nguyen-Van-Vien</sub>](https://github.com/Cyprien-nguyen-van-vien) | [<img src="https://github.com/damienBC.png?size=85" width=85><br><sub>Damien Benais-Captal</sub>](https://github.com/damienBC) | [<img src="https://github.com/Pierrelouisleroy.png?size=85" width=85><br><sub>Pierre-Louis Leroy</sub>](https://github.com/Pierrelouisleroy) | [<img src="https://github.com/Lipatant.png?size=85" width=85><br><sub>Virgile Berrier</sub>](https://github.com/Lipatant)
| :--: | :--: | :--: | :--: |
