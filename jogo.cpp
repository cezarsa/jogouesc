/*  General Public License - GPL 2002.
	Por estudantes de Ciъncia da Computaчуo - Universiade Estadual de Santa Cruz
	Thiago Santana da Silva (^Turbo^)  thiagofeira@hotmail.com  (2К Semestre)
	Giovanni Gallindo		(SID_CDF)  gigio@privat.ms          (1К Semestre)
	Mathias Brito					   mathiasbrito@yahoo.com	(2К Semestre)
	Sugestѕes, criticas mande um e-mail para nosso grupo: cmaisjogos@yahoogrupos.com.br  
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
using namespace std;
void chefao();
int abertura(); //a tela de abertura do jogo
void uesccombat(); //o nm do jogo
void regras_jogo(); //mostra o funcinamento do jogo
void agradecimentos(); //As pessoas que contribuiram para o jogo
void jogo(); //Roda o jogo
void inicializa_personagem(int&,int&,int&); // o Usuario distribui seus pontos entre os atributos
void inicia_luta(int, char[25], int, int, int, int, int, int, int, int , int, int, int); //Mostra os participantes da luta
void status(int,int,int,int,int); //Monstra o status do jogador
int dado(void); // sortei um dado
int combate (int,int,char[25],int&,int&,int&,int&,int&); //aqui eh que se da o combate
void monstros( int, int, int&, int&, int&, int&, int&); // pega os atributos do monstro em um banco de informacoes
int dano(int, int, int&, int, int, int&);//Calcula quanto vai tirar de life, com os respectivos atributos
void intensidade(int, char [25], char [25]); //dependendo da potencia, diz o golpe que sofreu
void refaz_personagem(int&,int&,int&,int&,int&); //o usuario ganha pontos e redistribui no seus atributos
void gameover(); // Fim do jogo
int porcentagem(int); //Calcula o tamanho da barrinha do life
void barrinha(int, char[25], int); // Faz a barrinha do LIFE
char nome_monstro[25]; // Variavel glabal, pq necessitava de ponteiro e nao sei ainda.
void zerar(); 
const int  life_inicial=50; // constante do life de todos(monstros,personagem)
 
int main()
{		
	static opcao=0;
	srand(time(0));
	do
	{
		opcao=abertura();
			switch(opcao){
				case 1 :
					jogo(); //Roda o jogo
					break;
				case 2:
					regras_jogo(); //Mostra as regras do jogo
					break;
				case 3:
					agradecimentos(); //Os agradecimentos as pessoas que contribuiram p/ nosso jogo
					break;
			}
	}while(opcao!=4);
	  return 0;
}

int abertura(){
		int escolha;
	do{
	uesccombat();
	cout<<"   ЎЏ Thiago Silva (^Turbo^), Giovanni Gallindo (SID_CDF) & Mathias Brito ЎЏ\n";
	cout<<"\t\t           GNU - General Public License\n";
	cout<<"\t\t  Copyrigth 2002. Free Software Foundation, inc.\n";
	cout<<"\t      Este programa eh distribuido sobre os termos da GPL v2\n\n";
	cout<<"  1 - Comercar o jogo\n";
	cout<<"  2 - Regras do Jogo\n";
	cout<<"  3 - Agradecimentos\n";
	cout<<"  4 - Sair \n";
	cout<<"O que deseja fazer? ";
	cin>>escolha;
	cout<<endl;
	}while(escolha<1 || escolha>4);
return escolha;
}

void uesccombat()
{
	system("CLS");
	cout<<"\n";
	cout<<"\t\t\t  лл  лл  лллллл  лллллл  лллллл\n";
	cout<<"\t\t\t  лл  лл  лл      лл      лл\n";
	cout<<"\t\t\t  лл  лл  лллл    лллллл  лл\n";
	cout<<"\t\t\t  лл  лл  лл          лл  лл\n";
	cout<<"\t\t\t  лллллл  лллллл  лллллл  лллллл\n\n";
	
	cout<<"\t        АААААА  АААААА  ААА АААА  АААААА   АААААА  ААААААА\n";
	cout<<"\t       АА      АА  АА  АА АА АА  АА   А   АА  АА     АА \n";
	cout<<"\t      АА      АА  АА  АА АА АА  АААААА   АААААА     АА\n";
	cout<<"\t     АА      АА  АА  АА    АА  АА   А   АА  АА     АА\n";
	cout<<"\t    АААААА  АААААА  АА    АА  АААААА   АА  АА     АА\n";
	cout<<"\t\t\t\t\t\t  Versao 0.2\n";
}
void jogo()
{	
	int resistencia_personagem=0,agilidade=0,pontos_personagem=0, ataque=0,
		fase=1, numero_monstro=1, perdeu=0,dinheiro=0;
	char nome_personagem[25]; 
	
	system("CLS"); 
					inicializa_personagem(resistencia_personagem, agilidade, ataque);	
					cout << "Digite seu nome Џ ";
					cin >> nome_personagem;
					system("CLS");
					fase=1;
					
					while(fase <= 6 )
					{
							while(numero_monstro <= 6){ 
								perdeu=combate(fase, numero_monstro, nome_personagem, resistencia_personagem, ataque, agilidade, pontos_personagem, dinheiro);
								if (perdeu==1){
									gameover();
									fase=9999;
									break;
								}
								system("CLS");
								if (fase==6 && numero_monstro==6){
									zerar();
									break;
								}
							refaz_personagem(pontos_personagem,resistencia_personagem,agilidade,ataque,dinheiro);
								numero_monstro++;
							}
					fase++;
					numero_monstro=1;
					}
}
void regras_jogo()
{
	system("CLS");
	cout<<"\t\tSeja bem vindo ao jogo ЎЎ UESC COMBAT ЏЏ\n\n";
	cout<<"\tRegras:\n";
	cout<<"No inicio do jogo, voce escolhe o NIVEL, de acordo com ele voce recebe \n";
	cout<<" uma quantidade de pontos.\n";
	cout<<"Distribua seus pontos entre os atributos. Sao eles:\n";
	cout<<"\t1 - RESISTENCIA: Capacidade de resistir aos golpes.\n";
	cout<<"\t2 - ATAQUE: Corresponde a sua capacidade de ataque.\n";
	cout<<"\t3 - AGILIDADE: Corresponde a sua capacidade de agilidade.\n";
	cout<<"O seu adversario tambem possui esses atributos, que sao necessarios no momento\n";
	cout<<"do combate. O combate eh realizado da seguinte forma:\n";
	cout<<"\t1 - Eh sorteado um numero para a batalha\n";
	cout<<"\t2 - Esse numero eh somado ao seu ataque.\n";
	cout<<"\t3 - Se essa soma for maior do que a agilidade do seu adversario, voce\n";
	cout<<"\t    acerta o golpe.\n";
	cout<<"\t4 - Apos o ataque o seu adversario perdera em LIFE o valor ATAQUE + \n";
	cout<<"\t  DADO(numero sorteado) - RESISTENCIA .\n";
	cout<<"\n\n\t Agora que voce ja sabe como funciona, boa diversao.\n\n\n\n";
	system("PAUSE");
}

void agradecimentos()
{
	system("cls");
	cout<<"\t\t\t\tЎ AGRADECIMENTOS Џ\n\n";
	cout<<"\tGostariamos  de  agradecer  a  algumas  pessoas  que tornaram esse jogo possivel.\n";
	cout<<"1 - Agradecemos em primeiro lugar ao homem que teve a brilhante ideia de contar seus carneirinhos utilizando pedrinhas, o que mais tarde deu origem ao abaco queeh o ancestral do computador.\n";
	cout<<"2 - Gostariamos de prestar homenagem aos homens que tornaram nossas vidas melhor Blaise  Pascal e  Charles Babage. Agradecemos tambem a Martin Richards (Pai da linguagem BCPL), Ken Tompson(Pai da linguagem B), que deram origem as linguagensC e C++\n";
	cout<<"3 - Louvamos a Dennis Ritchie, criador da linguagem C e a Bjarne Stroustrup pai da linguagem C++ utilizada para desenvolver esse game.\n";
	cout<<"\n\tAgradecemos especialmente as pessoas que  colaboraram diretamente com o nosso trabalho:\n";
	cout<<"Thiago Calo\tDanilo Delafonte\tHelder Barros (Valeu pelo STRCPY !)\n";
	cout<<"Caio       \tRodrigo         \tCesar Espinola\n";
	cout<<"Betinhum\n";
	cout<<"E muitos outros que contribuiram com sugestoes e opnioes. Obrigado!\n\n\n\n";
	system("PAUSE");
}
void inicializa_personagem(int &resistencia, int&agilidade, int &ataque)
{
	int pontos, aux,dinheiro=0, nivel=0;
	//pontos= 30 + rand() % 30;
	uesccombat();
	cout << "\n\t\t\t\tSeja Bem Vindo.\n\n";
	
	do{
		cout<<" 1 - Facil \n";
		cout<<" 2 - Normal \n";
		cout<<" 3 - Dificil \n";
	cout << " Escolha o NIVEL que voce deseja jogar:  ";
	cin>>nivel;
	if (nivel<1 || nivel > 3)
		cout<< "\a VALOR INVALIDO \n";
	}while (nivel<1 || nivel > 3);
	cout << "\nBOA SORTE!\n\n";
	
	switch (nivel){
		case  1:
			pontos = 40;
			break;
		case 2:
			pontos = 30;
			break;
		case 3:
			pontos = 20;
			break;
		default:
			cout<<"Nao devia entrar aqui\n";
	}

	system("PAUSE");
	system("CLS");
	cout << "Voce tem  " << pontos <<" pontos"<< endl;
	cout << "Distribua os pontos entre os atributos: \n";
	cout << "ATAQUE , AGILIDADE e RESISTENCIA.\n";
	
	//Atribuicao dos valores aos atributos
	do{
		
		do {
			cout << "VALOR DO ATAQUE Џ ";
			cin >> aux;
			
			if (aux > pontos ) // verifica se tem pontos suficientes
				cout << "Pontos insuficientes, DIGITE NOVAMENTE\n";
			if (aux < 0) // verifica se eh positivo
				cout << "Valor invalido... DIGITE NOVAMENTE\n";
			
		}while (aux > pontos || aux < 0 ) ;
		pontos -= aux;
		ataque+=aux;
		aux=0;
		
		if (pontos > 0) { //testa se ainda tem pontos
			
			do {
				cout<<"Voce tem "<<pontos<<" pontos"<<endl;
				cout << "VALOR DA AGILIDADE Џ ";
				cin >> aux;
				
				if (aux > pontos ) // verifica se tem pontos suficientes
					cout << "Pontos insuficientes, DIGITE NOVAMENTE\n";
				if (aux < 0) // verifica se eh positivo
					cout << "Valor invalido... DIGITE NOVAMENTE\n";

			}while (aux > pontos || aux < 0);	
			pontos -= aux;
			agilidade += aux;
			aux=0;
			
			if (pontos > 0){ // testa se ainda tem pontos
				
				do {
					cout<<"Voce tem "<<pontos<<" pontos"<<endl;
					cout << "VALOR DA RESISTENCIA Џ ";
					cin >> aux;
					
					if (aux > pontos ) // verifica se tem pontos suficientes
						cout << "Pontos insuficientes, DIGITE NOVAMENTE\n";
					if (aux < 0) // verifica se eh positivo
						cout << "Valor invalido... DIGITE NOVAMENTE\n";
				 
				}while (aux > pontos || aux < 0);
				pontos -= aux;
				resistencia += aux;
				aux=0;
			}
		}
		if (pontos > 0){
			system("CLS");	
			status(resistencia,agilidade,ataque,pontos,dinheiro);
			cout << "Vc ainda tem " << pontos << " pontos sobrando USE-OS\n";
		}
	
	}while(pontos>0);//verifica se sobrou pontos
	
	cout << "O seu personagem foi criado com sucesso\n";
	cout << "BOA AVENTURA\n\n";
}


int dado() {
	return 1 + rand() % 6;
}

void intensidade(int dado, char atacante[25], char vitima[25]) {
	switch(dado) {
		case 0:
			switch(1 + rand() % 3){
			case 1:
				cout << atacante << " errou o golpe" << endl;
				break;
			case 2: 
				cout<< "Passa de raspao o chute de " << atacante<< endl;
				break;
			case 3:
				cout<<atacante<<" nao acerta o chute"<<endl;
				break;
			}
		break;
		case 1:
			switch(1 + rand() % 3){
			case 1:
				cout << atacante << " deu um piteleco em " << vitima << endl;
				break;
			case 2: 
				cout<< atacante<<" puxa os cabelos de "<< vitima<< endl;
				break;
			case 3:
				cout<<atacante<<" da um beliscao em "<<vitima<<endl;
				break;
			}
			break;
		case 2:
			switch(1 + rand() % 3){
			case 1:
				cout << atacante << " acertou um murro na caixa dos peito de " << vitima << endl;
				break;
			case 2: 
				cout<< atacante<<" deu uma rasteira em "<< vitima<< endl;
				break;
			case 3:
				cout<<atacante<<" enfia o dedo no olho de "<<vitima<<endl;
				break;
			}
			break;
		case 3:
			switch(1 + rand() % 3){
			case 1:
				cout << atacante << " deu um chute na canela de " << vitima << endl;
				break;
			case 2: 
				cout<< atacante<<" deu uma mordida na orelha de "<< vitima<< endl;
				break;
			case 3:
				cout<<atacante<<" da um surdao em "<<vitima<<endl;
				break;
			}
			break;
		case 4:
			switch(1 + rand() % 3){
			case 1:
				cout << atacante << " deu um murro na boca do estomago de " << vitima << endl;
				break;
			case 2:
				cout<< atacante<<" deu um murro no olho de "<< vitima<< endl;
				break;
			case 3:
				cout<<atacante<<" da uma cadeirada em "<<vitima<<endl;
				break;
			}
			break;
		case 5:
			switch(1 + rand() % 3){
			case 1:
				cout << atacante << " passa o canivete no braco de  " << vitima << endl;
				break;
			case 2:
				cout<< atacante<<" da uma tijolada na cabeca de "<< vitima<< endl;
				break;
			case 3:
				cout<<atacante<<" da uma voadoura em "<<vitima<<endl;
				break;
			}
			break;
		case 6:
			switch(1 + rand() % 3){
			case 1:
				cout << atacante << " rancou tres dentes de " << vitima << endl;
				break;
			case 2:
				cout<< atacante<<" enfia uma faca na barriga de "<< vitima<< endl;
				break;
			case 3:
				cout<<atacante<<" arranca a lingua de "<<vitima<<endl;
				break;
			}
			break;
		case 7:
			switch (1 + rand() % 3) {
			case 1: 
				cout << vitima << " defendeu o chute de  " << atacante << endl;
				break;
			case 2:
				cout<< atacante <<" tentou da um gancho em  "<< vitima<<", mas "<< vitima<< " se esquiva.\n";
				break;
			case 3:
				cout<<vitima<<" se livra do murro de  "<<atacante<<endl;
				break;
			default:
			cout << "oops" << endl;

			}
						
		}
		
}
int combate(int fase, int numero_monstro, char nome_personagem[25],int &resistencia_personagem,int &ataque_personagem,int &agilidade_personagem,int &pontos_personagem, int &dinheiro_personagem)
{
	int cont=0,potencia=0, resistencia_monstro=0, 
		ataque_monstro=0, agilidade_monstro=0,dinheiro_monstro,rola_dado, 
		pontos_monstro=0, //pontos que o monstro passa para o personagem
		life_personagem=50, life_monstro=50;
	if (numero_monstro == 6)
		chefao();

	monstros(fase, numero_monstro, resistencia_monstro, ataque_monstro, agilidade_monstro, pontos_monstro, dinheiro_monstro);
	inicia_luta(fase, nome_personagem, resistencia_personagem, ataque_personagem, agilidade_personagem, pontos_personagem, dinheiro_personagem, resistencia_monstro, ataque_monstro, agilidade_monstro, pontos_monstro, dinheiro_monstro, numero_monstro); //monstra os participantes da luta
	                ;
	//inicio do combate
	while (life_personagem > 0 && life_monstro > 0) {
		cont++;
		cout << "\t\t----------> Resultado da " << cont << "І Rodada <------------\n\n";
		
		//jogada do monstro
		rola_dado=dado();
		cout << "\t\t### Jogada de "<< nome_monstro << " ###\n";
		cout<<"O numero sorteado para o de ataque de "<< nome_monstro <<" foi "<< rola_dado<<endl<<endl;

		potencia=dano(agilidade_monstro, ataque_monstro, life_personagem, agilidade_personagem, resistencia_personagem, rola_dado);
		intensidade(potencia, nome_monstro, nome_personagem);
		
		if (life_personagem <= 0) // Para nao existir life negativo
			life_personagem = 0;
		
		if (life_personagem<=0){
			cout << "Voce foi derrotado por " << nome_monstro <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<< endl;
			return 1;
			
		}
		
		//jogada do personagem
		rola_dado=dado();
		cout << "\n\n\t\t### Jogada de "<< nome_personagem << " ###\n";
		cout<<"O numero sorteado para o de ataque de "<< nome_personagem <<" foi "<< rola_dado<<"\n\n";
		potencia=dano(agilidade_personagem, ataque_personagem, life_monstro, agilidade_monstro, resistencia_monstro, rola_dado);
		intensidade(potencia, nome_personagem, nome_monstro);
		
		if (life_monstro <= 0)
			life_monstro = 0;

		if (life_monstro <= 0) {
			cout << "\n\nParabens voce derrotou " << nome_monstro << endl;
			cout<< "Voce ganhou "<<pontos_monstro<<" pontos"<<endl;
			cout<< "Voce ganhou "<<dinheiro_monstro<<" Reais\n\n\n\n\n\n"<<endl;
			pontos_personagem += pontos_monstro;
			dinheiro_personagem += dinheiro_monstro; 
			system("PAUSE");
			return 0;
		}
		barrinha(life_personagem,nome_personagem,life_monstro);
		cout<<"\n";
		system("PAUSE");
		system("CLS");	
	}
	system("CLS");	
	return 0;	
}

void inicia_luta(int fase, char nome_personagem[25], int resistencia_personagem, int ataque_personagem, int agilidade_personagem, int ponto_personagem, int dinheiro_personagem, int resistencia_monstro, int ataque_monstro, int agilidade_monstro, int ponto_monstro, int dinheiro_monstro, int numero_monstro)
{
	system("CLS");
	if (numero_monstro==6)
		cout<<"\t\t\t\t\t\t\t CHEFAO";
	cout<<"\n\t  /ўўўўў\\                FASE - "<<fase<<"                /ўўўўў\\\n";
	cout<<"\t  ў Я Я ў                LUTA - "<<numero_monstro<<"                ў Я Я ў\n";
	cout<<"\t  ў  -  ў                                        ў  -  ў\n";
	cout<<"\t  \\ўўўўў/                 л   л                  \\ўўўўў/\n";
	cout<<"\t     *                     л л                      *\n";
	cout<<"\t     *                      л                       *\n";
	cout<<"\t   *****                   л л                    *****\n";
	cout<<"\t  *  *  *                 л   л                  *  *  *\n";
	cout<<"\t     *                                              *\n";
	cout<<"\t    * *                                            * *\n";
	cout<<"\t   *   *                                          *   *\n\n";
	cout<<"\t"<<nome_personagem<<"\t\t\t\t       "<<nome_monstro<<"\n";

	cout<<" _________________________\t\t       _________________________\n";
	cout<<"   Atributo   |  Status  \t\t         Atributo   |  Status  \n";
	cout<<" -------------|-----------\t\t       -------------|-----------\n";
	cout<<"    Ataque    |    "<<ataque_personagem<<"    \t\t          Ataque    |    "<<ataque_monstro<<"\n";
	cout<<"  Agilidade   |    "<<agilidade_personagem<<"    \t\t       Agilidade    |    "<<agilidade_monstro<<"\n";
	cout<<" Resistencia  |    "<<resistencia_personagem<<"    \t\t       Resistencia  |    "<<resistencia_monstro<<"\n";
	cout<<"    Pontos    |    "<<ponto_personagem<<"    \t\t          Pontos    |    "<<ponto_monstro<<"\n";
	cout<<"   Dinheiro   |    "<<dinheiro_personagem<<"    \t\t         Dinheiro   |    "<<dinheiro_monstro<<"\n";
	cout<<" -------------------------\t\t      --------------------------\n";    
	
	system("PAUSE");
	system("CLS");
}

void monstros(int fase,int numero,int &resistencia,int &ataque,int &agilidade,int &pontos,int &dinheiro) {
	

		switch (fase){
		case 1:
			switch (numero) {
				case 1: // Rihan
					strcpy(nome_monstro,"Rihan");
					resistencia = 8;
					ataque = 8;
					agilidade = 8;
					pontos = 2;
					dinheiro = 2;
					break;
				case 2: // Jurema
					strcpy(nome_monstro,"Jurema");
					resistencia = 8;
					ataque = 8;
					agilidade = 9;
					pontos = 2;
					dinheiro = 3;
					break;
				case 3: // Largatauro
					strcpy(nome_monstro,"Largatauro");
					resistencia = 10;
					ataque = 10;
					agilidade = 9;
					pontos = 3;
					dinheiro = 5;
					break;
				case 4: // Lucas Beija-Homem
					strcpy(nome_monstro,"Lucas Beija-Homem");
					resistencia = 10;
					ataque = 12;
					agilidade = 9;
					pontos = 3;
					dinheiro = 6;
					break;
				case 5: // Paulete
					strcpy(nome_monstro,"Paulete");
					resistencia = 11;
					ataque = 9;
					agilidade = 10;
					pontos = 3;
					dinheiro = 7;
					break;
				case 6: //Vassorito chefao
					strcpy(nome_monstro,"Vassorito");
					resistencia = 14;
					ataque = 14;
					agilidade = 10;
					pontos = 5;
					dinheiro = 10;
					break;
				
				default:
					cout << "Nao devia entrar aqui\n";
			}
		break;
		case 2:	 //48
				switch (numero) {
					case 1: // Olivao
						strcpy(nome_monstro,"Olivao");
						resistencia = 13;
						ataque = 16;
						agilidade = 13;
						pontos = 5;
						dinheiro = 10;
						break;
					case 2: // Gaucho de Pelotas
						strcpy(nome_monstro,"Gaucho de Pelotas");
						resistencia = 14;
						ataque = 18;
						agilidade = 16;
						pontos = 5;
						dinheiro = 11;
						break;
					case 3: // Gilow
						strcpy(nome_monstro,"Gilow");
						resistencia = 15;
						ataque = 20;
						agilidade = 18;
						pontos = 5;
						dinheiro = 12;
						break;
					case 4: // Piriquito
						strcpy(nome_monstro,"Piriquito");
						resistencia = 16;
						ataque = 22;
						agilidade = 20;
						pontos = 5;
						dinheiro = 12;
						break;
					case 5: // Kiko
						strcpy(nome_monstro,"Kiko");
						resistencia = 18;
						ataque = 21;
						agilidade = 22;
						pontos = 5;
						dinheiro = 13;
						break;
					case 6: //Bola Bolia
						strcpy(nome_monstro,"Bola Bola");
						resistencia = 17;
						ataque = 26;
						agilidade = 27;
						pontos = 7;
						dinheiro = 15;
						break;
					
					default:
						cout << "Nao devia entrar aqui\n";
				
				}
				break;
		case 3:	//80
				switch (numero) {
					case 1: // Guioday
						strcpy(nome_monstro,"Guioday");
						resistencia = 21 ;
						ataque = 29;
						agilidade = 25;
						pontos = 6;
						dinheiro = 15;
						break;
					case 2: // Sundown
						strcpy(nome_monstro,"Sundown");
						resistencia = 21;
						ataque = 33;
						agilidade = 27;
						pontos = 6;
						dinheiro = 16;
						break;
					case 3: // Jusa
						strcpy(nome_monstro,"Jusa");
						resistencia = 22;
						ataque = 35;
						agilidade = 28;
						pontos = 6;
						dinheiro = 17;
						break;
					case 4: // Canario
						strcpy(nome_monstro,"Canario");
						resistencia = 23;
						ataque = 36;
						agilidade = 29;
						pontos = 6;
						dinheiro = 19;
						break;
					case 5: // Cabrinha
						strcpy(nome_monstro,"Cabrinha");
						resistencia = 28;
						ataque = 31;
						agilidade = 32;
						pontos = 6;
						dinheiro = 19;
						break;
					case 6: //Tam Capeta
						strcpy(nome_monstro,"_TaM_cApEtiNhA_");
						resistencia = 34;
						ataque = 36;
						agilidade = 35;
						pontos = 8;
						dinheiro = 20;
						break;
					
					default:
						cout << "Nao devia entrar aqui\n";
				
				}
				break;
		case 4:	//118
				switch (numero) {
					case 1: // Jonh Sux
						strcpy(nome_monstro,"Jonh Sux");
						resistencia = 38;
						ataque = 38;
						agilidade = 30;
						pontos = 7;
						dinheiro = 20;
						break;
					case 2: // Satangos
						strcpy(nome_monstro,"Satangos");
						resistencia = 41;
						ataque = 38;
						agilidade = 38;
						pontos = 7;
						dinheiro = 20;
						break;
					case 3: // Tyger
						strcpy(nome_monstro,"Tyger");
						resistencia = 38;
						ataque = 45;
						agilidade = 45;
						pontos = 7;
						dinheiro = 20;
						break;
					case 4: // Vitor
						strcpy(nome_monstro,"Vitor");
						resistencia = 20;
						ataque = 60;
						agilidade = 45;
						pontos = 7;
						dinheiro = 20;
						break;
					case 5: // Pina 
						strcpy(nome_monstro,"Pina");
						resistencia = 46;
						ataque = 40;
						agilidade = 41;
						pontos = 7;
						dinheiro = 20;
						break;
					case 6: //Kid
						strcpy(nome_monstro,"kid");
						resistencia = 30;
						ataque = 70;
						agilidade = 45;
						pontos = 10;
						dinheiro = 25;
						break;
					
					default:
						cout << "Nao devia entrar aqui\n";
				
				}
				break;
		case 5:	//163
				switch (numero) {
					case 1: // Munrrah
						strcpy(nome_monstro,"Munrrah");
						resistencia = 45;
						ataque = 53;
						agilidade = 52;
						pontos = 9;
						dinheiro = 25;
						break;
					case 2: // Sergio Ricardo
						strcpy(nome_monstro,"Sergio Ricardo");
						resistencia = 46;
						ataque = 55;
						agilidade = 51;
						pontos = 9;
						dinheiro = 25;
						break;
					case 3: // Gilberlandiuuu
						strcpy(nome_monstro,"Gilberlandiuuu");
						resistencia = 56;
						ataque = 56;
						agilidade = 56;
						pontos = 9;
						dinheiro = 25;
						break;
					case 4: // Titio Cobol
						strcpy(nome_monstro,"Titio Cobol");
						resistencia = 58;
						ataque = 60;
						agilidade = 53;
						pontos = 9;
						dinheiro = 25;
						break;
					case 5: // Teodoro	
						strcpy(nome_monstro,"Teodoro");
						resistencia = 40;
						ataque = 80;
						agilidade = 60;
						pontos = 9;
						dinheiro = 25;
						break;
					case 6: //Decio 
						strcpy(nome_monstro,"Decio");
						resistencia = 64;
						ataque = 68;
						agilidade = 60;
						pontos = 13;
						dinheiro = 30;
						break;
					
					default:
						cout << "Nao devia entrar aqui\n";
				
				}
				break;
		case 6:	//221
				switch (numero) {
					case 1: // calo
						strcpy(nome_monstro,"Calo");
						resistencia = 63;
						ataque = 65;
						agilidade = 64;
						pontos = 9;
						dinheiro = 30;
						break;
					case 2: // Danilo
						strcpy(nome_monstro,"Danilo");
						resistencia = 70;
						ataque = 73;
						agilidade = 67;
						pontos = 9;
						dinheiro = 50;
						break;
					case 3: // SID_CDF
						strcpy(nome_monstro,"SID_CDF");
						resistencia = 69;
						ataque = 75;
						agilidade = 75;
						pontos = 9;
						dinheiro = 60;
						break;
					case 4: // Mathias
						strcpy(nome_monstro,"Mathias");
						resistencia = 70;
						ataque = 75;
						agilidade = 77;
						pontos = 9;
						dinheiro = 70;
						break;
					case 5: // Turbo	
						strcpy(nome_monstro,"Turbo");
						resistencia = 65;
						ataque = 95;
						agilidade = 80;
						pontos = 9;
						dinheiro = 80;
						break;
					case 6: //Tia Paulinha
						strcpy(nome_monstro,"Tia Paulinha");
						resistencia = 80;
						ataque = 90;
						agilidade = 85;
						pontos = 15;
						dinheiro = 100;
						break;
					
					default:
						cout << "Nao devia entrar aqui\n";
				
				}
				default:
					cout << "Nao devia entrar aqui\n";
		}
}

int dano(int agilidade_atacante, int ataque_atacante,  int &life_vitima, int agilidade_vitima, int resistencia_vitima, int &rola_dado)
{
	int perda, defendeu=7;
	perda = ataque_atacante + rola_dado - agilidade_vitima;
	
	if (perda > 0 && ( ataque_atacante + rola_dado - resistencia_vitima) > 0 )
	{
		life_vitima -= perda + ( ataque_atacante + rola_dado - resistencia_vitima);
		return rola_dado;
	}
	else if ( (ataque_atacante + rola_dado - (agilidade_vitima + resistencia_vitima)/2 ) > 0 )
	{
		life_vitima -= ( ataque_atacante + rola_dado - (agilidade_vitima + resistencia_vitima)/2);
		rola_dado=1;
		return rola_dado;
	}
	else if ( perda > 0){
		life_vitima -= perda;
		return rola_dado;
	}
	else if (rola_dado == 6){
		life_vitima -= 6;
		return rola_dado;
	}

	return defendeu;
	
}

void refaz_personagem(int &pontos,int &resistencia, int&agilidade, int &ataque, int &dinheiro)
{
	int  aux=0, redefinir=0;
	cout<<"\tVoce tem "<<pontos<< " pontos \n";
	cout << "Distribua os pontos entre os atributos: \n";
	status(resistencia,agilidade,ataque,pontos,dinheiro);
	
	//Atribuicao dos valores aos atributos
	do{
		redefinir=0;
		do {
			cout << "ADICIONAR AO ATAQUE Џ ";
			cin >> aux;
			
			if (aux > pontos ) // verifica se tem pontos suficientes
				cout << "Pontos insuficientes, DIGITE NOVAMENTE\n";
			if (aux < 0) // verifica se eh positivo
				cout << "Valor invalido... DIGITE NOVAMENTE\n";
		}while (aux > pontos || aux < 0 );
		pontos -= aux;
		ataque+=aux;
		aux=0;
		system("cls");
		cout<<"\tVoce tem "<<pontos<< " pontos \n";
		cout << "Distribua os pontos entre os atributos: \n";
		status(resistencia,agilidade,ataque,pontos,dinheiro);
		
		if (pontos > 0) { //testa se ainda tem pontos
			
			do {
	//			cout<<"Voce tem "<<pontos<<" pontos"<<endl;
				cout << "ADICIONAR A AGILIDADE Џ ";
				cin >> aux;
				
				if (aux > pontos ) // verifica se tem pontos suficientes
					cout << "Pontos insuficientes, DIGITE NOVAMENTE\n";
				if (aux < 0) // verifica se eh positivo
					cout << "Valor invalido... DIGITE NOVAMENTE\n";

			}while (aux > pontos || aux < 0);	
			pontos -= aux;
			agilidade += aux;
			aux=0;
			system("cls");
			cout<<"\tVoce tem "<<pontos<< " pontos \n";
			cout << "Distribua os pontos entre os atributos: \n";
			status(resistencia,agilidade,ataque,pontos,dinheiro);
						
			if (pontos > 0){ // testa se ainda tem pontos
				
				do {
//					cout<<"Voce tem "<<pontos<<" pontos"<<endl;
					cout << "ADICIONAR A RESISTENCIA Џ ";
					cin >> aux;
					
					if (aux > pontos ) // verifica se tem pontos suficientes
						cout << "Pontos insuficientes, DIGITE NOVAMENTE\n";
					if (aux < 0) // verifica se eh positivo
						cout << "Valor invalido... DIGITE NOVAMENTE\n";
				 
				}while (aux > pontos || aux < 0);
				pontos -= aux;
				resistencia += aux;
				aux=0;
				system("cls");
			cout<<"\tVoce tem "<<pontos<< " pontos \n";
			cout << "Distribua os pontos entre os atributos: \n";
			status(resistencia,agilidade,ataque,pontos,dinheiro);
		
			}
			
		}
		if (pontos > 0){
			do{
				system("CLS");	
				status(resistencia,ataque,agilidade,pontos,dinheiro);
				cout << "Vc ainda tem " << pontos << " pontos sobrando.\n\n";
				cout<<" 1- Guardar os pontos e continuar jogando\n";
				cout<<" 2- Quero redistribuir os pontos que sobraram\n";
				cout<<"O que deseja fazer? ";
				cin>>redefinir;
				if (redefinir!=1 && redefinir!=2)
					cout<<"\a Valor Invalido, digite novamente";
			}while(redefinir!=1 && redefinir!=2);
		}
	
	}while(redefinir==2);//verifica se sobrou pontos
	
	cout << "O seu personagem foi ajustado com sucesso.\n";
	cout << "BOA AVENTURA\n\n";
}

void status(int resistencia, int agilidade, int ataque, int pontos, int dinheiro )
{	cout<<"\t Atributo     \tStatus\n\n";
	cout << "\tATAQUE      \t  "<<ataque<<endl;
	cout << "\tAGILIDADE   \t  "<<agilidade<<endl;
	cout << "\tRESISTENCIA \t  "<<resistencia<<endl; 
	cout << "\tPONTOS      \t  "<<pontos<<endl;
	cout << "\tDINHEIRO    \t  "<<dinheiro<<endl;

}


void gameover(){
	system("PAUSE");
	system("CLS");
	cout<<"\n\n\n\n\t\t\tлллллл  лллллл  ллл   ллл  лллллл\n";
	cout<<"\t\t\tлл      лл  лл  лл л л лл  лл\n";
	cout<<"\t\t\tлл ллл  лллллл  лл  л  лл  лллл\n";
	cout<<"\t\t\tлл  лл  лл  лл  лл     лл  лл\n";
	cout<<"\t\t\tлллллл  лл  лл  лл     лл  лллллл\n\n";
	
	cout<<"\t\t\t  лллллл  лл  лл лллллл  ллллл  \n";
	cout<<"\t\t\t  лл  лл  лл  лл лл      лл  лл  \n";
	cout<<"\t\t\t  лл  лл  лл  лл лллл    ллллл  \n";
	cout<<"\t\t\t  лл  лл   лллл  лл      лл  лл \n";
	cout<<"\t\t\t  лллллл    лл   лллллл  лл  лл \n\n\n\n\n\n\n\n\n\n";
	system("PAUSE");

}
  

void barrinha(int life_personagem,char nome_personagem[25], int life_monstro)
{	
	int barra=0;
	// Barrinha do life_personagem
		barra=porcentagem(life_personagem);
		cout<<"\n\n\t\t\t";
		cout<<" "<<nome_personagem<<" L I F E \n\t";
		for (int i=0; i<50; i++)// imprime o fundo da barrinha
			cout<<"А";
		 
		cout<<"\r\t";
		for (int j=0; j<barra; j++) //imprime a quantidade de fife
			cout<<"л";
		cout<<"\n\n\n\t\t\t"; 
		
	
	// Barrinha do monstro
		
		barra=0;
		barra=porcentagem(life_monstro);
		cout<<nome_monstro<<" L I F E \n\t";
		for (int k=0; k<50; k++)// imprime o fundo da barrinha
			cout<<"А"; 
		
		cout<<"\r\t";
		for (int l=0; l<barra; l++) //imprime a quantidade de fife
			cout<<"л";
		cout<<"\n\n\n";
		
}


int porcentagem(int life) {
	int barrinha;
	barrinha = ((100 * life)/life_inicial)/2;
	return barrinha;
}

void zerar()
{	system("CLS");
	cout<<"\n\n\tлллллл  лллллл  ллллл   лллллл  ллллл   лллллл  лл  лл  лллллл\n";
	cout<<"\tлл  лл  лл  лл  лл  лл  лл  лл  лл  лл  лл      ллл лл  лл\n";
	cout<<"\tлллллл  лллллл  ллллл   лллллл  лллллл  лллл    лллллл  лллллл\n";
	cout<<"\tлл      лл  лл  лл  лл  лл  лл  лл  лл  лл      лл ллл      лл\n";
	cout<<"\tлл      лл  лл  лл  лл  лл  лл  ллллл   лллллл  лл  лл  лллллл\n";
	
	cout<<"\n\n\t\t\tлл  лл  лллллл  лллллл  лллллл\n";
	cout<<"\t\t\tлл  лл  лл  лл  лл      лл\n";
	cout<<"\t\t\tлл  лл  лл  лл  лл      лллл\n";
	cout<<"\t\t\t лллл   лл  лл  лл      лл\n";
	cout<<"\t\t\t  лл    лллллл  лллллл  лллллл\n\n\n";

	cout<<"\t\tлл  лл  лллллл  лл  лл  лллллл  лллллл  лл  лл  лл\n";
	cout<<"\t\tлл  лл  лл      ллл лл  лл      лл      лл  лл  лл\n";
	cout<<"\t\tлл  лл  лллл    лллллл  лл      лллл    лл  лл  лл\n";
	cout<<"\t\t лллл   лл      лл ллл  лл      лл      лл  лл\n";
	cout<<"\t\t  лл    лллллл  лл  лл  лллллл  лллллл  лллллл  лл\n\n\n";
	system("PAUSE");
}

void chefao()
{
	system("CLS");
	cout<<"\n\n\n\n\n\n";
	cout<<"\t\t                               лл  лл      \n";
	cout<<"\t\t                              лл лл     \n";
	cout<<"\t\t                                          \n";  
	cout<<"\t\t  ллллл  лл  лл  лллллл  ллллл  ллллл  ллллл\n";
	cout<<"\t\t  лл     лл  лл  лл      лл     л   л  лл лл\n";
	cout<<"\t\t  лл     лллллл  лллллл  ллл    ллллл  лл лл\n";
	cout<<"\t\t  лл     лл  лл  лл      лл     лл лл  лл лл\n";
	cout<<"\t\t  ллллл  лл  лл  лллллл  лл     л   л  ллллл\n\n\n\n\n\n\n\n\n\n";
	system("PAUSE");
}
