/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2022
* Author: Vu Van Tien
* Date: 10.02.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

string notebook1(string ntb1) {
    // Complete this function to gain point

    ifstream file(ntb1);
    string s;
    getline(file,s);
    for (int i = 11; i < 14; i++)
    {
        if (s[i] < '0' || s[i] > '9') return "0000000000";
    }
    int n1 = (s[11] - '0')*100 + (s[12] - '0')*10 + (s[13] - '0');
    string fre = "0000000000";
    if (n1 == 0) return "0000000000";
    else
    {
        int num[1000];
        for (int i = 0; i < n1; i++)
        {
            file >> num[i];
            fre[num[i]]++;
            if (fre[num[i]] > '9') 
            {
                fre[num[i]] = fre[num[i]] - 10;
            }
        }
    }
    return fre;
}

string notebook2(string ntb2) {
    // Complete this function to gain point

    ifstream file(ntb2);
    string s;
    getline(file,s);
    if (s.size() != 5) return "1111111111";
    int n2 = 0;
    for (int i = 0; i < 5; i++)
    {
        n2 += (s[i] - '0')*pow(10,4-i);
    }
    if (n2 < 5 || n2 > 100) return "1111111111";
    int count = 0;
    for (int i = 0; i < n2; i++)
    {
        getline(file,s);
        for (int j = 0; j < s.size(); j++)
        {
            if ((s[j] == 'p' || s[j] == 'P') && s[j+1] == 'i' && s[j+2] == 'n' && s[j+3] == 'k')
            {
                count++;
                j += 3;
            }
        }
    }

    if (count < 10000) count *= count;
    string cntP = "9999999999";
    char num1[10], num2[10];
    int dem = 0;
    do
    {
        num1[dem] = (count % 10) + '0';
        count /= 10;
        dem++;
    }
    while (count > 0);

    for (int i = 0; i < dem; i++)
    {
        num2[i] = num1[dem - 1 - i];
    }
    num2[dem] = '\0';
    cntP.replace(0,dem,num2);
    return cntP;
}

string notebook3(string ntb3) {
    // Complete this function to gain point

    ifstream file(ntb3);
    int arr[10][10];

    // Nhap du lieu
    for (int row = 0; row < 10; row++)
    {
        for (int col = 0; col < 10; col++)
        {
            file >> arr[row][col];
            if (arr[row][col] < 0) arr[row][col] = abs(arr[row][col]);
            if (col != 9)
            {
                char x;
                file >> x;   
            }
        }
    }

    // Chuyen duong cheo chinh sang so nguyen to
    for (int row = 0; row < 10; row++)
    {
        for (int col = row + 1; col < 10; col++)
        {
            if (arr[row][col] == 0 || arr[row][col] == 1) arr[row][col] = 2;
            else
            {
                bool check = false;
                while (check == false)
                {
                    int dem = 0;
                    for (int i = 2; i <= arr[row][col]; i++)
                    {
                        if (arr[row][col] % i == 0) dem++;
                    }
                    if (dem == 1) check = true;
                    else  arr[row][col]++;
                }
            }
        }        
    }

    // Chuyen hang duoi duong cheo chinh sang day  Fibonacci

    // Nhap day Fibonacci
    int fib[5000];
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < 5000; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Chuyen
    for (int row = 0; row < 10; row++)
    {
        for (int col = 0; col < row; col++)
        {
            for (int i = 1; i < 5000; i++)
            {
                if (arr[row][col] <= fib[i])
                {
                    arr[row][col] = fib[i];
                    i = 5000;
                }
            }
        }
    }

    // Sap xep 3 so cuoi
    for (int row = 0; row < 10; row++)
    {
        for (int i = 7; i < 9; i++)
        {
            if (arr[row][i] > arr[row][i+1])
            {
                int doi = arr[row][i];
                arr[row][i] = arr[row][i+1];
                arr[row][i+1] = doi;
                if (i == 8 && arr[row][i] < arr[row][i-1]) i = 6;
            }
        }
    }

    // Tim mat ma
    string s = "0000000000";
    int ind;
    for (int row = 0; row < 10; row++)
    {
        ind = 0;
        for (int col = 1; col < 10; col++)
        {
            if (arr[row][col] >= arr[row][ind]) 
            {
                ind = col;
            }
        }
        s[row] = ind + '0';
    }
    return s;
}

string generateListPasswords(string pwd1, string pwd2, string pwd3) {
    // Complete this function to gain point

    string g12 = "0000000000";
    string g13 = g12, g23 = g12, g12g3 = g12, g1g23 = g12, g12g13 = g12;
    string p1, p2, p3;
    
    // g(pwd1,pwd2)
    p1 = pwd1;
    p2 = pwd2;
    for(int i = 0; i < 10; i++)
    {
        g12[i] = p1[i] + p2[i] - '0';
        if (g12[i] > '9') 
        {
            g12[i] -= 10;
            if (i < 9)
            {
                p1[i+1]++;
            }
        }
    }

    // g(pwd1,pwd3)
    p1 = pwd1;
    p3 = pwd3;
    for(int i = 0; i < 10; i++)
    {
        g13[i] = p1[i] + p3[i] - '0';
        if (g13[i] > '9') 
        {
            g13[i] -= 10;
            if (i < 9)
            {
                p1[i+1]++;
            }
        }
    }

    // g(pwd2,pwd3)
    p2 = pwd2;
    p3 = pwd3;
    for(int i = 0; i < 10; i++)
    {
        g23[i] = p2[i] + p3[i] - '0';
        if (g23[i] > '9') 
        {
            g23[i] -= 10;
            if (i < 9)
            {
                p2[i+1]++;
            }
        }
    }

    // g(g(pwd1,pwd2),pwd3)
    string p12 = g12;
    p3 = pwd3;
    for(int i = 0; i < 10; i++)
    {
        g12g3[i] = p12[i] + p3[i] - '0';
        if (g12g3[i] > '9') 
        {
            g12g3[i] -= 10;
            if (i < 9)
            {
                p12[i+1]++;
            }
        }
    }

    // g(pwd1,g(pwd2,pwd3))
    string p23 = g23;
    p1 = pwd1;
    for(int i = 0; i < 10; i++)
    {
        g1g23[i] = p1[i] + p23[i] - '0';
        if (g1g23[i] > '9') 
        {
            g1g23[i] -= 10;
            if (i < 9)
            {
                p1[i+1]++;
            }
        }
    }

    //g(g(pwd1,pwd2),g(pwd1,pwd3))
    string p13 = g13;
    p12 = g12;
    for(int i = 0; i < 10; i++)
    {
        g12g13[i] = p12[i] + p13[i] - '0';
        if (g12g13[i] > '9') 
        {
            g12g13[i] -= 10;
            if (i < 9)
            {
                p12[i+1]++;
            }
        }
    }

    return (pwd1 + ";" + pwd2 + ";" + pwd3 + ";" 
    + g12 + ";" + g13 + ";" + g23 + ";" 
    + g12g3 + ";" + g1g23 + ";" + g12g13);
}

