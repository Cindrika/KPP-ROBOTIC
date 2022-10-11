// NAMA		: CINDRIKA DWI PRAMUDITA
// NRP		: 2035221045
// Jurusan	: D4 Teknik Sipil

#include <iostream>
#include <cmath>
using namespace std;

#define GRAVITASI 10 //10 m/s^2
#define START_PENGUKURAN 1 //pengukuran dimulai dari 1 meter
#define SUDUT 45 //sudut elevasi tembakan
#define PHI 3.14159265

void mencari_V0(float *vt, int *v0)
{
	if (*vt >= 1 && *vt <=10)
    {
        *v0 = *vt-1;
    }
    else if (*vt >=11 && *vt <=20)
    {
        *v0 = *vt-3;
    }
    else if (*vt >=21 && *vt <=30)
    {
        *v0 = *vt-5;
    }
}

void speed_dgn_loss(float *vt, int g, int jarak, float sudut)
{
    *vt = sqrt((jarak*g)/sin(2*sudut));
    
    if (*vt >=1 && *vt <=10)
    {
        *vt = *vt+1;
    }
    else if (*vt >=11 && *vt <=20)
    {
        *vt = *vt+3;
    }
    else if (*vt >= 21 && *vt <=30)
    {
        *vt = *vt+5;
    }
}

int main() {
    float sudut, vt;
  	int jarak, v0, g;
    
    g = GRAVITASI;
    sudut = SUDUT*PHI/180;
    vt = 30;
    
    mencari_V0(&vt, &v0);
    jarak = (pow(v0,2)*sin(2*sudut))/g;
    speed_dgn_loss(&vt, g, jarak, sudut);

    cout << jarak << " " << vt <<  endl;
  
    return 0;
}