#include "GeneticAlgorithm.hpp"
#include <iostream>
#include <stdlib.h>
#include<math.h>
using namespace std;

GeneticAlgorithm::GeneticAlgorithm(AdjacencyList* adjl) {
    list = adjl->getList();
    currentCost = 0;
    new_population = nullptr;
    descendants = nullptr;
    sizeListVertex = adjl->getLenght();
    rowsP = 20; 
    columnsP = 10;
    

    population = (int **)malloc(sizeof(int *) * rowsP);
    for (int i = 0; i < rowsP; i++) {
        population[i] = (int*) malloc (sizeof(int) * columnsP);
        selectInitialPopulation(population[i], columnsP, sizeListVertex);
    }

    for(int i = 0; i < adjl->getLenght(); i++) {
        if(list[i].getContent() == '>') {
           begin = &list[i];
           break;
        }
    }
    for(int i = 0; i < adjl->getLenght(); i++) {
        if(list[i].getContent() == 'x') {
            end = &list[i];
            break;
        }
    }
    begin->print();
    end->print();


    // =====================================
    //  PRINTING INITIAL POPULATION
    // =====================================
    printf("POPULATION\n");
     //for (int i = 0; i < rowsP; i++) {
       //  for (int j = 0; j < columnsP; j++) {
         //   cout<< "(" << list[population[i][j]].getCoordinates()[0] << ", " << list[population[i][j]].getCoordinates()[1] << ")";
         //}
         //putchar('\n');
     //}

    for (int i = 0; i < 20; i++) {
         for (int j = 0; j < 10; j++) {
             printf("%5d", population[i][j]);
         }
      putchar('\n');
    }

     //fitness();
     start();


}


GeneticAlgorithm::~GeneticAlgorithm(){
    free_newPopulation();
    free_Population();
}

double* GeneticAlgorithm::fitness() {
    printf("ENTROOOOOOOOU NA FUNCAO FIT \n");
    double  add, x, y, ideal = 0,value = INFINITY, total, fit;
    double* costs; // Vetor que irá armazenar o custo de cada linha. Será usado no INsertion sort
    costs = (double*)malloc(sizeof(double) * (rowsP));
    int* pointer;
    Coordinate* start;
    Coordinate* exit;
    int index;

    start = begin -> getCoordinates();
    exit = end -> getCoordinates();
    printf("START: (%d ,%d) EXIT: (%d,%d)",start[0],start[1],exit[0],exit[1]);

    x = abs(start[0] - exit[0]);
    y = abs(start[1] -exit[1]);
    printf("X: %lf Y: %lf \n",x,y);

    add = pow(x,2) + pow(y,2);
    printf(" ADD: %lf\n",add);
    ideal = sqrt(add);
    printf("IDEAL : %lf\n",ideal);

    for (int i = 0; i < rowsP; i++) {

        total = 0;

        for (int j = 0; j < columnsP; j++) {
            index = population[i][j];
            list[index].setGCost( abs(list[index].getCoordinates()[0] - begin->getCoordinates()[0]) + abs(list[index].getCoordinates()[1] - begin->getCoordinates()[1]));
            list[index].setHCost( abs(list[index].getCoordinates()[0] - end->getCoordinates()[0]) + abs(list[index].getCoordinates()[1] - end->getCoordinates()[1]));
            list[index].setFCost(list[index].getGCost() + list[index].getHCost());
            total += list[index].getFCost();        
        }
        costs[i] = (ideal/total);
        printf("COST: %lf\n",costs[i]);
    }

   // chama Insertion_sort para ordenar vetor de custos e salvar outro vetor, que terá como conteúdo as linhas ordenadas por ordem de custo 

   // pointer = insertionSort(costs); // Insertion sort retornou um vetor de inteiros , que contém as linhas ordenadas por (ideal/custo), ou seja, os valores armazenados no vetor correspondem aos índices das linhas 

    //printf("pointeeeeeeeeeeeeeeer: %d\n",pointer[0]);
    //for(int i =0; i < rowsP; i++)
    //{
      //  printf("FOR TESTE APOS POINTER RECEBER AUX\n");
        //printf("%d\n",pointer[i]);
    //}
    //selectAfterFit(pointer);

    //crossover();

   
    return  costs;
}

