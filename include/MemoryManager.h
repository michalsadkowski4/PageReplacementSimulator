/**
 * @file MemoryManager.h
 * @brief Nag��wek klasy zarz�dzaj�cej pami�ci�.
 *
 * Klasa MemoryManager implementuje algorytmy zast�powania stron:
 * FIFO, OPT i LRU.
 */

#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include <vector>
#include <queue>

 /**
  * @class MemoryManager
  * @brief Klasa zarz�dzaj�ca pami�ci�.
  *
  * Klasa obs�uguje symulacj� algorytm�w zast�powania stron:
  * - FIFO (First-In-First-Out),
  * - OPT (Optimal),
  * - LRU (Least Recently Used).
  */
class MemoryManager {
public:
    /**
     * @brief Konstruktor klasy MemoryManager.
     * @param numFrames Liczba dost�pnych ramek w pami�ci.
     */
    explicit MemoryManager(int numFrames);

    /**
     * @brief Symuluje algorytm FIFO.
     * @param pages Sekwencja odwo�a� do stron.
     */
    void simulateFIFO(const std::vector<int>& pages);

    /**
     * @brief Symuluje algorytm OPT.
     * @param pages Sekwencja odwo�a� do stron.
     */
    void simulateOPT(const std::vector<int>& pages);

    /**
     * @brief Symuluje algorytm LRU.
     * @param pages Sekwencja odwo�a� do stron.
     */
    void simulateLRU(const std::vector<int>& pages);

private:
    int numFrames; ///< Liczba dost�pnych ramek w pami�ci.
    std::vector<int> frames; ///< Wektor reprezentuj�cy stan ramek.

    /**
     * @brief Sprawdza, czy strona znajduje si� w pami�ci.
     * @param page Numer strony do sprawdzenia.
     * @return true Je�li strona jest w pami�ci, false w przeciwnym razie.
     */
    bool isPageInMemory(int page) const;

    /**
     * @brief Wy�wietla aktualny stan pami�ci.
     */
    void printMemoryState() const;
};

#endif // MEMORY_MANAGER_H