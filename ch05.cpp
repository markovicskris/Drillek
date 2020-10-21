// drill5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <string>
int main() {
	try {
		//std::cout << "(1) Success!\n";
		//std::cout << "(2) Success!\n";
		//std::cout << "(3) Success!\n";
		//std::cout << "(4) Success!" << "\n";
		//int res = 7; std::vector<int> v(10); v[5] = res; std::cout << "(5) Success!\n";
		//std::vector<int> v1(10); v1[5] = 7; if (v1[5] == 7) std::cout << "(6) Success!\n";
		//if (5 != 3) std::cout << "(7) Success!\n"; else std::cout << "Fail!\n";
		//bool c = false; if (!c) std::cout << "(8) Success!\n"; else std::cout << "Fail!\n";
		//std::string s = "ape"; bool c1 = "fool" > s; if (c1) std::cout << "(9) Success\n";
		//std::string s1 = "ape"; if (s1 != "fool") std::cout << "(10) Success!\n";
		//std::string s2 = "ape"; if (s2 != "fool") std::cout << "(11) Success!\n";
		//std::string s3 = "ape"; if (s3 != "fool") std::cout << "(12) Success!\n";
		//std::vector<char> v2(5); for (int i = 0; i < v2.size(); ++i); std::cout << "(13) Success!\n";
		//std::vector<char> v3(5); for (int i = 0; i <= v3.size(); ++i); std::cout << "(14) Success!\n";
		//std::string s4 = "(15) Success!\n"; for (int i = 0; i < 6; ++i); std::cout << s4;
		//if (true) std::cout << "(16) Success'\n"; else std::cout << "Fail!\n";
		//int x = 2000; int c2 = x; if (c2 == 2000) std::cout << "(17) Success!\n";
		//std::string k = "(18) Success!\n"; for (int i = 0; i < 10; ++i); std::cout << k;
		//std::vector<int> v4(5); for (int i = 0; i <= v4.size(); ++i); std::cout << "(19) Success!\n";
		//int i = 0; int j = 9; while (i < 10)++i; if (j <= i) std::cout << "(20) Success!\n";
		//int x1 = 2; double d = 5 / (x1 - 1); if (d == 2 * x1 + 1) std::cout << "(21) Success!\n";
		//std::string s5 = "(22) Succes!\n"; for (int i = 0; i <= 10; ++i); std::cout << s5;
		//int i1 = 0; int j1 = 0; while (i1 < 10) ++i1; if (i1 > j1) std::cout << "(23) Success!\n";
		//int x2 = 4; double d1 = 5 / (x2 - 3); if (d1 = 2 * x2 / 1 + 1) std::cout << "(24) Success!\n";
		//std::cout << "(25) Success!\n";
		return 0;
	}
	catch (std::exception& e) {
		std::cerr << "error: " << e.what() << 'n';
		return 1;
	}
	catch (...) {
		std::cerr << "Oops:unknown exception!\n";
		return 2;
	}
}
