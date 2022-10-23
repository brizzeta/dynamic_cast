#include "A.h"
#include "B.h"
#include "C.h"
#include "D.h"

A* Generator()
{
    A* obj = nullptr;
    int choice = rand() % 4;

    switch (choice)
    {
    case 0:
        obj = new A;
        break;
    case 1:
        obj = new B;
        break;
    case 2:
        obj = new C;
        break;
    case 3:
        obj = new D;
        break;
    }

    return obj;
}

int main()
{
    const int size = 10;
    A* objA[size] = {};
    B* objB = nullptr;
    C* objC = nullptr;
    D* objD = nullptr;
    int amount_A = 0U;
    int amount_B = 0U;
    int amount_C = 0U;
    int amount_D = 0U;

    for (int i = 0U; i < size; ++i)
    {
        objA[i] = Generator();
        objD = dynamic_cast<D*>(objA[i]);

        if (objD != nullptr) {
            ++amount_D;
        }
        else {
            objC = dynamic_cast<C*>(objA[i]);
            if (objC != nullptr) {
                ++amount_C;
            }
            else {
                objB = dynamic_cast<B*>(objA[i]);

                if (objB != nullptr) {
                    ++amount_B;
                }
                else {
                    ++amount_A;
                }
            }
        }
        objA[i]->Show();
    }
    cout << "A: " << amount_A << endl;
    cout << "B: " << amount_B << endl;
    cout << "C: " << amount_C << endl;
    cout << "D: " << amount_D << endl;
}