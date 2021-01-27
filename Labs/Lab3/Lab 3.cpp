#include<iostream>
#include<cmath>
using namespace std;
float windChill (float tempParam, float windParam);
int main()
{
    float temperature, windSpeed, chillIndex;
    cout << "Enter Temperature Please: ";
    cin >> temperature;
    cout << "Enter Wind Speed Please: ";
    cin >> windSpeed;
    if ((temperature <= 50) && (windSpeed > 3)) {
        chillIndex = windChill (temperature, windSpeed);
        if (chillIndex == 0) {
            cout << "No Wind Chill." << endl;
        } else {
            cout << "Wind Chill Index (F) = " << chillIndex << endl;
        }
    } else {
        cout << "No wind chill index - temperature > 50 OR wind speed <= 3\n";
    }
}

float windChill (float tempParam, float windParam)
{
    return (35.74 + 0.6215*tempParam - 35.75*pow(windParam, 0.16) + 0.4275*tempParam*pow(windParam, 0.16));
}
