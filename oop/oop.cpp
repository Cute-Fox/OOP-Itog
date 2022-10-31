#include <exception>
#include <string>
#include <iostream>

// Task 1
using namespace std;

class DivistionByZero : public std::exception {
    std::string m_text;
public:
    DivistionByZero(std::string what) noexcept
        : std::exception()
        , m_text(std::move(what))
    {}

    const char* text() const noexcept {
        return m_text.c_str();
    }
};

template<typename T, typename U>
auto divide(T&& nominator, U&& denominator) {
    if (denominator == 0)
        throw DivistionByZero("Divistion by Zero");
    return nominator / denominator;
}

// Task 2
class Ex
{
public:
    double x;
    Ex(const double& x_) :x(x_) {}
    ~Ex() {}
};

class Bar
{
private:
    double y;

public:
    Bar() { y = 0; }
    ~Bar() {}
    void set(const double& a)
    {
        if (y + a <= 100)
        {
            y = a;

        }
        else throw Ex(y * a);
    }

};

// Task 3
class Robot;

class Exeptions
{

public:
    static void OffTheField(int x, int y, string command)
    {
        cout << "Exception handled OffTheField" << endl << "Robots coord: [" << x << ";" << y << "]" << endl << "Last command: " << command << endl;
    }
    static void IllegalCommand(const Robot& ob, int command)
    {
        cout << "Exception handled IllegalCommand" << endl;
        cout << "Last command: " << command << endl;
    }
};

class Robot
{
protected:
    int x, y;
public:
    Robot() { x = 0; y = 0; }

    void up()
    {
        if (y = y + 1 > 10)
        {
            Exeptions::OffTheField(x, y, "Up");
        }
        else y = y + 1;
        show();
    }
    void down()
    {
        if (y = y - 1 < 0)
        {
            Exeptions ob;
            ob.OffTheField(x, y, "Down");
        }
        else y--;
        show();
    }
    void left()
    {
        if (x = x - 1 < 0)
        {
            Exeptions ob;
            ob.OffTheField(x, y, "Left");
        }
        else x--;
        show();
    }
    void right()
    {
        if (x = x + 1 > 10)
        {
            Exeptions ob;
            ob.OffTheField(x, y, "Right");
        }
        else x++;
        show();
    }
    void show() const
    {
        cout << endl << "-! Robots coord: [" << x << ";" << y << "]" << endl;
    }
};

int main() {
    // Task 1
    cout << "--== Task 1 ==--" << endl;
    try {
        volatile int a = 2;
        int b = 3;
        cout << divide(a, b) << endl;

        cout << divide(move(a), b) << endl;

        cout << divide(3, 2) << endl;
        cout << divide(3.0, 2.0) << endl;
        cout << divide(1.0, 0.0) << endl;
    }
    catch (const DivistionByZero& e) {
        cerr << e.what() << endl;
    }
    cout << endl << endl;

    // Task 2
    cout << "--== Task 2 ==--" << endl;
    Bar b;
    int x;
    cin >> x;
    try
    {
        b.set(x);
    }
    catch (Ex& err)
    {
        std::cerr << "Exception: ay " << err.x << std::endl;
    }
    cout << endl << endl;

    // Task 3
    cout << "--== Task 3 ==--" << endl;
    setlocale(LC_ALL, "rus");
    int command;
    Robot rob;
    while (true)
    {
        cout << "Input number to move the robot one square" << endl << "1:  one square up." << endl
            << "2:  one square down."<< endl << "3:  one square left." << endl 
            << "4:  one square right." << endl << "5: Exit" << endl << "Command: ";
        cin >> command;
        cout << endl;
        switch (command)
        {
        case 1:
        {
            rob.up();
            break;
        }
        case 2:
        {
            rob.down();
            break;
        }
        case 3:
        {
            rob.left();
            break;
        }
        case 4:
        {
            rob.right();
            break;
        }
        case 5:
        {
            cout << "Exit from program" << endl;
            return 0;
        }
        default:
            Exeptions ob;
            ob.IllegalCommand(rob, command);
            break;
        }
    }
    cout << endl << endl;
}