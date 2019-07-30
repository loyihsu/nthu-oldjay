// Problem: http://140.114.86.238/problem/11943/
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <map>
#include <cctype>

struct element {
    std::string name;
    std::string formula;
    double mass;
};

int swaps;
int numOfMolecules;

std::map<std::string, double> period;

double calculate(std::string formula);
void quickSort(struct element *list, int low, int high);
int partition(struct element *list, int low, int high);

int main(int argc, const char * argv[]) {
    int numOfGroups, i;
    
    period["H"] = 1;
    period["He"] = 4;
    period["Li"] = 7;
    period["Be"] = 9;
    period["B"] = 11;
    period["C"] = 12;
    period["N"] = 14;
    period["O"] = 16;
    period["F"] = 19;
    period["Ne"] = 20;
    period["Na"] = 23;
    period["Mg"] = 24;
    period["Al"] = 27;
    period["Si"] = 28;
    period["P"] = 31;
    period["S"] = 32;
    period["Cl"] = 35;
    period["Ar"] = 40;
    period["K"] = 39;
    period["Ca"] = 40;
    period["Sc"] = 45;
    period["Ti"] = 48;
    period["V"] = 51;
    period["Cr"] = 52;
    period["Mn"] = 55;
    period["Fe"] = 56;
    period["Co"] = 59;
    period["Ni"] = 59;
    period["Cu"] = 64;
    period["Zn"] = 65;
    period["Ga"] = 70;
    period["Ge"] = 73;
    period["As"] = 75;
    period["Se"] = 79;
    period["Br"] = 80;
    period["Kr"] = 84;
    period["Rb"] = 85;
    period["Sr"] = 88;
    period["Y"] = 89;
    period["Zr"] = 91;
    period["Nb"] = 93;
    period["Mo"] = 96;
    period["Tc"] = 97;
    period["Ru"] = 101;
    period["Rh"] = 103;
    period["Pd"] = 106;
    period["Ag"] = 108;
    period["Cd"] = 112;
    period["In"] = 115;
    period["Sn"] = 119;
    period["Sb"] = 122;
    period["Te"] = 128;
    period["I"] = 127;
    period["Xe"] = 131;
    period["Cs"] = 133;
    period["Ba"] = 137;
    period["La"] = 139;
    period["Ce"] = 140;
    period["Pr"] = 141;
    period["Nd"] = 144;
    period["Pm"] = 145;
    period["Sm"] = 150;
    period["Eu"] = 152;
    period["Gd"] = 157;
    period["Tb"] = 159;
    period["Dy"] = 163;
    period["Ho"] = 165;
    period["Er"] = 167;
    period["Tm"] = 169;
    period["Yb"] = 173;
    period["Lu"] = 175;
    period["Hf"] = 178;
    period["Ta"] = 181;
    period["W"] = 184;
    period["Re"] = 186;
    period["Os"] = 190;
    period["Ir"] = 192;
    period["Pt"] = 195;
    period["Au"] = 197;
    period["Hg"] = 201;
    period["Tl"] = 204;
    period["Pb"] = 207;
    period["Bi"] = 209;
    period["Po"] = 209;
    period["At"] = 210;
    period["Rn"] = 222;
    period["Fr"] = 223;
    period["Ra"] = 226;
    period["Ac"] = 227;
    period["Th"] = 232;
    period["Pa"] = 231;
    period["U"] = 238;
    period["Np"] = 237;
    period["Pu"] = 244;
    period["Am"] = 243;
    period["Cm"] = 247;
    period["Bk"] = 247;
    period["Cf"] = 251;
    period["Es"] = 252;
    period["Fm"] = 257;
    period["Md"] = 258;
    period["No"] = 259;
    period["Lr"] = 262;
    period["Rf"] = 267;
    period["Db"] = 270;
    period["Sg"] = 269;
    period["Bh"] = 270;
    period["Hs"] = 270;
    period["Mt"] = 278;
    period["Ds"] = 281;
    period["Rg"] = 281;
    period["Cn"] = 285;
    period["Nh"] = 286;
    period["Fl"] = 289;
    period["Mc"] = 289;
    period["Lv"] = 293;
    period["Ts"] = 293;
    period["Og"] = 294;
    
    struct element *list;
    
    std::cin >> numOfGroups;
    std::cout << numOfGroups << std::endl;
    
    while (numOfGroups--) {
        swaps = 0;
        std::cin >> numOfMolecules;
        list = new struct element [numOfMolecules];
        
        for (i = 0; i < numOfMolecules; i++) {
            std::cin >> list[i].name;
            std::cin >> list[i].formula;
            std::cin >> list[i].mass;
        }
        
        for (i = 0; i < numOfMolecules; i++)
           if (!list[i].mass)
               list[i].mass = calculate(list[i].formula);
        
        quickSort(list, 0, numOfMolecules-1);
        
        std::cout << numOfMolecules << std::endl;
        
        for (i = 0; i < numOfMolecules; i++) {
            std::cout << std::resetiosflags(std::ios::adjustfield);
            std::cout << std::setiosflags(std::ios::left);
            
            std::cout << std::setw(40) << list[i].name << std::setw(25) << list[i].formula;
            
            std::cout << std::resetiosflags(std::ios::adjustfield);
            std::cout << std::setiosflags(std::ios::right);
            
            std::cout << std::setw(10) << std::setprecision (2) << std::fixed << list[i].mass << std::endl;
        }
        
        std::cout << swaps << " swaps during qsort" << std::endl;
        
        delete[] list;
    }

    return 0;
}

