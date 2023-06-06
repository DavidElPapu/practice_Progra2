#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int askNumber(string question, int high, int low = 1);
//GUESS MY NUMBER
void guessMyNumber();
void vectorsPart1();
void vectorPractice();
void vectorReserve();
void wordShuffleGame();
void iterators();
void iterInventory();
void buenWordShuffleGame();
int badSwapNumbers(int score1, int score2);
int goodSwapNumbers(int& score1, int& score2);
void swap();
void display(const vector<string>& vec);
void matrices();

//Exam P2
void BuySpace(vector<string>& inventory, unsigned int& gems, string itemFound);
void ReplaceItem(vector<string>& inventory, string itemFound);
string GetRandomItem(vector<string>& items);
void DisplayInventory(vector<string>& inventory);
bool AskYesNo(string question);
void ShowMenu();

const int MAX_ITEMS = 6;
const int SPACE_COST = 6;
const int FREE_ITEMS = 3;

int main()
{
    std::setlocale(LC_ALL, "es_ES.UTF-8");
    unsigned int gems = 8;

    //Items
    vector<string> items = { "espada", "martillo", "bomba", "escudo" };

    //inventory
    vector<string> inventory;
    inventory.reserve(MAX_ITEMS);
    vector<string>::const_iterator iter;
    bool isContinue;

    do
    {
        cout << "---INVENTARIO---" << endl;
        cout << "Gemas: " << gems << endl;

        string itemFound = GetRandomItem(items);

        cout << "Has encontrado un(a) " << itemFound << "!!" << endl;

        if (inventory.size() >= FREE_ITEMS)
        {
            ShowMenu();
            int option = askNumber("\nElige un numero ", 3);

            switch (option)
            {
            case 1:
                ReplaceItem(inventory, itemFound);
                break;
            case 2:
                BuySpace(inventory, gems, itemFound);
                break;
            default:
                break;
            }
        }
        else
        {
            inventory.push_back(itemFound);
        }

        //DisplayItems
        DisplayInventory(inventory);

        isContinue = AskYesNo("¿Seguir explorando?");

    } while (isContinue);

    cout << "Vuelve Pronto" << endl;
}

void BuySpace(vector<string>& inventory, unsigned int& gems, string itemFound)
{
    if (gems >= SPACE_COST)
    {
        cout << "\n Espacio comprado con éxito!!\n";
        inventory.push_back(itemFound);
        gems -= SPACE_COST;
    }
    else
    {
        cout << "\nNo tienes gemas suficientes!!\n";
    }
}

void ReplaceItem(vector<string>& inventory, string itemFound)
{
    vector<string>::iterator iter;
    int itemChosen = 0;
    cout << "Que item deseas reemplazar?" << endl;
    DisplayInventory(inventory);
    cin >> itemChosen;
    iter = inventory.begin() + itemChosen;
    *iter = itemFound;
}

string GetRandomItem(vector<string>& items)
{
    srand(time(NULL));
    int itemRandomIndex = (rand() % items.size());
    string itemSelected = items[itemRandomIndex];

    return itemSelected;
}

void DisplayInventory(vector<string>& inventory)
{
    vector<string>::const_iterator iter;
    int i = 0;
    cout << "Tus items" << endl;
    for (iter = inventory.begin(); iter != inventory.end(); iter++)
    {
        cout << i << "_" << *iter << endl;
        i++;
    }
}

bool AskYesNo(string question)
{
    char answer;

    do {
        cout << "\n" << question << "(y/n)";
        cin >> answer;
    } while (answer != 'y' && answer != 'n');

    if (answer == 'y')
    {
        return true;
    }

    return false;
}

void ShowMenu()
{
    cout << "\nYa no tienes espacio para más objetos, que te gustaría hacer:\n";
    cout << "\n1. Reemplazar objeto.";
    cout << "\n2. Continuar sin el objeto.";
    cout << "\n3. Añadir un espacio por " << SPACE_COST << " gemas.";
}

