#include <iostream>
#include <fstream>
#include <string>

int main()
{
    // Otevření vstupního souboru
    std::ifstream input("dopisKorfu.txt");
    if (!input.is_open())
    {
        std::cerr << "Chyba při otevírání vstupního souboru.\n";
        return 1;
    }

    // Získání názvu ostrova od uživatele
    std::cout << "Zadej nazev ostrova: ";
    std::string nazevOstrova;
    std::getline(std::cin, nazevOstrova); // Použití std::getline pro správné načtení vstupu
    if (nazevOstrova.empty())
        nazevOstrova = "Rhodos";

    // Otevření výstupního souboru
    std::ofstream output("dopis" + nazevOstrova + ".txt");
    if (!output.is_open())
    {
        std::cerr << "Chyba při otevírání výstupního souboru.\n";
        return 1;
    }

    // Čtení vstupního souboru a nahrazování slova „Korfu“
    std::string radek;
    while (std::getline(input, radek))
    {
        size_t pozice = 0;
        while ((pozice = radek.find("Korfu", pozice)) != std::string::npos)
        {
            radek.replace(pozice, 5, nazevOstrova); // Nahrazení slova „Korfu“
        }
        output << radek << '\n'; // Zápis upraveného řádku do výstupního souboru
    }

    // Uzavření souborů
    input.close();
    output.close();

    std::cout << "Soubor byl uspesne vytvoren jako: dopis" + nazevOstrova + ".txt\n";
    return 0;
}