#include "cppAndFortran.hpp"

using namespace std;

extern "C" {
    struct CommonData {
        double doubleScalar;
    };
    extern void fortran_setData();
    extern void fortran_copyDataFromCpp(CommonData* a_dataFromCpp);
    extern void fortran_copyDataToCpp(CommonData* a_dataToCpp);
    extern void fortran_printData();
}

C2F::C2F() {
    cout << "C2F::C2F: I exists!" << endl;
    m_commonData = new CommonData();
}

C2F::~C2F() {
    cout << "C2F::~C2F: I am gone." << endl;
    delete m_commonData;
}


        //void setDataInCpp();
        //void setDataInFortran();
        //void copyDataFromCpp();
        //void copyDataToCpp();
        //void printData();

void C2F::setDataInCpp() {
    cout << "C2F::setDataInCpp" << endl;
    m_commonData->doubleScalar = 1.1;
}

void C2F::setDataInFortran() {
    cout << "C2F::setDataInFortran" << endl;
    fortran_setData();
}

void C2F::copyDataFromCpp() {
    cout << "C2F::copyDataFromCpp" << endl;
    fortran_copyDataFromCpp(m_commonData);
}

void C2F::copyDataToCpp() {
    cout << "C2F::copyDataToCpp" << endl;
    fortran_copyDataToCpp(m_commonData);
}

void C2F::printData() {
    cout << "C2F::printCommonData" << endl;
    cout << "cpp: doubleScalar: " << m_commonData->doubleScalar << endl;
    fortran_printData();
}

int main(int argc, char *argv[]) {
    C2F* m_c2f = new C2F();
    cout << "From Cpp to Fortran:" << endl;
    m_c2f->setDataInCpp();
    m_c2f->copyDataFromCpp();
    m_c2f->printData();

    cout << "From Fortran to Cpp:" << endl;
    m_c2f->setDataInFortran();
    m_c2f->copyDataToCpp();
    m_c2f->printData();

    delete m_c2f;
    return 0;
}
