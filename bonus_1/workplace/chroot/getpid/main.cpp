#include <cstdio>
#include <iostream>
#include <ostream>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main(int argc, char* argv[]) {
	cout << getpid() << endl;
}