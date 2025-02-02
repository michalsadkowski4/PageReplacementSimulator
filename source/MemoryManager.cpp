#include "..//include/Utils.h"
#include "..//include/MemoryManager.h"
#include <iomanip>

MemoryManager::MemoryManager(int numFrames) : numFrames(numFrames), frames(numFrames, -1) {}

bool MemoryManager::isPageInMemory(int page) const {
    return std::find(frames.begin(), frames.end(), page) != frames.end();
}

void MemoryManager::printMemoryState() const {
    Utils::printMemoryState(frames);
}

void MemoryManager::simulateFIFO(const std::vector<int>& pages) {
    std::queue<int> fifoQueue;
    int faults = 0;

    std::cout << "\nSymulacja algorytmu FIFO:\n";
    for (size_t i = 0; i < pages.size(); ++i) {
        int page = pages[i];
        std::cout << "Krok " << i + 1 << " - Odwo³anie do strony " << page << ": ";

        if (isPageInMemory(page)) {
            std::cout << "HIT" << std::endl;
        }
        else {
            faults++;
            std::cout << "PAGE FAULT" << std::endl;

            bool placed = false;
            for (int j = 0; j < numFrames; ++j) {
                if (frames[j] == -1) {
                    frames[j] = page;
                    fifoQueue.push(j);
                    placed = true;
                    break;
                }
            }

            if (!placed) {
                int index = fifoQueue.front();
                fifoQueue.pop();
                frames[index] = page;
                fifoQueue.push(index);
            }
        }
        printMemoryState();
    }
    std::cout << "Liczba b³êdów strony (PAGE FAULTS): " << faults << std::endl;
}

void MemoryManager::simulateOPT(const std::vector<int>& pages) {
    int faults = 0;
    std::cout << "\nSymulacja algorytmu OPT (optymalnego):\n";
    for (size_t i = 0; i < pages.size(); ++i) {
        int page = pages[i];
        std::cout << "Krok " << i + 1 << " - Odwo³anie do strony " << page << ": ";
        if (isPageInMemory(page)) {
            std::cout << "HIT" << std::endl;
        }
        else {
            faults++;
            std::cout << "PAGE FAULT" << std::endl;
            bool placed = false;
            for (int j = 0; j < numFrames; ++j) {
                if (frames[j] == -1) {
                    frames[j] = page;
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                // ZnajdŸ stronê, która najpóŸniej bêdzie u¿ywana w przysz³oœci
                int victimIndex = -1;
                size_t farthest = pages.size();
                for (int j = 0; j < numFrames; ++j) {
                    size_t nextUse = pages.size();
                    for (size_t k = i + 1; k < pages.size(); ++k) {
                        if (pages[k] == frames[j]) {
                            nextUse = k; 
                            break;
                        }
                    }
                    // Jeœli strona nie bêdzie ju¿ u¿ywana, wybierz j¹
                    if (nextUse == pages.size()) {
                        victimIndex = j;
                        break;
                    }
                    // Wybierz stronê, która bêdzie u¿ywana najpóŸniej
                    if (nextUse > farthest) {
                        farthest = nextUse;
                        victimIndex = j;
                    }
                }
                frames[victimIndex] = page;
            }
        }
        printMemoryState();
    }
    std::cout << "Liczba b³êdów strony (PAGE FAULTS): " << faults << std::endl;
}

void MemoryManager::simulateLRU(const std::vector<int>& pages) {
    int faults = 0;
    std::vector<int> lastUsed(numFrames, -1); // Ostatni czas u¿ycia ka¿dej ramki
    std::cout << "\nSymulacja algorytmu LRU (Least Recently Used):\n";
    for (size_t i = 0; i < pages.size(); ++i) {
        int page = pages[i];
        std::cout << "Krok " << i + 1 << " - Odwo³anie do strony " << page << ": ";
        bool hit = false;
        int hitIndex = -1;
        for (int j = 0; j < numFrames; ++j) {
            if (frames[j] == page) {
                hit = true;
                hitIndex = j;
                break;
            }
        }
        if (hit) {
            std::cout << "HIT" << std::endl;
            lastUsed[hitIndex] = static_cast<int>(i);
        }
        else {
            faults++;
            std::cout << "PAGE FAULT" << std::endl;
            bool placed = false;
            for (int j = 0; j < numFrames; ++j) {
                if (frames[j] == -1) {
                    frames[j] = page;
                    lastUsed[j] = static_cast<int>(i);
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                // ZnajdŸ stronê, która by³a najdawniej u¿ywana
                int lruIndex = 0;
                int minLastUsed = lastUsed[0];
                for (int j = 1; j < numFrames; ++j) {
                    if (lastUsed[j] < minLastUsed) {
                        minLastUsed = lastUsed[j];
                        lruIndex = j;
                    }
                }
                frames[lruIndex] = page;
                lastUsed[lruIndex] = static_cast<int>(i); 
            }
        }
        printMemoryState();
    }
    std::cout << "Liczba b³êdów strony (PAGE FAULTS): " << faults << std::endl;
}