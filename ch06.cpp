//
// This is example code from Chapter 6.7 "Trying the second version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

/*
    This file is known as calculator02buggy.cpp
    I have inserted 5 errors that should cause this not to compile
    I have inserted 3 logic errors that should cause the program to give wrong results
    First try to find an remove the bugs without looking in the book.
    If that gets tedious, compare the code to that in the book (or posted source code)
    Happy hunting!
*/

#include "std_lib_facilities.h" //1st compile error

//------------------------------------------------------------------------------




double expression();

class Token{ //2nd compile error
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
    :full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()       // ERROR 2 no ref to Token_stream
{
    if (full) 
    {       // do we already have a Token ready?
        // remove token from buffer
        full=false;
        return buffer;
    } 

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
        case 'x':    // for "print"
        case '=':    // for "quit"
        case '(': case ')': case '+': case '-': case '*': case '/': 
            return Token(ch);        // let each character represent itself
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {    
            cin.putback(ch);         // put digit back into the input stream
            double val;
            cin >> val;              // read a floating-point number
            return Token('|',val);   // let '8' represent "a number"
        }
        default:
            error("Bad token");
            return 0;
        }
       
}


//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------
// declaration so that primary() can call expression()

//------------------------------------------------------------------------------

// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch(t.kind)
    {
        case '(':
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
        case '|':
            return t.value;
        default:
            error("primary expected");
            return 0;
    }
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
    double left = primary();
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
            case '*':
                left *= primary();
                t = ts.get();
                break; //missing break in switch-case
            case '/':
            {
                double d = primary();
                if (d == 0) error("divide by zero");
                left /= d;
                t = ts.get();
                break;
            }
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
    double left = term(); //compile error  missing )'   // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
            case '+':
                left += term();    // evaluate Term and add
                t = ts.get();
                break;
            case '-':
                left -= term();    // evaluate Term and subtract //not +=, but -=
                t = ts.get();
                break;
            default:
                ts.putback(t);     // put t back into the token stream
                return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

int main()
try
{
	double val=0;

    cout << "Welcome to our simple calcuator\n";
    cout << "Please enter the expressions usin floating-point numbers.\n";
    cout << "You can use +,-,*,/. If you want to print the result write =, if you want to exit the calculator write x.\n";

    

    while(cin)
    {
        Token t = ts.get();

        if (t.kind == 'x') break;
        if (t.kind == '=')
            cout << "=" << val << endl;
        else
            ts.putback(t);

        val = expression();
    }

    return 0;
  // error: dont need t.kind cuz its already in the token_stream::get()
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    
    return 2;
}

//------------------------------------------------------------------------------