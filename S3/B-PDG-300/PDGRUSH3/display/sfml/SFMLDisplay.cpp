/*
** EPITECH PROJECT, 2024
** B-PDG-300-MAR-3-1-PDGRUSH3-angelo.anselmet
** File description:
** SFMLDisplay
*/

#include "../../MyGKrellM.hpp"
#include <SFML/Graphics.hpp>

SFMLDisplay::SFMLDisplay()
{
}

SFMLDisplay::~SFMLDisplay()
{
}

void SFMLDisplay::show()
{
    while (this->window.isOpen()) {
        while (this->window.pollEvent(this->event)) {
            this->handleEvent();
        }
        // if (this->clock.getElapsedTime() >= sf::seconds(1))
        //     this->update();
        // this->window.clear(this->colorBg);
        // this->draw();
        // this->window.display();
    }
}

void SFMLDisplay::handleEvent()
{
    switch (this->event.type) {
        case sf::Event::Closed:
            this->window.close();
            break;
        default:
            break;
    }
}

void SFMLDisplay::update()
{
    this->sysinfo.update();
    this->clockwork.update();
    this->ram.update();
    this->battery.update();
    this->gpu.update();
    this->cpu.update();
}

void SFMLDisplay::draw()
{
    this->sysinfo.draw(this->window);
    this->clockwork.draw(this->window);
    this->ram.draw(this->window);
    this->battery.draw(this->window);
    this->gpu.draw(this->window);
    this->cpu.draw(this->window);
}

static void setupText(sf::Text &text, sf::Font &font, float x, float y, std::string str, float s, bool bold)
{
    text.setFont(font);
    text.setCharacterSize(s);
    text.setString(str);
    text.setPosition(x, y);
    text.setColor(sf::Color::Black);
    if (bold)
        text.setStyle(sf::Text::Bold);
}

static void setupBox(sf::RectangleShape &rect, float x, float y)
{
    rect.setFillColor(sf::Color(192, 192, 192));
    rect.setPosition(x, y);
    rect.setOutlineThickness(4);
    rect.setOutlineColor(sf::Color::Black);
}

static void setupIcon(sf::RectangleShape &icon, const sf::Texture &texture, float x, float y)
{
    icon.setPosition(x, y);
    icon.setTexture(&texture);
}

BoxSysInfo::BoxSysInfo()
{
    this->font.loadFromFile("./display/sfml/assets/Louis George Cafe.ttf");

    setupText(this->boxTitle, this->font, 370, 35, "System Informations", 30, true);
    this->box = sf::RectangleShape(sf::Vector2f(650, 275));
    setupBox(this->box, 25, 25);

    this->T_username.loadFromFile("./display/sfml/assets/username.png");
    this->R_username = sf::RectangleShape(sf::Vector2f(24, 24));
    setupIcon(this->R_username, this->T_username, 50, 100);
    setupText(this->Q_username, this->font, 100, 100, "Username:", 20, true);
    setupText(this->username, this->font, 220, 100, "", 20, false);

    this->T_hostname.loadFromFile("./display/sfml/assets/hostname.png");
    this->R_hostname = sf::RectangleShape(sf::Vector2f(24, 24));
    setupIcon(this->R_hostname, this->T_hostname, 50, 150);
    setupText(this->Q_hostname, this->font, 100, 150, "Hostname:", 20, true);
    setupText(this->hostname, this->font, 220, 150, "", 20, false);

    this->T_kernel.loadFromFile("./display/sfml/assets/kernel.png");
    this->R_kernel = sf::RectangleShape(sf::Vector2f(24, 24));
    setupIcon(this->R_kernel, this->T_kernel, 50, 250);
    setupText(this->Q_kernel, this->font, 100, 250, "Kernel:", 20, true);
    setupText(this->kernel, this->font, 180, 250, "", 20, false);

    this->T_OS.loadFromFile("./display/sfml/assets/os.png");
    this->R_OS = sf::RectangleShape(sf::Vector2f(24, 24));
    setupIcon(this->R_OS, this->T_OS, 50, 200);
    setupText(this->Q_OS, this->font, 100, 200, "OS:", 20, true);
    setupText(this->OS, this->font, 145, 200, "", 20, false);

    this->update();
}