void GeneticAlgorithm::selectAfterFit(int *vRows)
{
    printf("ENTROOU FUNCAO SELECT AFTER FIT\n");
    // vRows irá receber o  pointer , que é retornado na função fit
    //int new_population[rowsP/2][columnsP]; // Nova população 
    int index;

    new_population = (int **)malloc(sizeof(int *) * (rowsP/2));
    for (int i = 0; i < (rowsP/2); i++) 
    {
        printf("primeiro FOOOOOR \n");

        new_population[i] = (int*) malloc (sizeof(int) * columnsP);
    }

    for(int i =0; i < (rowsP/2); i++)
    {
        printf("FOR TESTE do SELECT AFTER FIT\n");
        printf("%d\n",vRows[i]);
    }

    printf("rowsp/2: %d   columns: %d \n",(rowsP/2),columnsP);
    for(int i = 0 ; i < (rowsP/2); i++)
    {
        for(int j = 0; j < columnsP; j++)
        {
            printf("segundo FOOOOOOR\n");
            index = vRows[i];
            printf(" INDEX: %d\n",index);
            new_population[i][j] = population[index][j]; // Copiando caminhos(linhas) com menores custos.
            printf("NEW POPULATION : %d \n",new_population[i][j]);
        
        }
    }

    printf("OUTRO FOOOOOOR\n");
   for(int i = 0 ; i < (rowsP/2); i++)
    {   
        for(int j = 0; j < columnsP; j++)
        {
           
           // new_population[i][j] = population[index][j]; // Copiando caminhos(linhas) com menores custos.
            printf("%5d ",new_population[i][j]);
        
        }
        printf("\n");
    }
    // return new_population; // retorna nova matriz de população , somete com as 10 linhas com menor custo, fazer o population receber essa nova população
    
}

void GeneticAlgorithm::crossover()
{
    // crossover vai retornar apenas um descendente, deve ser chamado várias vezes para obter 10 descendentes
    int j, k, row1, row2,column, ind;
    

    descendants = (int **)malloc(sizeof(int *) * (rowsP/2));
    for (int i = 0; i < (rowsP/2); i++) 
    {
        descendants[i] = (int*) malloc (sizeof(int) * columnsP);
    }

    for( int i = 0; i < (rowsP/2); i++) // rowsP/2 pode ser mudado para outro valor , depende de quantos forem selecionados para  anova população
    {
        ind = 1;

        while(ind == 1)
        {
            //incicializar as funções rand com a hora
            row1 = rand() % 10;
            row2 = rand() % 10; 
            column = rand() % 10; // garante aleatoriedade na posição do crossover;
            if( row1 != row2 && column != 0 && column!= 9) // Verifica se os dois números não são iguais, deve-se fazer ainda uma verificação de pares, ou seja, verificar se não repete crossover entre pares de linhas já usados.
            {
                ind = 0;
            } 
            printf("row1: %d, row2: %d, column: %d \n",row1,row2,column);
        }
    
        for ( j = 0, k = 0; k < columnsP;  k++, j++)
        {
            if(k <= column)
            {
                descendants[i][j] = new_population[row1][j];
            }
            else
            {
                descendants[i][j] = new_population[row2][j];
            }
        
        }
    }
    
    printf("DESCENDANTS:\n");
     for(int i = 0 ; i < (rowsP/2); i++)
    {   
        for(int j = 0; j < columnsP; j++)
        {
            printf(" %5d ",descendants[i][j]);
        }
        printf("\n");
    }

}



vector<Vertex *> GeneticAlgorithm::lottery(vector<vector<Vertex*>> tracks) {

}

