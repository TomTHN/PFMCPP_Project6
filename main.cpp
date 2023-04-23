/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference and don't change the return type either.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.

 2) revise the 'else' statement in main() that handles when `smaller` is a nullptr. 
 there is only one reason for `compare` to return nullptr. 
 Update this std::cout expression to specify why nullptr was returned.
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(int v, const char* tChar) : value(v), name(tChar) {}  //1

    int value; //2
    const char* name;//3
};

struct Operator                                //4
{
    T* compare(T* a, T* b) //5
    {
        if(a != nullptr && b != nullptr) 
        {
            if( a->value < b->value ) return a;
            if( a->value > b->value ) return b;
        }
        
        return nullptr;
    }
};

struct U
{
    float valueUOne { 0 }, valueUTwo { 0 };
    // no THIS keyword necessary because member function so it is implicit 
    float updateValue(float* newValue)      //12
    {
        if(newValue != nullptr)
        {
            std::cout << "U's valueUOne value: " << valueUOne << std::endl;
            valueUOne = *newValue;
            std::cout << "U's valueUOne updated value: " << valueUOne << std::endl;
            
            while( std::abs(valueUTwo - valueUOne) > 0.001f )
            {
                /*
                write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
                */
                valueUTwo += (valueUOne < valueUTwo) ? -0.1f : 0.1f;    //so the while loop is not necessary
            }
            
            std::cout << "U's valueUTwo updated value: " << valueUTwo << std::endl; 
        }
        
        return valueUTwo * valueUOne;
    }
};

struct UpdateWithThat
{
    static float updateValue(U* that, float* newValue)        //10
    {
        if(that != nullptr && newValue != nullptr)
        {
            std::cout << "U's valueUOne value: " << that->valueUOne << std::endl;
            that->valueUOne = *newValue;
            std::cout << "U's valueUOne updated value: " << that->valueUOne << std::endl;
            
            while( std::abs(that->valueUTwo - that->valueUOne) > 0.001f )
            {
                /*
                 write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
                 */
                that->valueUTwo += (that->valueUOne < that->valueUTwo) ? -0.1f : 0.1f; 
            }
            
            std::cout << "U's valueUTwo updated value: " << that->valueUTwo << std::endl; 
        }
        
        return that->valueUTwo * that->valueUOne;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T tOne(5,"tOne");                                             //6
    T tTwo(3,"tTwo");                                             //6
    
    Operator f;                                            //7
    auto* smaller = f.compare(&tOne, &tTwo);    //8
    
    if(smaller != nullptr)
    {
        std::cout << "the smaller one is " << smaller->name << std::endl; //9
    }
    else
    {
        std::cout << "Reasons for nullptr:" << std::endl << "1. tOne or tTwo is nullptr" << std::endl << "tOne tTwo same value" << std::endl; //9
    }
    
    U uOne;
    float updatedValue = 5.f;
    
    std::cout << "[static func] uOne's multiplied values: " << UpdateWithThat::updateValue(&uOne, &updatedValue) << std::endl;                  //11
    
    U uTwo;
    std::cout << "[member func] uTwo's multiplied values: " << uTwo.updateValue( &updatedValue ) << std::endl;
}
