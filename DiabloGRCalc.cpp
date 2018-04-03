#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <ios>
#include <array>

using namespace std;

double calculateMonsterDamage(const uint64_t& GR)
{
    const double Ahigh = 3604;
    const double Bhigh = pow(2,1/10.0);
    const double Amed = 2540;
    const double Bmed = pow(3604.0/Amed,1/5.0);    
    const double Alow = 130;
    const double Blow = pow(1.45,1/3.0);

    if(GR>=30)
        return Ahigh*pow(Bhigh,(GR-30));
    if(GR>=25)
        return Amed*pow(Bmed,(GR-25));
    return Alow*pow(Blow,(GR-1));
}

void showMonsterDamage(const uint64_t& GR)
{
    const double T13Damage = 28832;

    uint64_t monsterDamage;
    if(GR >= 7)
    {
        monsterDamage = round(calculateMonsterDamage(GR));
    }
    else
    {
        monsterDamage = ceil(calculateMonsterDamage(GR));
    }
    double monsterT13Damage = monsterDamage/T13Damage;
    if(monsterT13Damage >= 0.01) //No point in showing a number under the printed precision
    {
        cout << setprecision(2) << fixed << "Monster Damage:\t" << monsterDamage << "\t% of base or\t\t" << monsterT13Damage << "x T13 Damage" << endl;
    }
    else //Don't show the factor in relation to T13 if it'll display as 0.00x anyhow
    {
        cout << setprecision(2) << fixed << "Monster Damage:\t" << monsterDamage << "\t% of base or\t\t" << "<1% T13 Damage" << endl;
    }
}

double calculateMonsterHealth(const uint64_t& GR)
{
    const double aHealth = 200;
    const double bHealth = 1.17;
    return aHealth*pow(bHealth,(GR-1));
}

void showMonsterHealth(const uint64_t& GR)
{
    const double T13Health = 2108607;
    uint64_t monsterHealth;
    if(GR >= 55)
    {
        monsterHealth = floor(calculateMonsterHealth(GR));
    }
    else
    {
        monsterHealth = round(calculateMonsterHealth(GR));
    }
    double monsterT13Health = monsterHealth/T13Health;
    if(monsterT13Health >= 0.01) //No point in showing a number under the printed precision
    {
        cout << setprecision(2) << fixed << "Monster Health:\t" << monsterHealth << "\t% of base or\t\t" << monsterT13Health << "x T13 Health" << endl;
    }
    else //Don't show the factor in relation to T13 if it'll display as 0.00x anyhow
    {
        cout << setprecision(2) << fixed << "Monster Health:\t" << monsterHealth << "\t% of base or\t\t" << "<1% T13 Health" << endl;
    }
}

int main()
{
    //Welcome and declare constants needed in main-loop
    cout << "Welcome to the Diablo III GR Difficulty Calculator by Deadonstick!" << endl << "NOTE: Numbers above GR600 tend to get wonky due to 64-bit precision" << endl << "Input the number 0 to exit at any time." << endl << endl << endl;
    uint64_t input = 1;
    while (input > 0) //Program exit number is 0
    {
        //Get input
        cout << "Please input the GR difficulty rating you wish to know the difficulty of: ";
        cin >> input;
        cout << endl << endl;
        //See if we need to exit
        if(input <= 0)
        {
            break; //Sort of makes the check in the while loop redundant don't it?
        }
        //Begin printing results
        cout << "At GR" << input << " the stats are as follows:" << endl;
        showMonsterHealth(input);
        showMonsterDamage(input);
    }
    return 0;
}