#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string> 
#include <sstream>
#include <cmath>


class Braco_robo{
private:
int braco; //situação se o braço ta levantado ou abraçado
int ind; //indice
int l; // linha
int c; //coluna
int L; //largura
int C; // altura

public:

Braco_robo(){

}

~Braco_robo(){

}

void suspender(){
    braco = 0;
}

void abaixar(){
   braco = 1; 
}

int sit_braco(){
    return braco;
}





void mover_direita(){
   int aux = c + 1;

    if(valida(aux) ){
        c = aux;
    }
}

void mover_esquerda(){
     int aux = c- 1;

    if(valida(aux) ){
        c = aux;
    }
}

void mover_cima(){
 int aux = l - 1;

    if(valida(aux) ){
        l = aux;
    }
}

void mover_baixo(){
    int aux = l + 1;

    if(valida(aux) ){
        l = aux;
    }
    
}


bool valida(int numero){
    int limite  = C* L;
    if(numero > -1 &&  numero < limite){
        return true;
    }else{
        return false;
    }
    
}


int indice(){
        ind = l*L+c;
        return ind;
}

void setlinha(int linha){
    l = linha;
}

void setcoluna(int coluna){
    c = coluna;
}

void setlargura(int largura){
    L = largura;
}

void setaltura(int altura){
    C = altura;
}




};







int main(){
    int largura;
    int altura;
    std::string nome_do_arquivo;
    std::string arquivo_leitura;
    std::string saida;

    std::cout << "digite o nome do arquivo que voce deseja ler: \n";
    std::cin >> nome_do_arquivo;

    std::ifstream arquivo_entrada;// cria um objeto para ler o arquivo
    arquivo_entrada.open(nome_do_arquivo); // abre o arquivo para leitura
    
    // checa se o arquivo conseguiu ser aberto, se foi aberto copia tudo para dentro de uma string com "!" sendo usando para quebra de linha     
    if (arquivo_entrada.is_open() ) {    
            while( getline(arquivo_entrada , arquivo_leitura  ) ){
        
                saida += arquivo_leitura;
                saida += "!";
            }
 
        }else{
                std::cout << arquivo_leitura <<" nao pode ser aberto"  << std::endl;
        abort();
    } 
    //fechando arquivo 
arquivo_entrada.close();



//pega largura e altura nas linhas da string e o numero de comandos
std::string auxiliar;
std::string::size_type posicao_da_pesquisa1;
std::string::size_type posicao_da_pesquisa2;
std::string::size_type posicao_da_pesquisa3;
std::stringstream sst;
std::stringstream ss;
int numero; //numero de instruções


//le a primeira linha e grava a largura
posicao_da_pesquisa1 = saida.find("!");
auxiliar = saida.substr (0,posicao_da_pesquisa1);

sst << auxiliar << std::endl;
sst >> largura;

//le a segunda linha e grava a altura
posicao_da_pesquisa2 = saida.find("!",posicao_da_pesquisa1+1);
auxiliar = saida.substr (posicao_da_pesquisa1+1,posicao_da_pesquisa2);

sst << auxiliar << std::endl;
sst >> altura;

//le a terceira linha e grava o numero de comandos 
posicao_da_pesquisa3 = saida.find("!",posicao_da_pesquisa2+1);
int ande = posicao_da_pesquisa3 - (posicao_da_pesquisa2+1);
auxiliar = saida.substr ( posicao_da_pesquisa2+1, ande);

ss << auxiliar << std::endl;
ss >> numero ;



//cria uma matriz e preenche tudo com 0

int *mat = new int[altura * largura];


for (int i = 0; i < largura; i++)
{
  for (int  j = 0; j <altura ; j++)
  {
      mat[j * largura + i] = 0;
  }
  
}

//cria uma nova string com apartir da quarta linha
std::string::size_type posicao_da_pesquisa4;
posicao_da_pesquisa4 = saida.find("!",posicao_da_pesquisa3);
saida = saida.substr (posicao_da_pesquisa4+1);



   Braco_robo *primeiro  = new Braco_robo();    //cria um objeto braço robo


std::string aux;
std::string aux2;

// coloca o braço na posiçao inicial
        int col = 0;
        int lin = 0;
        primeiro->suspender();
        primeiro->setlargura(largura);
        primeiro->setaltura(altura);
        primeiro->setcoluna(col);
        primeiro->setlinha(lin);

// le as instruções
for (int x = 0; x < numero ; x++)
{        
        

        int numero_repete  = 1;

        //le a linha
        posicao_da_pesquisa1 = saida.find("!");
        aux = saida.substr (0,posicao_da_pesquisa1);

        //pega o comando
        auxiliar = aux.substr (0, 1);


        //verifica se tem repetiçao do comando 
        if(posicao_da_pesquisa1 > 1){
            aux2 = saida.substr (1,posicao_da_pesquisa1);
            numero_repete  = atoi(aux2.c_str());
        }
    

        //opera o braço
                if(auxiliar == "s"){
                    primeiro->suspender();
                }
                if(auxiliar == "a"){
                    primeiro->abaixar();
                }

                if(auxiliar == "c"){

                        for (int i = 0; i < numero_repete; i++)
                        {
                            primeiro->mover_cima();
                            if(primeiro->sit_braco( ) == 1 ){
                            mat[primeiro->indice()] = primeiro->sit_braco();
                            }
                        }   
                }

                  if(auxiliar == "b"){

                        for (int i = 0; i < numero_repete; i++)
                        {
                            primeiro->mover_baixo();
                             if(primeiro->sit_braco( ) == 1 ){
                            mat[primeiro->indice()] = primeiro->sit_braco();
                            }
                        }   
                }

                  if(auxiliar == "e"){

                        for (int i = 0; i < numero_repete; i++)
                        {
                            primeiro->mover_esquerda();
                          if(primeiro->sit_braco( ) == 1 ){
                            mat[primeiro->indice()] = primeiro->sit_braco();
                            }
                        }   
                }

                  if(auxiliar == "d"){

                        for (int i = 0; i < numero_repete; i++)
                        {
                            primeiro->mover_direita();
                             if(primeiro->sit_braco( ) == 1 ){
                            mat[primeiro->indice()] = primeiro->sit_braco();
                            }
                        }   
                }
               //std::cout << saida << " " <<numero_repete<<" " <<primeiro->indice() << "\n " ;

//diminui a linha da string q ja foi executada
posicao_da_pesquisa4 = saida.find("!",posicao_da_pesquisa1);
saida = saida.substr (posicao_da_pesquisa4+1);



}



// grava no arquivo
std::ofstream arquivo_saida;

std::cout << "digite o nome do arquivo de saida"<< std::endl;

std::string nome_arquivo_saida;

std::cin >> nome_arquivo_saida;

nome_arquivo_saida + ".pbm";

arquivo_saida.open(nome_arquivo_saida);

arquivo_saida << "P1\n";
arquivo_saida << "# jose rafael nobrega bezerra\n";
arquivo_saida << largura << "\n";
arquivo_saida << altura << "\n";

int maximo = largura*altura;
int contador; 
for (int i = 0; i < maximo ; i++)
{
  arquivo_saida<< mat[i] ;
  arquivo_saida<< " ";
  contador++;
  if(contador == largura ){
      contador = 0;
    arquivo_saida << "\n";
  } 
}

arquivo_saida.close();


    delete  []mat;
    delete primeiro;
    return 0;
}