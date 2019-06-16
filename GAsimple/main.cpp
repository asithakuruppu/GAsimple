//
//  main.cpp
//  GAsimple
//
//  Created by Shamil Asitha Kuruppu on 6/10/19.
//  Copyright © 2019 Ina via dahti sa. All rights reserved.
//

#include <iostream>
#include "Chromosome.cpp"

using namespace std;
int main(int argc, const char * argv[]) {
    int fitness[] = {0, 2, 4, 8, 16, 32, 64, 128, 256, 512};
//    Chromosome(10, 2, fitness);
    Population population(100, 10, 2, fitness);
    population.printPopulation();
    cout << "  \n";
    Chromosome bestChild = population.mateTop(fitness);
    cout << "best child \n";
    bestChild.print();
    return 0;

}
