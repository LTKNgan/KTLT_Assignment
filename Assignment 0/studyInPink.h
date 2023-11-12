/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 0
    * Programming Fundamentals Spring 2022
    * Author: Tran Huy
    * Date: 06.01.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

int firstMeet(int& EXP1, int& EXP2, const int& E1){
    
    if (E1 >= 0 && E1 < 400)
    {
        if (E1 < 50) EXP2 += 25;
        else if (E1 < 100) EXP2 += 50;
        else if (E1 < 150) EXP2 += 85;
        else if (E1 < 200) EXP2 += 75;
        else if (E1 < 250) EXP2 += 110;
        else if (E1 < 300) EXP2 += 135;
        else EXP2 += 160;

        if (E1 % 2 != 0) EXP1 = ceil(EXP1 + E1/10.0);
        else EXP1 = ceil(EXP1 - E1/5.0);
    }
    
    else if (E1 >= 400 && E1 < 1000)
    {
        if (E1 < 500) EXP2 = ceil(EXP2 + E1/7.0 + 9);
        else if (E1 < 600) EXP2 = ceil(EXP2 + E1/9.0 + 11);
        else if (E1 < 700) EXP2 = ceil(EXP2 + E1/5.0 + 6);
        else if (E1 < 800) 
        { 
            EXP2 += ceil(E1/7.0) + 9;
            if (EXP2 > 200) EXP2 = ceil(EXP2 + E1/9.0 + 11);
        }
        else if (E1 < 1000)
        {
            EXP2 = ceil(EXP2 + E1/7.0 + 9 + E1/9.0 + 11);
            if (EXP2 > 600) 
            {
                EXP2 = ceil(EXP2 + E1/5.0 + 6);
                EXP2 = ceil(EXP2 * 1.15);
            }       
        }
        EXP1 = ceil(EXP1 - 0.1*E1);
    }

    else return -999;
    
    if (EXP1 > 900) EXP1 = 900;
    if (EXP2 > 900) EXP2 = 900;
    if (EXP1 < 0) EXP1 = 0;
    if (EXP2 < 0) EXP2 = 0;
    return EXP1 + EXP2;
}

int investigateScene(int& EXP1, int& EXP2, int& HP2, int& M2, const int& E2){

    if (E2 >= 0 && E2 < 1000)
    {
        EXP2 += ceil(E2/9.0 + 10);
        EXP1 += ceil((E2/9.0 + 10)/3.0);
        if (E2 >= 300) 
        {
            EXP2 += ceil(E2 * 0.35);
            EXP1 += ceil((E2 * 0.35)/3.0);
        }
        if (E2 >= 500) 
        {
            EXP2 += ceil(0.17 * ((E2/9.0 + 10) + (E2 * 0.35)));
            EXP1 += ceil((0.17 * ((E2/9.0 + 10) + (E2 * 0.35)))/3.0);
        }
    }
    else return -999;
    
    HP2 = ceil(HP2 - pow(E2*1.0,3)/pow(2.0,23));
    
    if (E2 % 2 ==0) M2 += ceil(E2*E2/50.0);
    
    if (EXP1 > 900) EXP1 = 900;
    if (EXP2 > 900) EXP2 = 900;
    if (EXP1 < 0) EXP1 = 0;
    if (EXP2 < 0) EXP2 = 0;
    
    if (HP2 > 999) HP2 = 999;
    if (HP2 < 0) HP2 = 0;
    
    if (M2 > 2000) M2 = 2000;
    if (M2 < 0) M2 = 0;

    return EXP1 + EXP2 + HP2 + M2;
}

