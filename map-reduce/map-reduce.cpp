#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
void map_func(ifstream& ifs, ofstream& ofs){
	string word;
	while(ifs >> word){
		ofs << word << ",1" << endl;
	}
}

int main(void){
	map<string, int> mp1;
	//int n;
	ifstream in1;
	in1.open("1.in");
	ofstream out1("intermediate1.txt");
	//string word;
	//while(in1 >> word){
	//	cout << word << endl;
	//	out1 << word << ",1" << endl;
	//	//mp1[word]++;
	//}
	//check
	map_func(in1, out1);
	//for(auto itr = mp1.begin(); itr != mp1.end(); ++itr){
	//	cout << itr->first << ", " << itr->second << endl;
	//}
	
	map<string, int> mp2;
	ifstream in2;
	in2.open("2.in");
	ofstream out2("intermediate2.txt");
	//string word2;
	//while(in2 >> word2){
	//	cout << word2 << endl;
	//	//mp2[word2]++;
	//	out2 << word2 << ",1" << endl;
	//}
	map_func(in2, out2);
	// ここまでmap処理
	
	ifstream intermediate1("intermediate1.txt");
	string row1;
	map<string, int> map_all;
	while(intermediate1 >> row1){
		cout << row1 << endl;
		stringstream ss(row1);
		string key;
		getline(ss, key, ',');
		//string val_str;
		//int val = atoi(getline(ss, val_str, ","));
		int val;
		ss >> val;
		cout << key << "->" << val << endl;
		map_all[key] += val;
	}
	
	ifstream intermediate2("intermediate2.txt");
	string row2;
	while(intermediate2 >> row2){
		stringstream ss(row2);
		string key;
		getline(ss, key, ',');
		int val;
		ss >> val;
		cout << key << "->" << val << endl;
		map_all[key] += val;
	}
	for(auto itr = map_all.begin(); itr != map_all.end(); ++itr){
		cout << itr->first << ", " << itr->second << endl;
	}

	return 0;
}
