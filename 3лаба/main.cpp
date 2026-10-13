#include <iostream>
#include <Windows.h>
#include "Player.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Ukrainian");

    Player player;

    cout << "===================================================\n";
    cout << "   ËÀÁÎÐÀÒÎÐÍÀ ÐÎÁÎÒÀ ¹2 (Âàð³àíò 4)\n";
    cout << "   ÊËÀÑ ÏÐÎÃÐÀÂÀ× / Á²ÁË²ÎÒÅÊÀ ÌÓËÜÒÈÌÅÄ²À\n";
    cout << "===================================================\n\n";

    cout << "Îáåð³òü ñïîñ³á çàïîâíåííÿ äàíèõ:\n";
    cout << "1 - Ââåñòè äàí³ âðó÷íó ç êîíñîë³\n";
    cout << "2 - Çàâàíòàæèòè òåñòîâ³ (äåìîíñòðàö³éí³) äàí³\n";
    cout << "Âàø âèá³ð: ";

    int choice;
    cin >> choice;
    cin.ignore(10000, '\n');

    if (choice == 1) {
        player.FillLibrary();
    }
    else {
        player.LoadDemoData();
    }

    player.ShowAll();

    cout << "\n===================================================\n";
    cout << "           ÂÈÊÎÍÀÍÍß ÏÎØÓÊÎÂÈÕ ÇÀÏÈÒ²Â            \n";
    cout << "===================================================\n";

    player.ShowByActor();
    player.ShowByTitle();
    player.ShowByTheme();

    cout << "\nÐîáîòó ïðîãðàìè çàâåðøåíî. Íàòèñí³òü Enter äëÿ âèõîäó...";
    cin.get();
    return 0;
}