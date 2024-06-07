/*
** EPITECH PROJECT, 2024
** B-PDG-300-MAR-3-1-PDGRUSH3-angelo.anselmet
** File description:
** CurseDisplay
*/

// CurseDisplay.cpp
#include "../../MyGKrellM.hpp"

Curse::Curse()
{
    this->ramModule = new RamInfo;
    this->clockModule = new Clockwork;
    this->cpuModule = new CpuModule;
    this->systemModule = new SystemInfo;
    this->batteryModule = new BatteryModule;
    GpuInfo gpu;
    this->_sysData = this->systemModule->update();
    this->_cpuData = this->cpuModule->update();
    this->_ramData = this->ramModule->update();
    this->_clockData = this->clockModule->update();
    this->batteryModule->update();
    this->gpuData = gpu.getGpuInfo();
    initscr();
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    raw();
    keypad(stdscr, TRUE);
    noecho();
}

Curse::~Curse()
{
    endwin();
    delete ramModule;
    delete clockModule;
    delete cpuModule;
    delete systemModule;
    delete batteryModule;
}

std::string Curse::calculatePercentage(double current, double max) {
    double progressRatio = current / max;

    int percentage = static_cast<int>(progressRatio * 100);

    std::string percentageString = std::to_string(percentage);
    std::string finalShow;
    // for (int i = 0; i < (30 - percentageString.size()); i++)
    //     finalShow += " ";
    finalShow += percentageString;
    finalShow += "%";
    return finalShow;
}

std::string Curse::progressBar(double current, double max) {
    const int progressBarLength = 56;

    double progressRatio = current / max;

    int progressChars = static_cast<int>(progressRatio * progressBarLength);

    std::string progressBar = "[";
    progressBar.reserve(progressBarLength);

    for (int i = 0; i < progressBarLength; ++i) {
        if (i < progressChars)
            progressBar += '|';
        else
            progressBar += '.';
    }
    progressBar += "]";

    return progressBar;
}

void Curse::show()
{
    // this->_sysData = this->systemModule->update();
    this->_cpuData = this->cpuModule->update();
    this->_ramData = this->ramModule->update();
    this->_clockData = this->clockModule->update();
    this->batteryModule->update();
    clear();

    int spacing = 0;
    int starty = 0;
    int startx = 0;
    int squareHeight;  // Déclarer la variable ici

    // Affichage pour le module RAM
    
    std::string clockTxt = "Time: " + _clockData[0]["hour"] + ":" + _clockData[0]["min"] + ":" + _clockData[0]["sec"]
    + " | Date: " + _clockData[0]["day"] + "/" + _clockData[0]["mon"] + "/" + _clockData[0]["year"];    afficherCarre(starty, startx, clockTxt, squareHeight, " Clock ");
    
    starty += squareHeight + spacing;
    
    std::string sysTxt = "Hostname: ";
    sysTxt += _sysData[0]["hostname"];
    // sysTxt += "\n";
    sysTxt += "Username: ";
    sysTxt += _sysData[0]["username"];
    sysTxt += "\n";
    sysTxt += "Kernel: ";
    sysTxt += _sysData[0]["kernel"];
    sysTxt += "\n";
    sysTxt += "OS: ";
    sysTxt += _sysData[0]["os"];
    afficherCarre(starty, startx, sysTxt, squareHeight, " System Info ");

    starty += squareHeight + spacing;
    std::string batteryTxt = "";
    batteryTxt += this->progressBar(this->batteryModule->_BatteryPercentage, 100.0);
    batteryTxt += "\n";
    batteryTxt += this->calculatePercentage(this->batteryModule->_BatteryPercentage, 100.0);
    batteryTxt += "\t\t\t\t\t     ";
    batteryTxt += "in charge: ";
    batteryTxt += (this->batteryModule->_inCharge ? "Yes" : "No" );
    afficherCarre(starty, startx, batteryTxt, squareHeight, " Battery Info ");
    
    starty += squareHeight + spacing;
    std::string ramTxt = "";
    ramTxt += this->progressBar(std::stod(_ramData[0]["MemUse"]), std::stod(_ramData[0]["MemMax"]));
    ramTxt += "\n";
    ramTxt += "RAM Usage: ";
    ramTxt += _ramData[0]["MemUse"];
    ramTxt += " / ";
    ramTxt += _ramData[0]["MemMax"];
    afficherCarre(starty, startx, ramTxt, squareHeight, " RAM Info ");

    starty += squareHeight + spacing;
    std::string gpuTxt = "GPU Card: ";
    std::string data = this->gpuData;
    for (int i = 0; i < data.length(); i += 48) {
        std::string line = data.substr(i, 48);
        if (line.length() > 0)
            gpuTxt += line + "\n          ";
    }

    // if (data.length() % 49 == 0) {
    //     gpuTxt = gpuTxt.substr(0, gpuTxt.length() - 2);
    // }
    afficherCarre(starty, startx, gpuTxt, squareHeight, " GPU Info ");

    // Affichage pour le module CPU
    starty += squareHeight + spacing;
    
    std::string cpuTxt = "";
    for(int i = 0; i < _cpuData.size(); i++) {
        if (i == 0) {
            cpuTxt += "Total: ";
            cpuTxt += this->calculatePercentage(this->cpuModule->_cpuUsage, 100.0);
            cpuTxt += "\n";
            cpuTxt += this->progressBar(this->cpuModule->_cpuUsage, 100.0);
            
            cpuTxt += "\nPhysical: ";
            cpuTxt += std::to_string(_cpuData.size() / 2);
            cpuTxt += ", Virtual: ";
            cpuTxt += std::to_string(_cpuData.size());
            cpuTxt += "\n";
            cpuTxt += "Processes:\n";
            cpuTxt += "Total: ";
            cpuTxt += std::to_string(this->cpuModule->_nprocess);
            cpuTxt += " | Running: ";
            cpuTxt += std::to_string(this->cpuModule->_nprocessRunning);
            cpuTxt += " | Block: ";
            cpuTxt += std::to_string(this->cpuModule->_nprocessBlocked);
            cpuTxt += "\n";
        }
            cpuTxt += "Core ";
            cpuTxt += std::to_string(i + 1);
            cpuTxt += ": ";
            cpuTxt += _cpuData[i]["usage"];
            // cpuTxt += this->calculatePercentage(std::stod(_cpuData[i]["usage"]), 100.0);
            // cpuTxt += this->calculatePercentage(std::stod(_cpuData[i]["usage"]), 100.0);
            cpuTxt += "%\n";
        
    }
    afficherCarre(starty, startx, cpuTxt, squareHeight, " CPU Info ");

    // Affichage pour le module système
    

    // Affichage pour le module horloge
    

    refresh();

}