void GeneticAlgorithm::selectInitialPopulation(int *array, int lenght, int avaliablePopulation) {
    // srand(time_t(NULL));
    int i = 0;
    int j = 0;
    bool alreadyHas = false;
    while(i < lenght) {
        cout << "choosing population..." << endl;
        alreadyHas = false;
        int position = rand() % avaliablePopulation;
        for (j = 0; j < i; j++) {
            if(array[j] == position) {
                alreadyHas = true;
            }
        }
        if (!alreadyHas) {
            array[i] = position;
            i++;
        }
    }
}

int* GeneticAlgorithm::insertionSort(double *vCosts) 
{ 
    printf("insertion\n");
    int j, row;
    double cost_value;
    int* aux ; // vetor para armezanar os indices das linhas, que serão ordenados também de acordo com o custo de cada linha

    aux = (int *)malloc(sizeof(int *) * rowsP);
    
    for(int i = 0; i < rowsP; i++)
    {
        aux[i] = i;
    }

    for(int i = 0; i < rowsP; i++)
    {
        j = i;
        while(j > 0 && (vCosts[j - 1] < vCosts[j]) )
        {
            printf("WHILE DO INSERTION SORT\n");
            row = aux[j];
            cost_value = vCosts[j];
            printf(" cost_value: %lf",cost_value);
            vCosts[j] = vCosts[j - 1];
            printf(" costs[j]: %lf ",vCosts[j]);
            aux[j] = aux[j - 1];
            vCosts[j - 1] = cost_value;
            printf("costs[j-1]: %lf ",vCosts[j - 1]);
            aux[j - 1] = row;
            j--;
        }
    }

    printf("COSTS AFTER SORT\n");

    for(int i = 0; i < rowsP; i++)
    {   printf("FOR TESTE\n");
        printf(" %lf ",vCosts[i]);
    }

    for(int i =0; i < rowsP; i++)
    {
        printf("FOR TESTE INDICESLINHAS\n");
        printf("%d\n",aux[i]);
    }

    return aux;
} 

void GeneticAlgorithm::mutation()
{
    int ind_vertex,ind_column, ind_row;

    //  Para fazertaxa de 0.1 ou 0.001 bastaria chamar,respectivamente, a função mutation após 10 ou 100 loops do ga;
    
    ind_column = rand() % 10; // indica qual posição irá acontecer a mutação
    ind_row = rand() % 10; 
    ind_vertex = rand() % sizeListVertex;

    printf("ROW: %d COLUMN: %d  VERTEX: %d \n",ind_row,ind_column,ind_vertex);
       
    
    descendants[ind_row][ind_column] = ind_vertex;
    printf("NEW POPULATION MUTATION: %d\n",descendants[ind_row][ind_column]);
         
    printf("DESCENDANTS AGAIN :\n");
     for(int i = 0 ; i < (rowsP/2); i++)
    {   
        for(int j = 0; j < columnsP; j++)
        {
            printf(" %5d ",descendants[i][j]);
        }
        printf("\n");
    }
    

}

void GeneticAlgorithm::start()
{
    double *pointer_costs;
    int* pointer;
    double fit = 10;

    //while(fit < 0.8){

    pointer_costs = fitness();
    pointer = insertionSort(pointer_costs);
    selectAfterFit(pointer);
    crossover();
    fit = pointer_costs[0];
    printf("FIT: %lf\n",fit);
    mutation();
    //free_Population();
    //population = new_population;
    //free_newPopulation();
    //}

}

void GeneticAlgorithm::free_newPopulation()
{
    for(int i = 0; i < (rowsP/2) ; i++)
    {
        free(new_population[i]);
    }
    free(new_population);
}

void GeneticAlgorithm::free_Population()
{
    for(int i = 0; i < rowsP ; i++)
    {
        free(population[i]);
    }
    free(population);
}


// para fazer o loop poderia substituir a população inicial por descendentes que surgem devido ao crossover que será entre o melhor individuo e outros aleatórios
//mecanismos de substituição Rd, R1,etc
