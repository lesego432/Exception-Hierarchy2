#include <iostream>
#include <fstream>
#include <string>
#include "Array.h"
#include "DLList.h"
#include "Queue.h"
#include "Stack.h"
#include "Printer.h"
#include "Exception.h"
#include "InvalidIndexException.h"
#include "InvalidSizeException.h"
#include "ElementNotInListException.h"
#include "OutOfBoundsException.h"
#include "TooManyPrintersDeleted.h"
#include "PrinterNotInitialized.h"

int main() {
    try {
        Array<int> arr1(5);
        for (int i = 1; i <= 3; i++) {
            arr1 += i;
        }
        std::cout << "Array: " << arr1 << std::endl;
        std::cout << "Array size: " << (int)arr1 << std::endl;
        std::cout << "Array elements: " << arr1.numElements() << std::endl;

        DLList<int> dllist;
        for (int i = 1; i <= 5; i++) {
            dllist += i;
        }
        std::cout << "DLList: " << dllist << std::endl;
        std::cout << "DLList size: " << (int)dllist << std::endl;

        Queue<int> queue;
        for (int i = 1; i <= 4; i++) {
            queue += i;
        }
        std::cout << "Queue: " << queue << std::endl;
        std::cout << "Queue size: " << (int)queue << std::endl;

        Stack<int> stack;
        for (int i = 1; i <= 4; i++) {
            stack += i;
        }
        std::cout << "Stack: " << stack << std::endl;
        std::cout << "Stack size: " << (int)stack << std::endl;

        Printer<Queue, int>& printer = Printer<Queue, int>::requestPrinter();
        
        for (int i = 1; i <= 3; i++) {
            printer.insertDocument(i);
        }
        
        std::cout << "Documents in printer: " << printer.numberOfDocuments() << std::endl;
        
        std::cout << "Printing to stream:" << std::endl;
        printer.printToStream(std::cout);
        
        int searchDoc = 2;
        std::cout << "Is document " << searchDoc << " in queue? " << printer.isInQueue(searchDoc) << std::endl;
        
        Printer<Queue, int>::returnPrinter();

        Array<std::string> arr2(3);
        std::string s1 = "hello";
        std::string s2 = "world";
        std::string s3 = "test";
        arr2 += s1;
        arr2 += s2;
        arr2 += s3;
        std::cout << "String Array: " << arr2 << std::endl;

        DLList<std::string> strList;
        strList += s1;
        strList += s2;
        strList += s3;
        std::cout << "String DLList: " << strList << std::endl;

        try {
            Array<int> invalidArr(-1);
        } catch (InvalidSizeException& e) {
            std::cout << "Caught expected exception: " << e << std::endl;
        }

        try {
            arr1[10];
        } catch (InvalidIndexException& e) {
            std::cout << "Caught expected exception: " << e << std::endl;
        }

        try {
            int notInList = 999;
            dllist -= notInList;
        } catch (ElementNotInListException& e) {
            std::cout << "Caught expected exception: " << e << std::endl;
        }

        Iterator<DLList, int> dllIter;
        for (int i = 1; i <= 3; i++) {
            dllIter += i;
        }
        
        dllIter.setStart();
        while (!dllIter.isAtEnd()) {
            std::cout << "Iterator value: " << (int&)dllIter << std::endl;
            dllIter++;
        }

        std::cout << "All tests completed successfully!" << std::endl;

    } catch (Exception& e) {
        std::cout << "Unexpected exception: " << e << std::endl;
        return 1;
    }

    return 0;
}