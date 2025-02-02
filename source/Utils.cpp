#include "Utils.h"
#include <iomanip>

int Utils::getPositiveInteger() {
    int value;
    while (!(std::cin >> value) || value <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "B³¹d! Podaj liczbê dodatni¹: ";
    }
    return value;
}

int Utils::getChoice(int min, int max) {
    int choice;
    while (!(std::cin >> choice) || choice < min || choice > max) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Niepoprawny wybór. Podaj liczbê z zakresu [" << min << ", " << max << "]: ";
    }
    return choice;
}

std::vector<int> Utils::calculatePageNumbers(const std::vector<int>& addresses, int frameSize) {
    std::vector<int> pages;
    for (int address : addresses) {
        pages.push_back((address - 1) / frameSize);
    }
    return pages;
}

void Utils::displayAddressToPageMapping(const std::vector<int>& addresses, const std::vector<int>& pages) {
    std::cout << "\nInformacje o odwo³aniach:" << std::endl;
    for (size_t i = 0; i < addresses.size(); ++i) {
        std::cout << "Adres " << addresses[i] << " -> Strona " << pages[i] << std::endl;
    }
}

std::vector<int> Utils::mergeConsecutivePages(const std::vector<int>& pages) {
    std::vector<int> merged;
    if (!pages.empty()) {
        merged.push_back(pages[0]);
        for (size_t i = 1; i < pages.size(); ++i) {
            if (pages[i] != pages[i - 1]) {
                merged.push_back(pages[i]);
            }
        }
    }
    return merged;
}

void Utils::printVector(const std::vector<int>& vec) {
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

void Utils::printMemoryState(const std::vector<int>& frames) {
    std::cout << "+---------+---------+" << std::endl;
    std::cout << "| Ramka   | Strona  |" << std::endl;
    std::cout << "+---------+---------+" << std::endl;
    for (size_t i = 0; i < frames.size(); ++i) {
        std::cout << "| " << std::setw(7) << i << " | ";
        if (frames[i] == -1) {
            std::cout << std::setw(7) << " " << " |" << std::endl;
        }
        else {
            std::cout << std::setw(7) << frames[i] << " |" << std::endl;
        }
    }
    std::cout << "+---------+---------+" << std::endl << std::endl;
}