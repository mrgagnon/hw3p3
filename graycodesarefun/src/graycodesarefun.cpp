/* Maylee Gagnon
 * CS 2223
 * HW3 P3 Gray code
 * 11.10.19
 */

#include <iostream>
#include <vector>
using namespace std;

/*Prints the given lists of strings
 * @param lists The list/vector of strings to be printed
 * @param n The length of each string ie the number of bits in each
 */
void printArr(vector<string> lists, int n){
	for (int i = 0; i < lists.size(); i ++){
		for (int j = 0; j < n; j++){
			cout << (lists[i])[j];
		}
		cout << endl;
	}
}

/* Print a table with the index, the gray code, a list of child(ren) in the photo, and the action needed to achieve combination
 * The pool of names is hardcoded and based on the assignment
 * @param groupList The previously generated gray code listings
 * @param n The max number in each group
 */
void printWithNames(vector<string> groupList, int n) {
	//string names[4] = {"Alice", "Bob", "Chris", "Dylan"};
	string names[4] = {"Dylan", "Chris", "Bob", "Alice"};
	cout << "Index | Gray Code | Child(ren in Photo | Action" << endl;

	string prevGroup = "0000";

	for (int i = 0; i < groupList.size(); i++){ // printing each row
		string inPhoto[4] = {"","","",""}; // list of children in current group
		int inPhotoPos = 0;

		cout << i << " | ";

		string curGroup = groupList[i]; // get current group
		for (int j = 0; j < n; j++) { // go through the current group
			cout << curGroup[j];
			if (curGroup.at(j) == '1'){ // check if child in photo if yes add to current name list
				inPhoto[inPhotoPos] = names[j];
				inPhotoPos++;
			}
		}
		cout << " | ";

		for (int i = 0; i < inPhotoPos; i++){
			cout << inPhoto[i] << " ";
		}

		cout << " | ";
		for (int i = 0; i < n; i++){
			if (prevGroup.at(i) == '0' && curGroup.at(i) == '1'){
				cout << names[i] << " in";
			}
			else if (prevGroup.at(i) == '1' && curGroup.at(i) == '0') {
				cout << names[i] << " out";
			}

		}
		prevGroup = curGroup;
		cout << endl;
	}
}

/* Uses recursion to generate binary gray code for the given amount of bits
 * @param n The number of bits to generate
 * @return a list/vector of strings containing all of the combinations. Each string consists of 0s and 1s
 */
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

		for (int i = 0; i < L1.size(); i++){ // adding 0s and 1s
			L1[i] = "0" + L1[i];
			L2[i] = "1" + L2[i];
		}

		L.insert(L.end(), L1.begin(), L1.end()); // appending lists
		L.insert(L.end(), L2.begin(), L2.end());
	}
	return L;
}

/* Gets user input for the number. Call to createGray. Prints results.
 *
 */
int main() {
	int n;
	cout << "enter value for n" << endl;
	cin >> n;
	if (cin.bad()) {
		cout << "bad input. exiting." << endl;
		return 0;
	}

	vector<string> lists = createGray(n);
	//printArr(lists,n);
	printWithNames(lists, n);

	return 0;
}
