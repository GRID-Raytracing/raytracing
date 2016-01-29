# raytracing

This is a basic raytracer built in C++11. It was developed as an assingment for a lecture at Bergische Universität Wuppertal.

The code contains several incomplete features, which are not yet fit for use. 
Nevertheless, they should not prevent compilation and use of the completed features. 


## make targets

The following targets are defined in the included makefile:


__SphereField__ Creates and renders a scene containing a 10x10 square of colored and reflective spheres. The resulting image is 8000x8000 pixels.

__emptySceneRenderTest__ Creates an empty scene and renders it as a 100x100px image. Used for testing purposes (e.g. compile- or obvious runtime-errors).

__simpleSphereRenderTest__ Creates a scene containing one Sphere and renders it as a 100x100px image. Used for basic functional testing. Will result in a black image in the current version, due to a lack of light sources in the scene.

__twoSpheresOcclusionTest__ Creates a scene with two Spheres, one partially covering the other. Used to test correctness of detecting the closest intersection.

__ShadowedSphereTest__ Basically the same as simpleSphereRenderTest, but contains a light source.

__ReflectiveSphereTest__ Creates a scene with two spheres, one of them reflective. Used to test correctness of the reflection calculation.

__clean__ Removes all generated object-files, executables and images, except for the SphereField image.