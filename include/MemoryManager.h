/**
 * @file MemoryManager.h
 * @brief Nag³ówek klasy zarz¹dzaj¹cej pamiêci¹.
 *
 * Klasa MemoryManager implementuje algorytmy zastêpowania stron:
 * FIFO, OPT i LRU.
 */

#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include <vector>
#include <queue>

 /**
  * @class MemoryManager
  * @brief Klasa zarz¹dzaj¹ca pamiêci¹.
  *
  * Klasa obs³uguje symulacjê algorytmów zastêpowania stron:
  * - FIFO (First-In-First-Out),
  * - OPT (Optimal),
  * - LRU (Least Recently Used).
  */
class MemoryManager {
public:
    /**
     * @brief Konstruktor klasy MemoryManager.
     * @param numFrames Liczba dostêpnych ramek w pamiêci.
     */
    explicit MemoryManager(int numFrames);

    /**
     * @brief Symuluje algorytm FIFO.
     * @param pages Sekwencja odwo³añ do stron.
     */
    void simulateFIFO(const std::vector<int>& pages);

    /**
     * @brief Symuluje algorytm OPT.
     * @param pages Sekwencja odwo³añ do stron.
     */
    void simulateOPT(const std::vector<int>& pages);

    /**
     * @brief Symuluje algorytm LRU.
     * @param pages Sekwencja odwo³añ do stron.
     */
    void simulateLRU(const std::vector<int>& pages);

private:
    int numFrames; ///< Liczba dostêpnych ramek w pamiêci.
    std::vector<int> frames; ///< Wektor reprezentuj¹cy stan ramek.

    /**
     * @brief Sprawdza, czy strona znajduje siê w pamiêci.
     * @param page Numer strony do sprawdzenia.
     * @return true Jeœli strona jest w pamiêci, false w przeciwnym razie.
     */
    bool isPageInMemory(int page) const;

    /**
     * @brief Wyœwietla aktualny stan pamiêci.
     */
    void printMemoryState() const;
};

#endif // MEMORY_MANAGER_H