int traceLuggage(int& HP1, int& EXP1, int& M1, const int& E3)
{
    if ( E3 >= 0 && E3 < 1000)
    {
// CON DUONG 1
// Nhap gia tri cho P
    int P1[9], k, a = 1, sai = 0;  // k la vi tri, sai la so con duong khong tim thay hanh ly
    for (int i = 0; i < 9; i++)
    {
        P1[i] = (a + E3) % 26 + 65;
        a += 2;
    }
// Tim vi tri 80
    for (k = 0; k < 9; k++)
    {
        if (P1[k] == 80) break;
    }
// Neu khong tim duoc
    if (k == 9 && P1[8] != 80) 
    {
        M1 = ceil(M1 - 9.0*9.0*E3/9.0);
        sai++;
    }
// Neu tim duoc
    else 
    {
        HP1 = ceil(HP1 - P1[k]*(k + 1)*2);
        EXP1 += (1000 - P1[k]*(k + 1)) % 101;
        M1 = ceil(M1 - (k + 1)*E3/9.0);
    }
    
// CON DUONG 2
// Nhap gia tri cho P
    int P2[7] = {2, 3, 5, 7, 11, 13, 17}, s = 0, m = 0;
    for (int i = 0; i < 7; i++)
    {
        P2[i] = (P2[i] + E3) % 26;
        s += P2[i];
    }
    m = ceil(s/7.0);
    for (int i = 0; i < 7; i++)
    {
        P2[i] = (P2[i] + s + m) % 26 + 65;
    }
// Tim vi tri 80
    for (k = 0; k < 7; k++)
    {
        if (P2[k] == 80) break;
    }
// Neu khong tim duoc
    if (k == 7 && P2[6] != 80) 
    {
        M1 = ceil(M1 - 7.0*7.0*E3/9.0);
        sai++;
    }
// Neu tim duoc
    else 
    {
        HP1 = ceil(HP1 - P2[k]*(k+1)*2);
        EXP1 += (1000 - P2[k]*(k+1)) % 101;
        M1 = ceil(M1 - (k+1)*E3/9.0);
    }
    
// CON DUONG 3
// Nhap gia tri cho P
    int P3[20], i = 0, j = 1, max;
    while (i < 20)
    {
        for (int dem = 1; dem <= j; dem++)
        {
            if (j == dem*dem && j % 2 == 0)
            {
                P3[i] = (j + E3*E3) % 113;
                i++;
            }
        }
        j++;
    }
    max = P3[0];
    for (i = 1; i < 20; i++)
    {
        if (P3[i] > max) max = P3[i];
    }
    for (i = 0; i < 20; i++)
    {
        P3[i] = ceil((P3[i] + E3)/(1.0*max));
        P3[i] = P3[i] % 26 + 65;
    }
// Tim vi tri 80
    for (k = 20; k > 0; k--)
    {
        if (P3[k - 1] == 80) break;
    }
// Neu khong tim duoc
    if (k == 0 && P3[0] != 80) 
    {
        M1 = ceil(M1 - 20.0*20.0*E3/9.0);
        sai++;
    }
// Neu tim duoc
    else 
    {
        HP1 = ceil(HP1 - P3[k-1]*(21 - k)*3);
        EXP1 += (3500 - P3[k-1]*(21 - k)) % 300;
        M1 = ceil(M1 - (21 - k)*E3/9.0);
    }
    
// CON DUONG 4
// Nhap gia tri cho P
    int P4[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (i = 0; i < 12; i++)
    {
        P4[i] = P4[i] + pow(ceil(E3/29.0),3);
        P4[i] = P4[i] % 9;
    }
    int min = P4[0], min_idx = 0;
    for (i = 1; i < 12; i++)
    {
        if (P4[i] < min)
        {
            min = P4[i];
            min_idx = i + 1;
        }      
    }
    for (i = 0; i < 12; i++)
    {
        P4[i] = (P4[i] + E3)*ceil(min*1.0/min_idx);
        P4[i] = P4[i] % 26 + 65;
    }
// Tim vi tri 80
    for (k = 12; k > 0; k--)
    {
        if (P4[k-1] == 80) break;
    }
// Neu khong tim duoc
    if (k == 0 && P4[0] != 80) 
    {
        M1 = ceil(M1 - 12.0*12.0*E3/9.0);
        sai++;
    }
// Neu tim duoc
    else 
    {
        HP1 = ceil(HP1 - P4[k-1]*(13 - k)*4);
        EXP1 += (4500 - P4[k-1]*(13 - k)) % 400;
        M1 = ceil(M1 - (13 - k)*E3/9.0);
    }    
//Neu khong tim duoc o ca 4 duong
    if (sai == 4)
    {
        HP1 -= (59 * E3) % 900;
        EXP1 -= (79 * E3) % 300;
        
        if (EXP1 > 900) EXP1 = 900;
        if (EXP1 < 0) EXP1 = 0;
    
        if (HP1 > 999) HP1 = 999;
        if (HP1 < 0) HP1 = 0;
    
        if (M1 > 2000) M1 = 2000;
        if (M1 < 0) M1 = 0;
        return -1;
    }
    }
    else return -999;
    
    if (EXP1 > 900) EXP1 = 900;
    if (EXP1 < 0) EXP1 = 0;
    
    if (HP1 > 999) HP1 = 999;
    if (HP1 < 0) HP1 = 0;
    
    if (M1 > 2000) M1 = 2000;
    if (M1 < 0) M1 = 0;
    
    return EXP1 + HP1 + M1;
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