void Curse::changeModule(IModule* newModule)
{
}

void Curse::changeAffichage(IModule* newModule)
{
    int height = 5;
    int width = 10;
    int starty = (LINES - height) / 2;
    int startx = (COLS - width) / 2;
    int dummyHeight;  // Ajoutez une variable pour la hauteur (peut être ignorée)
    afficherCarre(starty, startx, "SomeContent", dummyHeight, "");
}

void Curse::splitString(const std::string& input, char delimiter, std::vector<std::string>& output)
{
    std::istringstream stream(input);
    std::string token;
    output.clear();

    while (std::getline(stream, token, delimiter)) {
        output.push_back(token);
    }
}

void Curse::afficherCarre(int starty, int startx, const std::string& content, int& squareHeight, const std::string title)
{
    std::vector<std::string> lines;

    if (content.find('\n') != std::string::npos) {
        splitString(content, '\n', lines);
    } else {
        lines.push_back(content);
    }

    int width = 60;
    squareHeight = lines.size() + 2;  // Calcul de la hauteur

    mvaddch(starty, startx, ACS_ULCORNER);  // Coin supérieur gauche
    mvaddch(starty, (startx + width - 1), ACS_URCORNER);  // Coin supérieur droit
    mvaddch(starty + squareHeight - 1, startx, ACS_LLCORNER);  // Coin inférieur gauche
    mvaddch(starty + squareHeight - 1, startx + width - 1, ACS_LRCORNER);  // Coin inférieur droit

    for (int i = 1; i < squareHeight - 1; ++i) {
        mvaddch(starty + i, startx, ACS_VLINE);  // Bordure verticale
        mvaddch(starty + i, startx + width - 1, ACS_VLINE);  // Bordure verticale
    }

    for (int i = 1; i < width - 1; ++i) {
        if (i > 2 && i < (3 + title.size())) {
            if (i == 3) {
                attron(COLOR_PAIR(1));
                mvprintw(starty, startx + i, "%s", title.c_str());
                attroff(COLOR_PAIR(1));
            }
                
        } else {
            mvaddch(starty, startx + i, ACS_HLINE);  // Bordure horizontale
        }

        // if (title == " System Info " && i > (3 + title.size())) {
        //     mvaddch(starty, startx + i + 1, ACS_HLINE); 
        // }
        
        mvaddch(starty + squareHeight - 1, startx + i, ACS_HLINE);  // Bordure horizontale
    }

    for (int i = 0; i < lines.size(); ++i) {
        mvprintw(starty + i + 1, startx + 1, "%s" ,lines[i].c_str());
    }
}

// void Curse::afficherCarre(int starty, int startx, const std::string& content, int& squareHeight)
// {
//     std::vector<std::string> lines;

//     if (content.find('\n') != std::string::npos) {
//         splitString(content, '\n', lines);
//     } else {
//         lines.push_back(content);
//     }

//     int width = content.length() + 2;
//     squareHeight = lines.size() + 2;  // Calcul de la hauteur

//     mvaddch(starty, startx, ACS_ULCORNER);  // Coin supérieur gauche
//     mvaddch(starty, startx + width - 1, ACS_URCORNER);  // Coin supérieur droit
//     mvaddch(starty + squareHeight - 1, startx, ACS_LLCORNER);  // Coin inférieur gauche
//     mvaddch(starty + squareHeight - 1, startx + width - 1, ACS_LRCORNER);  // Coin inférieur droit

//     for (int i = 1; i < squareHeight - 1; ++i) {
//         mvaddch(starty + i, startx, ACS_VLINE);  // Bordure verticale
//         mvaddch(starty + i, startx + width - 1, ACS_VLINE);  // Bordure verticale
//     }

//     for (int i = 1; i < width - 1; ++i) {
//         mvaddch(starty, startx + i, ACS_HLINE);  // Bordure horizontale
//         mvaddch(starty + squareHeight - 1, startx + i, ACS_HLINE);  // Bordure horizontale
//     }

//     // Affiche "Memoire RAM :" en rouge
//     attron(COLOR_PAIR(COLOR_RED));
//     mvprintw(starty + 1, startx + 1, "Memoire RAM :");
//     attroff(COLOR_PAIR(COLOR_RED));

//     for (int i = 0; i < lines.size(); ++i) {
//         mvprintw(starty + i + 1, startx + 16, lines[i].c_str());  // Décalage pour éviter la répétition
//     }
// }
