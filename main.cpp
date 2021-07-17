#include <iostream>
#include <string>

using namespace std;

// ----Task 1
class DivisionByZero {};

template <class T>
T Div(const T& a, const T& b)
{
        if (b!=0)
         return T (a/b);
        else throw DivisionByZero();
}

// ----Task 2

class Ex {
  private:
    double x;
  public:
    Ex(double X): x(X) {};
    double get() {return x;}
};

class Bar {
  private:
    double y;
  public:
    Bar(double Y = 0): y(Y) {};
    void set(double a) {
        if (y+a>100) {
            throw Ex(a*y);
        }
        else y=a;
    }
};

// ----Task 3

const int maxn = 10;

class Robo {
public:
    int x,y;
    int x1,y1;
    class OffTheField {
    public:
        OffTheField(int _x,int _y,int _x1,int _y1) {
         cout << "Robo x=" << _x <<" y=" << _y << " move x=" << _x1 << " move y=" << _y1 << endl;
        };
    };
    class IllegalCommand {
    public:
        IllegalCommand(int _x,int _y,int _x1,int _y1) {
            cout << "Robo x=" << _x <<" y=" << _y << " move x=" << _x1 << " move y=" << _y1 << endl;
        }
    };
    Robo(int X = 0, int Y=0, int X1 = 0, int Y1=0): x(X),y(Y), x1(X1),y1(Y1) {
        if (x<0 || x>maxn) throw OffTheField(x,y,x1,y1);
        if (y<0 || y>maxn) throw OffTheField(x,y,x1,y1);
    };
    void move(const int& X1,const int& Y1) {
        x1=X1; y1=Y1;
        int tempx=x+x1;
        int tempy=y+y1;
        if (tempx<0 || tempx>maxn) throw IllegalCommand(x,y,x1,y1);
        if (tempy<0 || tempy>maxn) throw IllegalCommand(x,y,x1,y1);
        print();
        x=tempx;
        y=tempy;

    };
    void print() {
      cout << "Robo x=" << x <<" y=" << y << " move x=" << x1 << " move y=" << y1 << endl;
    };

    void printEx(int x,int y, int x1, int y1) {
      cout << "Robo x=" << x <<" y=" << y << " move x=" << x1 << " move y=" << y1 << endl;
    };


};

int main()
{
   // ---- Task 1
// Написать шаблонную функцию div, которая должна вычислять результат деления двух параметров
// и запускать исключение DivisionByZero, если второй параметр равен 0. В функции main выводить
// результат вызова функции div в консоль, а также ловить исключения.
    cout << "Task 1" << endl;
    try {

        int i = Div(3, 4);
        cout << "3/4=" << i << '\n';

        double x = Div(6.0, 9.0);
        cout << "6/9=" << x << '\n';

        cout << "6/0=";
        double y = Div(6, 0);
        cout << y << '\n';

    }  catch ( DivisionByZero ) {
      cerr << "DivisionByZero" << endl;
    }

   // ---- Task 2
//    Написать класс Ex, хранящий вещественное число x и имеющий конструктор по вещественному числу,
//    инициализирующий x значением параметра. Написать класс Bar, хранящий вещественное число y
//    (конструктор по умолчанию инициализирует его нулем) и имеющий метод set с единственным
//    вещественным параметром a. Если y + a > 100, возбуждается исключение типа Ex с данными a*y,
//    иначе в y заносится значение a. В функции main завести переменную класса Bar и в цикле в блоке
//    try вводить с клавиатуры целое n. Использовать его в качестве параметра метода set до тех пор,
//    пока не будет введено 0. В обработчике исключения выводить сообщение об ошибке, содержащее данные
//    объекта исключения.
      cout << endl << "Task 2" << endl;
      Bar b;
      double n;
      do {
         try {
          cout << "Enter n=";
          cin >> n;
          b.set(n);
         }
         catch (Ex ex) {
            cout<<"Exception Ex(" << ex.get() << ")" << endl;
         }

      } while (n!=0);

  // ---- Task 3
//    Написать класс «робот», моделирующий перемещения робота по сетке 10x10, у которого есть метод,
//    означающий задание переместиться на соседнюю позицию. Эти методы должны запускать классы-исключения
//    OffTheField, если робот должен уйти с сетки, и IllegalCommand, если подана неверная команда
//    (направление не находится в нужном диапазоне). Объект исключения должен содержать всю необходимую
//    информацию — текущую позицию и направление движения. Написать функцию main, пользующуюся этим классом
//    и перехватывающую все исключения от его методов, а также выводящую подробную информацию о всех
//    возникающих ошибках.

      cout << endl << "Task 3" << endl;
      cout << "Probe 1" << endl;
      try {
          Robo r(12,6);
      }  catch (Robo::OffTheField) {
          cout<<"Robo exeption OffTheField"<<endl;
      }
      cout << endl << "Probe 2" << endl;
      try {
          Robo r(6,6);
          r.move(1,3);
          r.move(1,3);
      }  catch (Robo::IllegalCommand) {
          cout<<"Robo exeption IllegalCommand"<<endl;
      }

    return 0;
}
