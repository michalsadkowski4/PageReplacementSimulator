/**
 * @file main.cpp
 * @brief Główny plik programu, zawierający funkcję main.
 *
 * Program symuluje algorytmy zastępowania stron (FIFO, OPT, LRU).
 * Użytkownik podaje parametry pamięci i sekwencję odwołań do adresów,
 * a następnie wybiera algorytm do symulacji.
 */

#include <iostream>
#include "include//MemoryManager.h"
#include "include//Utils.h"

 /**
  * @brief Główna funkcja programu.
  *
  * Funkcja obsługuje interakcję z użytkownikiem, wczytuje dane wejściowe,
  * przetwarza je i uruchamia wybrany algorytm zastępowania stron.
  *
  * @return int Kod zakończenia programu (0 = sukces).
  */
int main() {
    setlocale(LC_ALL, ""); // Wsparcie dla polskich znaków

    int memoryBytes, frameSize;
    std::cout << "Podaj ilość bajtów pamięci komputera (liczba dodatnia): ";
    memoryBytes = Utils::getPositiveInteger();

    std::cout << "Podaj wielkość ramki w bajtach (liczba dodatnia): ";
    frameSize = Utils::getPositiveInteger();

    int numFrames = memoryBytes / frameSize;
    if (numFrames == 0) {
        std::cerr << "Błąd: liczba ramek wynosi 0 (prawdopodobnie rozmiar pamięci jest mniejszy niż ramka)." << std::endl;
        return 1;
    }

    std::cout << "Liczba ramek w pamięci: " << numFrames << "\n\n";

    int n;
    std::cout << "Podaj liczbę odwołań do adresów: ";
    n = Utils::getPositiveInteger();

    std::vector<int> addresses(n);
    std::cout << "Podaj kolejne odwołania do adresów (liczby całkowite dodatnie):" << std::endl;
    for (int& address : addresses) {
        address = Utils::getPositiveInteger();
    }

    std::vector<int> pages = Utils::calculatePageNumbers(addresses, frameSize);
    Utils::displayAddressToPageMapping(addresses, pages);

    std::vector<int> mergedPages = Utils::mergeConsecutivePages(pages);
    std::cout << "\nScalona sekwencja odwołań do stron:" << std::endl;
    Utils::printVector(mergedPages);

    MemoryManager manager(numFrames);

    std::cout << "\nWybierz algorytm zastępowania stron:" << std::endl;
    std::cout << "1. FIFO" << std::endl;
    std::cout << "2. OPT (algorytm optymalny)" << std::endl;
    std::cout << "3. LRU (Least Recently Used)" << std::endl;

    int choice = Utils::getChoice(1, 3);
    switch (choice) {
    case 1:
        manager.simulateFIFO(mergedPages);
        break;
    case 2:
        manager.simulateOPT(mergedPages);
        break;
    case 3:
        manager.simulateLRU(mergedPages);
        break;
    }

    return 0;
}