/*
** EPITECH PROJECT, 2024
** lastTry
** File description:
** main
*/
#include "include/RayTracer.hpp"
#include "include/main.hpp"
#include "include/ErrorHandling.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./raytracer [config_file]" << std::endl;
        return 84;
    }
    try {
        ErrorHandling error;
        if (error.checkExtension(argv[1]) == 84)
            throw std::runtime_error("Error: Invalid file extension");
        int width = 800;
        int height = 400;
        Vector3D lookfrom(13, 2, 3);
        Vector3D lookat(0, 0, 0);
        double dist_to_focus = 10.0;
        double aperture = 0.1;
        RayTracer raytracer(width, height, lookfrom, lookat, dist_to_focus, aperture, true);
        raytracer.run(argv[1]);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
}
