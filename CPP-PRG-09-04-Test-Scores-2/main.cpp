//
//  main.cpp
//  CPP-PRG-09-04-Test-Scores-2
//
//  Created by Keith Smith on 10/29/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Modify the program of Programming Challenge 2 (Test Scores #1) to allow the user
//  to enter name-score pairs. For each student taking a test, the user types the student's
//  name followed by the student's integer test score. Modify the sorting function so it
//  takes an array holding the student names, and an array holding the student test scores.
//  When the sorted list of scores is displayed, each student's name should be displayed
//  along with his or her score. In stepping through the arrays, use pointers rather than
// array subscripts

#include <iostream>

using namespace std;

int getStudentsTotal();
void enterStudentInformation(string *, float *, int);
void sortArrays(string *, float *, int);
void swapFunction(float *, float *);
void swapFunction(string *, string *);
void displaySortedArrays(string *, float *, int);

int main()
{
    string *strStudentNames = nullptr;
    
    float *fltStudentScores = nullptr;
    
    int intStudentsTotal;
    
    intStudentsTotal = getStudentsTotal();
    
    strStudentNames = new string[intStudentsTotal];
    fltStudentScores = new float[intStudentsTotal];
    
    enterStudentInformation(strStudentNames, fltStudentScores, intStudentsTotal);
    
    sortArrays(strStudentNames, fltStudentScores, intStudentsTotal);
    
    displaySortedArrays(strStudentNames, fltStudentScores, intStudentsTotal);
}

int getStudentsTotal()
{
    int intStudents;
    
    cout << "Please enter the number of students in the class: ";
    cin >> intStudents;
    while(!cin || intStudents < 1 || intStudents > 30)
    {
        cout << "Please enter a number between 1 and 30: ";
        cin.clear();
        cin.ignore();
        cin >> intStudents;
    }
    
    return intStudents;
}

void enterStudentInformation(string *strArrNames, float *fltArrScores, int intStudents)
{
    for(int i = 0 ; i < intStudents ; i++)
    {
        cout << "Enter student #" << (i + 1) << "\'s name: ";
        cin >> *(strArrNames + i);
        
        cout << "Enter " << *(strArrNames + i) << "\'s score: ";
        cin >> *(fltArrScores + i);
        while(!*(fltArrScores + i) || *(fltArrScores + i) < 0 || *(fltArrScores + i) > 100)
        {
            cout << "Enter a test score between 0 and 100: ";
            cin.clear();
            cin.ignore();
            cin >> *(fltArrScores + i);
        }
    }
}

void sortArrays(string *strArrNames, float *fltArrScores, int intStudents)
{
    int intStart;
    int intMinIndex;
    
    float *fltMinElement;
    
    for(intStart = 0 ; intStart < (intStudents - 1) ; intStart++)
    {
        intMinIndex = intStart;
        fltMinElement = &fltArrScores[intStart];
        
        for(int index = (intStart + 1) ; index < intStudents ; index++)
        {
            if(fltArrScores[index] < *fltMinElement)
            {
                fltMinElement = &fltArrScores[index];
                intMinIndex = index;
            }
        }
        swapFunction(&fltArrScores[intMinIndex], &fltArrScores[intStart]);
        swapFunction(&strArrNames[intMinIndex], &strArrNames[intStart]);
    }
}

void swapFunction(float *fltA, float *fltB)
{
    float *fltTemp = nullptr;
    
    fltTemp = fltA;
    fltA = fltB;
    fltB = fltTemp;
}

void swapFunction(string *strA, string *strB)
{
    string *strTemp = nullptr;
    
    strTemp = strA;
    strA = strB;
    strB = strTemp;
}

void displaySortedArrays(string *strArrNames, float *fltArrScores, int intStudents)
{
    cout << "Here are the student\'s scores sorted from highest to lowest:\n";
    
    for(int i = 0 ; i < intStudents ; i++)
    {
        cout << *(strArrNames + i) << "\t\t" << *(fltArrScores +i) << endl;;
    }
}
