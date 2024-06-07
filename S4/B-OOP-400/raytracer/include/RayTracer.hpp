/*
** EPITECH PROJECT, 2024
** lastTry
** File description:
** RayTracer
*/
#ifndef RAYTRACER_HPP
#define RAYTRACER_HPP
    #include "Ray.hpp"
    #include "Camera.hpp"
    #include "HitableList.hpp"
    #include "Material.hpp"
    #include "Sphere.hpp"
    #include "Cylinder.hpp"
    #include "Plane.hpp"
    #include "Light.hpp"
    #include "Cone.hpp"
    #include "../src/Parseur/FactoryParseur/FactoryParseur.hpp"
    #include "../src/Parseur/FactoryMaterial/FactoryMaterial.hpp"
    #include "../src/Parseur/Parseur/Parseur.hpp"

    class RayTracer {
        public:
            inline RayTracer(int w, int h, const Vector3D& lf, const Vector3D& la, double dtf, double ap, bool fastRender) : width(w), height(h), lookfrom(lf), lookat(la), dist_to_focus(dtf), aperture(ap), cam(lookfrom, lookat, Vector3D(0, 1, 0), 20, double(width) / double(height), aperture, dist_to_focus), _fastRender(fastRender) {}
            void run(std::string path);
            Vector3D color(const Ray& r, std::shared_ptr<Hitable> world, int depth);
            std::shared_ptr<Hitable> random_scene();
            void trace_Ray(int x, int y, std::ofstream &ofs);
            std::vector<std::shared_ptr<Hitable>> _primitives;
            std::vector<std::shared_ptr<Light>> _lights;

        private:
            int width;
            int height;
            std::shared_ptr<Hitable> world;
            Vector3D lookfrom;
            Vector3D lookat;
            double dist_to_focus;
            double aperture;
            Camera cam;
            sf::Image image;
            sf::Texture texture;
            size_t size;
            sf::Sprite sprite;
            bool _fastRender;
    };
#endif // RAYTRACER_HPP
