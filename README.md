# The Raytracer Project   
  
The repository for the Raytracer project.  
  
<img src="doc/Raytracer.gif" alt="demonstration Raytracer" width="680" height="400">  
  
  
---  
  
  
## Table of contents  
  
[1. The purpose of the project](#titre1)  
[2. How to use Raytracer](#titre2)  
[3. How to launch](#titre3)  
[4. People on the project](#titre4)  
  
  
---  
  
  
## <a id="titre1"></a>1. The purpose of the project   
  
Raytracing is a 3D rendering technique used in computer graphics. This technique consists  
of simulating the propagation of light in a virtual scene by tracing light rays from the  
camera or a light source and calculating their interaction with the objects in the scene.  
The result is a realistic image with very realistic light effects, reflections, refractions and shadows.  
Your goal is to create a program able to generate an image from a file describing the scene.  
  
<img src="doc/CPP_logo.png" alt="Logo Cpp" width="173" height="173">  
<img src="doc/Raytracer_diagram.png" alt="Raytracer Diagram" width="263" height="173">  
<img src="doc/Epitech_logo.png" alt="Logo Epitech" width="173" height="173">  
  
  
---  
  
  
## <a id="titre2"></a>2. How to use Raytracer   
  
To use Raytracer you need a configuration file like the following:  
  
```cpp  
  
/*  
    We with arguments to return which are the following:  
  
    --blending or -b for Blending, this allows us to overlay all the scene possibilities  
    --fov or -f for Field Of View, this allows us to give the fov of the scene  
    --height or -h for Height, this allows us to give the size we want for our scene  
    --width or -w for Width, which allows us to give the width of our scene  
    --out or -o for Out, for the file that will be rendered in 3D  
    --rebound or -r for Rebound, that allows us to choose the number of bounce of the light  
*/  
  
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
  
  
## <a id="titre3"></a>3. How to launch   
  
To run the project:  
  
```sh  
  
> make  
> ./raytracer <SCENE_FILE>  
  
```  
  
  
---  
  
  
## <a id="titre4"></a>4. People on the project   
  
| [<img src="https://github.com/Cyprien-nguyen-van-vien.png?size=85" width=85><br><sub>Cyprien Nguyen-Van-Vien</sub>](https://github.com/Cyprien-nguyen-van-vien) | [<img src="https://github.com/damienBC.png?size=85" width=85><br><sub>Damien Benais-Captal</sub>](https://github.com/damienBC) | [<img src="https://github.com/Pierrelouisleroy.png?size=85" width=85><br><sub>Pierre-Louis Leroy</sub>](https://github.com/Pierrelouisleroy) | [<img src="https://github.com/Lipatant.png?size=85" width=85><br><sub>Virgile Berrier</sub>](https://github.com/Lipatant)  
| :--: | :--: | :--: | :--: |  

cyprien.nguyen-van-vien@epitech.eu  
damien.benais-captal@epitech.eu  
pierre-louis.leroy@epitech.eu  
virgile.berrier@epitech.eu  
