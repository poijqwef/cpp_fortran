#define ARRAY_SIZE1 3
#define ARRAY_SIZE2 2

#include <iostream>

using namespace std;

extern "C" {
    struct CommonData;
}

class C2F {
    public:
        C2F();
        ~C2F();
        void setDataInCpp();
        void setDataInFortran();
        void copyDataFromCpp();
        void copyDataToCpp();
        void printData();
    private:
        CommonData* m_commonData;
};
