#include <iostream>
#include <sstream>
#include "priorityQueue.h"

int main()
{
    priorityQueue<std::string> receivedPackets;
    std::string word, message, receivedMessage;

    std::cout << "Prosze wpisac wiadomosc Jana do Anny:\n> ";

    std::getline(std::cin, message);
    std::istringstream iss(message);

    std::cout << "\nWiadomosc dzielona jest na kolejne pakiety (slowa), ktorych priorytet w kolejce jest taki sam jak kolejnosc w wiadomosci wyslanej przez Jana."
                 " Zakladamy, ze kolejne pakiety przychodza do Anny w losowej kolejnosci i dzieki wlasnosciom kolejki komputer Anny zlozy je w oryginalna wiadomosc.\n\n";

    std::cout << "Ponizej przedstawiono jak zmienia sie kolejka priorytetowa po dodaniu kolejnych pakietow (gdzie: [klucz] slowo).\n\n";

    for (unsigned int i = 1; iss >> word; ++i)
    {
        receivedPackets.insert(word, i);
        receivedPackets.print();
    }

    for (unsigned int i = 1; receivedPackets.size(); ++i)
        receivedMessage = receivedMessage + receivedPackets.removeMin() + " ";

    std::cout << "\nOdebrana wiadomosc: " << receivedMessage << '\n';
}
