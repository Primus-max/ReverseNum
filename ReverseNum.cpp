//Пользователь вводит четырехзначное число.Необходимо
//поменять в этом числе 1 и 2 цифры, а также 3 и 4 цифры.Если
//пользователь вводит не четырехзначное число — вывести
//сообщение об ошибке.


#include <iostream>
using namespace std;

/// <summary>
/// Вспомогательный метод возведения в степень
/// </summary>
/// <param name="base"><База системы исчисления</param>
/// <param name="exp">Степень</param>
/// <returns>Int возведённое в степень</returns>
int Exponentiation(int base, int exp) 
{
    int result = 1;
    for (int i = 0; i < exp; ++i)    
        result *= base;    

    return result;
}

/// <summary>
/// Метод реверса цифр в числе
/// </summary>
/// <param name="num">Ввод пользователя</param>
/// <returns>Int  перевёрнутое число</returns>
int ReverseDigits(int num) 
{
    int inputNum = num;
    int result = 0;

    // Получаю и меняю местами
    int digit1 = (inputNum / 100) % 10;
    int digit2 = (inputNum / 1000) % 10;
    int digit3 = inputNum % 10;
    int digit4 = (inputNum / 10) % 10;   

    // Складываю
    result = digit1 * Exponentiation(10, 3) + digit2 * Exponentiation(10, 2) + digit3 * Exponentiation(10, 1) + digit4 * Exponentiation(10, 0);

    return result;
}

/// <summary>
/// Метод валидации числа введённого пользователем
/// </summary>
/// <param name="num">Число введённое пользователем</param>
/// <returns>Bool результат валидации</returns>
bool ValidationInput(int num) 
{
    return (num >= 1000 && num <= 9999);
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int userInputNum = 0;
    bool inputValid = false;

    while (!inputValid)
    {
        cout << "Введи 4-ех значное число :";
        cin >> userInputNum;

        inputValid = ValidationInput(userInputNum); 

        if (!inputValid)
            cout << "Вы ввели не 4-ёх значное число, попробуйте ещё раз" << endl;
        else
            break;
    }
          

    int resultNum = ReverseDigits(userInputNum);

    cout << "Вот результат реверса цифр в ведённом числе : " << resultNum << endl;

    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
}
