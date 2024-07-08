#include <iostream>

#include "Vector3.h"
#include "Color.h"
#include "Point3.h"
#include "Ray.h"
#include "ecs/Scene.h"
#include "CollisionRecord.h"
#include "Interval.h"
#include "Random.h"
#include "Camera.h"

using namespace PathTracer;

Sphere randomSphere()
{
    static uint32_t seed = 1234567;

    double x = randomDouble(seed) * 2 - 1;
    seed = random(seed);

    double y = randomDouble(seed) * 2 - 1;
    seed = random(seed);

    double z = -1;
    seed = random(seed);

    double r = randomDouble(seed) * 0.2;
    seed = random(seed);

    return Sphere{{x, y, z}, r};
}

int main()
{
    Scene scene;

    //  Scene initialization

    for(int i = 0; i < 5; i++)
    {
        size_t entityId = scene.addEntity();
        scene.addComponent<SphericalRayColliderComponent>(entityId, {randomSphere()});
    }

    //  Writing image to the output in the ppm format

    Camera camera;

    camera.render(scene);

    return 0;
}