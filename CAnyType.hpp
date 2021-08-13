//
//  CAnyType.hpp
//  Task 2 by Koval Pavlo
//
//  Created by Павло Коваль on 06.08.2021.
//

#ifndef CAnyType_hpp
#define CAnyType_hpp

#include <iostream>
#include "CValueException.hpp"

class CAnyType
{
private:
    
    union typesValue
    {
        bool         _bool;
        char         _char;
        int          _int;
        float        _float;
        double       _double;
        unsigned int _unsignedInt;

    };
    
    enum typesName
    {
        BOOL,        // 0
        CHAR,        // 1
        INT,         // 2
        FLOAT,       // 3
        DOUBLE,      // 4
        UNSIGNEDINT, // 5
        NOVALUE      // 6
    };

    
    std::unique_ptr<typesValue> value;
    typesName type;
    
    void _isCorrectType(typesName tempType) const;

    
public:
    
    CAnyType()
    {
        type = NOVALUE;
    }

    template <typename T>
    CAnyType(T const i)
    {
        this->operator=(i);
    }

    CAnyType(const CAnyType &obj)
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
        
    }
    
    template <typename T>
    CAnyType& operator= (const T i)
    {
        
        typesValue temp;
        
        if (typeid(T) == typeid(bool))
        {
            temp._bool = i;
            type = BOOL;

            
        } else if (typeid(T) == typeid(char))
        {
            temp._char = i;
            type = CHAR;

            
        } else if (typeid(T) == typeid(int))
        {
            temp._int = i;
            type = INT;


        }else if (typeid(T) == typeid(float))
        {
            temp._float = i;
            type = FLOAT;


        }else if (typeid(T)== typeid(double))
        {
            temp._double = i;
            type = DOUBLE;


        }else if (typeid(T) == typeid(unsigned int))
        {
            temp._unsignedInt = i;
            type = UNSIGNEDINT;

        } else
        {
            type = NOVALUE;
        }
         
        value = std::make_unique<typesValue>(temp);
        
        return *this;
    }
    
    CAnyType& operator= (CAnyType &obj);

    bool         ToBool()        const;
    char         ToChar()        const;
    int          ToInt()         const;
    float        ToFloat()       const;
    double       ToDouble()      const;
    unsigned int ToUnsignedInt() const;
    
    void         DestroyObject();
    std::string  GetTypeName()   const;
    int          GetTypeIndex()  const;
    
    void         swap(CAnyType &obj);
    
    
};



#endif /* CAnyType_hpp */

