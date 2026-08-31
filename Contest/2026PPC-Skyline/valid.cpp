#include "testlib.h"
using namespace std;

int main(){
    registerValidation();

    int N = inf.readInt(1, 1000000, "N");
    inf.readEoln();

    for (int i=1;i<=N;i++){
        inf.readLong(1LL, 1000000000LL, format("H_%d", i).c_str());
        inf.readSpace();
        inf.readLong(1LL, 1000000000LL, format("W_%d", i).c_str());
        inf.readEoln();
    }

    inf.readEof();
}