bool chaseTaxi
(
    int arr[100][100],
    string points,
    string moves,
    string & outTimes,
    string & outCatchUps
) 
{
    // Complete this function to gain point

    // Thoi gian di qua từng diem
    int row = 0, col = 0;
    int indShe[1000][3];
    for (int i = 0; i < points.size(); i++)
    {
        if (points[i] >= '0' && points[i] <= '9' && points[i+1] >= '0' && points[i+1] <= '9')
        {
            indShe[row][col] = (points[i] - '0')*10 + (points[i+1] - '0');
            col++;
            i++; 
        }
        else if (points[i] >= '0' && points[i] <= '9')
        {
            indShe[row][col] = points[i] - '0';
            col++;
        }
        if (col == 2)
        {
            if (row == 0) 
            {
                indShe[row][col] = (indShe[0][0] + indShe[0][1])*14;
                row++;
                col = 0;
            }
            else
            {
                indShe[row][col] = indShe[row - 1][col] + (abs(indShe[row - 1][0] - indShe[row][0]) + abs(indShe[row - 1][1] - indShe[row][1]))*14;
                row++;
                col = 0;

            }
        }        
    }

    //cho tat ca o = -9
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            arr[i][j] = -9;
        }
    }

    // Vi tri taxi
    int index = -1;
    int x = 0, y = 0;
    int time = 0;
    arr[0][0] = time;
    for (int i = 0; i < moves.size(); i++)
    {
        switch (moves[i])
        {
            case 'R': 
            {
                if (y < 99) 
                {
                    y++;
                    time += 9;
                }
                break;
            }
            case 'L':
            {
                if (y > 0) 
                {
                    y--;
                    time += 9;
                }
                break;
            }
            case 'U':
            {
                if (x > 0) 
                {
                    x--;
                    time += 9;
                }
                break;
            }
            case 'D':
            {
                if (x < 99) 
                {
                    x++;
                    time += 9;
                }
                break;
            }
        }
        arr[x][y] = time;
    
        for (int j = 0; j < row; j++)
        {
            if (time >= indShe[j][2] && time < indShe[j + 1][2]) 
            {
                if (x == indShe[j][0] && y == indShe[j][1])
                {
                    index = j;
                    i = moves.size();
                }
                break;
            }
        }
    }

    // Xuat outTimes va outCatchUps
    ostringstream doi;
    doi << indShe[0][2];
    outTimes += (doi.str());
    if (index == -1)
    {  
        outCatchUps += "N";
        for (int i =  1; i < row; i++)
        {
            ostringstream doi;
            doi << indShe[i][2];
            outTimes += (";" + doi.str());
            outCatchUps = outCatchUps + ";" + "N";
        }
        return false;
    }
    else if (index == 0)
    {
        outCatchUps += "Y";
        for (int i = 1; i < row; i++)
        {
            outTimes = outTimes + ";" + "-";
            outCatchUps = outCatchUps + ";" + "-";
        }
    }
    else 
    {
        outCatchUps += "N";
        for (int i = 1; i < index; i++)
        {
            ostringstream doi;
            doi << indShe[i][2];
            outTimes += (";" + doi.str());
            outCatchUps = outCatchUps + ";" + "N";
        }
        ostringstream doi;
        doi << indShe[index][2];
        outTimes += (";" + doi.str());
        outCatchUps = outCatchUps + ";" + "Y";
        for (int i = index + 1; i < row; i++)
        {
            outTimes = outTimes + ";" + "-";
            outCatchUps = outCatchUps + ";" + "-";
        }
    }
    return true;
}

string enterLaptop(string tag, string message) {
    // Complete this function to gain point

    ifstream file(tag);
    string s1, s2;
    getline(file,s1);
    s1.replace(0,7,"");
    getline(file,s2);
    int num;
    
    for (int i = 0; i < s2.size(); i++)
    {
        if (s2[i] >= '0' && s2[i] <= '9' && s2[i+1] >= '0' && s2[i+1] <= '9')
        {
            num = (s2[i] - '0')*10 + (s2[i+1] - '0');
            break;
        }
        else if (s2[i] >= '0' && s2[i] <= '9')
        {
            num = s2[i] - '0';
            break;
        }
    }
    string pwdL = "";
    for (int i = 0; i < num; i++)
    {
       pwdL += message;
    }
    pwdL = s1 + ";" + pwdL;
    return pwdL;
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
