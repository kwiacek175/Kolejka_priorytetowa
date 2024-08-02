# Implementacja Kolejki Priorytetowej

## Przegląd

Niniejsze repozytorium zawiera implementację kolejki priorytetowej w języku C++ z wykorzystaniem listy dwukierunkowej. Kolejka priorytetowa umożliwia dodawanie elementów z przypisanymi priorytetami, gdzie elementy są pobierane na podstawie najmniejszego klucza priorytetu.

## Funkcje

- **Dodawanie**: Wstawianie elementów z przypisanym kluczem priorytetu.
- **Pobieranie Minimum**: Dostęp do elementu o najmniejszym kluczu priorytetu.
- **Usuwanie Minimum**: Usuwanie i zwracanie elementu o najmniejszym kluczu priorytetu.
- **Rozmiar**: Sprawdzanie bieżącej liczby elementów w kolejce.
- **Sprawdzenie Pustki**: Określenie, czy kolejka jest pusta.
- **Wyświetlanie**: Wydrukowanie bieżącego stanu kolejki.

## Pliki

- `priorityQueue.h`: Zawiera implementację szablonu klasy `priorityQueue`.
- `main.cpp`: Demonstruje użycie klasy `priorityQueue` poprzez prosty przykład obsługi pakietów wiadomości.

## Klasa: `priorityQueue<T>`

### Metody Publiczne

- `void insert(const T& element, unsigned int key)`: Wstawia element do kolejki z danym kluczem priorytetu.
- `T min() const`: Zwraca element o najmniejszym kluczu priorytetu. Rzuca wyjątek, jeśli kolejka jest pusta.
- `T removeMin()`: Usuwa i zwraca element o najmniejszym kluczu priorytetu. Rzuca wyjątek, jeśli kolejka jest pusta.
- `unsigned int size() const`: Zwraca liczbę elementów w kolejce.
- `bool isEmpty() const`: Sprawdza, czy kolejka jest pusta.
- `void print() const`: Wydrukowuje bieżący stan kolejki na konsoli.

## Kompilacja i Uruchamianie

Aby skompilować kod, użyj kompilatora C++, za pomocą następującego polecenia:

```sh
g++ -o priorityQueueDemo main.cpp

