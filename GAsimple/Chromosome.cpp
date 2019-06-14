//
//  Chromosome.cpp
//  GAsimple
//
//  Created by Shamil Asitha Kuruppu on 6/14/19.
//  Copyright © 2019 Ina via dahti sa. All rights reserved.
//

#include "Chromosome.hpp"
#include <stdlib.h>
#include <iostream>
#include <random>
using namespace std;
class Chromosome{
private: int length;
public: int gene [10];
public: int dimention;
public: int geneNum;
public: Chromosome(int length, int dimention){
    this->length = length;
    this->dimention = dimention;

    for(int i = 0; i < length; i++){
        int random = this->random() % dimention;
        this->gene[i] = random;
    };
}

public: Chromosome mate(Chromosome x){
    Chromosome z(x.length, x.dimention);

    for(int i = 0; i < x.length; i++){
        int random = this->random() % 2;
        z.gene[i] = random ? this->gene[i] : x.gene[i];
    };
    return z;

};
public: void print(){
    for(int i = 0; i < this->length; i++){
        cout<< this-> gene[i];
    }
    cout << "\n";
}
private: int random(){
    random_device rd;
    uniform_int_distribution<int> dist(0, 100);
    return dist(rd);
}
};
