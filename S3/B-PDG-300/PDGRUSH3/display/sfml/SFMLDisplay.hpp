/*
** EPITECH PROJECT, 2024
** B-PDG-300-MAR-3-1-PDGRUSH3-angelo.anselmet
** File description:
** SFMLDisplay
*/

#ifndef SFMLDISPLAY_HPP_
#define SFMLDISPLAY_HPP_

#include "../../MyGKrellM.hpp"

class BoxSysInfo {
    public:
        BoxSysInfo();
        ~BoxSysInfo();

        void update();
        void draw(sf::RenderWindow &window);

        sf::Font font;

        sf::Texture T_username;
        sf::RectangleShape R_username;
        sf::Text Q_username;
        sf::Text username;

        sf::Texture T_hostname;
        sf::RectangleShape R_hostname;
        sf::Text Q_hostname;
        sf::Text hostname;

        sf::Texture T_kernel;
        sf::RectangleShape R_kernel;
        sf::Text Q_kernel;
        sf::Text kernel;

        sf::Texture T_OS;
        sf::RectangleShape R_OS;
        sf::Text Q_OS;
        sf::Text OS;

        sf::Text boxTitle;
        sf::RectangleShape box;

        SystemInfo mod;
};

class BoxClockWork {
    public:
        BoxClockWork();
        ~BoxClockWork() {};

        void draw(sf::RenderWindow &window);
        void update();

        sf::Font font;

        sf::Texture T_date;
        sf::RectangleShape R_date;
        sf::Text Q_date;
        sf::Text date;

        sf::Texture T_hour;
        sf::RectangleShape R_hour;
        sf::Text Q_hour;
        sf::Text hour;

        sf::RectangleShape box;
        sf::Text boxTitle;

        Clockwork mod;
};

class BoxRam {
    public:
        BoxRam();
        ~BoxRam() {};

        void draw(sf::RenderWindow &win);
        void update();

        sf::Font font;
        sf::Text boxTitle;
        sf::RectangleShape box;

        sf::Texture texture;
        sf::RectangleShape icon;
        sf::Text maxMem;
        sf::Text curMem;

        int x = 330;
        int y = 543;
        int w = 300;
        int h = 10;
        float cur = 0;
        float max = 0;
        sf::RectangleShape barM;
        sf::RectangleShape barC;

        RamInfo mod;
};

class BoxBattery {
    public:
        BoxBattery();
        ~BoxBattery() {};

        void draw(sf::RenderWindow &win);
        void update();

        sf::Font font;
        sf::Text boxTitle;
        sf::RectangleShape box;

        sf::Texture texture1;
        sf::Texture texture2;
        sf::RectangleShape icon;
        sf::Text percent;

        int x = 330;
        int y = 693;
        int w = 300;
        int h = 10;
        float batteryPercentage;
        float maxBattery = 100.0;
        sf::RectangleShape barM;
        sf::RectangleShape barC;

        BatteryModule mod;
};

class BoxGPU {
    public:
        BoxGPU();
        ~BoxGPU() {};

        void draw(sf::RenderWindow &win);
        void update();

        sf::Font font;
        sf::Text boxTitle;
        sf::RectangleShape box;

        sf::Texture texture;
        sf::RectangleShape icon;

        sf::Text cardName;

        GpuInfo mod;
};

class BoxCPU {
    public:
        BoxCPU();
        ~BoxCPU() {};

        void draw(sf::RenderWindow &win);
        void update();

        sf::Font font;
        sf::Text boxTitle;
        sf::RectangleShape box;

        sf::Texture texture;
        sf::RectangleShape icon;

        sf::Text cardName;

        sf::Text freqT;
        sf::Text freq;

        sf::Text procTT;
        sf::Text procT;

        sf::Text procRT;
        sf::Text procR;

        sf::Text procBT;
        sf::Text procB;

        sf::Text usageTT;
        sf::Text usageT;

        int x = 65;
        int y = 1085;
        int w = 50;
        int h = 150;
        double usage;
        double maxUsage = 100;
        sf::RectangleShape barC;
        sf::RectangleShape barM;

        std::vector<sf::Text> cores;

        int virtualCores;
        int physicalCores;

        sf::Text virtTT;
        sf::Text virtT;

        sf::Text physTT;
        sf::Text physT;

        CpuModule mod;
};

class SFMLDisplay : public IDisplay {
    public:
        SFMLDisplay();
        ~SFMLDisplay();

        void show();
        void changeModule(IModule* mod) {};
        void changeAffichage(IModule* mod) {};
        void handleEvent();
        void draw();
        void update();

    protected:
    private:
        sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(700, 1300), "MyGKrellM");
        sf::Event event;
        sf::Color colorBg = sf::Color(96, 96, 96);
        sf::Clock clock;
        BoxSysInfo sysinfo;
        BoxClockWork clockwork;
        BoxRam ram;
        BoxBattery battery;
        BoxGPU gpu;
        BoxCPU cpu;
};

#endif /* !SFMLDISPLAY_HPP_ */