void swap(struct element *list, int i, int j) {
    if (i != j) {
        struct element temp;
        
        temp.name = list[i].name;
        temp.formula = list[i].formula;
        temp.mass = list[i].mass;
        
        list[i].name = list[j].name;
        list[i].formula = list[j].formula;
        list[i].mass = list[j].mass;
        
        list[j].name = temp.name;
        list[j].formula = temp.formula;
        list[j].mass = temp.mass;
        
        swaps++;
    }
}

void quickSort(struct element *list, int low, int high) {
    if (low < high){
        double pivot = list[low].mass;
        int i = low;
        int j = high;
        
        while (i != j){
            while (list[j].mass >= pivot && i < j)
                j--;
            while (list[i].mass <= pivot && i < j)
                i++;
            if (i < j) swap(list, i, j);
        }
        
        swap(list, low, i);
        
        quickSort(list, low, i-1);
        quickSort(list, i+1, high);
    }
}

double calculate(std::string formula) {
    int i=0, j=0, count_open, count_close;
    double output=0, newElement=0;
    std::string temp;
    
    int for_length = (int)formula.length();
    
    while (i < for_length) {
        if (formula[i] == '(') {
            count_open = 1;
            count_close = 0;
            i++;
            j = i;
            
            while (1) {
                if (formula[j] == '(') {
                    count_open++;
                } else if (formula[j] == ')') {
                    if (count_open == count_close+1)
                        break;
                    else {
                        count_close++;
                    }
                }
                j++;
            }
            
            std::string substring = formula.substr(i, j-i);
            
            newElement = calculate(substring);
            
            i = j;
            
            temp.clear();
            
            if (isdigit(formula[i+1])) {
                while (isdigit(formula[++i]))
                    temp.push_back(formula[i]);
                
                int number;
                sscanf(temp.c_str(), "%d", &number);
                newElement *= number;
            } else {
                i++;
            }
            
        } else if (formula[i] == '[') {
            count_open = 1;
            count_close = 0;
            
            i++;
            j = i;
            
            while (1) {
                if (formula[j] == '[') {
                    count_open++;
                } else if (formula[j] == ']') {
                    if (count_open == count_close+1)
                        break;
                    else
                        count_close++;
                }
                j++;
            }
            
            std::string substring = formula.substr(i, j-i);
            
            newElement = calculate(substring);
            
            i = j;
            
            temp.clear();
            
            if (isdigit(formula[i+1])) {
                while (isdigit(formula[++i]))
                    temp.push_back(formula[i]);
                
                int number;
                sscanf(temp.c_str(), "%d", &number);
                newElement *= number;
            } else {
                i++;
            }
            
        } else if (isupper(formula[i])) {
            temp.clear();
            temp.push_back(formula[i]);
            
            if (!islower(formula[i+1]) && !isdigit(formula[i+1])) {
                newElement = period[temp];
                i++;
            } else {
                if (islower(formula[i+1])) {
                    while (islower(formula[++i]))
                        temp.push_back(formula[i]);
                } else {
                    i++;
                }
                
                newElement = period[temp];
                
                temp.clear();
                
                if (isdigit(formula[i])) {
                    while (isdigit(formula[i])) {
                        temp.push_back(formula[i]);
                        i++;
                    }
                    int number;
                    sscanf(temp.c_str(), "%d", &number);
                    newElement *= number;
                }
            }
        }
        output += newElement;
    }
     
    return output;
}
