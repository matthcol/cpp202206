// Basics.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <string>
#include <cstdint>
//#include <compare> // C++20

// using namespace std;

void test_integers() {
    // 8 bits integers : 2^8 = 255
    // - signed : -128 to 127

    char x8 = 65;
    int8_t x8b = 65;
    unsigned char ux8;
    uint8_t ux8b;
    ux8 = 255;
    // 16 bits ?
    short xs = 32000; 
    // 32 bits ? => 2^32 ~= 4G
    int xi = 2000000000;
    // ?? 
    long xl = 8000000000L;
    // 64 bits ?? 2^64 ~= 16E 
    long long xxl = 8000000000LL;
    uint64_t xxlb = 8000000000LL;

    std::cout << "char (" << sizeof(char) << "): " << (int) x8 << std::endl;
    std::cout << "short (" << sizeof(short) << "): " << xs << std::endl;
    std::cout << "int (" << sizeof(int) << "): " << xi << std::endl;
    std::cout << "long (" << sizeof(long) << "): " << xl << std::endl;
    std::cout << "long long (" << sizeof(long long) << "): " << xxl << std::endl;


}

void test_floats() {
    // IEEE754 => physics
    // float = 32 bits, double = 64 bits (to be checked)
    float prix = 0.1f; // 0.00011001100110011001100..
    std::cout << std::setprecision(10)
        << prix
        << ", " << 2 * prix
        << ", " << 3 * prix
        << std::endl;
    double grand = 1E308;
    double inf = grand * 2;
    std::cout << inf << std::endl
            << (inf / inf) << std::endl;
}

void test_booleans() {
    bool isItOk = true;
    std::cout << isItOk << std::endl
        << std::boolalpha << isItOk << std::endl
        << std::noboolalpha << isItOk << std::endl;
}

void test_operators_numeric() {
    // + - * / %
    int p = 5;  // 00...0101  // operator assign
    int y = -p - -3;
    int w;
    w = 8; // operator copy
    // bitwise : << >> & | ^
    std::cout << (p << 2) << std::endl
        << (p ^ 6) << std::endl
        << (p & 6) << std::endl
        << (p | 6) << std::endl;
    // assign + compute (inplace)
    p++;
    ++p;
    p--;
    --p;
    p += 4;  // +=, -=, *=, /=
    p %= 5;

}

void test_operators_logic() {
    // until C++20 : ==, !=, <, <=, >, >=
    // since C++20 : <=> (opt: ==, !=)
    // combine :  !, && || (seq)
    int x = 5;
    int y = 7;
    std::cout << std::boolalpha
        << (x == y) << std::endl
        //<< std::is_lt(x <=> y) << std::endl
        ;
}

void test_string() {
    std::string ville1("Toulouse"); // constructor by "copy"
    std::string ville2 = "Balma"; // constructor by "copy"
    std::cout << ville1[0] << " : " << ville1 << std::endl;
    ville1[0] = 'Y';
    std::cout << ville1[0] << " : " << ville1 << std::endl;
    ville2 = "Pau"; // operator copy
}

void test_control_flow_if() {
    // if
    int x = 3;
    if (x < 10) {
        // block if 1st test is true
        x++;
    } else if (x == 10) {
        //
    } else {
        //
    }

    // switch .. case
    switch (x) {
    case 0:
    case 1:
        std::cout << "Cas 0 ou 1" << std::endl;
        break;
    case 2:
        std::cout << "Cas 2" << std::endl;
        break;
    case 3:
        std::cout << "Something to do before with 3" << std::endl;
    case 4:
        std::cout << "Cas 3 ou 4" << std::endl;
        break;
    default:
        std::cout << "Other case" << std::endl;
    }
}


void test_control_flow_loop() {
    std::vector<int> nombrePairs{ 2, 4, 6, 8 };
    // for i
    for (int i = 0; i < nombrePairs.size(); i++) {
        std::cout << " . " << nombrePairs[i] << std::endl;
    }
    // for each (C++11) on all iterable data
    //for (int nb: nombrePairs) { // copy
    //for (auto nb : nombrePairs) { // copy
    //for (const auto& nb : nombrePairs) { // reference en mode constant
    for (auto& nb : nombrePairs) { // reference
        std::cout << " * " << (nb+1) << std::endl;
        nb++;
    }

    for (const auto& nb : nombrePairs) {
        std::cout << " ~ " << (nb + 1) << std::endl;
    }

    // while (test) { }
    // do { } while(test);
}

void hello() {
    std::string ville;
    std::vector<int> v;
    std::cout << "Hello World!" << std::endl;
    // std::cout << v << std::endl; // possible with overload
}

int main() 
{
    //hello();
    // test_integers();
    // test_floats();
    //test_booleans();
    //test_operators_numeric();
    //test_string();
    //test_control_flow_if();
    test_control_flow_loop();
    return EXIT_SUCCESS;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
