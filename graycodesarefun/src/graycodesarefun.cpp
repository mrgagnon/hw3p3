/* Maylee Gagnon
 * CS 2223
 * HW3 P3 Gray code
 * 11.10.19
 */

#include <iostream>
#include <vector>
using namespace std;

vector<string> createGray(int n){
	if (n == 1){
		vector<string> arr;
		arr.push_back("0");
		arr.push_back("1");
		return arr;
	}
	else {
		vector<string> arrPrev;
		arrPrev = createGray(n-1); //recursive call

		vector<string> arrRev;  // Reversing L1/arrPrev
		for (int i = arrPrev.size()-1; i >= 0; i--){
			arrRev.push_back(arrPrev[i]);
		}

		for (int i = 0; i < arrPrev.size()-1;i++){ //Adding 0 infront of arrPrev/L1, 1 infront of arrRev/L2
			arrPrev[i] = "0" + arrPrev[i];
			arrRev[i] = "1" + arrRev[i];
		}

		vector<string> arrResult; //appending the two lists
		arrResult.insert(arrResult.begin(), arrPrev.begin(), arrPrev.end());
		arrResult.insert(arrResult.end(), arrRev.begin(), arrRev.end());
		return arrResult;
	} // end else
}

int main() {
	cout << "Hello1" << endl;

	vector<string> lists = createGray(3);
	for (int i = 0; i < lists.size(); i ++){
			for (int j = 0; j < 3; j++){
				cout << (lists[i])[j];
			}
		cout << endl;
	}
	return 0;
}
