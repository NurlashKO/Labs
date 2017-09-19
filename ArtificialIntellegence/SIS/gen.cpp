#include <iostream>
#include <fstream>

using namespace std;

struct Student {
	string name;
	string courses[5];
};

string RandomString(int len)
{
   srand(time(0));
   string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
   string newstr;
   int pos;
   while(newstr.size() != len) {
    pos = ((rand() % (str.size() - 1)));
    newstr += str.substr(pos,1);
   }
   return newstr;
}

int main() {
	freopen("courses","r",stdin);
	freopen("students","w",stdout);
	string c[12];
	for(int i = 0; i < 12; i++) {
		cin >> c[i];
	}
	int n = 100;
	cout << "{\n";
	for (int i = 1; i < n; i ++) {
		Student* s;
		s -> name = RandomString(10);
		cout << "\t" << s -> name << ": { ";
		for (int j = 0; j < 5; j ++) {
			int r = 1;
			r = rand()%11;
			s -> courses[j] = c[r];
			cout << s -> courses[j] << ", ";

		}
		cout << "}\n";
	}
	cout << "}";

}
