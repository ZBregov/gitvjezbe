#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[]) {
    // Provera broja argumenata
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <output_file>\n";
        return 1;
    }

    // Otvaranje ulazne datoteke
    std::ifstream input_file(argv[1]);
    if (!input_file) {
        std::cerr << "Error: Unable to open input file.\n";
        return 1;
    }

    // Otvaranje izlazne datoteke
    std::ofstream output_file(argv[2]);
    if (!output_file) {
        std::cerr << "Error: Unable to open output file.\n";
        return 1;
    }

    // Učitavanje redaka iz ulazne datoteke i ispisivanje duplikata u izlaznu datoteku
    std::string line;
    while (std::getline(input_file, line)) {
        // Ispisivanje prvog puta
        output_file << line << '\n';
        // Ispisivanje drugog puta
        output_file << line << '\n';
    }

    // Zatvaranje datoteka
    input_file.close();
    output_file.close();

    std::cout << "Duplication complete.\n";
    return 0;
}