BoxSysInfo::~BoxSysInfo()
{
}

void BoxSysInfo::update() {
    this->mod.update();
    std::vector<std::map<std::string, std::string>> sysinfo = this->mod.getSysInfo();
    this->username.setString(sysinfo[0]["username"]);
    this->hostname.setString(sysinfo[0]["hostname"]);
    this->kernel.setString(sysinfo[0]["kernel"]);
    this->OS.setString(sysinfo[0]["os"]);
}

void BoxSysInfo::draw(sf::RenderWindow &window)
{
    window.draw(this->box);
    window.draw(this->boxTitle);

    window.draw(this->R_username);
    window.draw(this->Q_username);
    window.draw(this->username);

    window.draw(this->R_hostname);
    window.draw(this->Q_hostname);
    window.draw(this->hostname);

    window.draw(this->R_kernel);
    window.draw(this->Q_kernel);
    window.draw(this->kernel);

    window.draw(this->R_OS);
    window.draw(this->Q_OS);
    window.draw(this->OS);
}

BoxClockWork::BoxClockWork()
{
    this->font.loadFromFile("./display/sfml/assets/Louis George Cafe.ttf");
    setupText(this->boxTitle, this->font, 515, 335, "Clockwork", 30, true);
    this->box = sf::RectangleShape(sf::Vector2f(650, 125));
    setupBox(this->box, 25, 325);

    this->T_date.loadFromFile("./display/sfml/assets/date.png");
    this->R_date = sf::RectangleShape(sf::Vector2f(24, 24));
    setupIcon(this->R_date, this->T_date, 50, 385);
    setupText(this->Q_date, this->font, 100, 385, "Date:", 20, true);
    setupText(this->date, this->font, 175, 385, "", 20, false);

    this->T_hour.loadFromFile("./display/sfml/assets/hour.png");
    this->R_hour = sf::RectangleShape(sf::Vector2f(24, 24));
    setupIcon(this->R_hour, this->T_hour, 375, 385);
    setupText(this->Q_hour, this->font, 425, 385, "Hour:", 20, true);
    setupText(this->hour, this->font, 500, 385, "", 20, false);

    this->update();
}

void BoxClockWork::update() {
    std::vector<std::map<std::string, std::string>> clock = this->mod.update();
    std::string date = clock[0]["day"] + '/' + clock[0]["mon"] + '/' + clock[0]["year"];
    std::string hour = clock[0]["hour"] + ':' + clock[0]["min"] + ":" + clock[0]["sec"];

    this->date.setString(date);
    this->hour.setString(hour);
}

void BoxClockWork::draw(sf::RenderWindow &win) {
    win.draw(this->box);
    win.draw(this->boxTitle);

    win.draw(this->R_hour);
    win.draw(this->Q_hour);
    win.draw(this->hour);

    win.draw(this->R_date);
    win.draw(this->Q_date);
    win.draw(this->date);
}

BoxRam::BoxRam()
{
    this->font.loadFromFile("./display/sfml/assets/Louis George Cafe.ttf");
    setupText(this->boxTitle, this->font, 500, 485, "RAM Usage", 30, true);
    this->box = sf::RectangleShape(sf::Vector2f(650, 125));
    setupBox(this->box, 25, 475);

    this->texture.loadFromFile("./display/sfml/assets/ram.png");
    this->icon = sf::RectangleShape(sf::Vector2f(24, 24));
    setupIcon(this->icon, this->texture, 50, 535);

    setupText(this->curMem, this->font, 100, 535, "", 20, true);
    setupText(this->maxMem, this->font, 185, 535, "", 20, false);

    this->update();

    this->barM = sf::RectangleShape(sf::Vector2f(this->w, this->h));
    this->barM.setPosition(this->x, this->y);
    this->barM.setFillColor(sf::Color::Red);

    this->barC = sf::RectangleShape(sf::Vector2f((this->cur * this->w) / this->max, this->h));
    this->barC.setPosition(this->x, this->y);
    this->barC.setFillColor(sf::Color::Green);
}

void BoxRam::draw(sf::RenderWindow &win)
{
    win.draw(this->box);
    win.draw(this->boxTitle);
    win.draw(this->icon);
    win.draw(this->curMem);
    win.draw(this->maxMem);
    win.draw(this->barM);
    win.draw(this->barC);
}

