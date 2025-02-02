/**
 * @file Utils.h
 * @brief Nag��wek funkcji pomocniczych.
 *
 * Zawiera funkcje wspomagaj�ce walidacj� danych, obliczenia
 * oraz wy�wietlanie informacji.
 */

#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <iostream>

namespace Utils {
    /**
     * @brief Pobiera dodatni� liczb� ca�kowit� od u�ytkownika.
     * @return int Dodatnia liczba ca�kowita.
     */
    int getPositiveInteger();

    /**
     * @brief Pobiera wyb�r u�ytkownika z podanego zakresu.
     * @param min Minimalna warto�� dozwolona.
     * @param max Maksymalna warto�� dozwolona.
     * @return int Wybrana warto�� z zakresu [min, max].
     */
    int getChoice(int min, int max);

    /**
     * @brief Oblicza numery stron na podstawie adres�w.
     * @param addresses Sekwencja adres�w.
     * @param frameSize Rozmiar ramki w bajtach.
     * @return std::vector<int> Numery stron odpowiadaj�ce adresom.
     */
    std::vector<int> calculatePageNumbers(const std::vector<int>& addresses, int frameSize);

    /**
     * @brief Wy�wietla mapowanie adres�w na numery stron.
     * @param addresses Sekwencja adres�w.
     * @param pages Sekwencja numer�w stron.
     */
    void displayAddressToPageMapping(const std::vector<int>& addresses, const std::vector<int>& pages);

    /**
     * @brief Scalanie powtarzaj�cych si� stron w sekwencji.
     * @param pages Sekwencja numer�w stron.
     * @return std::vector<int> Scalona sekwencja stron.
     */
    std::vector<int> mergeConsecutivePages(const std::vector<int>& pages);

    /**
     * @brief Wy�wietla wektor liczb ca�kowitych.
     * @param vec Wektor do wy�wietlenia.
     */
    void printVector(const std::vector<int>& vec);

    /**
     * @brief Wy�wietla aktualny stan pami�ci w formie tabeli.
     * @param frames Wektor reprezentuj�cy stan ramek.
     */
    void printMemoryState(const std::vector<int>& frames);
}

#endif // UTILS_H