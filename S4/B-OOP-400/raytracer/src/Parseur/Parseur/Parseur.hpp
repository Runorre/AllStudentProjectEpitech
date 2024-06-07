/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Parseur
*/

#ifndef PARSEUR_HPP_
#define PARSEUR_HPP_
#include "../../../include/RayTracer.hpp"
#include "../../../include/main.hpp"
#include "../BuilderParseur/BuilderParseur.hpp"

class Parseur {
    public:
        ~Parseur();
        Parseur(std::string path);
        
        std::shared_ptr<Camera> getCam() const { return _cam; }
        std::vector<std::shared_ptr<Hitable>> getPrimitives() const { return _primitives; }
        std::vector<std::shared_ptr<Light>> getLights() const { return _lights; }
        // double getAmbiantLight() const { return ambiantLight; };
        // double getDiffuseLight() const { return diffuseLight; };

    protected:
    private:
        void parseCamera(libconfig::Setting &camera);
        void parsePrimitives(libconfig::Setting &primitives);
        void parseLights(libconfig::Setting &lights);
        std::shared_ptr<Camera> _cam;
        std::vector<std::shared_ptr<Hitable>> _primitives;
        std::vector<std::shared_ptr<Light>> _lights;
        // double ambiantLight;
        // double diffuseLight;
};

#endif /* !PARSEUR_HPP_ */