void BoxRam::update()
{
    std::vector<std::map<std::string, std::string>> mem = this->mod.update();
    std::string cur = mem[0]["MemUse"];
    std::string max = mem[0]["MemMax"];

    this->curMem.setString(cur);
    this->maxMem.setString("/" + max + " kB");
    this->cur = atof(cur.c_str());
    this->max = atof(max.c_str());

    this->barC.setSize(sf::Vector2f((this->cur * this->w) / this->max, this->h));
}

BoxBattery::BoxBattery()
{
    this->font.loadFromFile("./display/sfml/assets/Louis George Cafe.ttf");
    setupText(this->boxTitle, this->font, 560, 635, "Battery", 30, true);
    this->box = sf::RectangleShape(sf::Vector2f(650, 125));
    setupBox(this->box, 25, 625);

    this->texture1.loadFromFile("./display/sfml/assets/battery1.png");
    this->texture2.loadFromFile("./display/sfml/assets/battery2.png");
    this->icon = sf::RectangleShape(sf::Vector2f(24, 24));
    setupIcon(this->icon, this->texture1, 50, 685);
    setupText(this->percent, this->font, 100, 685, "", 20, true);

    this->update();

    this->barM = sf::RectangleShape(sf::Vector2f(this->w, this->h));
    this->barM.setPosition(this->x, this->y);
    this->barM.setFillColor(sf::Color::Red);

    this->barC = sf::RectangleShape(sf::Vector2f((this->batteryPercentage * this->w) / this->maxBattery, this->h));
    this->barC.setPosition(this->x, this->y);
    this->barC.setFillColor(sf::Color::Green);
}

void BoxBattery::draw(sf::RenderWindow &win)
{
    win.draw(this->box);
    win.draw(this->boxTitle);
    win.draw(this->icon);
    win.draw(this->percent);
    win.draw(this->barM);
    win.draw(this->barC);
}

void BoxBattery::update()
{
    this->mod.update();
    this->batteryPercentage = this->mod._BatteryPercentage;
    if (this->mod._inCharge) {
        this->icon.setTexture(&this->texture2);
    } else {
        this->icon.setTexture(&this->texture1);
    }
    this->percent.setString(std::to_string(this->batteryPercentage) + '%');
    this->barC.setSize(sf::Vector2f((this->batteryPercentage * this->w) / this->maxBattery, this->h));
}

BoxGPU::BoxGPU ()
{
    this->font.loadFromFile("./display/sfml/assets/Louis George Cafe.ttf");
    setupText(this->boxTitle, this->font, 415, 790, "GPU Informations", 30, true);
    this->box = sf::RectangleShape(sf::Vector2f(650, 125));
    setupBox(this->box, 25, 775);

    this->texture.loadFromFile("./display/sfml/assets/gpu.png");
    this->icon = sf::RectangleShape(sf::Vector2f(24, 24));
    setupIcon(this->icon, this->texture, 50, 840);

    setupText(this->cardName, this->font, 100, 840, "", 20, false);

    this->update();
}

void BoxGPU::update()
{
    this->cardName.setString(this->mod.getGpuInfo());
}

void BoxGPU::draw(sf::RenderWindow &win)
{
    win.draw(this->box);
    win.draw(this->boxTitle);
    win.draw(this->icon);
    win.draw(this->cardName);
}

