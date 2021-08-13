//
//  CAnyType.cpp
//  Task 2 by Koval Pavlo
//
//  Created by Павло Коваль on 06.08.2021.
//

#include "CAnyType.hpp"


void CAnyType::_isCorrectType(typesName tempType) const
{
    if (type != tempType)
    {
        throw MyException(this->GetTypeName());
    }
}

CAnyType& CAnyType::operator= (CAnyType &obj)
{
    if (obj.GetTypeIndex() == 0)
    {
        this->operator=(obj.ToBool());
        this->type = BOOL;

        
    } else if (obj.GetTypeIndex() == 1)
    {
        this->operator=(obj.ToChar());
        this->type = CHAR;

        
    } else if (obj.GetTypeIndex() == 2)
    {
        this->operator=(obj.ToInt());
        this->type = INT;


    }else if (obj.GetTypeIndex() == 3)
    {
        this->operator=(obj.ToFloat());
        this->type = FLOAT;


    }else if (obj.GetTypeIndex() == 4)
    {
        this->operator=(obj.ToDouble());
        this->type = DOUBLE;


    }else if (obj.GetTypeIndex() == 5)
    {
        this->operator=(obj.ToUnsignedInt());
        this->type = UNSIGNEDINT;

    } else
    {
        this->type = NOVALUE;
    }
    
    
    return *this;
}





bool         CAnyType::ToBool()        const
{
    this->_isCorrectType(BOOL);
    return value->_bool;
}

char         CAnyType::ToChar()        const
{
    this->_isCorrectType(CHAR);
    return value->_char;
}

int          CAnyType::ToInt()         const
{
    this->_isCorrectType(INT);
    return value->_int;
}

float        CAnyType::ToFloat()       const
{
    this->_isCorrectType(FLOAT);
    return value->_float;
}

double       CAnyType::ToDouble()      const
{
    this->_isCorrectType(DOUBLE);
    return value->_double;
}

unsigned int CAnyType::ToUnsignedInt() const
{
    this->_isCorrectType(UNSIGNEDINT);
    return value->_unsignedInt;
}

void         CAnyType::DestroyObject() 
{
    type = NOVALUE;
}

std::string CAnyType::GetTypeName() const
{
    if (type == 0)
    {
        return "BOOl";
        
    } else if (type == 1)
    {
        return "CHAR";
        
    } else if (type == 2)
    {
        return "INT";
        
    }else if (type == 3)
    {
        return "FLOAT";
        
    }else if (type == 4)
    {
        return "DOUBLE";
        
    }else if (type == 5)
    {
        return "UNSIGNED INT";
        
    }else
    {
        return "NO VALUE";
    }
}

int         CAnyType::GetTypeIndex()  const
{
    return type;
}

void     CAnyType::swap(CAnyType &obj)
{
    CAnyType temp = *this;
    *this = obj;
    obj = temp;
    
}
