/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Parseur
*/

#include "Parseur.hpp"

Parseur::Parseur(std::string path) {
    libconfig::Config cfg;
    try {
        cfg.readFile(path.c_str());
    } catch(const libconfig::FileIOException &fioex) {
        std::cerr << "I/O error while reading file." << std::endl;
        throw std::runtime_error("I/O error while reading file.");
    } catch(const libconfig::ParseException &pex) {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine() << " - " << pex.getError() << std::endl;
        throw std::runtime_error("Parse error");
    } catch (const libconfig::SettingTypeException &aled) {
        std::cerr << "Setting type exception: " << aled.what() << std::endl;
        throw std::runtime_error("Setting type exception");
    }

    try {
        this->parseCamera(cfg.lookup("camera"));
        this->parsePrimitives(cfg.lookup("primitives"));
        this->parseLights(cfg.lookup("lights"));
    } catch (const libconfig::SettingNotFoundException &nfex) {
        std::cerr << nfex.getPath() << std::endl;
        throw std::runtime_error("Setting not found");
    } catch (const libconfig::SettingTypeException &stex) {
        std::cerr << "The following value is not in the correct format : " << stex.getPath() << std::endl;
        throw std::runtime_error("Setting type exception");
    }
}

void Parseur::parsePrimitives(libconfig::Setting &primitive) {
    for (int i = 0; i < primitive.getLength(); ++i) {
        std::string name = primitive[i].getName();
        if (name != "spheres" && name != "planes")
            throw libconfig::SettingNotFoundException("Unknown primitive type.");
        for (int e = 0; e < primitive[i].getLength(); ++e) {
            this->_primitives.push_back(Factory::factoryCreator(name, primitive[i][e]));
        }
    }
}

void Parseur::parseLights(libconfig::Setting &lights) {
    for (int i = 0; i < lights.getLength(); ++i) {
        std::string name = lights[i].getName();
        if (name != "point" && name != "directional")
            throw libconfig::SettingNotFoundException("Unknown light type.");
        LightDirector ld;
        if (name == "point") {
            ld.makeLight(std::make_shared<LightBuilder<Light>>(), lights[i], name);
            this->_lights.push_back(ld.openLight());
        } else if (name == "directional") {
            std::cout << "Feature comming soon" << std::endl;
        }
        
    }

}

void Parseur::parseCamera(libconfig::Setting &camera) {
    if (!camera.exists("lookfrom") || !camera.exists("lookat") || !camera.exists("vup") || !camera.exists("vfov") || !camera.exists("aperture") || !camera.exists("focusdist") || !camera.exists("aspect"))
        throw libconfig::SettingNotFoundException("Missing setting in configuration file section Camera.");
    if (camera["vup"].getLength() != 3 || !camera["vup"].exists("x") || !camera["vup"].exists("y") || !camera["vup"].exists("z"))
        throw libconfig::SettingNotFoundException("Missing setting in configuration file section Camera.");
    if (camera["lookfrom"].getLength() != 3 || camera["lookat"].getLength() != 3)
        throw libconfig::SettingNotFoundException("Missing setting in configuration file section Camera");
    if (!camera["lookfrom"].exists("x") || !camera["lookfrom"].exists("y") || !camera["lookfrom"].exists("z") || !camera["lookat"].exists("x") || !camera["lookat"].exists("y") || !camera["lookat"].exists("z"))
        throw libconfig::SettingNotFoundException("Missing setting in configuration file section Camera.");
    
    double lookfromX = camera["lookfrom"]["x"];
    double lookfromY = camera["lookfrom"]["y"];
    double lookfromZ = camera["lookfrom"]["z"];
    double lookatX = camera["lookat"]["x"];
    double lookatY = camera["lookat"]["y"];
    double lookatZ = camera["lookat"]["z"];
    double vupX = camera["vup"]["x"];
    double vupY = camera["vup"]["y"];
    double vupZ = camera["vup"]["z"];
    Vector3D lookfrom = Vector3D(lookfromX, lookfromY, lookfromZ);
    Vector3D lookat = Vector3D(lookatX, lookatY, lookatZ);
    Vector3D vup = Vector3D(vupX, vupY, vupZ);
    double aperture = camera["aperture"];
    double vfov = camera["vfov"];
    double aspect = camera["aspect"];
    double focusdist = camera["focusdist"];

    this->_cam = std::make_shared<Camera>(lookfrom, lookat, vup, vfov, aspect, aperture, focusdist);
}

Parseur::~Parseur() {}