BoxCPU::BoxCPU ()
{
    this->font.loadFromFile("./display/sfml/assets/Louis George Cafe.ttf");
    setupText(this->boxTitle, this->font, 415, 935, "CPU Informations", 30, true);
    this->box = sf::RectangleShape(sf::Vector2f(650, 350));
    setupBox(this->box, 25, 925);

    this->texture.loadFromFile("./display/sfml/assets/cpu.png");
    this->icon = sf::RectangleShape(sf::Vector2f(24, 24));
    setupIcon(this->icon, this->texture, 50, 985);

    setupText(this->cardName, this->font, 100, 985, "", 20, false);

    setupText(this->freqT, this->font, 50, 1020, "Frequency:", 18, true);
    setupText(this->freq, this->font, 150, 1020, "", 18, false);

    setupText(this->procTT, this->font, 50, 1050, "Total processes:", 18, true);
    setupText(this->procT, this->font, 200, 1050, "", 18, false);

    setupText(this->procRT, this->font, 265, 1050, "Running processes:", 18, true);
    setupText(this->procR, this->font, 440, 1050, "", 18, false);

    setupText(this->procBT, this->font, 465, 1050, "Blocked processes:", 18, true);
    setupText(this->procB, this->font, 640, 1050, "", 18, false);

    setupText(this->usageTT, this->font, 50, 1200, "CPU Usage:", 18, true);
    setupText(this->usageT, this->font, 50, 1245, "", 18, false);

    setupText(this->virtTT, this->font, 300, 1245, "Virtual cores:", 18, true);
    setupText(this->virtT, this->font, 425, 1245, "", 18, false);

    setupText(this->physTT, this->font, 500, 1245, "Physical cores:", 18, true);
    setupText(this->physT, this->font, 635, 1245, "", 18, false);

    size_t i = 0, size = this->mod._coresVector.size();
    int initX = 175, x = initX, initY = 1080, y = initY, offsetX = 150, offsetY = 35, cpt = 1;
    std::string corename;
    while (i < size) {
        this->cores.push_back(sf::Text());
        corename = "Core" + std::to_string(i) + ": ";
        setupText(this->cores[i], this->font, x, y, corename.c_str(), 18, false);
        x += offsetX;
        if (cpt % 3 == 0) {
            x = initX;
            y += offsetY;
        }
        i ++;
        cpt ++;
    }

    std::string tmpstr = std::to_string(size / 2);
    this->physT.setString(tmpstr.c_str());
    tmpstr = std::to_string(size);
    this->virtT.setString(tmpstr.c_str());

    this->update();

    this->barM = sf::RectangleShape(sf::Vector2f(this->w, this->h));
    this->barM.setPosition(this->x, this->y);
    this->barM.setFillColor(sf::Color::Red);

    float tmp = (this->usage * this->h) / this->maxUsage;
    this->barC.setSize(sf::Vector2f(this->w, tmp));
    this->barC.setPosition(this->x,  this->y + (((this->maxUsage - this->usage) * 0.01) * this->h));
    this->barC.setFillColor(sf::Color::Green);
}

void BoxCPU::update()
{
    std::vector<std::map<std::string, std::string>> cpu = this->mod.update();
    size_t i = 0, size = cpu.size();

    if (size == 0) {
        std::cout << "non" << std::endl;
        return;
    }
    std::string corename;
    size_t size2 = this->cores.size();
    while (i < size && i < size2) {
        corename = "Core" + std::to_string(i) + ": " + cpu[i]["usage"] + '%';
        this->cores[i].setString(corename.c_str());
        i ++;
    }

    this->cardName.setString(cpu[0]["model name"]);
    this->freq.setString(std::to_string(this->mod.getFreq()) + " MHz");
    this->procT.setString(std::to_string(this->mod._nprocess));
    this->procR.setString(std::to_string(this->mod._nprocessRunning));
    this->procB.setString(std::to_string(this->mod._nprocessBlocked));

    this->usage = this->mod._cpuUsage;
    float tmp = (this->usage * this->h) / this->maxUsage;
    this->usageT.setString(std::to_string(this->usage) + '%');
    this->barC.setSize(sf::Vector2f(this->w, tmp));
    this->barC.setPosition(this->x, this->y + (((this->maxUsage - this->usage) * 0.01) * this->h));
}

void BoxCPU::draw(sf::RenderWindow &win)
{
    win.draw(this->box);
    win.draw(this->boxTitle);
    win.draw(this->icon);
    win.draw(this->cardName);
    win.draw(this->freqT);
    win.draw(this->freq);
    win.draw(this->procTT);
    win.draw(this->procT);
    win.draw(this->procRT);
    win.draw(this->procR);
    win.draw(this->procBT);
    win.draw(this->procB);
    win.draw(this->barM);
    win.draw(this->barC);
    //win.draw(this->usageTT);
    win.draw(this->usageT);
    win.draw(this->virtT);
    win.draw(this->virtTT);
    win.draw(this->physT);
    win.draw(this->physTT);

    for (const sf::Text txt : this->cores) {
        win.draw(txt);
    }
}
