#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> m;

    // It prints according key size
    m["tv"] = 100;
    m["laptop"] = 100;
    m["headphone"] = 50;
    m["tablet"] = 120;
    m["watch"] = 50;

    m.insert({"camera", 25});
    m.emplace("dress", 200);

    for (auto p : m)
    {
        cout << p.first << " " << p.second << endl;
    }
    cout << endl;

    cout << "count: " << m.count("laptop") << endl;
    if (m.find("camera") != m.end())
    {
        cout << "found\n";
    }
    else
    {
        cout << "not found\n";
    }

    return 0;
}