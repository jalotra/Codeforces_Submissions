#include <iostream>
using namespace std;

int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;

void read() {	
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;
    x1 *= 2, y1 *= 2;
    x2 *= 2, y2 *= 2;
    x3 *= 2, y3 *= 2;
    x4 *= 2, y4 *= 2;
    x5 *= 2, y5 *= 2;
    x6 *= 2, y6 *= 2;
}

bool ok(int x, int y, int x1, int y1, int x2, int y2) {
	return x < x1 || x2 < x || y < y1 || y2 < y;
}

void solve() {
    read();
	for (int x = x1; x <= x2; x++) {
		if (ok(x, y1, x3, y3, x4, y4) && ok(x, y1, x5, y5, x6, y6)) {
			cout << "YES" << endl;
			return;
		}
		if (ok(x, y2, x3, y3, x4, y4) && ok(x, y2, x5, y5, x6, y6)) {
			cout << "YES" << endl;
			return;
		}
	}
	for (int y = y1; y <= y2; y++) {
		if (ok(x1, y, x3, y3, x4, y4) && ok(x1, y, x5, y5, x6, y6)) {
			cout << "YES" << endl;
			return;
		}
		if (ok(x2, y, x3, y3, x4, y4) && ok(x2, y, x5, y5, x6, y6)) {
			cout << "YES" << endl;
			return;
		}	
	}
	cout << "NO" << endl;
}

int main(){
    
    solve();
}
