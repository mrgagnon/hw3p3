/* Maylee Gagnon
 * CS 2223
 * HW3 P3 Gray code
 * 11.10.19
 */

#include <iostream>
#include <vector>
using namespace std;

void printArr(vector<string> lists, int n){
	for (int i = 0; i < lists.size(); i ++){
		for (int j = 0; j < n; j++){
			cout << (lists[i])[j];
		}
		cout << endl;
	}
}
vector<string> createGray(int n){
	vector<string> L;
	if (n == 1){
		L.push_back("0");
		L.push_back("1");
	}
	else {
		vector<string> L1;  //L1 is recursive call n-1
		n--;
		L1 = createGray(n);

		vector<string> L2; //L2 is L1 in reverse
		for (int i = L1.size()-1; i >= 0; i--){
			L2.push_back(L1[i]);
		}

		for (int i = 0; i < L1.size(); i++){ // adding 0s/1s
			L1[i] = "0" + L1[i];
			L2[i] = "1" + L2[i];
		}

		L.insert(L.end(), L1.begin(), L1.end()); // appending lists
		L.insert(L.end(), L2.begin(), L2.end());
	} // end else
	return L;
}
int main() {
	int n;
	cout << "enter value for n" << endl;
	cin >> n;
	if (cin.bad()) {
		cout << "bad input. exiting." << endl;
		return 0;
	}
//	cout << "n:" << n << endl;
	vector<string> lists = createGray(n);

	printArr(lists,n);

	return 0;
}
