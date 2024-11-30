#include <iostream>
#include <string>
#include <utility> // for std::move

using namespace std;

int main()
{
    int a = 10;

    cout << std::move(a) << endl;

    return 0;
}
