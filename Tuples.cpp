//Given a stream of numbers and a difference "d" find and delete triplets (a,b,c) such that |a-b| <= d && |c-b| <= d && |c-a| <=d




#include <iostream>
#include <set>
#include <cmath>
using namespace std;

bool isValidTriplet(int a, int b, int c, int d) {
    return abs(a - b) <= d && abs(b - c) <= d && abs(c - a) <= d;
}

void processStream(int d) {
    multiset<int> nums;
    int num;

    while (cin >> num) {
        nums.insert(num);

        if (nums.size() >= 3) {
            auto it1 = nums.begin();
            auto it2 = next(it1);
            auto it3 = next(it2);

            while (it3 != nums.end()) {
                int a = *it1, b = *it2, c = *it3;
                if (isValidTriplet(a, b, c, d)) {
                    nums.erase(it1);
                    nums.erase(it2);
                    nums.erase(it3);
                    break; // Restart checking after removing triplet
                }
                ++it1;
                ++it2;
                ++it3;
            }
        }

        cout << "Current numbers: ";
        for (int n : nums) cout << n << " ";
        cout << endl;
    }
}

int main() {
    int d;
    cout << "Enter the threshold value d: ";
    cin >> d;
    cout << "Start entering numbers (Ctrl+D to end):\n";
    processStream(d);
    return 0;
}
