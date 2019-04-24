#include "GeneticAlgorithm.hpp"
#include <iostream>
#include <stdlib.h>
#include<math.h>
#include<time.h>
using namespace std;

GeneticAlgorithm::GeneticAlgorithm(AdjacencyList* adjl) {
    srand(time(NULL));
    list = adjl->getList();
    currentCost = 0;
    new_population = nullptr;
    descendants = nullptr;
    best_walk = nullptr;
    //pointer_costs = nullptr;
    sizeListVertex = adjl->getLenght();
    rowsP = 20; 
    columnsP = 7;
    


    for(int i = 0; i < adjl->getLenght(); i++) {
        if(list[i].getContent() == '>') {
           begin = &list[i];
           ibegin = i;
           break;
        }
    }
    for(int i = 0; i < adjl->getLenght(); i++) {
        if(list[i].getContent() == 'x') {
            end = &list[i];
            iend = i;
            break;
        }
    }
    population = (int **)malloc(sizeof(int *) * rowsP);
    for (int i = 0; i < rowsP; i++) {
        population[i] = (int*) malloc (sizeof(int) * columnsP);
        selectInitialPopulation(population[i], columnsP, sizeListVertex);
    }
    begin->print();
    end->print();
    printf("\n%d", ibegin);
    printf("\n%d", iend);


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

    for (int i = 0; i < rowsP; i++) 
    {
         for (int j = 0; j < columnsP; j++) {
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
    free_Descendants();
}

double* GeneticAlgorithm::fitness(int **population_matrix) {
   // printf("ENTROOOOOOOOU NA FUNCAO FIT \n");
    double  add, x, y, ideal = 0,value = INFINITY, total, fit;
    double* costs; // Vetor que irá armazenar o custo de cada linha. Será usado no INsertion sort
    costs = (double*)malloc(sizeof(double) * rowsP);
    int* pointer;
    Coordinate* start;
    Coordinate* exit;
    int index,next_index;

    start = begin -> getCoordinates();
    exit = end -> getCoordinates();
  //  printf("START: (%d ,%d) EXIT: (%d,%d)",start[0],start[1],exit[0],exit[1]);

    x = abs(start[0] - exit[0]);
    y = abs(start[1] -exit[1]);
    printf("X: %lf Y: %lf \n",x,y);

    add = pow(x,2) + pow(y,2);
   // printf(" ADD: %lf\n",add);
    ideal = sqrt(add);
    //printf("IDEAL : %lf\n",ideal);

    for (int i = 0; i < rowsP; i++) {

        total = 0;

        for (int j = 0; j < (columnsP - 1); j++) {
            index = population_matrix[i][j];
            next_index = population_matrix[i][j + 1];
            total += (abs(list[index].getCoordinates()[0] - list[next_index].getCoordinates()[0])+ abs(list[index].getCoordinates()[1] - list[next_index].getCoordinates()[1]));
           // if(j == (columnsP - 2))
            //{
              //  total+= (abs(list[next_index].getCoordinates()[0] - end -> getCoordinates()[0])+ abs(list[next_index].getCoordinates()[1] - end -> getCoordinates()[1]));
            //}
                  
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
    //printf("ENTROOU FUNCAO SELECT AFTER FIT\n");
    // vRows irá receber o  pointer , que é retornado na função fit
    //int new_population[rowsP/2][columnsP]; // Nova população 
    int index;

    new_population = (int **)malloc(sizeof(int *) * rowsP);

    for(int i = 0; i < rowsP; i++) 
    {
        //printf("primeiro FOOOOOR \n");

        new_population[i] = (int*) malloc (sizeof(int) * columnsP);
    }

    for(int i = 0; i < rowsP; i++)
    {
       // printf("FOR TESTE do SELECT AFTER FIT\n");
       // printf("%d\n",vRows[i]);
    }

    //printf("rowsp/2: %d   columns: %d \n",rowsP,columnsP);
    for(int i = 0 ; i < rowsP; i++)
    {
        for(int j = 0; j < columnsP; j++)
        {
            //printf("segundo FOOOOOOR\n");
            index = vRows[i];
            //printf(" INDEX: %d\n",index);
            new_population[i][j] = population[index][j]; // Copiando caminhos(linhas) com melhores custos.
            //printf("NEW POPULATION : %d \n",new_population[i][j]);
        
        }
    }

   // printf("OUTRO FOOOOOOR\n");
   for(int i = 0 ; i < rowsP; i++)
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

void GeneticAlgorithm::crossover(double *pointer_costs)
{
    // crossover vai retornar apenas um descendente, deve ser chamado várias vezes para obter 10 descendentes
    int j, k, row1, row2,column, ind;
    

    descendants = (int **)malloc(sizeof(int *) * rowsP);
    for (int i = 0; i < rowsP; i++) 
    {
        descendants[i] = (int*) malloc (sizeof(int) * columnsP);
    }

    for( int i = 0; i < rowsP; i++) // rowsP/2 pode ser mudado para outro valor , depende de quantos forem selecionados para  anova população
    {
        ind = 1;

        //srand(time(NULL));
        while(ind == 1)
        {
            
            //incicializar as funções rand com a hora
            row1 = rand() % rowsP;
            //printf("ROOOOOOOOOOOOOOOW1: %d\n",row1);
            row2 = rand() % rowsP; 
           // printf("ROOOOOOOOOOOOOOOOOW2: %d\n", row2);
            column = rand() % columnsP; // garante aleatoriedade na posição do crossover;
            if( row1 != row2 && column != 0 && column!= columnsP - 1) // Verifica se os dois números não são iguais, deve-se fazer ainda uma verificação de pares, ou seja, verificar se não repete crossover entre pares de linhas já usados.
            {
                ind = 0;
            } 
           // printf("row1: %d, row2: %d, column: %d \n",row1,row2,column);
        }
        descendants[i][0] = ibegin;
        descendants[i][columnsP - 1] = iend;
        for ( j = 1, k = 1; k < columnsP -1;  k++, j++)
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
        for(int h = 0; h < columnsP - 1; h++)
        {
            if(descendants[i][h] == descendants[i][h + 1])//para não repetir alelos próximos
            {
                i--;
                h = columnsP;
            }
        }
    }
    
    printf("DESCENDANTS:\n");
     for(int i = 0 ; i < rowsP; i++)
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
    int i = 0;
    int j = 0;
    bool alreadyHas = false;
    while(i < lenght - 1) {
        
       // cout << "choosing population..." << endl;
        alreadyHas = false;
        int position = rand() % avaliablePopulation;
        for (j = 1; j < i; j++) {
            array[0] = ibegin;
            array[lenght - 1] = iend;
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

int* GeneticAlgorithm::insertionSort(double *pointer_costs) 
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
        while(j > 0 && (pointer_costs[j - 1] < pointer_costs[j]) )
        {
           // printf("WHILE DO INSERTION SORT\n");
            row = aux[j];
            cost_value = pointer_costs[j];
            //printf(" cost_value: %lf",cost_value);
            pointer_costs[j] = pointer_costs[j - 1];
           // printf(" costs[j]: %lf ",pointer_costs[j]);
            aux[j] = aux[j - 1];
            pointer_costs[j - 1] = cost_value;
            //printf("costs[j-1]: %lf ",pointer_costs[j - 1]);
            aux[j - 1] = row;
            j--;
        }
    }

    printf("COSTS AFTER SORT\n");

    for(int i = 0; i < rowsP; i++)
    {  // printf("FOR TESTE\n");
        printf(" %lf ",pointer_costs[i]);
    }

    for(int i =0; i < rowsP; i++)
    {
       // printf("FOR TESTE INDICESLINHAS\n");
        printf("%d\n",aux[i]);
    }

    return aux;
} 

void GeneticAlgorithm::mutation()
{
    int ind_vertex,ind_column, ind_row;

    //  Para fazertaxa de 0.1 ou 0.001 bastaria chamar,respectivamente, a função mutation após 10 ou 100 loops do ga;
    //srand(time(NULL));
    ind_column = rand() % columnsP; // indica qual posição irá acontecer a mutação
    ind_row = rand() % rowsP; 
    ind_vertex = rand() % sizeListVertex;

   // printf("ROW: %d COLUMN: %d  VERTEX: %d \n",ind_row,ind_column,ind_vertex);
       
    
    descendants[ind_row][ind_column] = ind_vertex;
   // printf("NEW POPULATION MUTATION: %d\n",descendants[ind_row][ind_column]);
         
    printf("DESCENDANTS AGAIN :\n");
     for(int i = 0 ; i < rowsP; i++)
    {   
        for(int j = 0; j < columnsP; j++)
        {
            printf(" %5d ",descendants[i][j]);
        }
        printf("\n");
    }
    

}

int  GeneticAlgorithm::roulette_weight(double *pointer_costs)
{
    int counter = 0, number, index;
    double value, aux;
    double* pointer;
    // srand(time_t(NULL));


    pointer = (double*)malloc(sizeof(double)*rowsP);

    pointer[0] = pointer_costs[0] * 100;
    for(int i= 1; i < rowsP; i++)
    {

        aux = (pointer_costs[i] * 100);
       // printf("VALUEEEEE WEIGHT: %lf\n",aux);
        pointer[i] = pointer[i -1] + aux;
       // printf("VALUE POINTER[I] %lf\n",pointer[i]);
        
    }
    index = pointer[rowsP - 1];
    //printf("CASTING %d\n",index);

    number = rand() % index;
   // printf("NUMBER AFTER RAND: %d\n",number);
    if(number < pointer[0])
    {
        return 0;
    }
    for(int i = 1; i < rowsP; i++)
    {
        if(pointer[i - 1] <= number && number < pointer[i])
        {
            //printf("pointer[i - 1]: %lf  pointer[i]: %lf\n",pointer[i - 1], pointer[i]);
            return i;
        }
    }

}

void  GeneticAlgorithm::build_population(double *pointer_costs1,double *pointer_costs2)
{
  int** population_aux;
  int row;

  population_aux = (int**)malloc(sizeof(int*)*rowsP);
  for(int i = 0; i < rowsP; i++)
  {
      population_aux[i] = (int*)malloc(sizeof(int)*columnsP);
  }  


  //srand(time(NULL));
  for(int i = 0; i < rowsP; i++)
  {
      
    for(int j = 0; j < columnsP; j++)
    {
        if(i < (rowsP/2))
        {
            row = rand()%rowsP;// recebe vetor de custos da descendants
            population_aux[i][j] = descendants[row][j];

        }
        else
        {
            row = roulette_weight(pointer_costs1);
            population_aux[i][j] = new_population[row][j];
        }
        
    }
      
  }
  
  printf("NEW POPULATION BUILDED: \n");
  for(int i = 0; i < rowsP; i++)
  { 
    for(int j = 0; j < columnsP; j++)
    {
        population[i][j] = population_aux[i][j];
        printf("%5d",population[i][j]);  
    }
    printf("\n");
  }
}

void GeneticAlgorithm::start()
{
    double* pointerCosts;
    double* pointerCostsNew;
    int* pointer;
    int* pointerNew;
    double fit = 0;
    int aux, counter = 0,i = 0,index;

    best_walk = (int*)malloc(sizeof(int)*columnsP);

  while(fit < 0.7){
    
    //srand(time(NULL)*i);
    i++;    
    
    pointerCosts = fitness(population);
    pointer = insertionSort(pointerCosts);
    selectAfterFit(pointer);
    fit = pointerCosts[0];
    if(fit >= 0.7)
    {
        index = pointer[0];
        printf("MELHOR CAMINHOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO:\n");
        for(int j = 0; j < columnsP; j++)
        {
            best_walk[j] = new_population[index][j];
            printf("%5d",best_walk[j]);
        }
        printf(" \n");
    }
    crossover(pointerCosts);
    mutation();
    aux = roulette_weight(pointerCosts);
    //printf("AFTER ROULETTE: %d\n",aux);

    pointerCostsNew = fitness(descendants);
    pointerNew = insertionSort(pointerCostsNew);
    selectAfterFit(pointerNew);
    build_population(pointerCosts,pointerCostsNew);
     
   }
   

}

void GeneticAlgorithm::free_newPopulation()
{
    for(int i = 0; i < rowsP ; i++)
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

void GeneticAlgorithm::free_Descendants()
{
    for(int i = 0; i < rowsP ; i++)
    {
        free(descendants[i]);
    }
    free(descendants);
}


// para fazer o loop poderia substituir a população inicial por descendentes que surgem devido ao crossover que será entre o melhor individuo e outros aleatórios
//mecanismos de substituição Rd, R1,etc
