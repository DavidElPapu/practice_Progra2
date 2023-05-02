#include <iostream>
#include <string>
#include <vector>

using namespace std;

int askNumber(string question, int high, int low = 1);
//GUESS MY NUMBER
void guessMyNumber();
void vectorsPart1();
void vectorPractice();
void vectorReserve();


int main()
{
    const int NUM_SCORES = 4;
    int score;

    vector<int>::const_iterator iter;
    vector<int> scores;

    for (int i = 0; i < NUM_SCORES; i++)
    {
        cout << "Score " << i + 1 << endl;
        cin >> score;
        scores.push_back(score);
    }

    for (iter = scores.begin(); iter != scores.end(); iter++)
    {
        cout << *iter << endl;
    }

}

void vectorReserve()
{
    vector<int> scores(10, 0);
    cout << "Vector size is: " << scores.size() << endl;
    cout << "Vector capacity is: " << scores.capacity() << endl;
    scores.reserve(20);
    scores.push_back(0);
    cout << "Vector size is: " << scores.size() << endl;
    cout << "Vector capacity is: " << scores.capacity() << endl;

    scores.push_back(3);
    cout << "Vector size is: " << scores.size() << endl;
    cout << "Vector capacity is: " << scores.capacity() << endl;

}

void vectorsPart1()
{
    //vector<string> myStuff = { "espada", "martillo", "bomba" };
    //vector<string> inventory(10);
    //vector<string> inventory(10, " Vacio ");
    //vector<string> inventory(myStuff);


    vector<string> inventory;

    inventory.push_back("Espada");
    inventory.push_back("Escudo");
    inventory.push_back("Martillo");

    cout << "Tienes " << inventory.size() << " items en tu inventario" << endl;

    //Iteration FOR
    for (unsigned int i = 0; i < inventory.size(); i++)
    {
        cout << inventory[i] << endl;
    }

    cout << "\nCambiaste tu " << inventory[0] << " por una Bomba.";
    inventory[0] = "Bomba";

    cout << "\n";

    //Iteration DO-WHILE
    int i = 0;
    do {
        cout << inventory[i] << endl;
        i++;
    } while (i < inventory.size());

    cout << inventory[0] << " tiene " << inventory[0].size() << " letras en él ";

    cout << " Perdiste un item en la última batalla " << endl;

    //Delete item from vector
    inventory.pop_back();
    //Interation FOR
    for (unsigned int i = 0; i < inventory.size(); i++)
    {
        cout << inventory[i] << endl;
    }

    cout << "Un enemigo ha robado todas tus armas" << endl;
    //inventory.clear();
}

void vectorPractice()
{
    int invSize = 0;
    string object = " ";
    while (invSize <= 0 || invSize > 10)
    {
        system("cls");
        cout << "Buenas, escriba el tamaño que quiere que tenga su inventario" << endl;
        cin >> invSize;
        if (invSize > 10)
        {
            cout << "Oye, eso es demasiado espacio, intenta poner un numero menor a 10 " << endl;
        }
        else if (invSize <= 0)
        {
            cout << "Enserio?, no puedes tener solo 0 espacios, vamos viejo" << endl;
        }
    }
    vector<string> inventory(invSize);
    system("cls");
    cout << "Ahora toca llenar tu inventario de chucherias" << endl;
    for (int i = 0; i < inventory.size(); i++)
    {
        cout << "Escribe el objeto que quieres meter" << endl;
        cout << "(Te quedan " << inventory.size() - i << " espacios disponibles)" << endl;
        cin >> inventory[i];
        //inventory.push_back(object);
    }
    system("cls");
    cout << "Este es tu inventario actualmente:" << endl;
    for (int i = 0; i < inventory.size(); i++)
    {
        cout << i + 1 << ") " << inventory[i] << endl;
    }
    
}



int askNumber(string question, int high, int low)
{
    int number = 0;

    do {
        cout << question << "entre " << low << " y " << high << endl;
        cin >> number;
    } while (number > high || number < low);

    return number;
}


void guessMyNumber()
{
    srand(static_cast<unsigned int>(time(0)));
    //srand(time(NULL));
    int randomNumber = rand();
    int secretNumber = (randomNumber % 100) + 1;
    int guess;
    int tries = 0;
    int veryClose;


    cout << "GUESS MY NUMBER" << endl;
    cout << "Adivina el número en el menor número de intentos posible." << endl;

    //Depurar
    cout << secretNumber;
    do
    {

        guess = askNumber("\nIngresa un número ", 300);

        tries++;

        veryClose = secretNumber - guess;


        if (veryClose <= 5 && veryClose >= -5 && veryClose != 0)
        {
            cout << "Muy cerca!!\n";
        }

        if (guess > secretNumber) {
            cout << "Muy Alto\n\n";
        }
        else if (guess < secretNumber) {
            cout << "Muy Bajo\n\n";
        }
        else {
            cout << "Excelente lo hiciste en -- " << tries << "-- intentos";

        }
    } while (guess != secretNumber);
}