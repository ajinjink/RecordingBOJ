#include <iostream>
#include <map>
using namespace std;
map<int, int>sold;

int main()
{
    int soldnum;
    cin >> soldnum;
    
    int ticketnum;
    for (int i = 0; i < soldnum; i++) {
        cin >> ticketnum;
        sold.insert(make_pair(ticketnum, ticketnum));
    }

    for (int i = 1; i < 1000000; i++) {
        if (sold.find(i) != sold.end()) {
            continue;
        }
        else{
            cout << i << endl;
            break;
        }
    }

}