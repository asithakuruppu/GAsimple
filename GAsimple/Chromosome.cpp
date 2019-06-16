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
#include <list>

using namespace std;
class Chromosome{
private: int length;
public: int gene [10];
public: int dimention;
public: int geneNum;
public: int fitness;
public: Chromosome(int length, int dimention, int fitnessArray[]){
    this->length = length;
    this->dimention = dimention;
    int fitness = 0;

    for(int i = 0; i < length; i++){
        int random = this->random() % dimention;
        this->gene[i] = random;
        fitness += fitnessArray[i] * this->gene[i];
        };
    this->fitness = fitness;

};

public: Chromosome mate(Chromosome x, int fitnessArray[]){
    Chromosome z(x.length, x.dimention, fitnessArray);
    z.fitness = 0;
    for(int i = 0; i < x.length; i++){
        int random = this->random() % 2;
        z.gene[i] = random ? this->gene[i] : x.gene[i];
        z.fitness += fitnessArray[i];
    };
    return z;

};
public: void print(){
    for(int i = 0; i < this->length; i++){
        cout<< this-> gene[i] << " ";
    }
    cout  << this->fitness << "\n";
};
private: int random(){
    random_device rd;
    uniform_int_distribution<int> dist(0, 100);
    return dist(rd);
}
};

class Population{
private: int size;
private: list<Chromosome> pop;
private: int fitnessArray[10];
public: Population(int populationSize, int geneLegnth, int dimention){
    this->size = populationSize;
    for(int i = 0; i < size; i++){
        Chromosome a(geneLegnth, dimention, this->fitnessArray);
        pop.push_back(a);
    }
    pop.sort(this->sortChromosome);
}

public: Population(int populationSize, int geneLegnth, int dimention, int fitnessArray[]){
    this->size = populationSize;
    for(int i = 0; i < size; i++){
        Chromosome a(geneLegnth, dimention, fitnessArray);
        pop.push_back(a);
    }
    pop.sort(this->sortChromosome);
}
private: bool static sortChromosome(const Chromosome& a, const Chromosome& b){
    return a.fitness < b.fitness;
}
public: void printPopulation(){
    list<Chromosome> population = this->pop;

    cout << "Population " << population.size() << "\n";
    for(list<Chromosome>::iterator i = population.begin(); i != population.end(); ++i ) {
        i->print();

    }
}
public: Chromosome mateTop(int * fitnessArray){
    Chromosome topA = this->pop.back();
    topA.print();
    this->pop.pop_back();
    Chromosome topB = this->pop.back();
    topB.print();
    return topA.mate(topB, fitnessArray);
}
public:

};
