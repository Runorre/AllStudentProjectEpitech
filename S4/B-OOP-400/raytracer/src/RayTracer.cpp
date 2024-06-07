/*
** EPITECH PROJECT, 2024
** $
** File description:
** RayTracer
*/

#include "../include/RayTracer.hpp"

Vector3D RayTracer::color(const Ray& r, std::shared_ptr<Hitable> world, int depth) {
    hit_record rec;
    if (world->hit(r, 0.001, MAXFLOAT, rec)) {
        Vector3D color(0, 0, 0);
        for (const std::shared_ptr<Light>& lightPtr : _lights) {
            const Light& light = *lightPtr;
            Ray lightRay(rec.p, light.position - rec.p);
            hit_record lightRec;
            if (!world->hit(lightRay, 0.001, MAXFLOAT, lightRec)) {
                Vector3D attenuation;
                Ray scattered;
                if (rec.mat_ptr->scatter(lightRay, rec, attenuation, scattered)) {
                    color += attenuation * this->color(scattered, world, depth + 1) * light.color * light.intensity;
                }
            }
        }
        return color;
    } else {
        Vector3D unit_dir = unit_vector(r.direction());
        double t = 0.5*(unit_dir.y() + 1.0);
        return (1.0-t)*Vector3D(1.0,1.0,1.0)+t*Vector3D(0.5,0.7,1.0);
    }
}

std::shared_ptr<Hitable> RayTracer::random_scene() {
    int n = 500;
    std::vector<std::shared_ptr<Hitable>> _primitives;
    _primitives.push_back(std::make_shared<Sphere>(Vector3D(0, -1000, 0), 1000, std::make_shared<Lambertian>(Vector3D(0.5,0.5,0.5))));
    
    Vector3D lightPosition(0, 10, 0);
    Vector3D lightColor(1, 1, 1);
    double lightIntensity = 1.0;
    _lights.push_back(std::make_shared<Light>(lightPosition, lightColor, lightIntensity));

    for(int a = -2; a < 2; a++) {
        for(int b = -1; b < 1; b++) {
            double choose_mat = 0.5;
            Vector3D center(a+0.9*0.5,0.2,b+0.9*0.5);
            if ((center-Vector3D(4,0.2,0)).length() > 0.9 && _primitives.size() < n) {
                if (choose_mat < 0.8) {
                    // _primitives.push_back(std::make_shared<Cylinder>(center, 0.2, 5, std::make_shared<Dielectric>(1.5)));
                    // _primitives.push_back(std::make_shared<Cone>(center, 0.2, 5, std::make_shared<Dielectric>(1.5)));
                } else if(choose_mat < 0.95) {
                    // _primitives.push_back(std::make_shared<Cylinder>(center, 0.2, 5, std::make_shared<Metal>(Vector3D(0.5*(1+0.5),0.5*(1+0.5),0.5*(1+0.5)),0.5*0.5)));
                    // _primitives.push_back(std::make_shared<Cone>(center, 0.2, 5, std::make_shared<Metal>(Vector3D(0.5*(1+0.5),0.5*(1+0.5),0.5*(1+0.5)),0.5*0.5)));
                } else {
                    // _primitives.push_back(std::make_shared<Cylinder>(center, 0.2, 5, std::make_shared<Lambertian>(Vector3D(0.5*0.5,0.5*0.5,0.5*0.5))));
                    // _primitives.push_back(std::make_shared<Cone>(center, 0.2, 5, std::make_shared<Lambertian>(Vector3D(0.5*0.5,0.5*0.5,0.5*0.5))));
                }
            }
        }
    }
    // _primitives.push_back(std::make_shared<Cylinder>(Vector3D(0, 1, 0), 1.0, 5, std::make_shared<Dielectric>(1.5)));
    // _primitives.push_back(std::make_shared<Cylinder>(Vector3D(-4, 1, 0), 1.0, 5, std::make_shared<Lambertian>(Vector3D(0.4,0.2,0.1))));
    // _primitives.push_back(std::make_shared<Cylinder>(Vector3D(4, 1, 0), 1.0, 5, std::make_shared<Metal>(Vector3D(0.7,0.6,0.5),0.0)));
    _primitives.push_back(std::make_shared<Cone>(Vector3D(0, 1, 0), 1.0, 5, std::make_shared<Dielectric>(1.5)));
    // _primitives.push_back(std::make_shared<Cone>(Vector3D(-4, 1, 0), 1.0, 5, std::make_shared<Lambertian>(Vector3D(0.4,0.2,0.1))));
    // _primitives.push_back(std::make_shared<Cone>(Vector3D(4, 1, 0), 1.0, 5, std::make_shared<Metal>(Vector3D(0.7,0.6,0.5),0.0)));
    this->size = _primitives.size();
    return std::make_shared<HitableList>(_primitives, _primitives.size());
}

void RayTracer::trace_Ray(int x, int y, std::ofstream &ofs) {
    int ns = 0;
    if (_fastRender == true)
        ns = 100;
    else
        ns = 200;
    Vector3D col(0, 0, 0);
    for (int s = 0; s < ns; s++) {
        double u = double(x + 0.5) / double(width);
        double v = double(y + 0.5) / double(height);
        Ray r = cam.get_Ray(u, v);
        col += color(r, world, 0);
    }
    col /= double(ns);
    col = Vector3D(sqrt(col.r()), sqrt(col.g()), sqrt(col.b()));
    int ir = int(255.99 * col[0]);
    int ig = int(255.99 * col[1]);
    int ib = int(255.99 * col[2]);
    ofs << ir << " " << ig << " " << ib << "\n";
    this->image.setPixel(x, y, sf::Color(ir, ig, ib));
}

void RayTracer::run(std::string path) {
    std::ofstream ofs("output.ppm");
    ofs << "P3\n" << this->width << " " << this->height << "\n255\n";
    sf::RenderWindow window(sf::VideoMode(this->width, this->height), "Generating image...");
    this->image.create(this->width, this->height);
    
    if (path == "random.cfg") {
        world = random_scene();
    } else {
        Parseur parser(path);
        _primitives = parser.getPrimitives();
        _lights = parser.getLights();
        world = std::make_shared<HitableList>(_primitives, _primitives.size());
    }

    std::thread rayTracingThread([this, &ofs, &window]() {
        for (int y = this->height - 1; y >= 0; y--) {
            for (int x = 0; x < this->width; x++) {
                trace_Ray(x, y, ofs);
            }
            this->image.flipVertically();
            this->texture.loadFromImage(this->image);
            this->image.flipVertically();
            this->sprite.setTexture(this->texture);

            window.clear();
            window.draw(this->sprite);
            window.display();
        }
    });

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
    rayTracingThread.join();

    sf::RenderWindow finalWindow(sf::VideoMode(this->width, this->height), "Ray Tracing");
    this->image.flipVertically();
    this->texture.loadFromImage(this->image);
    this->sprite.setTexture(this->texture);
    while (finalWindow.isOpen()) {
        sf::Event event;
        while (finalWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                finalWindow.close();
        }
        finalWindow.clear();
        finalWindow.draw(this->sprite);
        finalWindow.display();
    }
}
