/**
 * @file Utils.h
 * @brief Nag³ówek funkcji pomocniczych.
 *
 * Zawiera funkcje wspomagaj¹ce walidacjê danych, obliczenia
 * oraz wyœwietlanie informacji.
 */

#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <iostream>

namespace Utils {
    /**
     * @brief Pobiera dodatni¹ liczbê ca³kowit¹ od u¿ytkownika.
     * @return int Dodatnia liczba ca³kowita.
     */
    int getPositiveInteger();

    /**
     * @brief Pobiera wybór u¿ytkownika z podanego zakresu.
     * @param min Minimalna wartoœæ dozwolona.
     * @param max Maksymalna wartoœæ dozwolona.
     * @return int Wybrana wartoœæ z zakresu [min, max].
     */
    int getChoice(int min, int max);

    /**
     * @brief Oblicza numery stron na podstawie adresów.
     * @param addresses Sekwencja adresów.
     * @param frameSize Rozmiar ramki w bajtach.
     * @return std::vector<int> Numery stron odpowiadaj¹ce adresom.
     */
    std::vector<int> calculatePageNumbers(const std::vector<int>& addresses, int frameSize);

    /**
     * @brief Wyœwietla mapowanie adresów na numery stron.
     * @param addresses Sekwencja adresów.
     * @param pages Sekwencja numerów stron.
     */
    void displayAddressToPageMapping(const std::vector<int>& addresses, const std::vector<int>& pages);

    /**
     * @brief Scalanie powtarzaj¹cych siê stron w sekwencji.
     * @param pages Sekwencja numerów stron.
     * @return std::vector<int> Scalona sekwencja stron.
     */
    std::vector<int> mergeConsecutivePages(const std::vector<int>& pages);

    /**
     * @brief Wyœwietla wektor liczb ca³kowitych.
     * @param vec Wektor do wyœwietlenia.
     */
    void printVector(const std::vector<int>& vec);

    /**
     * @brief Wyœwietla aktualny stan pamiêci w formie tabeli.
     * @param frames Wektor reprezentuj¹cy stan ramek.
     */
    void printMemoryState(const std::vector<int>& frames);
}

#endif // UTILS_H