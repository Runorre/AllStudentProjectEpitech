/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Builder
*/

#ifndef BUILDER_HPP_
#define BUILDER_HPP_

#include "../../../include/RayTracer.hpp"
#include "../../../include/main.hpp"

class LightBuilderBase {
    public:
        virtual ~LightBuilderBase() {};
        virtual std::shared_ptr<Light> getLight() = 0;
        virtual void createNewLightProduct(libconfig::Setting &setting, std::string nameOfLight, std::map<std::string, std::vector<std::string>> parms) = 0;
};

template <typename LightType>
class LightBuilder : public LightBuilderBase {
    public:
        ~LightBuilder() {};
        std::shared_ptr<Light> getLight() override { return m_light; };
        void createNewLightProduct(libconfig::Setting &setting, std::string nameOfLight, std::map<std::string, std::vector<std::string>> parms) {
            if(parms.find(nameOfLight) == parms.end()) {
                throw libconfig::SettingNotFoundException("Light d'ont exist");
            }
            for(long unsigned int i = 0; i < parms[nameOfLight].size(); i++) {
                if (!setting.exists(parms[nameOfLight][i]))
                    throw libconfig::SettingNotFoundException("Missing setting in configuration file section Light. aa");
            }
            this->m_light = std::make_shared<LightType>(setting);
        };

    private:
        std::shared_ptr<LightType> m_light;
};

class LightDirector {
    public:
        std::shared_ptr<Light> openLight() { return m_lightBuilder->getLight(); }
        void makeLight(std::shared_ptr<LightBuilderBase> lb, libconfig::Setting &setting, std::string nameOfLight) { 
            m_lightBuilder = lb; 
            m_lightBuilder->createNewLightProduct(setting, nameOfLight, _ParamsMap);
        }
    private:
        std::shared_ptr<LightBuilderBase> m_lightBuilder;
        std::map<std::string, std::vector<std::string>> _ParamsMap = {
            {"point", {"position", "color", "intensity"}}
        };
};

#endif /* !BUILDER_HPP_ */
