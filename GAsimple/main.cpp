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
    std::cout << "Hello, World!\n";
    Chromosome c(10, 10);
    Chromosome d(10, 10);
    Chromosome e = c.mate(d);
    c.print();
    d.print();
    e.print();
    return 0;

}
