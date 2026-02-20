#include <iostream>
#include <string>
#include <fstream>

int input_k(int k) {
	using namespace std;

	cout << "¬ведите число k = ";
	cin >> k;
	while (k < 2 || k>10) {
		cout << "¬ведите 2<=k<=10 = ";
		cin >> k;
	}
	return k;
}

int input_n(int n) {
	using namespace std;

	cout << "¬ведите число n = ";
	cin >> n;
	while (n < 1 || n>20) {
		cout << "¬ведите 1<n<20 = ";
		cin >> n;
	}
	return n;
}

int checking_usl(int n, int k, int change) {
	using namespace std;

	if (n + k > 26) {
		cout << "(n+k<26)" << endl;
		cout << "1 - помен€ть число k\n 2 - помен€ть число n\n ¬ведите цифру: ";
		cin >> change;
		while (change < 1 || change > 2) {
			cout << "¬ведите цифру 1-2: ";
			cin >> change;
		}
	}
	return change;
}

