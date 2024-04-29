#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

int main(int argc, char *argv[]) {
    try {
        // Provera broja argumenata
        if (argc != 3) {
            throw std::invalid_argument("Usage: <input_file> <output_file>");
        }

        // Otvaranje ulazne datoteke
        std::ifstream input_file(argv[1]);
        if (!input_file.is_open()) {
            throw std::ios_base::failure("Error: Unable to open input file.");
        }

        // Otvaranje izlazne datoteke
        std::ofstream output_file(argv[2]);
        if (!output_file.is_open()) {
            throw std::ios_base::failure("Error: Unable to open output file.");
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
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
        return 1;
    } catch (const std::ios_base::failure& e) {
        std::cerr << "File error: " << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    }
}
