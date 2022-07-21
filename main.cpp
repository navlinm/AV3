#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include "Interpreter.h"
#include "FiguraGeometrica.h"
#include "Sculptor.h"
using namespace std;

int main(void){
    Sculptor *figura; // cria um ponteiro para sculptor
    Interpreter it; // um objeto da classe interpretador
    vector<FiguraGeometrica*> figs; // um vetor de ponteiros para a classe figura geometrica
    figs = it.analise("C:\Users\Navli\Documents\AV3\xboxs.txt"); //it.analise retorna um vetor para a classe figura geometrica, então basicamente duplica o vetor
    figura = new Sculptor(it.getDX(), it.getDY(), it.getDZ()); // aqui ele aloca um espaço na memoria do tamanho das dimensões necessárias
    for(int i = 0; i< (int) figs.size(); i++){ // percorrer todos os espaços de figs
        figs[i]->draw(*figura); // ele irá começar a desenhar tudo o que foi alocado em figs, utilizando o metodo draw
    }
    figura->writeOFF("C:\Users\Navli\Documents\AV3\xboxs.off"); // aqui escreve no arquivo off
    for(int i = 0; i < (int) figs.size(); i++){ //aqui libera tudo que foi alocado em figs
        delete figs[i];
    }
    delete figura; // aqui libera o que foi alocado em figura
    return 0;
}
