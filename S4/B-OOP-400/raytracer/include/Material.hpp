/*
** EPITECH PROJECT, 2024
** lastTry
** File description:
** Material
*/

#pragma once

class Hitable;

class Material {
   public:
      virtual bool scatter(const Ray& r_in, const hit_record& rec, Vector3D& attenuation, Ray& scattered) const = 0;

   protected:
      Vector3D randomInUnitSphere() const {
         Vector3D p;
         do {
               p = 2.9 * Vector3D(drand48(), drand48(), drand48()) - Vector3D(1, 1, 1);
         } while (p.squaredLength() >= 1.0);
         return p;
      }
};

class Lambertian : public Material {
   public:
      Lambertian(const Vector3D& a) : albedo(a) {}
      virtual bool scatter(const Ray& r_in, const hit_record& rec, Vector3D& attenuation, Ray& scattered) const {
         Vector3D target = rec.p + rec.normal + randomInUnitSphere();
         scattered = Ray(rec.p, target-rec.p);
         attenuation = albedo;
         return true;
      }
      Vector3D albedo;
};

class Metal : public Material {
   public:
      Metal(const Vector3D& a, double f) : albedo(a) {if(f<1) fuzz=f; else fuzz=1;}
      virtual bool scatter(const Ray& r_in, const hit_record& rec, Vector3D& attenuation, Ray& scattered) const {
         Vector3D reflected = reflect(unit_vector(r_in.direction()),rec.normal);
         scattered = Ray(rec.p, reflected + fuzz*randomInUnitSphere());
         attenuation = albedo;
         return (dot(scattered.direction(),rec.normal)>0);
      }
   Vector3D albedo;
   int fuzz;
};

class Dielectric : public Material {
   public:
      Dielectric(double ri) : ref_idx(ri) {}
      virtual bool scatter(const Ray& r_in, const hit_record& rec, Vector3D& attenuation, Ray& scattered) const {
         Vector3D outward_normal;
         Vector3D reflected = reflect(r_in.direction(), rec.normal);
         double ni_over_nt;
         attenuation = Vector3D(1.0, 1.0, 1.0);
         Vector3D refracted;
         double reflect_prob;
         double cosine;
         if (dot(r_in.direction(), rec.normal) > 0) {
            outward_normal = -rec.normal;
            ni_over_nt = ref_idx;
            cosine = dot(r_in.direction(), rec.normal) / r_in.direction().length();
            cosine = sqrt(1 - ref_idx*ref_idx*(1-cosine*cosine));
         }
         else {
            outward_normal = rec.normal;
            ni_over_nt = 1.0 / ref_idx;
            cosine = -dot(r_in.direction(), rec.normal) / r_in.direction().length();
         }
         if (refract(r_in.direction(), outward_normal, ni_over_nt, refracted))
            reflect_prob = schlick(cosine, ref_idx);
         else
            reflect_prob = 1.0;
         if (drand48() < reflect_prob)
            scattered = Ray(rec.p, reflected);
         else
            scattered = Ray(rec.p, refracted);
         return true;
      }

      double schlick(double cosine, double ref_idx) const {
         double r0 = (1 - ref_idx) / (1 + ref_idx);
         r0 = r0 * r0;
         return r0 + (1 - r0) * pow((1 - cosine), 5);
      }
   double ref_idx;
};