void matrices()
{
    const int ROWS = 5;
    const int COLUMNS = 5;

    cout << "Caja" << endl;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (j == 0 || j == (COLUMNS - 1) || i == 0 || i == (ROWS - 1))
            {
                cout << " 1 ";
            }
            else
            {
                cout << " 0 ";
            }
        }
        cout << " " << endl;
    }

    cout << "Diagonal" << endl;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (i == j)
            {
                cout << " 1 ";
            }
            else
            {
                cout << " 0 ";
            }
        }
        cout << " " << endl;
    }

    cout << "Diagonal Invertida" << endl;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (j == ((ROWS - 1) - i))
            {
                cout << " 1 ";
            }
            else
            {
                cout << " 0 ";
            }
        }
        cout << " " << endl;
    }

    cout << "Caja con X" << endl;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (i == j || (j == 0 || j == (COLUMNS - 1) || i == 0 || i == (ROWS - 1)))
            {
                cout << " 1 ";
            }
            else if (j == ((ROWS - 1) - i))
            {
                cout << " 1 ";
            }
            else
            {
                cout << " 0 ";
            }
        }
        cout << " " << endl;
    }
}

void display(const vector<string>& vec)
{
    /* Esto va en el main
    vector<string> inventory;

    inventory.push_back("sword");
    inventory.push_back("armor");
    inventory.push_back("gun");

    display(inventory);
    */

    vector<string>::const_iterator iter;
    for (iter = vec.begin(); iter != vec.end(); iter++)
    {
        cout << *iter << endl;
    }
}

void swap()
{
    int score1 = 20;
    int score2 = 100;

    cout << score1 << endl;
    cout << score2 << endl;

    //BAD SWAPPER
    badSwapNumbers(score1, score2);

    cout << score1 << endl;
    cout << score2 << endl;

    //GOOD SWAPPER
    goodSwapNumbers(score1, score2);

    cout << score1 << endl;
    cout << score2 << endl;
}

int goodSwapNumbers(int& score1, int& score2)
{
    int intermedio;

    intermedio = score1;
    score1 = score2;
    score2 = intermedio;

    return score1, score2;
}

int badSwapNumbers(int score1, int score2)
{
    int intermedio;

    intermedio = score1;
    score1 = score2;
    score2 = intermedio;

    return score1, score2;
}

void buenWordShuffleGame()
{
    const int MAX_ATTEMPTS = 3;
    int attempts = 0;

    vector<string> words;
    words.push_back("COMPUTADORA");
    words.push_back("JUEGO");
    words.push_back("CODIGO");
    words.push_back("REFRIGERADOR");

    srand(time(NULL));
    int randomNumber = rand();
    int wordsRandomIndex = (randomNumber % words.size());
    string wordSelected = words[wordsRandomIndex];

    //cout << wordSelected << endl;

    random_shuffle(wordSelected.begin(), wordSelected.end());
    cout << wordSelected << endl;

    string correctWord;

    do
    {
        cin >> correctWord;
        transform(correctWord.begin(), correctWord.end(), correctWord.begin(), ::toupper);
        //cout << correctWord << endl;

        if (correctWord == words[wordsRandomIndex])
        {
            cout << "Adivinaste la palabra!!!" << endl;
            break;
        }
        else
        {
            attempts++;
            cout << "Fallaste inutil, te quedan " << MAX_ATTEMPTS - attempts << " intentos" << endl;
        }

    } while (attempts != MAX_ATTEMPTS);

    if (attempts == MAX_ATTEMPTS)
    {
        cout << "Perdiste, date de baja, la palabra era: " << endl;
        cout << words[wordsRandomIndex] << endl;
    }
}

