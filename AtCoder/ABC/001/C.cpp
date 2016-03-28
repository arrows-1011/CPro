#include <iostream>

using namespace std;

string get_wind_dir(double Deg)
{
    if (Deg < 11.25 || Deg >= 348.75) {
        return "N";
    } else if (Deg < 33.75) {
        return "NNE";
    } else if (Deg < 56.25) {
        return "NE";
    } else if (Deg < 78.75) {
        return "ENE";
    } else if (Deg < 101.25) {
        return "E";
    } else if (Deg < 123.75) {
        return "ESE";
    } else if (Deg < 146.25) {
        return "SE";
    } else if (Deg < 168.75) {
        return "SSE";
    } else if (Deg < 191.25) {
        return "S";
    } else if (Deg < 213.75) {
        return "SSW";
    } else if (Deg < 236.25) {
        return "SW";
    } else if (Deg < 258.75) {
        return "WSW";
    } else if (Deg < 281.25) {
        return "W";
    } else if (Deg < 303.75) {
        return "WNW";
    } else if (Deg < 326.25) {
        return "NW";
    } else {
        return "NNW";
    }
}

int get_wind_power(double Dis)
{
    Dis = (int)(Dis/6 + 0.5);
    Dis /= 10;

    if (Dis <= 0.2) {
        return 0;
    } else if (Dis <= 1.5) {
        return 1;
    } else if (Dis <= 3.3) {
        return 2;
    } else if (Dis <= 5.4) {
        return 3;
    } else if (Dis <= 7.9) {
        return 4;
    } else if (Dis <= 10.7) {
        return 5;
    } else if (Dis <= 13.8) {
        return 6;
    } else if (Dis <= 17.1) {
        return 7;
    } else if (Dis <= 20.7) {
        return 8;
    } else if (Dis <= 24.4) {
        return 9;
    } else if (Dis <= 28.4) {
        return 10;
    } else if (Dis <= 32.6) {
        return 11;
    } else {
        return 12;
    }
}

int main()
{
    double Deg, Dis;
    cin >> Deg >> Dis;
    Deg /= 10;
    
    string wind_dir = get_wind_dir(Deg);
    int wind_power = get_wind_power(Dis);

    if (wind_power == 0) {
        wind_dir = "C";
    }
    cout << wind_dir << " " << wind_power << endl;
    return 0;
}
