# CPP & Fortran mixed environment
    
    This shows an example about communicating methods and data from cpp to Fortran.

## Instructions

    cmake .
    make
    ./cppAndFortran

## Output

    C2F::C2F: I exists!
    From Cpp to Fortran:
    C2F::setDataInCpp
    C2F::copyDataFromCpp
    C2F::printCommonData
    cpp: doubleScalar: 1.1
    cpp: doubleArray[0][0]: 1.1
    cpp: doubleArray[0][1]: 2.2
    cpp: doubleArray[0][2]: 3.3
    cpp: doubleArray[1][0]: 4.4
    cpp: doubleArray[1][1]: 5.5
    cpp: doubleArray[1][2]: 6.6
     fortran: doubleScalar:    1.1000000000000001     
     fortran: doubleArray(           1 ,           1 ):    1.10000002    
     fortran: doubleArray(           1 ,           2 ):    2.20000005    
     fortran: doubleArray(           1 ,           3 ):    3.29999995    
     fortran: doubleArray(           2 ,           1 ):    4.40000010    
     fortran: doubleArray(           2 ,           2 ):    5.50000000    
     fortran: doubleArray(           2 ,           3 ):    6.59999990    
     
     TO OBTAIN THE SAME VALUES, THE ARRAY NEEDS TO BE TRANPOSED!
     
     Cpp is row-first filling: 
     
       start  -->  [X]  -->  [X]  -->  [X]  --> (new line)
     
              -->  [X]  -->  [X]  -->  [X]
     
     Fortran is column-first filling: 
     
            start
              |         |
              v         v
     
             [X]       [X]
     
              |         |
              v         v
     
             [X]       [X]
     
              |         |
              v         v
     
             [X]       [X]
     
              |
              v
        (new column)
     
    From Fortran to Cpp:
    C2F::setDataInFortran
    C2F::copyDataToCpp
    C2F::printCommonData
    cpp: doubleScalar: -1.1
    cpp: doubleArray[0][0]: -1.1
    cpp: doubleArray[0][1]: -2.2
    cpp: doubleArray[0][2]: -3.3
    cpp: doubleArray[1][0]: -4.4
    cpp: doubleArray[1][1]: -5.5
    cpp: doubleArray[1][2]: -6.6
     fortran: doubleScalar:   -1.1000000238418579     
     fortran: doubleArray(           1 ,           1 ):   -1.10000002    
     fortran: doubleArray(           1 ,           2 ):   -2.20000005    
     fortran: doubleArray(           1 ,           3 ):   -3.29999995    
     fortran: doubleArray(           2 ,           1 ):   -4.40000010    
     fortran: doubleArray(           2 ,           2 ):   -5.50000000    
     fortran: doubleArray(           2 ,           3 ):   -6.59999990    
     
     TO OBTAIN THE SAME VALUES, THE ARRAY NEEDS TO BE TRANPOSED!
     
     Cpp is row-first filling: 
     
       start  -->  [X]  -->  [X]  -->  [X]  --> (new line)
     
              -->  [X]  -->  [X]  -->  [X]
     
     Fortran is column-first filling: 
     
            start
              |         |
              v         v
     
             [X]       [X]
     
              |         |
              v         v
     
             [X]       [X]
     
              |         |
              v         v
     
             [X]       [X]
     
              |
              v
        (new column)
     
    C2F::~C2F: I am gone.