void iterInventory()
{
    vector<string> inventory;
    inventory.push_back("Espada");
    inventory.push_back("Escudo");
    inventory.push_back("Martillo");
    inventory.push_back("Rifle");

    vector<string>::iterator myIterator;
    vector<string>::const_iterator iter;

    cout << "Tus Items: " << endl;
    for (iter = inventory.begin(); iter != inventory.end(); iter++)
    {
        cout << *iter << endl;
    }

    //Intercambiar
    cout << "Intercambiaste tu " << inventory[2] << " por un arco" << endl;
    myIterator = inventory.begin() + 2;
    *myIterator = "Arco";
    cout << "Tus Items" << endl;
    for (iter = inventory.begin(); iter != inventory.end(); iter++)
    {
        cout << *iter << endl;
    }

    //SIZE
    cout << "El nombre del item " << *myIterator << " tiene ";
    cout << (*myIterator).size() << " letras" << endl;

    cout << "El nombre del item " << *myIterator << " tiene ";
    cout << (myIterator)->size() << " letras" << endl;

    //INSERT
    cout << "Recuperaste la bomba robada" << endl;
    inventory.insert(inventory.begin() + 4, "bomba");
    cout << "Tus Items" << endl;
    for (iter = inventory.begin(); iter != inventory.end(); iter++)
    {
        cout << *iter << endl;
    }

    //Delete
    cout << "Your " << inventory[1] << " has been destroyed by an enemy!!!\n";
    inventory.erase(inventory.begin() + 1);
    for (iter = inventory.begin(); iter != inventory.end(); iter++)
    {
        cout << *iter << endl;
    }
}

void iterators()
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

    cout << "Buscar puntajes: Ingresa el puntaje que quieres buscar" << endl;
    cin >> score;

    iter = find(scores.begin(), scores.end(), score);

    if (iter != scores.end())
    {
        cout << "Tu puntaje se encuentra en el vector" << endl;
    }
    else
    {
        cout << "No encontramos el puntaje que buscas" << endl;
    }

    /*Random Shuffle*/

    srand(time(NULL));
    //random_shuffle(scores.begin(), score.
}

void wordShuffleGame()
{
    int vidas = 3;
    string guessWord = " ";
    string OGword = " ";
    srand(static_cast<unsigned int>(time(0)));
    int randomNumber = rand();
    int secretNumber = (randomNumber % 20) + 1;
    string word[] = {
        "barbaro",
        "arquera",
        "gigante",
        "rompemuros",
        "duende",
        "globo",
        "mago",
        "curandera",
        "dragon",
        "minero",
        "yeti",
        "titan",
        "esbirro",
        "valquiria",
        "golem",
        "bruja",
        "sabueso",
        "cazadora",
        "hechizo",
        "heroe"
    };
    while (vidas > 0)
    {
        randomNumber = rand();
        secretNumber = (randomNumber % 20) + 1;
        OGword = word[secretNumber];
        random_shuffle(word[secretNumber].begin(), word[secretNumber].end());
        cout << word[secretNumber] << endl;
        word[secretNumber] = OGword;
        cout << "Escribe la palabra ordenada" << endl;
        cout << "(Te quedan " << vidas << " vidas)" << endl;
        cin >> guessWord;
        if (guessWord == word[secretNumber])
        {
            system("cls");
            cout << "Correcto" << endl;
        }
        else
        {
            system("cls");
            cout << "Incorrecto, la palabra era " << word[secretNumber] << endl;
            vidas = vidas - 1;
        }
        if (vidas == 0)
        {
            system("cls");
            cout << "Perdiste todas tus vidas, quieres volver a jugar ?" << endl;
            cin >> guessWord;
            if (guessWord == "si" || guessWord == "Si")
            {
                vidas = 3;
            }
        }
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
    string input;
    bool isValid = false;
    //int number = 0;
    bool primeraVez = true;

    do {
        isValid = true;
        if (primeraVez == false)
        {
            cout << question << "entre " << low << " y " << high << endl;
        }
        
        //cin >> input;
        getline(cin, input);
        

        for (char c : input)
        {
            if (!isdigit(c))
            {
                isValid = false;
                break;
            }
        }

        if (!isValid)
        {
            cout << "Entrada inválida, porfavor elige solo numeros." << endl;
        }
        else if (input.empty() && primeraVez == false)
        {
            cout << "Entrada vacia, no valida, pon algo" << endl;
        }
        else if (input.empty() && primeraVez == true)
        {
            primeraVez = false;
        }
        else
        {
            cout << "Bien hecho" << endl;
        }
    } while (!isValid || input.empty());
    
    //number > high || number < low

    return stoi(input);
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