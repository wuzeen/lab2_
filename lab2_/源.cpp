/*static Randomizer& instance() -- returns a reference to the sole Randomizer object
nextInt(int high) -- returns an int in the range [0..high-1)
nextInt(int low, int high) -- returns an int in the range [low..high)
die(int sides) -- returns an int in the range [1..sides]
nextDouble() -- returns a double in the range [0,1)
randomChar(const string& s) -- returns a char selected at random from s (each character in the string is equally likely)
Allow or forbid constructors and operators as appropriate for a singleton class.

In the implementation you may use the c functions rand() and srand(), and use the time() function to seed srand -- as in srand(time(NULL)). ?You will need to include ctime and cstdlib to get those functions.

Pass in a tar file containing (and containing only) the files:
Randomizer.h
Randomizer.cpp
Your tar file should NOT be compressed at all. ?It should NOT have the required files embedded in a folder. ?It should not be a tar of a zipped file. ?When you execute tar -tf, only the two files shown should appear. ?*/
#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#define _MAX 2147483647
using namespace std;


class Randomizer {
public:
	static Randomizer& wu_instance() {
		if (instance == NULL)
			instance = new Randomizer();
		return *instance;
	}
	//overload function--paramar list
	int nextInt(int high) {
		if (high>0)//确保函数健壮性，除数不为0
			return rand() % high;
		else
		{
			cout << "error!!!" << endl;
			exit(0);
		}
	}

	int nextInt(int low, int high) {

		if (low<high)
			return rand() % (high - low) + low;//确保函数健壮性，在某个范围内，前面的数字小于后面的数字
		else
		{
			cout << "error!!!!" << endl;
			exit(0);
		}

	}

	int die(int sides) {
		if (sides>0)
			return rand() % sides + 1;
		else
		{
			cout << "error!!!!!" << endl;
			exit(0);
		}
	}
	double nextDouble() {
		return 1 / (rand() % _MAX + 1);
	}

	char randomChar(const string& s) {

		return s.at(die(s.size()));
	}

	~Randomizer() {
		cout << "the number is destroyed!!!" << endl;
	}
private:
	static Randomizer *instance;
	Randomizer() {
		srand(time(NULL));
	}

};
Randomizer* Randomizer::instance = new Randomizer();
int main() {

	Randomizer a_number = Randomizer::wu_instance();//定义一个数

	cout << a_number.nextInt(19) << endl;
	cout << a_number.nextInt(6, 23) << endl;
	cout << a_number.randomChar("abcdfteeruwqwoqyiqoop") << endl;
	cout << a_number.nextDouble() << endl;
	system("pause");
	return 0;

}








