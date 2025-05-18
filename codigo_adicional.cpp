#include <iostream>
#include <vector>
using namespace std;

struct Nodo {
    int p1, d1, p2, d2;
};

int idx = 0;

bool Equilibrio(const vector<Nodo> &movil, int &pesoTotal) {
    const Nodo &n = movil[idx++];
    int pesoIzq = n.p1;
    int pesoDer = n.p2;
    bool izqE = true;
    bool derE = true;

    if (n.p1 == 0)
        izqE = Equilibrio(movil, pesoIzq);
    if (n.p2 == 0)
        derE = Equilibrio(movil, pesoDer);

    pesoTotal = pesoIzq + pesoDer;
    return izqE && derE && (pesoIzq * n.d1 == pesoDer * n.d2);
}

int main() {
    vector<Nodo> movil;
    while (true) {
        int p1, d1, p2, d2;
        cin >> p1 >> d1 >> p2 >> d2;
        if (p1 == 0 && d1 == 0 && p2 == 0 && d2 == 0)
            break;
        movil.push_back({p1, d1, p2, d2});
    }

    int peso;
    idx = 0;
    if (Equilibrio(movil, peso))
        cout << "SI";
    else
        cout << "NO";

    return 0;
}
