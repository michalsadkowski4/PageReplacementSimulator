# Symulator Algorytmów Zastępowania Stron

## Opis Projektu

Program symuluje trzy popularne algorytmy zastępowania stron:
- **FIFO** (First-In-First-Out),
- **OPT** (Optimal),
- **LRU** (Least Recently Used).

Użytkownik może wprowadzić parametry pamięci, sekwencję odwołań do adresów oraz wybrać algorytm do symulacji. Program wyświetla krok po kroku stan pamięci oraz liczbę błędów strony (PAGE FAULTS).

## Struktura Projektu

- **`main.cpp`**: Główny plik programu, zawierający funkcję `main`.
- **`MemoryManager.h` i `MemoryManager.cpp`**: Implementacja klasy zarządzającej pamięcią.
- **`Utils.h` i `Utils.cpp`**: Funkcje pomocnicze (walidacja danych, obliczenia, wyświetlanie informacji).

## Instrukcja Uruchomienia

1. Skompiluj projekt za pomocą kompilatora C++:

   g++ main.cpp MemoryManager.cpp Utils.cpp -o page_replacement_simulator

2. Uruchom program:
./page_replacement_simulator

3. Postępuj zgodnie z instrukcjami wyświetlanymi w terminalu.

4. Przykład użycia

Podaj ilość bajtów pamięci komputera (liczba dodatnia): 16
Podaj wielkość ramki w bajtach (liczba dodatnia): 4
Liczba ramek w pamięci: 4

Podaj liczbę odwołań do adresów: 8
Podaj kolejne odwołania do adresów (liczby całkowite dodatnie):
1 5 9 13 17 21 25 29

Informacje o odwołaniach:
Adres 1 -> Strona 0
Adres 5 -> Strona 1
Adres 9 -> Strona 2
Adres 13 -> Strona 3
Adres 17 -> Strona 4
Adres 21 -> Strona 5
Adres 25 -> Strona 6
Adres 29 -> Strona 7

Scalona sekwencja odwołań do stron:
0 1 2 3 4 5 6 7 

Wybierz algorytm zastępowania stron:
1. FIFO
2. OPT (algorytm optymalny)
3. LRU (Least Recently Used)

Autor
Michał Sadkowski
Email: michalsadkowski@hotmail.com
GitHub: https://github.com/michalsadkowski4