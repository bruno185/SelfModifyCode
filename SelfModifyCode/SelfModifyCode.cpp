// SelfModifyCode.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
using namespace std;

extern "C" int DoSelf(int i);
int i;

int main()
{
    std::cout << "Hello World!\n";
    for (i=0;i<10;i++){

    cout << DoSelf(100) << endl;
    }

}

