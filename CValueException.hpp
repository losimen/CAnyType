//
//  CValueException.hpp
//  Task 2 by Koval Pavlo
//
//  Created by Павло Коваль on 13.08.2021.
//

#ifndef CValueException_hpp
#define CValueException_hpp

#include <exception>

struct MyException : public std::exception
{
    const char * what () const throw ()
    {
        return "\nThe requested type does not match to stored\n";
    }
    
    MyException(std::string msg)
    {
        std::cout << "\nCAnyType exception class, value type: " + msg << std::endl;
    }
    
};


#endif /* CValueException_hpp */
